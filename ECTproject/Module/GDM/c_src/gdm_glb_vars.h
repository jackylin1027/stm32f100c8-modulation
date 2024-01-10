#ifndef GDM_GLB_VARS_H
#define GDM_GLB_VARS_H
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 gdm_glb_vars.h
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
#include "gdm_idef.h"
#include "..\gdm_udef.h"
//**********************************************************************************************************************
//
// E X T E R N A L   V A R I A B L E   A L L O C
//
//**********************************************************************************************************************
#ifdef GDM_ALLOC
#define EXTERNAL
#else
#define EXTERNAL extern
#endif
//**********************************************************************************************************************
//
// D E C L A R E   G L O B E   V A R I A B L E
//
//**********************************************************************************************************************
EXTERNAL	UINT8		gb_gdm_row;
EXTERNAL	UINT8		gb_gdm_col;
extern          const UINT32 udm_big_num_table[];
EXTERNAL	UINT8		gb_gdm_canvas[GDM_MAX_LINE*GDM_MAX_SEG];
#if (GDM_MAX_LINE) <= 8
EXTERNAL UINT8	gb_gdm_line_refresh;
#else
EXTERNAL UINT8 gb_gdm_line_refresh[(MAX_LINE>>3)+1];
#endif // 
EXTERNAL 	UINT8	gb_gdm_line_range[GDM_MAX_LINE<<1];
//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S
//
//**********************************************************************************************************************
void gdm_glb_vars_init();
#undef EXTERNAL
#endif		// GDM_GLB_VARS_H 
