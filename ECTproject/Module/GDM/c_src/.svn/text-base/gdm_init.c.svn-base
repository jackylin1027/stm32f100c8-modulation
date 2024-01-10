//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 gdm_init.c
//
//! @author 	 Willman Chen
//
//! @date 		 2009/07/14
//
//  @brief 		 Initial Subroutine
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "..\drv_src\gdm_drv.h"
#include "gdm_glb_vars.h"
#include "..\gdm_udef.h"
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 gdm_init
//
//! @author 	 Willman Chen
//
//! @date 		 2009/07/14
//
//! @brief 		 initial function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void gdm_init()
{
    gdm_sfr_init();
    gdm_glb_vars_init();
#if GDM_USE_UART == 1
    GDM_UART_INIT_API();
    FK_SET_PIN_OUPUT_PUSH_PUMP_API(FK_PORTA,FK_PIN1);
    FK_SET_OUTPUT_PIN_LOW_API(FK_PORTA,FK_PIN1);
    GDM_DATA_SEND_OUT_API('L');
    GDM_DATA_SEND_OUT_API('C');
    GDM_DATA_SEND_OUT_API('M');
    GDM_DATA_SEND_OUT_API(GDM_MAX_SEG);
    GDM_DATA_SEND_OUT_API(GDM_MAX_LINE<<3);
    GDM_DATA_SEND_OUT_API(0);
#endif
}
