#ifndef UIF_TASK_H
#define UIF_TASK_H
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 	 uif_task.h
//
//! @author	 Willman
//
//! @date 	 2009/06/23
//
// @brief 	 Here declare task function
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "..\uif_udef.h"
//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S
//
//**********************************************************************************************************************
void  uif_task();
UINT8 uif_chk_state_chg();
UINT8 uif_chk_level_chg();
void uif_state_remove();
void uif_level_next();
void uif_level_last();
void uif_null_func();
void uif_state_next_install(void *);
void uif_set_buf_var(UINT8 );
void uif_add_buf_var(void*);
void uif_move_buf_var_cursor();
void uif_save_buf_var_and_exit();;
void uif_display_menu_var(UINT8 *,UINT8 ,UINT32);
void uif_state_install(UINT8 *);
void uif_display_menu_box(UINT32);
void uif_display_menu_item(UINT8  *,UINT8 ,UINT8 ,UINT8 );
void uif_display_menu_cursor(UINT8 ,UINT8 ,UINT8 ,UINT8 );
void uif_display_box(UINT8,UINT8,UINT8 ,UINT8 ,UINT8);
void uif_state_reduce(UINT8);
void uif_display_acsii_menu_item(UINT8*);
void uif_display_setting_menu_item(UINT8*);
void uif_display_timeout_isr();
void uif_display_dot_position(UINT16 display_dot_num);
#endif		// UIF_TASK_H 
