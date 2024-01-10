#ifndef UIF_UDEF_H
#define UIF_UDEF_H
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 	 uif_udef.h
//
//! @author	 Willman
//
//! @date 	 2009/06/23
//
// @brief 	 Here define all API
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// E X T E R N A L   G L O B A L   C O N S T A N C E   /   V A R I A B L E S   I N   E E P R O M
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// C O N D I C T I O N   C O M P I L E
//
//**********************************************************************************************************************
//! @brief Please tell men the main menu
#define UIF_MAIN_STATE                                                          uif_show_value_state
#define UIF_MAIN_INCLUDE_STATE_H					        "uif_show_value_state.h"
//! @brief The first screen menu
#define UIF_WELCOME_STATE                                                       uif_welcome_state
#define UIF_WELCOME_INCLUDE_STATE_H						"uif_welcome_state.h"
//! @brief The variable records the index of menu focus item on the current screen
#define UIF_MENU_PTR                                                            gs_uif_status.menu_ptr
//! @brief The variable records the index of menu first item on the current screen
#define UIF_MENU_TOP								gs_uif_status.menu_top
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "..\fk\fk_udef.h"
#include "..\btc\btc_udef.h"
#include "..\key\key_udef.h"
#include "..\pfc\pfc_udef.h"
#include "..\led7seg\led7seg_udef.h"
#include "c_src\uif_glb_vars.h"
#include "c_src\uif_init.h"
#include "c_src\uif_task.h"
//**********************************************************************************************************************
//
// A P I   F O R   O T H E R   M O D U L E S
//
//**********************************************************************************************************************
//! @brief User Interface Function Module Initial API
#define	UIF_INIT_API()								uif_init()
//! @brief UI task ,this should be execute in the main loop of PFC
#define UIF_TASK_API()                                                          uif_task()
//! @brief The API for checking menu state is changed or not.
#define UIF_CHK_STATE_CHG_API()                                                 uif_chk_state_chg()
//! @brief The API for checking menu level is changed or not.
#define UIF_CHK_LEVEL_CHG_API()                                                 uif_chk_level_chg()
//! @brief The API for install new menu state.
#define UIF_STATE_INSTALL_API(state)                                            uif_state_install((UINT8*)&state)
//! @brief The API for exiting current menu state
#define UIF_STATE_REMOVE_API()                                                  uif_state_remove()
//! @brief The API for entering next level of current menu
#define UIF_LEVEL_NEXT_API()                                                    uif_level_next()
//! @brief The API for entering last level of current menu
#define UIF_LEVEL_LAST_API()							uif_level_last()
//! @brief The API for displaying system variable value by the index
#define UIF_DISPLAY_VAR_BY_INDEX_API(index,value)                               uif_display_menu_var(UIF_NULL,index,value)
//! @brief The API for displaying the variable vaule in the buffer
#define UIF_DISPLAY_BUF_VAR_API()                                               UIF_DISPLAY_VAR_BY_INDEX_API(gs_uif_num_buf.index,gs_uif_num_buf.value)
//! @brief The API for displaying the menu prompt
#define UIF_DISPLAY_MENU_PROMPT_API(menu)                                       UIF_DIS_STR_API((UINT8 *)(menu+UIF_MENU_PTR)->prompt)
//! @brief The API for setting level change
#define UIF_SET_LEVEL_CHG_API()							gs_uif_status.level_chg=1

