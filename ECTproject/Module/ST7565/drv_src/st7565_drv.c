//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 st7565_drv.c
//
//! @author 	 Willman Chen
//
//! @date 		 2009/07/14
//
//  @brief 		 Driver Subroutine
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "st7565_drv.h"
#include "..\c_src\st7565_idef.h"
#include "..\st7565_udef.h"
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 		 st7565_set_column
//
//! @author 	 Willman Chen
//
//! @date 		 2009/07/14
//
//! @brief 		 Set up the column position of LCD
//
//! @param 		 column	The column we wana setting
//
//! @return 	 None
//
//**********************************************************************************************************************
void st7565_set_column(UINT8 column)
{
    ST7565_WRITE_CMD_API(0x10|((column&0xf0)>>4));
    ST7565_WRITE_CMD_API(column&0x0f);
}

//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 		 st7565_set_cursor
//
//! @author 	 Willman Chen
//
//! @date 		 2009/07/14
//
//! @brief 		 Set up the column position of LCD
//
//! @param 		 x	The x position we wana setting
//! @param       y  The y position we wana setting
//
//! @return 	 None
//
//**********************************************************************************************************************
void st7565_set_cursor(UINT8 x,UINT8 y)
{
    ST7565_SET_START_PAGE_API(x);
    st7565_set_column(y);
}

//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 		 st7565_set_electronic_volume
//
//! @author 	 Willman Chen
//
//! @date 		 2009/07/14
//
//! @brief 		 Set up the column position of LCD
//
//! @param 		 vol	The electronic volume we wana setting
//
//! @return 	 None
//
//**********************************************************************************************************************
void st7565_set_electronic_volume(UINT8 vol)
{
    ST7565_WRITE_CMD_API(0x81);
    ST7565_WRITE_CMD_API(vol&0x3f);
}

//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 		 st7565_sfr_init
//
//! @author 	 Willman Chen
//
//! @date 		 2009/07/14
//
//! @brief 		 Register initial function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void st7565_write(UINT32 addr,UINT8 data)
{    
#if ST7565_USED_PARALLEL ==1
    //PORTClearBits(ST7565_A0);
    if (addr==ST7565_CMD_ADDRESS)
        ST7565_A0_LOW();
    else
        ST7565_A0_HIGH();
    //PORTWrite(IOPORT_E,t);
    if(data&0x01)
        ST7565_D0_HIGH();
    else
        ST7565_D0_LOW();
    if(data&0x02)
        ST7565_D1_HIGH();
    else
        ST7565_D1_LOW();
    if(data&0x04)
        ST7565_D2_HIGH();
    else
        ST7565_D2_LOW(); 
    if(data&0x08)
        ST7565_D3_HIGH();
    else
        ST7565_D3_LOW();
    if(data&0x10)
        ST7565_D4_HIGH();
    else
        ST7565_D4_LOW();
    if(data&0x20)
        ST7565_D5_HIGH();
    else
        ST7565_D5_LOW();
    if(data&0x40)
        ST7565_D6_HIGH();
    else
        ST7565_D6_LOW();
    if(data&0x80)
        ST7565_D7_HIGH();
    else
        ST7565_D7_LOW();    
    //PORTClearBits(ST7565_WR);
    ST7565_WR_LOW();
    //PORTClearBits(ST7565_CS);
    ST7565_CS_LOW();
    //PORTSetBits(ST7565_CS);
    ST7565_CS_HIGH();
    //PORTSetBits(ST7565_WR);
    ST7565_WR_HIGH();
    //PORTSetBits(ST7565_A0);
    ST7565_A0_HIGH();
#endif    
    
#if ST7565_USED_SERIES == 1
    UINT16 i;
    ST7565_CS_LOW();
    if (addr==ST7565_CMD_ADDRESS)
        ST7565_A0_LOW();
    else
        ST7565_A0_HIGH();
    for (i=0; i<8; i++)
    {
        ST7565_CLK_LOW();
        if (data&0x80)
            ST7565_DATA_HIGH();
        else
            ST7565_DATA_LOW();
        ST7565_CLK_HIGH();
        data<<=1;
    }
    ST7565_CS_HIGH();
#endif  
}

