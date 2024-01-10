#ifndef KEY_UDEF_H
#define KEY_UDEF_H
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 	 key_udef.h
//
//! @author	 Willman Chen
//
//! @date 	 2009/06/23
//
// @brief 	 Here define all API
//
//*********************************************************************************************************************/
//**********************************************************************************************************************
//
// E X T E R N A L   G L O B A L   C O N S T A N C E   /   V A R I A B L E S   I N   E E P R O M
//
//*********************************************************************************************************************/
//! Keymap Index
#define KEY_COM_NUM          2
#define KEY_KEY_NUM          3
enum KEY_TABLE
{
    KEY_START ,
    KEY_ENTER = KEY_START,
    KEY_UP    ,
    KEY_ESC   ,
    KEY_TOTAL ,
};
//**********************************************************************************************************************
//
// C O N D I C T I O N   C O M P I L E
//
//*********************************************************************************************************************/
//! @brief set it to 1,if we wana using click key function
#define   KEY_HAS_CLICK               1
//! @brief set it to 1,if we wana using press key function
#define   KEY_HAS_PRESSED             1
//! @brief set it to 1,if we wana using repeat key function
#define   KEY_HAS_REPEAT              1
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//*********************************************************************************************************************/
#include "..\pfc\pfc_udef.h"
#include "..\st7565\st7565_udef.h"
#include "..\uif\uif_udef.h"
#include "c_src\key_init.h"
#include "c_src\key_task.h"
#include "c_src\key_glb_vars.h"
//**********************************************************************************************************************
//
// A P I   F O R   O T H E R   M O D U L E S
//
//*********************************************************************************************************************/
//! @brief Key Module Initial API
#define	KEY_INIT_API()														key_init()
//! @brief The task rountine for detecting key state,please place it in the main loop of pfc.
#define KEY_TASK_API()                                                      key_task()
//! @brief The key click checking function
#define KEY_CLICK_CHK_API(key)                                              key_click_chk(key)
//! @brief The key press checking function
#define KEY_PRESSED_CHK_API(key)                                            key_pressed_chk(key)
//! @brief The key repeat checking function
#define KEY_REPEAT_CHK_API(key)                                             key_repeat_chk(key)
//! @brief the api for clearing key state buffer
#define KEY_BUFFER_CLR_API()                                                key_buf_clr()
//**********************************************************************************************************************
//
// A P I   C A L L   F R O M   O T H E R   M O D U L E S
//
//*********************************************************************************************************************/
//! @brief the api for raising uif action flag
#define KEY_UIF_ACTION_API()                                                PFC_SET_UIF_TASK_API()
//! @brief The API for turning on back light
#define KEY_TURN_ON_BACKLIGHT_API()				            UIF_SET_KEY_FLAG_API()
//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S
//
//*********************************************************************************************************************/
#endif		// KEY_UDEF_H 
