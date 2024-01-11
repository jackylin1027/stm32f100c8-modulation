//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 	 fk_glb_vars.c
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//  @brief 	 Init globe variable
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#define FK_ALLOC
#include "fk_glb_vars.h"
#undef FK_ALLOC
#include "fk_idef.h"
#include "..\fk_udef.h"
//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N
//
//**********************************************************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif
  
    UART_HandleTypeDef* gt_fk_usart_handle[]=
    {
        &fk_usart1, &fk_usart2,&fk_usart3,
    };   
    TIM_HandleTypeDef* gt_fk_timer_handle[]=
    {
        &fk_tim1,&fk_tim2, &fk_tim3, &fk_tim4, &fk_tim6, &fk_tim7,
    };
    
    const UINT32 gt_fk_exti_line[]=
    {
        FK_EXTI0,FK_EXTI1,FK_EXTI2,FK_EXTI3,
        FK_EXTI4,FK_EXTI5,FK_EXTI6,FK_EXTI7,
        FK_EXTI8,FK_EXTI9,FK_EXTI10,FK_EXTI11,
        FK_EXTI12,FK_EXTI13,FK_EXTI14,FK_EXTI15,
    };
    const void* gt_fk_port_index[]=
    {
        FK_PORTA,FK_PORTB,
        FK_PORTC,FK_PORTD,
        FK_PORTE,        
    };
    const UINT32 gt_fk_pin_index[]=
    {
        FK_PIN0,FK_PIN1,FK_PIN2,FK_PIN3,
        FK_PIN4,FK_PIN5,FK_PIN6,FK_PIN7,
        FK_PIN8,FK_PIN9,FK_PIN10,FK_PIN11,
        FK_PIN12,FK_PIN13,FK_PIN14,FK_PIN15,
    };

    const UINT32 gt_fk_exti_irq_register[]=
    {
        FK_EXTI_IRQ0,FK_EXTI_IRQ1,FK_EXTI_IRQ2,FK_EXTI_IRQ3,FK_EXTI_IRQ4,
        FK_EXTI_IRQ9_5,FK_EXTI_IRQ9_5,FK_EXTI_IRQ9_5,FK_EXTI_IRQ9_5,FK_EXTI_IRQ9_5,
        FK_EXTI_IRQ15_10,FK_EXTI_IRQ15_10,FK_EXTI_IRQ15_10,FK_EXTI_IRQ15_10,FK_EXTI_IRQ15_10,FK_EXTI_IRQ15_10,
    };

    const UINT32 gt_fk_dma_irq_register[]=
    {
        DMA1_Channel1_IRQn,DMA1_Channel2_IRQn,DMA1_Channel3_IRQn,DMA1_Channel4_IRQn,
        DMA1_Channel5_IRQn,DMA1_Channel6_IRQn,DMA1_Channel7_IRQn,
#if !defined (STM32F10X_HD)
#if !defined (STM32F10X_MD)
#if !defined (STM32F10X_MD_VL)
        DMA2_Channel1_IRQn,DMA2_Channel2_IRQn,DMA2_Channel3_IRQn,DMA2_Channel4_IRQn,
        DMA2_Channel5_IRQn,
#endif
#endif
#endif
    };

    const UINT32 gt_fk_dma_channel_register[]=
    {
        DMA1_Channel1_BASE,DMA1_Channel2_BASE,DMA1_Channel3_BASE,DMA1_Channel4_BASE,DMA1_Channel5_BASE,
        DMA1_Channel6_BASE,DMA1_Channel7_BASE,
    };

    const UINT8 gt_fk_exti_priority[]=
    {
        FK_EXTI0_PRIORITY,FK_EXTI1_PRIORITY,FK_EXTI2_PRIORITY,FK_EXTI3_PRIORITY,
        FK_EXTI4_PRIORITY,FK_EXTI9_5_PRIORITY,FK_EXTI15_10_PRIORITY,FK_EXTI15_10_PRIORITY,
    };

    const UINT8 gt_fk_dma_priority[]=
    {
        FK_DMA1_CHANNEL1_PRIORITY,FK_DMA1_CHANNEL2_PRIORITY,FK_DMA1_CHANNEL3_PRIORITY,FK_DMA1_CHANNEL4_PRIORITY,
        FK_DMA1_CHANNEL5_PRIORITY,FK_DMA1_CHANNEL6_PRIORITY,FK_DMA1_CHANNEL7_PRIORITY,

    };

    const UINT32 gt_fk_timer_register[]=
    {
        TIM2_BASE,TIM3_BASE,TIM4_BASE,TIM6_BASE,TIM7_BASE,
    };

    const UINT32 gt_fk_timer_irq[]=
    {
        TIM2_IRQn,TIM3_IRQn,TIM4_IRQn ,TIM6_IRQn,TIM7_IRQn, 
    };

    const UINT8 gt_fk_timer_priority[]=
    {
        FK_TIM1_CC_PRIORITY,FK_TIM2_PRIORITY,FK_TIM3_PRIORITY,FK_TIM4_PRIORITY,FK_TIM6_PRIORITY,FK_TIM7_PRIORITY,
    };

    const UINT32 gt_fk_uart_port_register[]=
    {
        GPIOA_BASE,GPIOB_BASE,GPIOA_BASE,GPIOD_BASE,GPIOB_BASE,GPIOD_BASE,
    };
    const UINT32 gt_fk_uart_tx_pin_register[]=
    {
        FK_PIN9,FK_PIN6,FK_PIN2,FK_PIN5,FK_PIN10,FK_PIN8,
    };
    const UINT32 gt_fk_uart_rx_pin_register[]=
    {
        FK_PIN10,FK_PIN7,FK_PIN3,FK_PIN6,FK_PIN11,FK_PIN9,
    };

    const UINT32 gt_fk_uart_name[]=
    {
        USART1_BASE,USART1_BASE,USART2_BASE,USART2_BASE,USART3_BASE,USART3_BASE,
    };

    const UINT32 gt_fk_uart_irq_register[]=
    {
        USART1_IRQn,USART2_IRQn,USART3_IRQn
    };
    const UINT8 gt_fk_uart_priority[]=
    {
        FK_UART1_PRIORITY,FK_UART2_PRIORITY,FK_UART3_PRIORITY,FK_UART3_PRIORITY
    };

    const void* gt_fk_adc_port[]=
    {
        FK_PORTA,FK_PORTA,FK_PORTA,FK_PORTA,FK_PORTA,FK_PORTA,FK_PORTA,FK_PORTA,
        FK_PORTB,FK_PORTB,FK_PORTC,FK_PORTC,FK_PORTC,FK_PORTC,FK_PORTC,FK_PORTC,
    };

    const UINT32 gt_fk_adc_pin[]=
    {
        FK_PIN0,FK_PIN1,FK_PIN2,FK_PIN3,FK_PIN4,FK_PIN5,FK_PIN6,FK_PIN7,
        FK_PIN0,FK_PIN1,FK_PIN0,FK_PIN1,FK_PIN2,FK_PIN3,FK_PIN4,FK_PIN5,
    };


    const void* gt_fk_i2c_register[]=
    {
        FK_I2C_CH1,FK_I2C_CH2,
    };

    const void* gt_fk_i2c_port[]=
    {
        FK_PORTB,FK_PORTB,
    };

    const UINT32 gt_fk_i2c_pin[]=
    {
        FK_PIN6,FK_PIN10,FK_PIN7,FK_PIN11
    };

    STC_FK_INTERRUPT gs_fk_interrupt_list;

    const UINT32 gt_fk_spi_register[]=
    {
      SPI1_BASE,SPI2_BASE,
    };

    const void* gt_fk_spi_port[]=
    {
      FK_PORTA,FK_PORTB,FK_PORTB,
    };

    const UINT32 gt_fk_spi_pins[]=
    {
        // CLK ,  MOSI , MISO   
        FK_PIN5,FK_PIN7,FK_PIN6,    // SPI1
        FK_PIN13,FK_PIN15,FK_PIN14, // SPI2
    };      

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 fk_null
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 task function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_null()
    {

    }
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 fk_glb_vars_init
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//! @brief 	 task function
//
//! @param 	 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_glb_vars_init()
    {
        UINT8 i;
        UINT8 *ptr;
        gfunc_fk_systick_func=fk_null;
        gfunc_fk_rtc_func=fk_null;
        gfunc_fk_adc_func=fk_null;
        gfunc_fk_pvd_func=fk_null;
        gfunc_fk_rtc_alarm_func=fk_null;
        for (i=0; i<FK_EXTI_TOTAL; i++)
            gfunc_fk_exti_func[i]=fk_null;
        for (i=0; i<FK_DMA_TOTAL; i++)
            gfunc_fk_dma_func[i]=fk_null;
        for (i=0; i<FK_TIMER_INTERRUPT_TOTAL; i++)
            gfunc_fk_timer_interrupt[i]=fk_null;
        ptr=(UINT8*)&gs_fk_interrupt_list;
        for (i=0; i<sizeof(gs_fk_interrupt_list); i++)
            *(ptr+i)=0x00;
        gb_fk_capture_compare_timer=0;
        gb_fk_capture_compare_channel=0;
    }
//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N
//
//**********************************************************************************************************************
#ifdef __cplusplus
}
#endif