void st7565_sfr_init()
{
    UINT32 i,j;
#if ST7565_USED_PARALLEL ==1
    ST7565_RESET_INIT();
    ST7565_D0_INIT();
    ST7565_D1_INIT();
    ST7565_D2_INIT();
    ST7565_D3_INIT();
    ST7565_D4_INIT();
    ST7565_D5_INIT();
    ST7565_D6_INIT();
    ST7565_D7_INIT();
    ST7565_P_S_INIT();
    ST7565_C_86_INIT(); 
    ST7565_RD_INIT();
    ST7565_WR_INIT(); 
#endif
#if ST7565_USED_SERIES==1  
    ST7565_P_S_LOW();    
    ST7565_C_86_HIGH();    
    ST7565_RD_HIGH();
    ST7565_WR_LOW();        
    FK_SET_PIN_INPUT_FLOATING_API(ST7565_D6_PORT,ST7565_D6_PIN);
    FK_SET_PIN_INPUT_FLOATING_API(ST7565_D7_PORT,ST7565_D7_PIN);
#endif

    ST7565_CS_INIT();
    ST7565_A0_INIT();
    ST7565_CLK_INIT();
    ST7565_DATA_INIT();

#if ST7565_USED_PARALLEL ==1    
    ST7565_P_S_HIGH(); 
    ST7565_C_86_LOW();    
    ST7565_RD_HIGH();
    ST7565_WR_LOW();     
    FK_SET_PIN_INPUT_FLOATING_API(ST7565_DATA_PORT,ST7565_DATA_PIN);
    FK_SET_PIN_INPUT_FLOATING_API(ST7565_CLK_PORT,ST7565_CLK_PIN);
    
    
    /* Test io function */
//    ST7565_D0_HIGH();
//    ST7565_D1_LOW();
//    ST7565_D2_HIGH();
//    ST7565_D3_LOW();
//    ST7565_D4_HIGH();
//    ST7565_D5_LOW();
//    ST7565_D6_HIGH();
//    ST7565_D7_LOW();
//    ST7565_D0_LOW();
//    ST7565_D1_HIGH();
//    ST7565_D2_LOW();
//    ST7565_D3_HIGH();
//    ST7565_D4_LOW();
//    ST7565_D5_HIGH();
//    ST7565_D6_LOW();
//    ST7565_D7_HIGH();
#endif   

    ST7565_BACKLIGHT_INIT();
    ST7565_BACKLIGHT_OFF();

#if ST7565_USED_PARALLEL ==1    
    for (i=0;i<0xffff;i++);
    ST7565_RESET_HIGH();
#endif

    ST7565_RESET_LCD_API();
    ST7565_SET_COMMON_OUTPUT_MODE_API(0x00);		// just 0 / 1 two options : 0x80 -> normal   0x00 -> reverse
    ST7565_SET_BIAS_API(1);				// just 0 / 1 two options : 1=> 1/9 bias   0=> 1/7 bias
    ST7565_SET_POWER_CONTROL_MODE_API(0x0f);		// please info the datasheet of ST7565
    ST7565_SET_RESISTANCE_API(6);
    ST7565_SET_ELECTRONIC_VOLUME_API(0x10);			// please info the datasheet of ST7565
    ST7565_SET_START_LINE_API(0);
    ST7565_SET_DISPLAY_DIRECTION_NORMAL_API();
    ST7565_DISPLAY_ON_API();
    for (j=ST7565_LINE0; j<ST7565_MAX_LINE; j++)
    {
        st7565_set_cursor(j,0);
        for (i=0; i<ST7565_MAX_COL; i++)
            ST7565_WRITE_DATA_API(0xff);
    }
    st7565_set_cursor(0,0);
}
