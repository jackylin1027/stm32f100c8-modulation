#ifndef ST7565_UDEF_H
#define ST7565_UDEF_H
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 st7565_udef.h
//
//! @author 	 Willman Chen
//
//! @date 		 2009/07/14
//
//  @brief 		 Here define all API
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// E X T E R N A L   G L O B A L   C O N S T A N C E   /   V A R I A B L E S   I N   E E P R O M
//
//**********************************************************************************************************************
enum ST7565_LINES
{
    ST7565_LINE0,
    ST7565_LINE1,
    ST7565_LINE2,
    ST7565_LINE3,
    ST7565_LINE4,
    ST7565_LINE5,
    ST7565_LINE6,
    ST7565_LINE7,
    ST7565_MAX_LINE,
    ST7565_MAX_COL=128,
};
//**********************************************************************************************************************
//
// C O N D I C T I O N   C O M P I L E
//
//**********************************************************************************************************************
#define ST7565_USED_SERIES      0
#define ST7565_USED_PARALLEL    1
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "..\fk\fk_udef.h"
#include "c_src\st7565_init.h"
#include "drv_src\st7565_drv.h"
#include "c_src\st7565_task.h"
//**********************************************************************************************************************
//
// A P I   F O R   O T H E R   M O D U L E S
//
//**********************************************************************************************************************
//! @brief ST7565 graphic lcm driver module initial API
#define	ST7565_INIT_API()							st7565_init()
//! @brief ST7565 graphic lcm driver module reset API
#define	ST7565_RESET_API()							st7565_reset()
//! @brief The API for swithing on LCD
#define ST7565_DISPLAY_ON_API()							ST7565_WRITE_CMD_API(0xAF)
//! @brief The API for switch off LCD
#define ST7565_DISPLAY_OFF_API()						ST7565_WRITE_CMD_API(0xAE)
//! @brief The API for setting the offset of start line
#define ST7565_SET_START_LINE_API(line)						ST7565_WRITE_CMD_API(0x40|(line&0x3f))
//! @brief The API for setting the offset of start page
#define ST7565_SET_START_PAGE_API(page)						ST7565_WRITE_CMD_API(0xB0|(page&0x0f))
//! @brief The API for setting the column position of LCD
#define ST7565_SET_COLUMN_API(col)						st7565_set_column(col)
//! @brief The API for the normal direction of displaying screen
#define ST7565_SET_DISPLAY_DIRECTION_NORMAL_API()				ST7565_WRITE_CMD_API(0xA0)
//! @brief The API for the inverse direction of displaying screen
#define ST7565_SET_DISPLAY_DIRECTION_INVERSE_API()				ST7565_WRITE_CMD_API(0xA1)
//! @brief The API for normal pixel color
#define ST7565_SET_PIXEL_NORMAL_API()						ST7565_WRITE_CMD_API(0xA6)
//! @brief The API for inverse pixel color
#define ST7565_SET_PIXEL_INVERSE_API()						ST7565_WRITE_CMD_API(0xA7)
//! @brief The API for setting all pixels on
#define ST7565_SET_ALL_PIXELS_ON_API()						ST7565_WRITE_CMD_API(0xA5)
//! @brief The API for setting not all pixels on
#define ST7565_SET_NOT_ALL_PIXELS_ON_API()					ST7565_WRITE_CMD_API(0xA4)
//! @brief The API for setting the bias of lcd
#define ST7565_SET_BIAS_API(bias)						ST7565_WRITE_CMD_API(0xA2|(bias&0x01))
//! @brief The API for resetting the lcd
#define ST7565_RESET_LCD_API()							ST7565_WRITE_CMD_API(0xE2)
//! @brief The API for setting the internal resistance
#define ST7565_SET_RESISTANCE_API(resistance)					ST7565_WRITE_CMD_API(0x20|(resistance&0x07))
//! @brief The API for setting the electronic volume
#define ST7565_SET_ELECTRONIC_VOLUME_API(vol)					st7565_set_electronic_volume(vol)
//! @brief The API for setting the indicator cursor on
#define ST7565_SET_STATIC_INDICATOR_ON_API()					ST7565_WRITE_CMD_API(0xAD)
//! @brief The API for setting the indecaotr cursor off
#define ST7565_SET_STATIC_INDICATOR_OFF_API()					ST7565_WRITE_CMD_API(0xAC)
//! @brief The API for setting the common output mode
#define ST7565_SET_COMMON_OUTPUT_MODE_API(mode)					ST7565_WRITE_CMD_API(0xC0|(mode&0x80))
//! @brief The API for setting the power control mode
#define ST7565_SET_POWER_CONTROL_MODE_API(mode)					ST7565_WRITE_CMD_API(0x28|(mode&0x07))
//! @brief The API for setting cursor position
#define ST7565_SET_CURSOR_API(x,y)						st7565_set_cursor(x,y)
//! @brief The API for turning on back light
#define ST7565_TURN_ON_BACKLIGHT_API()						ST7565_BACKLIGHT_ON()
//! @brief The API for turning off back light
#define ST7565_TURN_OFF_BACKLIGHT_API()						ST7565_BACKLIGHT_OFF()
//**********************************************************************************************************************
//
// A P I   C A L L   F R O M   O T H E R   M O D U L E S
//
//**********************************************************************************************************************
//! @brief send out a command to ST7565
#define ST7565_WRITE_CMD_API(cmd)						st7565_write(ST7565_CMD_ADDRESS,cmd)
//! @brief send out data to ST7565
#define ST7565_WRITE_DATA_API(data)						st7565_write(ST7565_DATA_ADDRESS,data)
//! @brief send out data block
#define ST7565_WRITE_DATA_BLOCK_API(data,len)                                   st7565_write_block(ST7565_CMD_ADDRESS,data,len)
//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S
//
//**********************************************************************************************************************
#endif		// ST7565_UDEF_H 
