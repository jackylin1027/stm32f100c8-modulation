//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 gdm_task.c
//
//! @author 	 Willman Chen
//
//! @date 		 2009/07/14
//
//  @brief 		 Task Subroutine
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "..\drv_src\gdm_drv.h"
#include "gdm_glb_vars.h"
#include "..\gdm_udef.h"

//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 		 gdm_cls_line
//
//! @author 	 Willman Chen
//
//! @date 		 2009/07/14
//
//! @brief 		 This function is used for clearing certain line of lcd in graphic mode.
//
//! @param 		 line The index of graphic mode lcd line.
//
//! @return 	 None
//
//**********************************************************************************************************************
void gdm_cls_line(UINT8 line)
{
    GDM_SET_LCD_CURSOR_API(line,GDM_FIRST_COL);
    for (gb_gdm_col=GDM_FIRST_COL; gb_gdm_col<GDM_MAX_SEG; gb_gdm_col++)
        GDM_WRITE_DATA_API(GDM_BLANK_SEG);
}

//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 		 gdm_cls
//
//! @author 	 Willman Chen
//
//! @date 		 2009/07/14
//
//! @brief 		 Clear the LCD screen && mamory map screen
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void gdm_cls()
{
    UINT8 i;
    gdm_cls_canvas();
    for (i=0; i<GDM_MAX_LINE; i++)
        gdm_cls_line(i);
}

//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 		 gdm_cls_canvas
//
//! @author 	 Willman Chen
//
//! @date 		 2009/07/14
//
//! @brief 		 Clear the mamory map screen
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void gdm_cls_canvas()
{
    UINT8 i;
    for (i=GDM_FIRST_LINE; i<GDM_MAX_LINE; i++)
    {
        for (gb_gdm_col=GDM_FIRST_COL; gb_gdm_col<GDM_MAX_SEG; gb_gdm_col++)
            gb_gdm_canvas[i*GDM_MAX_SEG+gb_gdm_col]=GDM_BLANK_SEG;
#if GDM_MAX_LINE <=8
        gb_gdm_line_refresh|=(0x01<<i);
#else
        gb_gdm_line_refresh[i>>3]|=(0x01<<(i&0x07));
#endif
        gb_gdm_line_range[i<<1]=GDM_FIRST_COL;
        gb_gdm_line_range[(i<<1)+1]=GDM_MAX_SEG;
    }
    gb_gdm_col=GDM_FIRST_COL;
    gb_gdm_row=GDM_FIRST_LINE;
}

//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 		 gdm_setup_cursor
//
//! @author 	 Willman Chen
//
//! @date 		 2009/07/14
//
//! @brief 		 Setup the cursor postion of graphic mode lcd.
//
//! @param 		 x	The x position of cursor we wana setting
//! @param		 y  The y position of cursor we wana setting
//
//! @return 	 None
//
//**********************************************************************************************************************
void gdm_setup_cursor(UINT8 row,UINT8 col)
{
    gb_gdm_row=row;
    gb_gdm_col=col;
}

//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 		 gdm_setup_cursor_offset
//
//! @author 	 Willman Chen
//
//! @date 		 2009/07/14
//
//! @brief 		 Setup the cursor postion of graphic mode lcd.
//
//! @param 		 x	The x position of cursor we wana setting
//! @param		 y  The y position of cursor we wana setting
//
//! @return 	 None
//
//**********************************************************************************************************************
void gdm_setup_cursor_offset(UINT8 row,UINT8 col)
{
    gb_gdm_row+=row;
    gb_gdm_col+=col;
}