//! @brief The function of state install,be used with keymap.
#define UIF_STATE_INSTALL_FUNC                                                  uif_state_install
//! @brief The function of state remove,be used with keymap.
#define UIF_STATE_REMOVE_FUNC                                                   uif_state_remove
//! @brief The function of level next,be used with keymap.
#define UIF_LEVEL_NEXT_FUNC                                                     uif_level_next
//! @brief The function of level last,be used with keymap.
#define UIF_LEVEL_LAST_FUNC							uif_level_last
//! @brief The function of null function,be used with keymap.
#define UIF_NULL_FUNC                                                           uif_null_func
//! @brief The function of state next,be used with keymap
#define UIF_STATE_NEXT_FUNC                                                     uif_state_next_install
//! @brief The function of save variable value && exit current menu,be used with keymap
#define UIF_SAVE_AND_EXIT_FUNC                                                  uif_save_buf_var_and_exit
//! @brief The function of adding the value of the variable,be used with keymap
#define UIF_ADD_BUF_VAR_FUNC                                                    uif_add_buf_var
//! @brief The function of moving the cursor of the screen in the value setting menu,be used with keymap
#define UIF_MOVE_BUF_VAR_CURSOR_FUNC                                            uif_move_buf_var_cursor
//! @brief The function of getting the dot number of the variable by telling the system variable index,be used with keymap.
#define UIF_GET_VAR_DOT_BY_INDEX_API(index)                                     uif_get_var_dot(index)
//! @brief The function of setting the font type
#define UIF_SET_FONT_API(font)							gs_uif_status.font_type=font
//! @brief The API for displaying menu box
#define UIF_DIS_MENU_BOX_API(str)						uif_display_menu_box(str)
//! @brief The API for displaying menu item
#define UIF_DIS_MENU_ITEM_API(menu,row,col,row_step)				uif_display_menu_item((UINT8*)menu,row,col,row_step)
//! @brief The API for displaying menu cursor
#define UIF_DIS_MENU_CURSOR_API(row,col,row_step,col_step)			uif_display_menu_cursor(row,col,row_step,col_step)
//! @brief The API for reducing state
#define UIF_STATE_REDUCT_API(level)						uif_state_reduce(level)
//! @brief The API for drawing a box
#define UIF_DIS_BOX_API(row,col,box_w,box_h,line_width)				uif_display_box(row,col,box_w,box_h,line_width)
//! @brief The API for displaying menu item(use ascii)
#define UIF_DIS_ASCII_MENU_ITEM_API(menu)                                       uif_display_acsii_menu_item((UINT8*)menu)
//**********************************************************************************************************************
//
// A P I   C A L L   F R O M   O T H E R   M O D U L E S
//
//**********************************************************************************************************************
//! @brief The API for copying mapping memory data to led7seg
#define UIF_LED_REFRESH_API()							LED7SEG_REFRESH_API()
//! @brief The API for display number(value) 
#define UIF_DIS_NUM_API(num)                                                    LED7SEG_DIS_NUM_API(num)
//! @brief The API for displaying string 
#define UIF_DIS_STR_API(str)                                                    LED7SEG_DIS_STR_API(str)
//! @brief The API for clean displaying string and number                       
#define UIF_CLR_LED_API()                                                       LED7SEG_CLR_API()
//! @brief The API for displaying string use XOR mode           
#define UIF_XOR_DIS_STR_API(str)                                                LED7SEG_XOR_DIS_STR_API(str)
//! @brief The API for setting uif action flag
#define UIF_SET_ACTION_FLAG_API()                                               PFC_SET_UIF_TASK_API()
//! @brief The API for setting key event flag
#define UIF_SET_KEY_FLAG_API()                                                  gs_uif_status.key_event=1
//! @brief The API for setting second level software timer
#define UIF_SET_SEC_CNT_API(cnt)                                                BTC_SET_SEC_CNT_API(BTC_UIF_USER_SEC,cnt)
//! @brief The API for setting half second level software timer
#define UIF_SET_HALF_SEC_CNT_API(cnt)                                           BTC_SET_HALF_CNT_API(BTC_UIF_USER_HALF_SEC,cnt)
//! @brief The API for setting quarter second level software timer
#define UIF_SET_QUARTER_SEC_CNT_API(cnt)                                        BTC_SET_QUARTER_CNT_API(BTC_UIF_USER_QUARTER_SEC,cnt)
//! @brief The API for clearing second level software timer
#define UIF_CLR_SEC_CNT_API()                                                   BTC_CLR_SEC_CNT_API(BTC_UIF_USER_SEC)
//! @brief The API for clearing half second level software timer
#define UIF_CLR_HALF_SEC_CNT_API()                                              BTC_CLR_HALF_SEC_CNT_API(BTC_UIF_USER_HALF_SEC)
//! @brief The API for clearing quarter second level software timer
#define UIF_CLR_QUARTER_SEC_CNT_API()                                           BTC_CLR_QUARTER_SEC_CNT_API(BTC_UIF_USER_QUARTER_SEC)
//! @brief The API for getting the second level software timer counter
#define UIF_GET_SEC_CNT_API()                                                   BTC_GET_SEC_CNT_API(BTC_UIF_USER_SEC)
//! @brief The API for getting the half second level software timer counter
#define UIF_GET_HALF_SEC_CNT_API()                                              BTC_GET_HALF_SEC_CNT_API(BTC_UIF_USER_HALF_SEC)
//! @brief The API for getting the quarter second level software timer counter
#define UIF_GET_QUARTER_SEC_CNT_API()                                           BTC_GET_QUARTER_SEC_CNT_API(BTC_UIF_USER_QUARTER_SEC)
//! @brief The API for setting the timing of menu timeout
#define UIF_SET_MENU_TIMEOUT_API()                                              BTC_SET_SEC_CNT_API(BTC_UIF_MENU_TIMEOUT,UIF_MENU_TIMEOUT)
//! @brief The API for checking the menu timout is expired or not
#define UIF_CHK_MENU_TIMEOUT_API()                                              BTC_GET_SEC_CNT_API(BTC_UIF_MENU_TIMEOUT)==0
//! @brief The API for clearing the key state buffer
#define UIF_CLR_KEY_BUF_API()                                                   KEY_BUFFER_CLR_API()
//! @brief The API for checking the key click event
#define UIF_KEY_CLICK_API(key)                                                  KEY_CLICK_CHK_API(key)
//! @brief The API for checking the key press event
#define UIF_KEY_PRESSED_API(key)                                                KEY_PRESSED_CHK_API(key)
//! @brief The API for checking the key repeat event
#define UIF_KEY_REPEAT_API(key)                                                 KEY_REPEAT_CHK_API(key)
//! @brief The API for getting the system variable vaule by telling the index
#define UIF_GET_SYS_VALUE_API(index)                                            PFC_GET_SYS_VARS_API(index)
//! @brief The API for setting the system variable vaule by telling the index
#define UIF_SET_SYS_VALUE_API(index,value)                                      PFC_SET_SYS_VARS_API(index,value)
//! @brief The API for restoring the eeprom data
#define UIF_RESTORE_EEPROM_SETTING_API()                                        PFC_RESTORE_USER_DATA_API()                           
//! @brief The API for restoring the eeprom data
#define UIF_READ_BACK_EEPROM_SETTING_API()                                      PFC_READ_USER_DATA_API()
//! @brief The API for restoring the eeprom data
#define UIF_READ_BACK_FACTORY_EEPROM_SETTING_API()                              PFC_READ_FACTORY_DATA_API()
//! @brief The API for reset eeprom parameter
#define UIF_RESET_EEPROM_SETTING_API()						PFC_LOAD_DEFAULT_SETTING=1
//! @brief The API for setting the Cp level
#define UIF_SET_CP_LEVEL_API()                                                  PFC_SET_CP_LEVEL_API()
//! @brief The API for getting max value of the variable by index
#define UIF_GET_MAX_VALUE_BY_INDEX_API(index)                                   PFC_GET_MAX_VALUE_BY_INDEX_API(index)
//! @brief The API for getting min value of the variable by index
#define UIF_GET_MIN_VALUE_BY_INDEX_API(index)                                   PFC_GET_MIN_VALUE_BY_INDEX_API(index)
//! @brief The API for get led display color(this application color judage by PFC_ERROR_HIALARM)
#define UIF_GET_DISPALY_COLOR()                                                 (PFC_ERROR_CODE&PFC_ERROR_PRESSURE_ALARM)
//! @brief The API for refresh ssd7seg module dispaly value
#define UIF_LED7SEG_REFRESH_API(dot_pos,color)                                  LED7SEG_REFRESH_API(dot_pos,color)
//! @brief The reset timer for displaying setting munu 
#define UIF_DISPLAY_RESET_TIMEOUT_TIMER_API()				        HBTC_SET_TIMER_API(HBTC_UIF_DISPLAY_TIMER,2000,uif_display_timeout_isr)
//! @brief The API for flash LED port
#define UIF_SET_LED_FLASH_API(state,flash_status,mode)                          SSD_IO_SET_STATE_OUTPUT_FLASH(state,flash_status,mode)
//! @brief The API for turn on the LED port
#define UIF_SET_LED_ON_API(state)                                               SSD_IO_SET_STATE_OUTPUT_ON(state)
//! @brief The API for turn on all the LED port         
#define UIF_SET_LED_FULL_ON_API()                                               SSD_IO_SET_STATE_OUTPUT_FULL_ON()
//! @brief The API for turn off the LED port
#define UIF_SET_LED_OFF_API(state)                                              SSD_IO_SET_STATE_OUTPUT_OFF(state)
//! @brief The API for turn off all the LED port                                
#define UIF_SET_LED_FULL_OFF_API()                                              SSD_IO_SET_STATE_OUTPUT_FULL_OFF()
//! @brief The API for get displaying string start position
#define UIF_GET_STR_START_POS()                                                 LED7SEG_GET_STR_START_POS_API()
//! @brief The API for diaplaying diginum char
#define UIF_DIS_DIGINUM_API(digi)                                               LED7SEG_DIS_DIGINUM_API(digi)
//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S
//
//**********************************************************************************************************************
#endif		// UIF_UDEF_H 
