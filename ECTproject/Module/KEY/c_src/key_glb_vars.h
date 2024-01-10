#ifndef KEY_GLB_VARS_H
#define KEY_GLB_VARS_H
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 	 key_glb_vars.h
//
//! @author 	 Willman Chen
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
#include "..\key_udef.h"
//**********************************************************************************************************************
//
// E X T E R N A L   V A R I A B L E   A L L O C
//
//**********************************************************************************************************************
#ifdef KEY_ALLOC
#define EXTERNAL
#else
#define EXTERNAL extern
#endif

typedef struct
{
    UINT8 key_expired :1 ;
    UINT8 key_timer   :7 ;
} STC_KEY;
//**********************************************************************************************************************
//
// D E C L A R E   G L O B E   V A R I A B L E
//
//**********************************************************************************************************************
//! @brief The flag for recording we need to clear the key buffer
EXTERNAL UINT8      gb_key_clr_buf;
//! @brief The buffer for Recording the current I/O state
EXTERNAL UINT8      gb_key_curr;
#if KEY_HAS_CLICK == 1
//! @brief The buffer for Recording the click key state
EXTERNAL UINT8      gb_key_click;
#endif
#if KEY_HAS_PRESSED == 1
//! @brief The buffer for Recording the press key state
EXTERNAL STC_KEY    gs_key_pressed[KEY_TOTAL];
#endif
#if KEY_HAS_REPEAT == 1
//! @brief The buffer for Recording the repeat key state
EXTERNAL STC_KEY    gs_key_repeat[KEY_TOTAL];
#endif
//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S
//
//**********************************************************************************************************************
void key_glb_vars_init();
#undef EXTERNAL
#endif		// KEY_GLB_VARS_H 
