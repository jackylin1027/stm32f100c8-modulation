//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 	 uif_task.c
//
//! @author	 Willman
//
//! @date 	 2009/06/23
//
// @brief 	 Task Subroutine
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "..\drv_src\uif_drv.h"
#include "..\uif_udef.h"
#include UIF_MAIN_INCLUDE_STATE_H

//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 uif_null_func
//
//! @author  Willman Chen
//
//! @date 	 2009/06/23
//
//! @brief 	 for keymap null function
//
//**********************************************************************************************************************
void uif_null_func()
{
}
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 uif_level_next
//
//! @author  Willman Chen
//
//! @date 	 2009/06/23
//
//! @brief 	 move to next level
//
//**********************************************************************************************************************
void uif_level_next()
{
    gs_uif_status.level_chg=1;
    //===== Ver1.0.02 =====
    gb_uif_setting_menu_ptr=0;
     UIF_DISPLAY_RESET_TIMEOUT_TIMER_API();
    if (++UIF_MENU_PTR>=gs_uif_state->menu_max_line)
    {
        UIF_MENU_PTR--;
        UIF_MENU_TOP++;
    }

    if (UIF_MENU_PTR+UIF_MENU_TOP>=gs_uif_state->item_cnt)
        UIF_MENU_PTR=UIF_MENU_TOP=0;

    UIF_SET_ACTION_FLAG_API();
    UIF_CLR_KEY_BUF_API();
    UIF_SET_MENU_TIMEOUT_API();
    //===== Ver1.0.02 =====
    UIF_SET_LED_FULL_ON_API();    
}

//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 uif_level_last
//
//! @author  Willman Chen
//
//! @date 	 2009/06/23
//
//! @brief 	 move to next level
//
//**********************************************************************************************************************
void uif_level_last()
{
    gs_uif_status.level_chg=1;
    //===== Ver1.0.02 =====
    gb_uif_setting_menu_ptr=0;
    if (--UIF_MENU_PTR<0)
    {
        if (UIF_MENU_TOP)
        {
            UIF_MENU_TOP--;
            UIF_MENU_PTR++;
        }
        else
        {
            UIF_MENU_PTR=gs_uif_state->menu_max_line-1;
            UIF_MENU_TOP=gs_uif_state->item_cnt-gs_uif_state->menu_max_line;
        }
    }

    UIF_SET_ACTION_FLAG_API();
    UIF_CLR_KEY_BUF_API();
    UIF_SET_MENU_TIMEOUT_API();
    //===== Ver1.0.02 =====
    UIF_SET_LED_FULL_ON_API();    
}

//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 uif_chk_level_chg
//
//! @author  Willman Chen
//
//! @date 	 2009/06/23
//
//! @brief 	check level change event
//
// @return 	result Level change or not
//
//**********************************************************************************************************************
UINT8 uif_chk_level_chg()
{
    UINT8 result=gs_uif_status.level_chg;
    gs_uif_status.level_chg=0;
    return result;
}

//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 uif_chk_state_chg
//
//! @author	 Willman Chen
//
//! @date 	 2009/06/23
//
//! @brief 	 check state change event
//
// @return 	 result State change or not
//
//**********************************************************************************************************************
UINT8 uif_chk_state_chg()
{
    UINT8 result=gs_uif_status.state_chg;
    gs_uif_status.state_chg=0;
    return result;
}

//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 uif_state_remove
//
//! @author  Willman Chen
//
//! @date 	 2009/06/23
//
//! @brief 	 remove state
//
//**********************************************************************************************************************
void uif_state_remove()
{
    if (!gb_uif_stack_ptr)
        return ;
    //===== Ver1.0.02 =====
    gb_uif_setting_menu_ptr=0;
    gs_uif_status.state_chg=1;
    gs_uif_status.level_chg=1;
    UIF_MENU_PTR=gs_uif_stack[--gb_uif_stack_ptr].menu_ptr;
    UIF_MENU_TOP=gs_uif_stack[gb_uif_stack_ptr].menu_top;
    gs_uif_state=gs_uif_stack[gb_uif_stack_ptr].state;
    UIF_CLR_SEC_CNT_API();
    UIF_CLR_HALF_SEC_CNT_API();
    UIF_CLR_QUARTER_SEC_CNT_API();
    UIF_SET_ACTION_FLAG_API();
    UIF_CLR_KEY_BUF_API();
    UIF_SET_MENU_TIMEOUT_API();
    //===== Ver1.0.02 =====
    UIF_SET_LED_FULL_ON_API();
}

//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 uif_state_reduce
//
//! @author  Willman Chen
//
//! @date 	 2009/06/23
//
//! @brief 	 reduce state
//
//! @param	 level	The level count we wana reducing
//**********************************************************************************************************************
void uif_state_reduce(UINT8 level)
{
    if (gb_uif_stack_ptr<level)
        return ;
    gs_uif_status.state_chg=1;
    gs_uif_status.level_chg=1;
    gb_uif_stack_ptr-=level;
    UIF_MENU_PTR=gs_uif_stack[gb_uif_stack_ptr].menu_ptr;
    UIF_MENU_TOP=gs_uif_stack[gb_uif_stack_ptr].menu_top;
    gs_uif_state=gs_uif_stack[gb_uif_stack_ptr].state;
    UIF_SET_ACTION_FLAG_API();
    UIF_CLR_KEY_BUF_API();
    UIF_SET_MENU_TIMEOUT_API();
    UIF_CLR_SEC_CNT_API();
    UIF_CLR_HALF_SEC_CNT_API();
    UIF_CLR_QUARTER_SEC_CNT_API();
    //===== Ver1.0.02 =====
    UIF_SET_LED_FULL_ON_API();    
}