//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 		 gdm_dis_mapping_memory_to_lcd
//
//! @author 	 Willman Chen
//
//! @date 		 2009/07/14
//
//! @brief 		 Mapping memory data to lcd screen.
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void gdm_dis_mapping_memory_to_lcd()
{
    INT16 line,col;

    for (line=GDM_FIRST_LINE; line<GDM_MAX_LINE; line++)
    {
#if GDM_MAX_LINE <= 8
        if (gb_gdm_line_refresh&(0x01<<line))
#else
        if (gb_gdm_line_refresh[i>>3]&(0x01<<(line&0x07)))
#endif
        {
#if GDM_USE_UART == 1
            UINT32 len=gb_gdm_line_range[(line<<1)+1]-gb_gdm_line_range[(line<<1)];
            GDM_DATA_SEND_OUT_API('R');
            GDM_DATA_SEND_OUT_API('A');
            GDM_DATA_SEND_OUT_API('W');
            GDM_DATA_SEND_OUT_API(gb_gdm_line_range[line<<1]);
            GDM_DATA_SEND_OUT_API(line<<3);
            GDM_DATA_SEND_OUT_API(len);
#endif
#if GDM_UPSIDE_DOWN	== 1
            GDM_SET_LCD_CURSOR_API((GDM_MAX_LINE-line-1),gb_gdm_line_range[line<<1]);
#else
            gb_gdm_line_range[line<<1]=0x00;
            gb_gdm_line_range[(line<<1)+1]=0x80;
            col=gb_gdm_line_range[line<<1];
            GDM_SET_LCD_CURSOR_API(line,col);
#endif
#if GDM_UPSIDE_DOWN	== 1
            for (col=gb_gdm_line_range[line<<1]; col<gb_gdm_line_range[(line<<1)+1]; col++)
#else
            for (col=gb_gdm_line_range[(line<<1)+1]-1; col>=gb_gdm_line_range[(line<<1)]; col--)
#endif
            {
#if GDM_UPSIDE_DOWN	== 1
                UINT8 data=gb_gdm_canvas[line*GDM_MAX_SEG+col]&0xff;
                UINT8 reverse_data=0,i;
                for (i=0; i<8; i++)
                {
                    reverse_data>>=1;
                    if (data&0x80)
                        reverse_data|=0x80;
                    data<<=1;
                }
                GDM_WRITE_DATA_API(reverse_data);
#else
                GDM_WRITE_DATA_API(gb_gdm_canvas[line*GDM_MAX_SEG+col]);
#endif
#if GDM_USE_UART == 1
                GDM_DATA_SEND_OUT_API(gb_gdm_canvas[line*GDM_MAX_SEG+col]);
#endif
            }
            gb_gdm_line_range[line<<1]=GDM_MAX_SEG;
            gb_gdm_line_range[(line<<1)+1]=GDM_FIRST_COL;
#if GDM_MAX_LINE <=8
            gb_gdm_line_refresh&=~(0x01<<line);
#else
            gb_gdm_line_refresh[line>>3]&=~(0x01<<(line&0x07));
#endif
        }
    }
}

