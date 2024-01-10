//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 ssd_io_init.c
//
//! @author 	 Jacky Lin
//
//! @date 		 2021/12/28
//
//  @brief 		 Initial Subroutine
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S 
//
//**********************************************************************************************************************
#include "..\drv_src\ssd_io_drv.h" 
#include "ssd_io_glb_vars.h"
//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N 
//
//**********************************************************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 ssd_io_init
//
//! @author 	 Jacky Lin
//
//! @date 		 2021/12/28
//
//! @brief 		 initial function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void ssd_io_init()
{
	ssd_io_sfr_init();
	ssd_io_glb_vars_init();
}
//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N 
//
//**********************************************************************************************************************
#ifdef __cplusplus
}
#endif
