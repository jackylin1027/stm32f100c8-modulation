#ifndef UIF_IDEF_H
#define UIF_IDEF_H
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 	 uif_idef.h
//
//! @author	 Willman
//
//! @date 	 2009/06/23
//
// @brief 	 Here define internal constant
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// E X T E R N A L   G L O B A L   C O N S T A N C E   /   V A R I A B L E S   I N   E E P R O M
//
//**********************************************************************************************************************
//! @brief the level step of the menu
enum  UIF_MENU_LEVEL
{
    UIF_STATUS_LEVEL,
    UIF_1ST_MENU_LEVEL,
    UIF_2ND_MENU_LEVEL,
    UIF_3RD_MENU_LEVEL,
    UIF_4TH_MENU_LEVEL,
    UIF_5TH_MENU_LEVEL,
    UIF_SWAP_MENU_LEVEL,
} ;
enum  UIF_SETTING_MENU_DIS
{
    UIF_SETTING_MENU_1ST_DIS,
    UIF_SETTING_MENU_2ND_DIS,
};
//! @brief the null value
#define  UIF_NULL                   0
//! @brief the max stack level of the menu state
#define  UIF_MAX_STACK              5
//! @brief The dot number of showing the Cp value
#define  UIF_CP_DOT                 1
//! @brief No dot
#define  UIF_NO_DOT                 0
//! @brief The max digital of the LCD screen
#define  UIF_MAX_LCD_DIGITAL        4
//! @brief The timing of menu timeout
#define  UIF_MENU_TIMEOUT           100
//! @brief The timing of waitting for setting cp_high && cp_low
#define  UIF_WAIT_CP_RESTORE_TIME   15
#endif		// UIF_IDEF_H 