//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 		 gdm_fill
//
//! @author 	 Willman Chen
//
//! @date 		 2009/07/14
//
//! @brief 		 the main core of GDM,used to fill graphic pattern to lcd mapping memory
//
//! @param 		 type		The type of the pattern,there're three types @n
//							GDM_PATTERN		The graphic pattern type @n
//							GDM_RECT		The rect type			 @n
//							GDM_FILL		Fill all pixels type	 @n
//! @param		 pattern	The address of the pattern
//! @param		 w			The width of the pattern
//! @param		 h			The height of the pattern
//! @param		 style		The filling style,there're four style @n
//							GDM_BIT_NORMAL		fill the pattern normal
//							GDM_BIT_INVERSE		fill the pattern with inverse
//							GDM_BIT_XOR			fill the pattern with xor computing
//							GDM_BIT_OR			fill the pattern with or computing
//
//! @return 	 None
//
//**********************************************************************************************************************
void gdm_fill(UINT8 type,UINT8 *pattern,UINT8 w,UINT8 h,UINT8 style)
{
    UINT8	*target;
    UINT8 	i,j,k,top,buttom,src,mask,pat_offset=0;
    UINT32	scan_times;

    if (((gb_gdm_row+h)>>3)>GDM_MAX_LINE || (gb_gdm_col+w>GDM_MAX_SEG))
        return ;

    for (j=(gb_gdm_row>>3); (j<<3)<gb_gdm_row+h; j++)
    {
        scan_times=j-(gb_gdm_row>>3);
        /* search and sign it up which line need to be refresh */
#if (GDM_MAX_LINE) <= 8
        gb_gdm_line_refresh|=(0x01<<j);
#else
        gb_gdm_line_refresh[j>>3]|=(0x01<<(j&0x07));
#endif // GDM_MAX_LINE <= 8

        /* find left and right range need to be refresh */
        if (gb_gdm_col<gb_gdm_line_range[j<<1])
            gb_gdm_line_range[j<<1]=gb_gdm_col;
        if (gb_gdm_col+w>gb_gdm_line_range[(j<<1)+1])
            gb_gdm_line_range[(j<<1)+1]=gb_gdm_col+w;

        /* if it's the first row,count offset bits from 8*n Row position */
        if (!scan_times)
            top=gb_gdm_row&0x07;
        else
            top=0;

        /* if it's the buttom row ,the byte data need to be shift */
        if (j==((gb_gdm_row+h)>>3))
            buttom=(gb_gdm_row+h)&0x07;
        else
            buttom=0;

        /* Get to mask for computing */
        for (mask=0,k=0; k<8; k++)
        {
            mask>>=1;
            if (k<top)
                mask|=0x80;
            if ((j==((gb_gdm_row+h)>>3))&&(k>=buttom))
                mask|=0x80;
        }

        /* Get the start addr of Memory Map */
        target=&gb_gdm_canvas[gb_gdm_col+j*GDM_MAX_SEG];

        if (top)
            pat_offset=top;

        for (i=gb_gdm_col; i<gb_gdm_col+w; i++)
        {
            switch(type)
            {
            case GDM_PATTERN:
            {
                // if it's the first row
                if (top)
                {
                    src=((*(pattern+i-gb_gdm_col))<<top);
                }
                else
                {
                    // if it's the middle row
                    if (pat_offset && !buttom)
                    {
                        src=(*(pattern+i-gb_gdm_col+(scan_times-1)*w)>>(8-pat_offset));
                        src|=(*(pattern+i-gb_gdm_col+scan_times*w)<<(pat_offset));
                    }
                    else
                    {
                        // if it's the buttom row
                        if (buttom && pat_offset)
                        {
                            src=((*(pattern+i-gb_gdm_col+(scan_times-1)*w))>>(8-pat_offset));
                            src|=((*(pattern+i-gb_gdm_col+scan_times*w))<<(pat_offset));
                        }
                        else				// if it's no offset
                        {
                            src=*(pattern+i-gb_gdm_col+scan_times*w);
                        }
                    }
                }
                break;
            }
            case GDM_RECT:
                src=GDM_FILL_BYTE;
                break;
            case GDM_BLANK:
                src=GDM_BLANK_BYTE;
                break;
            }

            switch(style)
            {
            case GDM_BIT_NORMAL:
            {
                *target&=mask;					// clear background bit
                *target|=(src&(~mask));			//	fill it on
                break;
            }
            case GDM_BIT_INVERSE:
            {
                *target&=mask;					// clear background bit
                *target|=~(src&(~mask));		//	fill it on
                break;
            }
            case GDM_BIT_XOR:
                *target^=(src&(~mask));
                break;
            case GDM_BIT_OR:
                *target|=(src&(~mask));
                break;
            }
            target++;
        }
    }
    gdm_setup_cursor(gb_gdm_row,gb_gdm_col+w);
}

//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 		 gdm_dis_char
//
//! @author 	 Willman Chen
//
//! @date 		 2009/07/14
//
//! @brief 		 the main core of GDM,used to fill graphic pattern to lcd mapping memory
//
//! @param 		 ch			The ascii code of the char
//! @param		 font	The address of the pattern
//! @param		 style		The filling style,there're four style @n
//							GDM_BIT_NORMAL		fill the pattern normal
//							GDM_BIT_INVERSE		fill the pattern with inverse
//							GDM_BIT_XOR			fill the pattern with xor computing
//							GDM_BIT_OR			fill the pattern with or computing
//
//! @return 	 None
//
//**********************************************************************************************************************
void gdm_dis_char(UINT8 ch,UINT8 font,UINT8 style)
{
    FONT_INFO *info=GDM_GET_FONT_TABLE_API(font);
    UINT8 *font_table=(UINT8 *)(info->char_table);
    UINT8 font_w=info->font_w;
    UINT8 font_h=info->font_h;
    // we need to take more one byte per width ,if h is more then 8
    UINT8 font_size=font_w<<((font_h-1)>>3);

    if ((gb_gdm_col+font_w)>=GDM_MAX_SEG || (gb_gdm_row+font_h)>(GDM_MAX_LINE<<3))
        return ;

    ch-=GDM_ASCII_START;
    switch (style)
    {
    case GDM_BIT_NORMAL:
        GDM_FILL_PATTERN_API((font_table+ch*font_size),font_w,font_h);
        break;
    case GDM_BIT_INVERSE:
        GDM_FILL_PATTERN_INVERSE_API((font_table+ch*font_size),font_w,font_h);
        break;
    case GDM_BIT_XOR:
        GDM_FILL_PATTERN_XOR_API((font_table+ch*font_size),font_w,font_h);
        break;
    case GDM_BIT_OR:
        GDM_FILL_PATTERN_OR_API((font_table+ch*font_size),font_w,font_h);
        break;
    }

    if (style==GDM_BIT_NORMAL)
        GDM_FILL_BLANK_API(1,font_h);
    else
        gb_gdm_col++;
}

