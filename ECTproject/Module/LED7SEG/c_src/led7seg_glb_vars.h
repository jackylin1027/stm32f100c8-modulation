//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N 
//
//**********************************************************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif
#ifndef LED7SEG_GLB_VARS_H
#define LED7SEG_GLB_VARS_H
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 led7seg_glb_vars.h
//
//! @author 	 Jacky Lin
//
//! @date 		 2021/12/29
//
//  @brief 		 Here declare globe variable
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S 
//
//**********************************************************************************************************************
#include "..\led7seg_udef.h"
#include "led7seg_idef.h"    
//**********************************************************************************************************************
//
// E X T E R N A L   V A R I A B L E   A L L O C 
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// T Y P E D E F   S T R U C T   D E F I N I T I O N 
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S 
//
//**********************************************************************************************************************
void led7seg_glb_vars_init();
#endif		// LED7SEG_GLB_VARS_H 
#ifdef LED7SEG_ALLOC
	#define EXTERNAL
#else
	#define EXTERNAL extern
#endif
//**********************************************************************************************************************
//
// D E C L A R E   G L O B E   V A R I A B L E 
//
//**********************************************************************************************************************
EXTERNAL const UINT8 gb_led7seg_font[];
EXTERNAL UINT8 gb_led7seg_refresh_str[LED7SEG_MAX_CHAR_NUM];
EXTERNAL UINT8 gb_led7seg_refresh_num[LED7SEG_MAX_CHAR_NUM];
//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N 
//
//**********************************************************************************************************************
#undef EXTERNAL
#ifdef __cplusplus
}
#endif