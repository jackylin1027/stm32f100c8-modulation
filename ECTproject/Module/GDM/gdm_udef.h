#ifndef GDM_UDEF_H
#define GDM_UDEF_H
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 gdm_udef.h
//
//! @author 	 Willman Chen
//
//! @date 		 2009/07/14
//
//  @brief 		 Here define all API
//
//**********************************************************************************************************************
#define				GDM_USE_UART											0
#define				GDM_USE_I2C												0
//**********************************************************************************************************************
//
// E X T E R N A L   G L O B A L   C O N S T A N C E   /   V A R I A B L E S   I N   E E P R O M
//
//**********************************************************************************************************************
#define	GDM_MAX_SEG															ST7565_MAX_COL
#define	GDM_MAX_LINE														ST7565_MAX_LINE
enum GDM_CENTER_TYPE
{
    GDM_NO_CENTER,
    GDM_CENTER,
};
//**********************************************************************************************************************
//
// C O N D I C T I O N   C O M P I L E
//
//**********************************************************************************************************************
#define GDM_UPSIDE_DOWN														0
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "..\fk\fk_udef.h"
#include "..\st7565\st7565_udef.h"
#include "..\udm\udm_udef.h"
#include "c_src\gdm_idef.h"
#include "c_src\gdm_init.h"
#include "c_src\gdm_task.h"
#include "c_src\gdm_glb_vars.h"
//**********************************************************************************************************************
//
// A P I   F O R   O T H E R   M O D U L E S
//
//**********************************************************************************************************************
#define	GDM_INIT_API()								gdm_init()
#define	GDM_FILL_PATTERN_API(addr,w,h)						gdm_fill(GDM_PATTERN,addr,w,h,GDM_BIT_NORMAL)
#define	GDM_FILL_PATTERN_XOR_API(addr,w,h)					gdm_fill(GDM_PATTERN,addr,w,h,GDM_BIT_XOR)
#define	GDM_FILL_PATTERN_OR_API(addr,w,h)					gdm_fill(GDM_PATTERN,addr,w,h,GDM_BIT_OR)
#define	GDM_FILL_PATTERN_INVERSE_API(addr,w,h)					gdm_fill(GDM_PATTERN,addr,w,h,GDM_BIT_INVERSE)
#define	GDM_FILL_PATTERN_PROTOTYPE_API(addr,w,h,type)				gdm_fill(GDM_PATTERN,addr,w,h,type)
#define	GDM_FILL_RECT_API(w,h)							gdm_fill(GDM_RECT,GDM_NULL,w,h,GDM_BIT_NORMAL)
#define	GDM_FILL_RECT_XOR_API(w,h)						gdm_fill(GDM_RECT,GDM_NULL,w,h,GDM_BIT_XOR)
#define	GDM_FILL_RECT_OR_API(w,h)						gdm_fill(GDM_RECT,GDM_NULL,w,h,GDM_BIT_OR)
#define	GDM_FILL_BLANK_API(w,h)							gdm_fill(GDM_BLANK,GDM_NULL,w,h,GDM_BIT_NORMAL)
#define	GDM_CHAR_API(ch,font)							gdm_dis_char(ch,font,GDM_BIT_NORMAL)
#define	GDM_CHAR_XOR_API(ch,font)						gdm_dis_char(ch,font,GDM_BIT_XOR)
#define	GDM_CHAR_OR_API(ch,font)						gdm_dis_char(ch,font,GDM_BIT_OR)
#define	GDM_CHAR_INVERSE_API(ch,font)						gdm_dis_char(ch,font,GDM_BIT_INVERSE)
#define	GDM_CHAR_PROTOTYPE_API(ch,type)						gdm_dis_char(ch,0,type)
#define	GDM_STR_API(ch,font)							gdm_dis_str(ch,font,GDM_BIT_NORMAL,0,GDM_NO_CENTER)
#define	GDM_STR_XOR_API(ch,font)						gdm_dis_str(ch,font,GDM_BIT_XOR,0,GDM_NO_CENTER)
#define	GDM_STR_OR_API(ch,font)							gdm_dis_str(ch,font,GDM_BIT_OR,0,GDM_NO_CENTER)
#define	GDM_STR_INVERSE_API(ch,font)						gdm_dis_str(ch,font,GDM_BIT_INVERSE,0,GDM_NO_CENTER)
#define	GDM_STR_BOX_API(ch,font,start_col,return_col,line)			gdm_dis_str(ch,font,GDM_BIT_NORMAL,0,GDM_NO_CENTER)
#define	GDM_STR_SPACE_API(ch,font,spacing)					gdm_dis_str(ch,font,GDM_BIT_NORMAL,spacing,GDM_NO_CENTER)
#define	GDM_STR_SPACE_XOR_API(ch,font,spacing)					gdm_dis_str(ch,font,GDM_BIT_XOR,spacing,GDM_NO_CENTER)
#define	GDM_STR_SPACE_OR_API(ch,font,spacing)					gdm_dis_str(ch,font,GDM_BIT_OR,spacing,GDM_NO_CENTER)
#define	GDM_CENTER_STR_API(ch,font)						gdm_dis_str(ch,font,GDM_BIT_NORMAL,0,GDM_CENTER)
#define	GDM_CENTER_STR_XOR_API(ch,font)						gdm_dis_str(ch,font,GDM_BIT_XOR,0,GDM_CENTER)
#define	GDM_CENTER_STR_OR_API(ch,font)						gdm_dis_str(ch,font,GDM_BIT_OR,0,GDM_CENTER)
#define	GDM_CENTER_STR_SPACE_API(ch,font,spacing)				gdm_dis_str(ch,font,GDM_BIT_NORMAL,spacing,GDM_CENTER)
#define	GDM_CENTER_STR_SPACE_XOR_API(ch,font,spacing)				gdm_dis_str(ch,font,GDM_BIT_XOR,spacing,GDM_CENTER)
#define	GDM_CENTER_STR_SPACE_OR_API(ch,font,spacing)				gdm_dis_str(ch,font,GDM_BIT_OR,spacing,GDM_CENTER)
#define	GDM_CLS_API()								gdm_cls()
#define	GDM_CLS_CANVAS_API()							gdm_cls_canvas()
#define	GDM_SETUP_CURSOR_API(x,y)						gdm_setup_cursor(x,y)
#define	GDM_CURSOR_OFFSET_API(row,col)						gdm_cursor_offset(row,col)
#define	GDM_GET_ROW_API()							gb_gdm_row
#define	GDM_GET_COL_API()							gb_gdm_col
#define	GDM_REFRESH_API()							gdm_dis_mapping_memory_to_lcd()
#define	GDM_GET_MAX_COL_API()							(MAX_SEG-1)
#define	GDM_DIS_SYMB_API(symb)							gdm_dis_symb((UINT32)symb,GDM_BIT_NORMAL)
#define GDM_DIS_SYMB_XOR_API(symb)						gdm_dis_symb((UINT32)symb,GDM_BIT_XOR)
#define GDM_DIS_SYMB_INVERSE_API(symb)						gdm_dis_symb((UINT32)symb,GDM_BIT_INVERSE)
#define GDM_DIS_SYMB_OR_API(symb)						gdm_dis_symb((UINT32)symb,GDM_BIT_OR)
//**********************************************************************************************************************
//
// A P I   C A L L   F R O M   O T H E R   M O D U L E S
//
//**********************************************************************************************************************
#define	GDM_WRITE_DATA_API(i)							ST7565_WRITE_DATA_API(i)
#define GDM_SET_LCD_CURSOR_API(x,y)						ST7565_SET_CURSOR_API(x,y)
#define	GDM_ALL_PIXEL_ON_API()							ST7565_ALL_PIXELS_ON_API()
#define	GDM_ALL_PIXEL_OFF_API()							ST7565_ALL_PIXELS_OFF_API()
#define	GDM_DISPLAY_OFF_API()							ST7565_DISPLAY_OFF_API()
#define	GDM_DISPLAY_ON_API()							ST7565_DISPLAY_ON_API()
#define	GDM_GET_FONT_TABLE_API(font_type)					UDM_GET_FONT_TABLE(font_type)
#define GDM_DATA_SEND_OUT_API(data)						FK_UART2_SEND_BYTE_API(data);FK_UART2_TX_WAIT_API() // PIC_UART2_SEND_API(data)
//! @brief The API for initial UART function
#define GDM_UART_INIT_API()                                                     FK_UART2_POLLING_API(57600,FK_UART_8BITS_MODE,FK_UART_ONE_STOP_BIT,FK_UART_PARITY_NONE)
//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S
//
//**********************************************************************************************************************
#endif		// GDM_UDEF_H 
