//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 	 fk_drv.c
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//  @brief 	 Driver Subroutine
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "..\fk_udef.h"
#include "..\c_src\fk_glb_vars.h"
#include "fk_drv.h"
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
//! @fn          fk_sfr_init
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void fk_sfr_init()
{
    // System clock configurated by CubeMX software, so cancel the function in fk_lib, JackyLin //
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          FK_NMI_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_NMI_Handler(void)
    {

    }
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_PVD_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_PVD_Handler(void)
    {
        gfunc_fk_pvd_func();
    }
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_HardFault_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_HardFault_Handler(void)
    {

    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_MemManage_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_MemManage_Handler(void)
    {

    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_BusFault_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_BusFault_Handler(void)
    {

    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_UsageFault_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_UsageFault_Handler(void)
    {

    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_SVC_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_SVC_Handler(void)
    {

    }
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_DebugMon_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_DebugMon_Handler(void)
    {

    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_PendSV_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_PendSV_Handler(void)
    {

    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_SysTick_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_SysTick_Handler(void)
    {
        gfunc_fk_systick_func();
    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_EXTI0_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_EXTI0_Handler(void)
    {
        // ISR function created by CubeMX software, so cancel the function in fk_lib, JackyLin //
    }
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_EXTI1_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_EXTI1_Handler(void)
    {
        // ISR function created by CubeMX software, so cancel the function in fk_lib, JackyLin //
    }
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_EXTI2_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_EXTI2_Handler(void)
    {
        // ISR function created by CubeMX software, so cancel the function in fk_lib, JackyLin //
    }
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_EXTI3_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_EXTI3_Handler(void)
    {
        // ISR function created by CubeMX software, so cancel the function in fk_lib, JackyLin //
    }
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_EXTI4_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_EXTI4_Handler(void)
    {
        // ISR function created by CubeMX software, so cancel the function in fk_lib, JackyLin //
    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_EXTI9_5_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_EXTI9_5_Handler(void)
    {
        // ISR function created by CubeMX software, so cancel the function in fk_lib, JackyLin //
    }
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_EXTI15_10_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_EXTI15_10_Handler(void)
    {
        // ISR function created by CubeMX software, so cancel the function in fk_lib, JackyLin //
    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_rtc_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_rtc_Handler(void)
    {
        // ISR function created by CubeMX software, so cancel the function in fk_lib, JackyLin //
    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_rtc_alarm_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_rtc_alarm_Handler(void)
    {
        // ISR function created by CubeMX software, so cancel the function in fk_lib, JackyLin //
    }
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_wwatchdog_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_wwatchdog_Handler(void)
    {
        void (*func)(void);
        func=(void(*)(void))0x0000;
        func();
    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_dma_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_dma_Handler(void)
    {
        // ISR function created by CubeMX software, so cancel the function in fk_lib, JackyLin //
    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_tim1_cc_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void fk_tim1_cc_Handler(void)
{
        // ISR function created by CubeMX software, so cancel the function in fk_lib, JackyLin //    
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_tim2_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_tim2_Handler(void)
    {
        // ISR function created by CubeMX software, so cancel the function in fk_lib, JackyLin //
    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_tim3_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_tim3_Handler(void)
    {
        // ISR function created by CubeMX software, so cancel the function in fk_lib, JackyLin //
    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_tim4_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_tim4_Handler(void)
    {
        // ISR function created by CubeMX software, so cancel the function in fk_lib, JackyLin //
    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_tim3_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_tim5_Handler(void)
    {
        // ISR function created by CubeMX software, so cancel the function in fk_lib, JackyLin //
    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_uart1_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_uart1_Handler(void)
    {        
        // ISR function created by CubeMX software, so cancel the function in fk_lib, JackyLin //               
    }
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_uart2_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_uart2_Handler(void)
    {
        // ISR function created by CubeMX software, so cancel the function in fk_lib, JackyLin //  
    }
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_uart3_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_uart3_Handler(void)
    {
        // ISR function created by CubeMX software, so cancel the function in fk_lib, JackyLin //
    }

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn          fk_adc1_2_Handler
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 Register initial function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_adc1_2_Handler(void)
    {
        // ISR function created by CubeMX software, so cancel the function in fk_lib, JackyLin //
    }
//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N
//
//**********************************************************************************************************************
#ifdef __cplusplus
}
#endif