//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 uif_state_install
//
//! @author  Willman Chen
//
//! @date 	 2009/06/23
//
//! @brief 	 install menu
//
// @param 	 New state
//
//**********************************************************************************************************************
void uif_state_install(UINT8 *new_state_temp)
{
    STC_UIF_STATE *new_state=(STC_UIF_STATE*)new_state_temp;
    gs_uif_status.state_chg=1;
    gs_uif_status.level_chg=1;
    // push current menu into stack,if the next state level number is bigger then now.
    if (new_state->level>gs_uif_state->level)
    {
        gs_uif_stack[gb_uif_stack_ptr].state=gs_uif_state;
        gs_uif_stack[gb_uif_stack_ptr].menu_top=gs_uif_status.menu_top;
        gs_uif_stack[gb_uif_stack_ptr++].menu_ptr=gs_uif_status.menu_ptr;
    }
    else
    {
        // pop back the menu ,then install new menu state
        while (gs_uif_state->level > new_state->level)
        {
            gs_uif_state=gs_uif_stack[--gb_uif_stack_ptr].state;
            UIF_MENU_PTR=gs_uif_stack[gb_uif_stack_ptr].menu_ptr;
            UIF_MENU_TOP=gs_uif_stack[gb_uif_stack_ptr].menu_top;
        }
    }
    gs_uif_state=new_state;
    UIF_MENU_PTR=0;
    UIF_MENU_TOP=0;
    UIF_CLR_SEC_CNT_API();
    UIF_CLR_HALF_SEC_CNT_API();
    UIF_CLR_QUARTER_SEC_CNT_API();
    UIF_SET_ACTION_FLAG_API();
    UIF_CLR_KEY_BUF_API();
    UIF_SET_MENU_TIMEOUT_API();
    //===== Ver1.0.02 =====
    UIF_SET_LED_FULL_ON_API();    
}

//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 uif_state_next_install
//
//! @author  Willman Chen
//
//! @date 	 2009/06/23
//
//! @brief 	 install next menu state
//
//! @param 	 arg the current menu state
//
//**********************************************************************************************************************
void uif_state_next_install(void *arg)
{
    //===== Ver1.0.02 =====
    STC_UIF_SETTING_MENU *menu=arg;
    menu+=UIF_MENU_PTR+UIF_MENU_TOP;
    if (menu->state!=UIF_NULL)
        uif_state_install((UINT8*)menu->state);
}
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 uif_display_setting_menu_item
//
//! @author  Jacky Lin
//
//! @date 	 2022/01/16
//
//! @brief 	 displaying menu item by setting flash menu
//
//! @param 	 arg the current menu state
//
//**********************************************************************************************************************
//===== Ver1.0.02 =====
void uif_display_setting_menu_item(UINT8 *ascii_menu_addr)
{
    STC_UIF_SETTING_MENU *menu=(STC_UIF_SETTING_MENU*)ascii_menu_addr;
    
    if((menu+UIF_MENU_PTR)->display_func!=UIF_NULL)
    {
        UIF_DISPLAY_RESET_TIMEOUT_TIMER_API();
        if(gb_uif_setting_menu_ptr==UIF_SETTING_MENU_1ST_DIS)
          UIF_DIS_STR_API((menu+UIF_MENU_PTR)->ascii);
        else 
          (menu+UIF_MENU_PTR)->display_func();          
    }
    else
    {
        UIF_DIS_STR_API((menu+UIF_MENU_PTR)->ascii);
    }
}
//===== Ver1.0.02 =====
void uif_display_timeout_isr()
{
    gs_uif_status.level_chg=1;
    gb_uif_setting_menu_ptr^=0x01;
}
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn         uif_display_dot_position
//
//! @author 	 Jacky Lin
//
//! @date 	 2022/01/17
//
//! @brief 	 task function
//
//**********************************************************************************************************************
void uif_display_dot_position(UINT16 display_dot_num)
{
    switch(display_dot_num)
    {
        case 3:UIF_XOR_DIS_STR_API("    .   ");break;
        case 4:UIF_XOR_DIS_STR_API("   .    ");break;
        case 5:UIF_XOR_DIS_STR_API("  .     ");break;      
    }      
}
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 		 uif_task
//
//! @author 	 Willman Chen
//
//! @date 	 2009/06/23
//
//! @brief 	 task function
//
//**********************************************************************************************************************
void uif_task()
{

    UINT8 i;
    STC_UIF_KEYMAP const *key_ptr=gs_uif_state->menu_click_keymap;
    for (i=KEY_START; i<KEY_TOTAL; i++,key_ptr++)
    {
        if (key_ptr->key_func!=UIF_NULL_FUNC && KEY_CLICK_CHK_API(i))
            key_ptr->key_func(key_ptr->arg);
    }
    gs_uif_state->menu_func();
    if (gs_uif_status.key_event)
    {
        gs_uif_status.key_event=0;
        UIF_SET_MENU_TIMEOUT_API();
    }
    // if timeout ,we need to go back to Status State
    if (UIF_CHK_MENU_TIMEOUT_API())
    {
        UIF_STATE_REMOVE_API();
    }
}