//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 		 gdm_dis_char
//
//! @author 	 Willman Chen
//
//! @date 		 2009/07/14
//
//! @brief 		 the main core of GDM,used to fill graphic pattern to lcd mapping memory
//
//! @param 		 str	The ascii code of the char
//! @param		 font	The index of font table
//! @param		 style		The filling style,there're four style @n
//							GDM_BIT_NORMAL		fill the pattern normal
//							GDM_BIT_INVERSE		fill the pattern with inverse
//							GDM_BIT_XOR			fill the pattern with xor computing
//							GDM_BIT_OR			fill the pattern with or computing
//! @param		 spacing The spacing between char and char
//! @param		 center  Place string as the center of LCD
//
//! @return 	 None
//
//**********************************************************************************************************************
void gdm_dis_str(UINT8 *str,UINT8 font,UINT8 style,UINT8 spacing,UINT8 center)
{
    FONT_INFO *info=GDM_GET_FONT_TABLE_API(font);
    UINT8 font_w=info->font_w;
    UINT8 i,len;
    UINT8 *ptr;

    if (center)
    {
        ptr=str;
        /* count words number */
        for (i=0; *(ptr+i); i++);
        len=i*(font_w+spacing+1);	// font_w need to add 1 for BLANK_SEG
        GDM_SETUP_CURSOR_API(gb_gdm_row,((GDM_MAX_SEG-len)>>1));
    }

    for (; *str; str++)
    {
        switch (style)
        {
        case	GDM_BIT_NORMAL:
            GDM_CHAR_API(*str,font);
            break;
        case	GDM_BIT_XOR:
            GDM_CHAR_XOR_API(*str,font);
            break;
        case	GDM_BIT_OR:
            GDM_CHAR_OR_API(*str,font);
            break;
        }
        if (gb_gdm_col+spacing+font_w>=GDM_MAX_SEG)
            return ;
    }
}

//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 		 gdm_dis_symb
//
//! @author 	 Willman Chen
//
//! @date 		 2009/07/14
//
//! @brief 		 the main core of GDM,used to fill graphic pattern to lcd mapping memory
//
//! @param 		 symb	The symbol we wana displaying
//! @param		 type		The filling style,there're four style @n
//							GDM_BIT_NORMAL		fill the pattern normal
//							GDM_BIT_INVERSE		fill the pattern with inverse
//							GDM_BIT_XOR			fill the pattern with xor computing
//							GDM_BIT_OR			fill the pattern with or computing
//
//! @return 	 None
//
//**********************************************************************************************************************
void gdm_dis_symb(UINT32 symb,UINT8 type)
{
    if (symb<UDM_NULL_SYMB)
    {
        GDM_CHAR_API(symb,type);
        return ;
    }

    if (symb < UDM_ICON_SYMBOL_START)		// CHAR
    {
        GDM_CHAR_PROTOTYPE_API(UDM_CHAR_TB(symb),type);
        if (symb >=UDM_NCHAR2_SYMBOL_START)
            GDM_CHAR_PROTOTYPE_API(UDM_CHAR_TB(symb+UDM_CHAR_SIZE),type);
    }
    else if (symb>=UDM_ICON_SYMBOL_START && symb <UDM_PATTERN_SYMBOL_START) // ICON
    {
        GDM_FILL_PATTERN_PROTOTYPE_API(UDM_ICON_TB(symb),UDM_GET_SYMB_W_API(symb),UDM_ICON_H,type);
    }
    else // PATTERN
    {
        GDM_FILL_PATTERN_PROTOTYPE_API(UDM_PAT_DATA(symb),UDM_PAT_W(symb),UDM_PAT_H(symb),type);
    }
}
