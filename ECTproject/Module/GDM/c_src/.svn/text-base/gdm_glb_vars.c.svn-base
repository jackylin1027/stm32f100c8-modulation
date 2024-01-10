//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 gdm_glb_vars.c
//
//! @author 	 Willman Chen
//
//! @date 		 2009/07/14
//
//  @brief 		 Init globe variable
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#define GDM_ALLOC
#include "gdm_glb_vars.h"
#undef GDM_ALLOC
#include "..\gdm_udef.h"
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 gdm_glb_vars_init
//
//! @author 	 Willman Chen
//
//! @date 		 2009/07/14
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void gdm_glb_vars_init()
{
    UINT8 i;

    for (i=0; i<(GDM_MAX_LINE<<1); i+=2)
    {
        gb_gdm_line_range[i]=GDM_MAX_SEG;
        gb_gdm_line_range[i+1]=GDM_FIRST_COL;
    }
#if (GDM_MAX_LINE) <= 8
    gb_gdm_line_refresh=0x00;
#else
    for (i=0; i<GDM_MAX_LINE>>3; i++)
        gb_gdm_line_refresh[i]=0x00;
#endif
}
