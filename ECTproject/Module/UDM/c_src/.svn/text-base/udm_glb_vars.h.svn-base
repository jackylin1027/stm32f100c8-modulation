#ifndef UDM_GLB_VARS_H
#define UDM_GLB_VARS_H
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 udm_glb_vars.h
//
//! @author 	 Willman Chen
//
//! @date 		 2009/07/14
//
//  @brief 		 Here declare globe variable
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "..\udm_udef.h"
//**********************************************************************************************************************
//
// E X T E R N A L   V A R I A B L E   A L L O C
//
//**********************************************************************************************************************
#ifdef UDM_ALLOC
#define EXTERNAL
#else
#define EXTERNAL extern
#endif

typedef struct
{
    UINT8	char_pat[5];
} CHAR_5X7;

typedef struct
{
    UINT8 char_pat[14];
} CHAR_7X9;

typedef struct
{
    UINT8	*char_table;
    UINT8	font_w;
    UINT8	font_h;
} FONT_INFO;

//**********************************************************************************************************************
//
// D E C L A R E   G L O B E   V A R I A B L E
//
//**********************************************************************************************************************
EXTERNAL	const FONT_INFO udm_font5x7;
EXTERNAL	const FONT_INFO udm_font7x9;
EXTERNAL	const FONT_INFO* const udm_font[UDM_ALL_FONT];
#if UDM_USE_SYMB == 1
#include "udm_symb.h"
extern const UINT8 udm_icon_table[UDM_ICON_ARRAY_SIZE-UDM_BASE_PATTERN_START];
#endif
#if UDM_USE_ROM_PROMPT == 1
extern const UINT8 gs_udm_rom_prompt[];
#endif
#if UDM_USE_TRADITIONAL_CHINESE == 1
extern const UINT32 gw_udm_traditional_chinese_prompt[];
#endif
#if UDM_USE_SIMPLE_CHINESE == 1
extern const UINT32 gw_udm_simple_chinese_prompt[];
#endif
//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S
//
//**********************************************************************************************************************
void udm_glb_vars_init();
#undef EXTERNAL
#endif		// UDM_GLB_VARS_H 
