#ifndef UIF_GLB_VARS_H
#define UIF_GLB_VARS_H
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 	 uif_glb_vars.h
//
//! @author	 Willman
//
//! @date 	 2009/06/23
//
// @brief 	 Here declare globe variable
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "uif_idef.h"
#include "..\uif_udef.h"
//**********************************************************************************************************************
//
// E X T E R N A L   V A R I A B L E   A L L O C
//
//**********************************************************************************************************************
#ifdef UIF_ALLOC
#define EXTERNAL
#else
#define EXTERNAL extern
#endif
typedef struct
{
    UINT32 value;
    UINT32 *addr;
    UINT8 index;
    UINT8 cursor;
} STC_NUM_BUFFER;

typedef struct
{
    void (*key_func)();
    const void *arg;
} STC_UIF_KEYMAP;

typedef struct
{
    const UINT8 level;
    const UINT8 item_cnt;
    void (*menu_func)();
    const STC_UIF_KEYMAP *menu_click_keymap;
    UINT8 menu_max_line;
} STC_UIF_STATE;

typedef struct
{
    UINT32 		  prompt;
    const STC_UIF_STATE   *state;
} STC_UIF_MENU;
typedef struct
{
    UINT8 ascii[8];
    void (*display_func)();
    const STC_UIF_STATE   *state;
}STC_UIF_SETTING_MENU;
typedef struct
{
    UINT8  state_chg:1;
    UINT8  level_chg:1;
    UINT8  key_event:1;
    UINT8  font_type:5;
    INT16  menu_ptr;
    INT8   menu_top;
} STC_UIF_STATUS;

typedef struct
{
    const STC_UIF_STATE *state;
    INT8 menu_ptr;
    INT8 menu_top;
} STC_UIF_STATE_STACK;

//**********************************************************************************************************************
//
// D E C L A R E   G L O B E   V A R I A B L E
//
//**********************************************************************************************************************
//! @brief UI State Pointer
EXTERNAL  const STC_UIF_STATE   *gs_uif_state;
//! @brief UI Status
EXTERNAL  STC_UIF_STATUS        gs_uif_status;
//! @brief UI Menu Stack
EXTERNAL  STC_UIF_STATE_STACK   gs_uif_stack[UIF_MAX_STACK];
//! @breif UI Stack Pointer
EXTERNAL  UINT8                 gb_uif_stack_ptr;
//! @brief UI Recording Temp Number Variable
EXTERNAL  STC_NUM_BUFFER        gs_uif_num_buf;
//! @brief UI digital temp number array
EXTERNAL  UINT8					gb_uif_digi_num[8];
//! @brief UI X scale
EXTERNAL  FLOAT32				gf_uif_x_scale;
//! @brief UI Y scale
EXTERNAL  FLOAT32				gf_uif_y_scale;
//! @brief UI temp float
EXTERNAL  FLOAT32				gf_uif_temp_float;
//! @brief select display setting menu first or second string 
EXTERNAL  UINT8                                 gb_uif_setting_menu_ptr;
//! @brief UI temp integer
EXTERNAL  UINT32				gf_uif_temp_integer;
//! @brief UI display led digital start position        
EXTERNAL  UINT8                                 gb_uif_digital_start_pos;
EXTERNAL  UINT8                                 gb_uif_digital_dot_pos;
//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S
//
//**********************************************************************************************************************
void uif_glb_vars_init();
#undef EXTERNAL
#endif		// UIF_GLB_VARS_H 
