//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 	 uif_glb_vars.c
//
//! @author 	 Willman
//
//! @date 	 2009/06/23
//
// @brief 	 Init globe variable
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#define UIF_ALLOC
#include "uif_glb_vars.h"
#undef UIF_ALLOC
#include "uif_task.h"
#include UIF_WELCOME_INCLUDE_STATE_H
#include UIF_MAIN_INCLUDE_STATE_H
#include "uif_main_menu_state.h"
//#include "uif_out1_parameter_menu_state.h"
//#include "uif_engr_main_menu_state.h"
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 uif_glb_vars_init
//
//! @author  Willman
//
//! @date 	 2009/06/23
//
//! @brief 	 task function
//
//**********************************************************************************************************************
void uif_glb_vars_init()
{
    *((UINT8*)&gs_uif_status)=0x00;
    gb_uif_stack_ptr=0;
    gs_uif_status.font_type=0;
    gs_uif_state=&UIF_MAIN_STATE;
    uif_state_install((UINT8*)&UIF_WELCOME_STATE);
}
