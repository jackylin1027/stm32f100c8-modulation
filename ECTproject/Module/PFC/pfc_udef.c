//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 	 pfc_udef.c
//
//! @author  Willman Chen
//
//! @date 	 2009/06/19
//
// @brief 	 Main loop
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "c_src\pfc_task.h"
#include "pfc_udef.h"
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 pfc_loop
//
//! @author      Willman Chen
//
//! @date 	 2009/06/19
//
//! @brief 	 The main loop function
//
//**********************************************************************************************************************
void pfc_loop()
{

#if MAIN_USE_WATCHDOG == 1
    PFC_WATCHDOG_ENABLE_API();
#endif
    
    while (1)
    {
        pfc_task();
    }
}
