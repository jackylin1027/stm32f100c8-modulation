//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 	 fk_task.c
//
//! @author 	 Willman Chen
//
//! @date 	 2010/10/25
//
//  @brief 	 Task Subroutine
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "..\fk_udef.h"
#include "fk_glb_vars.h"
#include "fk_idef.h"
#include "..\drv_src\fk_drv.h"
#include "fk_task.h"
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
  //! @fn 	 fk_port_index
  //
  //! @author 	 Jacky Lin
  //
  //! @date 	 2023/04/13
  //
  //! @brief 	 task function
  //
  //! @param	 None
  //
  //! @return 	 None
  //
  //**********************************************************************************************************************
  UINT8 fk_port_index(UINT32 port)
  {
    UINT8 i;
    for (i=0; i<FK_PORT_TOTAL; i++)
      if (port==(UINT32)gt_fk_port_index[i])
        break;
    return i;
  }
  
  //**********************************************************************************************************************
  //
  // Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
  //
  //! @fn 	 fk_pin_index
  //
  //! @author 	 Jacky Lin
  //
  //! @date 	 2023/04/13
  //
  //! @brief 	 task function
  //
  //! @param	 None
  //
  //! @return 	 None
  //
  //**********************************************************************************************************************
  UINT8 fk_pin_index(UINT32 pin)
  {
    UINT8 i;
    for (i=0; i<FK_PIN_TOTAL; i++)
      if (pin==(UINT32)gt_fk_pin_index[i])
        break;
    return i;
  }
  //**********************************************************************************************************************
  //
  // Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
  //
  //! @fn 	 fk_set_io
  //
  //! @author 	 Jacky Lin
  //
  //! @date 	 2023/04/13
  //
  //! @brief 	 task function
  //
  //! @param	 None
  //
  //! @return 	 None
  //
  //**********************************************************************************************************************
  void fk_set_io(UINT32 port,UINT32 pin,UINT32 speed,UINT32 mode,UINT32 pull)
  {
        GPIO_InitTypeDef  GPIO_InitStruct;
        
        fk_port_peripherals_enable(port); 
        GPIO_InitStruct.Pin = pin;
        GPIO_InitStruct.Speed = speed;
        GPIO_InitStruct.Mode = mode;
        GPIO_InitStruct.Pull = pull;
        HAL_GPIO_Init((GPIO_TypeDef *)port, &GPIO_InitStruct);        
  }
  
  //**********************************************************************************************************************
  //
  // Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
  //
  //! @fn 	 fk_get_crc
  //
  //! @author 	 Jacky Lin
  //
  //! @date 	 2023/04/13
  //
  //! @brief 	 task function
  //
  //! @param	 None
  //
  //! @return 	 None
  //
  //**********************************************************************************************************************
  UINT32 fk_get_crc(UINT32 *data,UINT32 size)
  {
      // Initial function complemmently by CubeMX software, so cancel the function in fk_lib, JackyLin //
    return 0;
  }
  
  //**********************************************************************************************************************
  //
  // Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
  //
  //! @fn 	 fk_set_io_interrupt
  //
  //! @author 	 Jacky Lin
  //
  //! @date 	 2023/04/13
  //
  //! @brief 	 task function
  //
  //! @param	 None
  //
  //! @return 	 None
  //
  //**********************************************************************************************************************
  void fk_set_io_interrupt(UINT32 port,UINT32 pin,UINT32 mode,void(*func)(void),UINT32 enable)
  {
     // GPIO_InitTypeDef GPIO_InitStruct = {0};
      UINT8 pin_index=fk_pin_index(pin);
      //UINT8 priority=gt_fk_exti_priority[pin_index];
      
      //fk_port_peripherals_enable(port); 
      if (enable==(UINT32) ENABLE)
      {
          //GPIO_InitStruct.Pin = pin;
          //GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
          //GPIO_InitStruct.Pull = GPIO_PULLUP;
          //HAL_GPIO_Init((GPIO_TypeDef *)port, &GPIO_InitStruct);      
          gfunc_fk_exti_func[pin_index]=func;
      }
      /* EXTI interrupt init*/    
      //fk_nvic_enable(gt_fk_exti_irq_register[pin_index],priority,enable);
  }
  //**********************************************************************************************************************
  //
  // Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
  //
  //! @fn 	 fk_set_io_interrupt
  //
  //! @author 	 Jacky Lin
  //
  //! @date 	 2023/04/13
  //
  //! @brief 	 task function
  //
  //! @param	 None
  //
  //! @return 	 None
  //
  //**********************************************************************************************************************
  void fk_rtc_enable(UINT32 time)
  {
      // Initial function complemmently by CubeMX software, so cancel the function in fk_lib, JackyLin //
      FK_RESET_RTC_ALARM_API();
  }
  //**********************************************************************************************************************
  //
  // Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
  //
  //! @fn 	 fk_set_rtc_second_func
  //
  //! @author 	 Jacky Lin
  //
  //! @date 	 2023/04/13
  //
  //! @brief 	 task function
  //
  //! @param	 None
  //
  //! @return 	 None
  //
  //**********************************************************************************************************************
  void fk_set_rtc_second_func(void(*func)(void))
  {
      // Initial function complemmently by CubeMX software, so cancel the function in fk_lib, JackyLin //
  }
  //**********************************************************************************************************************
  //
  // Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
  //
  //! @fn 	 fk_reset_rtc_alarm
  //
  //! @author 	 Jacky Lin
  //
  //! @date 	 2023/04/13
  //
  //! @brief 	 task function
  //
  //! @param	 None
  //
  //! @return 	 None
  //
  //**********************************************************************************************************************  
  void fk_reset_rtc_alarm(void)
  {    
      RTC_TimeTypeDef nTime;
      RTC_AlarmTypeDef aTime;
      HAL_RTC_GetTime(&fk_rtc,&nTime,RTC_FORMAT_BIN);
      
      nTime.Seconds +=1;
      if(nTime.Seconds==60)
      {
          nTime.Minutes += 1;
          if(nTime.Minutes==60)
          {
              nTime.Hours += 1;
              if(nTime.Hours == 24)
              {
                  nTime.Hours = 0;
              }
              nTime.Minutes=0;
          }
          nTime.Seconds=0;
      }
      aTime.AlarmTime = nTime;
      HAL_RTC_SetAlarm_IT(&fk_rtc,&aTime,RTC_FORMAT_BIN);
  } 
  //**********************************************************************************************************************
  //
  // Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
  //
  //! @fn 	 fk_write_flash
  //
  //! @author 	 Jacky Lin
  //
  //! @date 	 2023/04/13
  //
  //! @brief 	 task function
  //
  //! @param	 None
  //
  //! @return 	 None
  //
  //**********************************************************************************************************************
  UINT32 fk_write_flash(UINT32 page,UINT32 *buf,UINT32 size)
  {
      UINT32 addr=FK_M3_FLASH_START+(page*FK_FLASH_PAGE_SIZE);
      UINT32 i,status;
      HAL_FLASH_Unlock();
      __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPERR);
      for (i=0; i<FK_NEED_PAGE; i++)
      {
            FLASH_PageErase(addr+i*FK_FLASH_PAGE_SIZE);
            // Wait for last operation to be completed
            status = FLASH_WaitForLastOperation(FLASH_TIMEOUT_VALUE);     
            // If the erase operation is completed, disable the ERASE Bit
            CLEAR_BIT(FLASH->CR, FLASH_CR_PER);
            CLEAR_BIT(FLASH->CR, FLASH_CR_PG);            
            if (status!=HAL_OK)
                return 0;
      }
      
      for (i=0; i<size; i+=sizeof(UINT32))
      {
        status=HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, addr+i, *(buf+(i/sizeof(UINT32))));
        if (status!=HAL_OK)
          return 0;
      }
      HAL_FLASH_Lock();
      return 1;
  }
  
  //**********************************************************************************************************************
  //
  // Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
  //
  //! @fn 	 fk_write_flash
  //
  //! @author 	 Jacky Lin
  //
  //! @date 	 2023/04/13
  //
  //! @brief 	 task function
  //
  //! @param	 None
  //
  //! @return 	 None
  //
  //**********************************************************************************************************************
  void fk_read_flash(UINT32 page,UINT32 *buf,UINT32 size)
  {
      UINT32 i;
      UINT32 addr=FK_M3_FLASH_START+(page*FK_FLASH_PAGE_SIZE);
      UINT32 *read=(UINT32*)addr;
      for (i=0;i<size; i+=4,read++,buf++)
        *buf=*read;
  }
 //**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 fk_port_index
//
//! @author 	 Jacky Lin
//
//! @date 		 2023/04/26
//
//! @brief 		 Gpio port index search function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_port_peripherals_enable(UINT32 port)
    {
        switch(port)
        {
            case (UINT32)FK_PORTA:      __HAL_RCC_GPIOA_CLK_ENABLE();   break;
            case (UINT32)FK_PORTB:      __HAL_RCC_GPIOB_CLK_ENABLE();   break;
            case (UINT32)FK_PORTC:      __HAL_RCC_GPIOC_CLK_ENABLE();   break;
            case (UINT32)FK_PORTD:      __HAL_RCC_GPIOD_CLK_ENABLE();   break;
            default: break;
        }        
    } 
  
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 fk_nvic_enable
//
//! @author 	 Jacky Lin
//
//! @date 		 2023/04/26
//
//! @brief 		 Nested Vectored Interrupt Controller Configuration function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
    void fk_nvic_enable(UINT32 irq_channel,UINT32 priority,UINT32 enable)
    {
        UINT32 PreemptPriority=priority%16;
        HAL_NVIC_SetPriority((IRQn_Type)irq_channel, PreemptPriority, 0);
        if(enable)
            HAL_NVIC_EnableIRQ((IRQn_Type)irq_channel);      
        else
            HAL_NVIC_DisableIRQ((IRQn_Type)irq_channel);
    }  
  //**********************************************************************************************************************
  //
  // Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
  //
  //! @fn 	 fk_watchdog_enable
  //
  //! @author 	 Jacky Lin
  //
  //! @date 	 2023/04/13
  //
  //! @brief 	 task function
  //
  //! @param	 None
  //
  //! @return 	 None
  //
  //**********************************************************************************************************************
  void fk_watchdog_enable()
  {
      // Initial function complemmently by CubeMX software, so cancel the function in fk_lib, JackyLin //
  }
  
  //**********************************************************************************************************************
  //
  // Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
  //
  //! @fn 	 fk_wwatchdog_enable
  //
  //! @author 	 Willman Chen
  //
  //! @date 	 2010/10/25
  //
  //! @brief 	 task function
  //
  //! @param	 None
  //
  //! @return 	 None
  //
  //**********************************************************************************************************************
  void fk_wwatchdog_enable()
  {
      // Initial function complemmently by CubeMX software, so cancel the function in fk_lib, JackyLin //
  }
  //**********************************************************************************************************************
  //
  // Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
  //
  //! @fn 	 fk_speed_up
  //
  //! @author 	 Willman Chen
  //
  //! @date 	 2010/10/25
  //
  //! @brief 	 task function
  //
  //! @param	 None
  //
  //! @return 	 None
  //
  //**********************************************************************************************************************
  void fk_speed_up()
  {
      // Initial function complemmently by CubeMX software, so cancel the function in fk_lib, JackyLin //
  }
  //**********************************************************************************************************************
  //
  // Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
  //
  //! @fn 	 fk_enter_stop_mode
  //
  //! @author 	 Willman Chen
  //
  //! @date 	 2010/10/25
  //
  //! @brief 	 task function
  //
  //! @param	 None
  //
  //! @return 	 None
  //
  //**********************************************************************************************************************
  void fk_enter_stop_mode()
  {
    UINT32 *ptr=(UINT32*)&gs_fk_interrupt_list;
    FK_RELOAD_IWATCHDOG_API();
    if (*ptr==0)
    {
#if MAIN_LOW_POWER_MODE == 1
      PWR_EnterSTOPMode(PWR_Regulator_LowPower, PWR_STOPEntry_WFI);
#endif
#if MAIN_ENTER_SLEEP_MODE == 1
      FK_ENTER_SLEEP_MODE_API();
#endif
    }
    FK_RELOAD_IWATCHDOG_API();
  }
  
  //**********************************************************************************************************************
  //
  // Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
  //
  //! @fn 	 fk_dma_enable
  //
  //! @author 	 Willman Chen
  //
  //! @date 	 2010/10/25
  //
  //! @brief 	 task function
  //
  //! @param	 None
  //
  //! @return 	 None
  //
  //**********************************************************************************************************************
  void fk_dma_enable(UINT8 channel,UINT32 *source,UINT32 *dest,UINT32 size,void(*func)(void))
  {
      // Initial function complemmently by CubeMX software, so cancel the function in fk_lib, JackyLin //   
  }
  //**********************************************************************************************************************
  //
  // Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
  //
  //! @fn 	 fk_nvic_disable
  //
  //! @author 	 Willman Chen
  //
  //! @date 	 2010/10/25
  //
  //! @brief 	 task function
  //
  //! @param	 None
  //
  //! @return 	 None
  //
  //**********************************************************************************************************************
  void fk_nvic_disable(UINT32 irq_channel)
  {
      // Initial function complemmently by CubeMX software, so cancel the function in fk_lib, JackyLin //   
  }
  
  //**********************************************************************************************************************
  //
  // Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
  //
  //! @fn 	 fk_timer_enable
  //
  //! @author 	 Willman Chen
  //
  //! @date 	 2010/10/25
  //
  //! @brief 	 task function
  //
  //! @param	 None
  //
  //! @return 	 None
  //
  //**********************************************************************************************************************
  void fk_timer_interrupt_enable(UINT8 timer,UINT32 prescale,UINT32 count,void(*func)(void))
  {
        if(count ==0)
        	return;
        else if(count == 1)	
        {
        	count = 2;
        	prescale = prescale/2;
        }            
        gt_fk_timer_handle[timer]->Init.Prescaler = prescale-1;
        gt_fk_timer_handle[timer]->Init.CounterMode = TIM_COUNTERMODE_DOWN;
        gt_fk_timer_handle[timer]->Init.Period = count-1;        
        gt_fk_timer_handle[timer]->Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;        
        gt_fk_timer_handle[timer]->Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
        if (HAL_TIM_Base_Init(gt_fk_timer_handle[timer]) != HAL_OK)
        {
            Error_Handler();
        }          
        gfunc_fk_timer_interrupt[timer]=func;
        FK_TIMER_INTERRUPT_START(gt_fk_timer_handle[timer]); 
        HAL_TIM_Base_Start_IT(gt_fk_timer_handle[timer]);
  }
  //**********************************************************************************************************************
  //
  // Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
  //
  //! @fn 	 fk_timer_interrupt_register_callback
  //
  //! @author 	 Jacky Lin
  //
  //! @date 	 2024/01/11
  //
  //! @brief 	 register function for timer interrupt
  //
  //! @param	 None
  //
  //! @return 	 None
  //
  //**********************************************************************************************************************  
  void fk_timer_interrupt_register_callback(UINT8 timer, void (*func) (void))
  {
        gfunc_fk_timer_interrupt[timer]=func;
        FK_TIMER_INTERRUPT_START(gt_fk_timer_handle[timer]); 
        HAL_TIM_Base_Start_IT(gt_fk_timer_handle[timer]);  
  }
  //**********************************************************************************************************************
  //
  // Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
  //
  //! @fn 	 fk_timer_capture_enable
  //
  //! @author 	 Willman Chen
  //
  //! @date 	 2010/10/25
  //
  //! @brief 	 task function
  //
  //! @param	 None
  //
  //! @return 	 None
  //
  //**********************************************************************************************************************
  void fk_timer_capture_enable(UINT8 timer,UINT16 channel,UINT32 port,UINT32 pin,UINT16 edge,void(*func)(void))
  {
      // Initial function complemmently by CubeMX software, so cancel the function in fk_lib, JackyLin //   
  }
  //**********************************************************************************************************************
  //
  // Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
  //
  //! @fn 	 fk_timer_enable
  //
  //! @author 	 Willman Chen
  //
  //! @date 	 2010/10/25
  //
  //! @brief 	 fk_hal_uart_init for reinitial uart handle parameter, so it don't initiate of all the including GPIO ¡B RCC ¡B NVIC  register  
  //
  //! @param	 None
  //
  //! @return 	 None
  //
  //**********************************************************************************************************************
  void fk_hal_uart_init(UINT8 comport,UINT32 baudrate,UINT16 bits,UINT16 stop_bits,UINT16 parity,UINT8 mode,UINT8(*tx_func)(void),void(*rx_func)(void))
  {        
        gt_fk_usart_handle[comport/2]->Init.BaudRate=baudrate;
        gt_fk_usart_handle[comport/2]->Init.WordLength=bits;
        gt_fk_usart_handle[comport/2]->Init.StopBits=stop_bits;
        gt_fk_usart_handle[comport/2]->Init.Parity=parity;
        gt_fk_usart_handle[comport/2]->Init.Mode=UART_MODE_TX_RX;
        gt_fk_usart_handle[comport/2]->Init.HwFlowCtl=UART_HWCONTROL_NONE;
        gt_fk_usart_handle[comport/2]->Init.OverSampling=UART_OVERSAMPLING_16;
        
        if (HAL_UART_Init(gt_fk_usart_handle[comport/2]) != HAL_OK)
        {
            Error_Handler();
        }        
        gfunc_fk_uart_tx_func[comport/2]=tx_func;
        gfunc_fk_uart_rx_func[comport/2]=rx_func;         
  }
  
  //**********************************************************************************************************************
  //
  // Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
  //
  //! @fn 	 fk_uart_tx_dma_init
  //
  //! @author 	 dean huang
  //
  //! @date 	 2015/08/04
  //
  //! @brief 	 None
  //
  //! @param 	 None
  //
  //! @return 	 None
  //
  //**********************************************************************************************************************
  void fk_uart_tx_dma_init(UINT8 comport,UINT32 baudrate,UINT16 bits,UINT16 stop_bits,UINT16 parity,UINT8 dma_channel,UINT8 *buf,UINT32 size,void (*func)(void))
  {
      // Initial function complemmently by CubeMX software, so cancel the function in fk_lib, JackyLin //   
  }
  
  
  //**********************************************************************************************************************
  //
  // Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
  //
  //! @fn 	 fk_adc_functions
  //
  //! @author 	 Willman Chen
  //
  //! @date 	 2010/10/25
  //
  //! @brief 	 task function
  //
  //! @param	 None
  //
  //! @return 	 None
  //
  //**********************************************************************************************************************
  void fk_adc_functions(UINT8 set,UINT8 channel,UINT8 dma_channel,UINT8 func_index,UINT8 func_mode,void (*func)(void),UINT16 *buf,UINT32 size)
  {
      // Initial function complemmently by CubeMX software, so cancel the function in fk_lib, JackyLin //   
  }
  
  //**********************************************************************************************************************
  //
  // Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
  //
  //! @fn 	 fk_adc_polling
  //
  //! @author 	 Willman Chen
  //
  //! @date 	 2010/10/25
  //
  //! @brief 	 task function
  //
  //! @param	 None
  //
  //! @return 	 None
  //
  //**********************************************************************************************************************
  UINT16 fk_adc_polling(UINT8 set)
  {
      // Initial function complemmently by CubeMX software, so cancel the function in fk_lib, JackyLin //   
    return 0;
  }
  
  //**********************************************************************************************************************
  //
  // Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
  //
  //! @fn 	 fk_set_dac
  //
  //! @author 	 Willman Chen
  //
  //! @date 	 2010/10/25
  //
  //! @brief 	 task function
  //
  //! @param	 None
  //
  //! @return 	 None
  //
  //**********************************************************************************************************************
  void fk_set_dac(UINT8 channel,UINT32 port,UINT32 pin)
  {
      // Initial function complemmently by CubeMX software, so cancel the function in fk_lib, JackyLin //   
  }
  //**********************************************************************************************************************
  //
  // Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
  //
  //! @fn 	 fk_i2c_init
  //
  //! @author 	 Vic Chen
  //
  //! @date 	 2010/11/16
  //
  //! @brief 	I2C INIT function
  //
  //! @param	 None
  //
  //! @return 	 None
  //
  //**********************************************************************************************************************
  void fk_i2c_init(UINT8 channel,UINT32 speed)
  {
      //hi2c1.Instance = I2C1;
      //hi2c1.Init.ClockSpeed = 100000;
      //hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
      //hi2c1.Init.OwnAddress1 = 0;
      //hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
      //hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
      //hi2c1.Init.OwnAddress2 = 0;
      //hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
      //hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
      //if (HAL_I2C_Init(&hi2c1) != HAL_OK)
      //{
      //  Error_Handler();
      //}    
      // Initial function complemmently by CubeMX software, so cancel the function in fk_lib, JackyLin //   
  }
  
  //**********************************************************************************************************************
  //
  // Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
  //
  //! @fn 	 fk_spi_init
  //
  //! @author 	 Willman Chen
  //
  //! @date 	 2010/12/20
  //
  //! @brief 	 task function
  //
  //! @param	 None
  //
  //! @return 	 None
  //
  //**********************************************************************************************************************
  void fk_spi_init(UINT8 set,UINT8 dma,UINT8 *buf,UINT32 len)
  {
      // Initial function complemmently by CubeMX software, so cancel the function in fk_lib, JackyLin //   
  }
  //**********************************************************************************************************************
  //
  // Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
  //
  //! @fn 	 fk_pvd_enable
  //
  //! @author 	 Willman Chen
  //
  //! @date 	 2010/12/20
  //
  //! @brief 	 task function
  //
  //! @param	 None
  //
  //! @return 	 None
  //
  //**********************************************************************************************************************
  void fk_pvd_enable(UINT32 voltage,void(*func)(void))
  {
      // Initial function complemmently by CubeMX software, so cancel the function in fk_lib, JackyLin //   
  }
  
  
  
  
  //**********************************************************************************************************************
  //
  // Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
  //
  //! @file 		 i2c_io_task.c
  //
  //! @author 	         Roger Chang
  //
  //! @date 		 2010/12/20
  //
  //  @brief 		 fk_i2c_master_receive 
  //
  //**********************************************************************************************************************
  UINT8 fk_i2c_master_receive(UINT8 cmd, UINT8* data,  UINT8 length)
  {
    // This corresponds to i2c_master_recv
    // S Addr Rd [A] [Data] A [Data] A ... A [Data] NA P
    gb_fk_i2c_status_flag = FK_I2C_OK;
    fk_i2c_tx_start();					                        //======	Send START
    fk_i2c_tx_byte((UINT8)(cmd|FK_I2C_IO_READ_CMD_MASK));                             //======	Send Slave Address & Read bit
    fk_i2c_io_rx_ack();					                      //======	Get  ACK  from slave dev
    do                                                        // Decrement RX byte counter
    {        
      length=length-1;
      *(data+length) = fk_i2c_rx_byte();	                      //======	Get  DATA from slave dev
      if (length)
        fk_i2c_io_tx_ack();	                              //======	Send ACK from master dev
      else
        fk_i2c_io_tx_nanack();		    	                  //======	Send NACK from master dev if last Data
    }  while (length);
    fk_i2c_tx_stop();		                                      //======	Send STOP   
    return gb_fk_i2c_status_flag;
  }
  
  //**********************************************************************************************************************
  //
  // Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
  //
  //! @file 		 i2c_io_task.c
  //
  //! @author 	         Roger Chang
  //
  //! @date 		 2010/12/20
  //
  //  @brief 		 fk_i2c_master_send 
  //
  //**********************************************************************************************************************
  UINT8 fk_i2c_master_send( UINT8 cmd, UINT8* data, UINT8 len)
  {
    // This corresponds to i2c_master_send.
    // S Addr Wr [A] Data [A] Data [A] ... [A] Data [A] P 
    gb_fk_i2c_status_flag = FK_I2C_OK;
    fk_i2c_tx_start();		    		        //======	Send START
    fk_i2c_tx_byte(cmd&FK_I2C_IO_WRITE_CMD_MASK); //======	Send Slave Address & Write
    fk_i2c_io_rx_ack();		    			//======	Get  ACK  from slave dev
    do
    {                                       // Decrement TX byte counter
      fk_i2c_tx_byte(data[--len]); 	        //======	Send data
      fk_i2c_io_rx_ack();	                //======	Get  ACK  from slave dev
    } while (len);
    fk_i2c_tx_stop();		                    //======	Send STOP       
    return gb_fk_i2c_status_flag;
  }
  
  //**********************************************************************************************************************
  //
  // Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
  //
  //! @file 		 i2c_io_task.c
  //
  //! @author 	         Roger Chang
  //
  //! @date 		 2010/12/20
  //
  //  @brief 		 fk_i2c_io_rx_ack 
  //
  //**********************************************************************************************************************
  UINT8 fk_i2c_io_rx_ack()
  {	//  assert: scl is low
//    gb_fk_i2c_status_flag = FK_I2C_FAIL;
//    FK_I2C_IO_SET_SDA_IN();        
//#if MCP3421_HAS_DELAY_WITH_EACH_COMMAND == 1
//    fk_i2c_io_delay(FK_I2C_IO_DELAY_TIME);                              //  Set to input 
//#endif
//    for (UINT16 k = 0; k < FK_I2C_IO_DELAY_FOR_ACK; k++)             //  Check ACK (low)
//    {
//      if (!(FK_I2C_IO_CHK_SDA_STATE()))
//      {
//        gb_fk_i2c_status_flag = FK_I2C_OK;
//        break;
//      }
//    }                                                             //SDA?ˆæ”¶?°LO, SCL?å?ä¸€?‹HI, LO
//    FK_I2C_IO_SET_SCL_OUT();
//    FK_I2C_IO_SCL_H();  
//#if MCP3421_HAS_DELAY_WITH_EACH_COMMAND == 1
//    fk_i2c_io_delay(FK_I2C_IO_DELAY_TIME);        
//#endif
//    FK_I2C_IO_SCL_L();         
//#if MCP3421_HAS_DELAY_WITH_EACH_COMMAND == 1
//    fk_i2c_io_delay(FK_I2C_IO_DELAY_TIME);        
//#endif
//    
//    return gb_fk_i2c_status_flag;
    return 0;
  }
  //**********************************************************************************************************************
  //
  // Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
  //
  //! @file 		 i2c_io_task.c
  //
  //! @author 	         Roger Chang
  //
  //! @date 		 2010/12/20
  //
  //  @brief 		 fk_i2c_io_tx_ack 
  //
  //**********************************************************************************************************************
  void fk_i2c_io_tx_ack()
  {	//  assert: scl is low
//    FK_I2C_IO_SET_SDA_OUT();
//    FK_I2C_IO_SET_SCL_OUT();
//    FK_I2C_IO_SDA_L();       
//#if FK_I2C_IO_HAS_DELAY_WITH_EACH_COMMAND == 1
//    fk_i2c_io_delay(FK_I2C_IO_DELAY_TIME);      //  Set to output, data low so SDA = 0
//#endif
//    FK_I2C_IO_SCL_H();
//#if FK_I2C_IO_HAS_DELAY_WITH_EACH_COMMAND == 1
//    fk_i2c_io_delay(FK_I2C_IO_DELAY_TIME);      //  Set to input, SCL = 1 due to pull-up
//#endif
//    FK_I2C_IO_SCL_L();                       //  Set to output, data low so SCL = 0
  }
  //**********************************************************************************************************************
  //
  // Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
  //
  //! @file 		 i2c_io_task.c
  //
  //! @author 	         Roger Chang
  //
  //! @date 		 2010/12/20
  //
  //  @brief 		 fk_i2c_io_tx_nanack 
  //
  //**********************************************************************************************************************
  void fk_i2c_io_tx_nanack()
  {
//    FK_I2C_IO_SET_SDA_OUT();
//    FK_I2C_IO_SET_SCL_OUT();
//    FK_I2C_IO_SDA_H();              
//#if FK_I2C_IO_HAS_DELAY_WITH_EACH_COMMAND == 1
//    fk_i2c_io_delay(FK_I2C_IO_DELAY_TIME);        
//#endif
//    FK_I2C_IO_SCL_H();
//#if FK_I2C_IO_HAS_DELAY_WITH_EACH_COMMAND == 1
//    fk_i2c_io_delay(FK_I2C_IO_DELAY_TIME);        
//#endif
//    FK_I2C_IO_SCL_L();
  }
  //**********************************************************************************************************************
  //
  // Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
  //
  //! @file 		 i2c_io_task.c
  //
  //! @author 	         Roger Chang
  //
  //! @date 		 2010/12/20
  //
  //  @brief 		 fk_i2c_io_rx_nanack 
  //
  //**********************************************************************************************************************
  void fk_i2c_io_rx_nanack()
  {
//    gb_fk_i2c_status_flag = FK_I2C_FAIL;
//    FK_I2C_IO_SET_SDA_IN();
//#if FK_I2C_IO_HAS_DELAY_WITH_EACH_COMMAND == 1
//    fk_i2c_io_delay(FK_I2C_IO_DELAY_TIME);                       //  Set to input
//#endif
//    for (UINT16 k = 0; k < FK_I2C_IO_DELAY_FOR_NACK; k++)     //  Check ACK (low)
//    {
//      if (!(FK_I2C_IO_CHK_SDA_STATE()))
//      {
//        gb_fk_i2c_status_flag = FK_I2C_OK;
//        break;
//      }
//    }                                                      //  After receving low signal from SDA,we need to pass hi signal to SCL
//    FK_I2C_IO_SET_SCL_OUT();
//    FK_I2C_IO_SCL_H();
//#if FK_I2C_IO_HAS_DELAY_WITH_EACH_COMMAND == 1
//    fk_i2c_io_delay(FK_I2C_IO_DELAY_TIME);        
//#endif
//    FK_I2C_IO_SCL_L();
//#if FK_I2C_IO_HAS_DELAY_WITH_EACH_COMMAND == 1
//    fk_i2c_io_delay(FK_I2C_IO_DELAY_TIME);        
//#endif
  }
  //**********************************************************************************************************************
  //
  // Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
  //
  //! @file 		 i2c_io_task.c
  //
  //! @author 	         Roger Chang
  //
  //! @date 		 2010/12/20
  //
  //  @brief 		 fk_i2c_io_delay 
  //
  //**********************************************************************************************************************
#if FK_I2C_IO_HAS_DELAY_WITH_EACH_COMMAND == 1
  void fk_i2c_io_delay(UINT8 data)
  {               
    for (;data>0;data--);  	//  delay to meet I2C spec
  }                                           
#endif
  //**********************************************************************************************************************
  //
  // Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
  //
  //! @file 		 i2c_io_task.c
  //
  //! @author 	         Roger Chang
  //
  //! @date 		 2010/12/20
  //
  //  @brief 		 fk_i2c_tx_start 
  //
  //**********************************************************************************************************************
  void fk_i2c_tx_start()
  {
//    FK_I2C_IO_SET_SDA_OUT();
//    FK_I2C_IO_SET_SCL_OUT();
//    FK_I2C_IO_SDA_H();               
//#if FK_I2C_IO_HAS_DELAY_WITH_EACH_COMMAND == 1
//    fk_i2c_io_delay(FK_I2C_IO_DELAY_TIME);        
//#endif
//    FK_I2C_IO_SCL_H();
//#if FK_I2C_IO_HAS_DELAY_WITH_EACH_COMMAND == 1
//    fk_i2c_io_delay(FK_I2C_IO_DELAY_TIME);        
//#endif
//    FK_I2C_IO_SDA_L() ;
//#if FK_I2C_IO_HAS_DELAY_WITH_EACH_COMMAND == 1
//    fk_i2c_io_delay(FK_I2C_IO_DELAY_TIME);        
//#endif
//    FK_I2C_IO_SCL_L();
//#if FK_I2C_IO_HAS_DELAY_WITH_EACH_COMMAND == 1
//    fk_i2c_io_delay(FK_I2C_IO_DELAY_TIME);        
//#endif
  }
  //**********************************************************************************************************************
  //
  // Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
  //
  //! @file 		 i2c_io_task.c
  //
  //! @author 	         Roger Chang
  //
  //! @date 		 2010/12/20
  //
  //  @brief 		 fk_i2c_tx_stops 
  //
  //**********************************************************************************************************************
  void fk_i2c_tx_stop()
  {	//  assert: scl is low
//    FK_I2C_IO_SET_SDA_OUT();
//    FK_I2C_IO_SET_SCL_OUT();
//    FK_I2C_IO_SCL_H();                
//#if FK_I2C_IO_HAS_DELAY_WITH_EACH_COMMAND == 1
//    fk_i2c_io_delay(FK_I2C_IO_DELAY_TIME);        
//#endif
//    FK_I2C_IO_SDA_H();
//#if FK_I2C_IO_HAS_DELAY_WITH_EACH_COMMAND == 1
//    fk_i2c_io_delay(FK_I2C_IO_DELAY_TIME);        
//#endif
  }
  //**********************************************************************************************************************
  //
  // Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
  //
  //! @file 		 i2c_io_task.c
  //
  //! @author 	         Roger Chang
  //
  //! @date 		 2010/12/20
  //
  //  @brief 		 fk_i2c_tx_byte 
  //
  //**********************************************************************************************************************
  void fk_i2c_tx_byte(UINT8 data)
  {	//  assert: scl is low
//    UINT8 i;
//    FK_I2C_IO_SET_SDA_OUT();
//    FK_I2C_IO_SET_SCL_OUT();
//    for (i = 0; i < FK_I2C_IO_BYTE_BITS; i++)
//    {
//      if ( (data&FK_I2C_IO_BYTE_BIT7) )
//        FK_I2C_IO_SDA_H();
//      else
//        FK_I2C_IO_SDA_L();    
//#if FK_I2C_IO_HAS_DELAY_WITH_EACH_COMMAND == 1
//      fk_i2c_io_delay(FK_I2C_IO_DELAY_TIME);    
//#endif
//      FK_I2C_IO_SCL_H();
//      data <<= 1;
//#if FK_I2C_IO_HAS_DELAY_WITH_EACH_COMMAND == 1
//      fk_i2c_io_delay(FK_I2C_IO_DELAY_TIME);    
//#endif
//      FK_I2C_IO_SCL_L();
//#if FK_I2C_IO_HAS_DELAY_WITH_EACH_COMMAND == 1
//      fk_i2c_io_delay(FK_I2C_IO_DELAY_TIME);    
//#endif
//    }
  }
  //**********************************************************************************************************************
  //
  // Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
  //
  //! @file 		 i2c_io_task.c
  //
  //! @author 	         Roger Chang
  //
  //! @date 		 2010/12/20
  //
  //  @brief 		 fk_i2c_rx_byte 
  //
  //**********************************************************************************************************************
  UINT8 fk_i2c_rx_byte(void)
  {	//  assert: scl is low
//    UINT8 i;
//    UINT8 buf = 0;
//    FK_I2C_IO_SET_SDA_IN();        
//#if FK_I2C_IO_HAS_DELAY_WITH_EACH_COMMAND == 1
//    fk_i2c_io_delay(FK_I2C_IO_DELAY_TIME);        
//#endif
//    for (i = 0; i < FK_I2C_IO_BYTE_BITS; i++)
//    {    
//      buf=((buf<<1)&0xff);           
//      FK_I2C_IO_SCL_H();
//#if FK_I2C_IO_HAS_DELAY_WITH_EACH_COMMAND == 1
//      fk_i2c_io_delay(FK_I2C_IO_DELAY_TIME);    
//#endif
//      if (FK_I2C_IO_CHK_SDA_STATE())
//        buf |= 0x01;
//      FK_I2C_IO_SCL_L();
//#if FK_I2C_IO_HAS_DELAY_WITH_EACH_COMMAND == 1
//      fk_i2c_io_delay(FK_I2C_IO_DELAY_TIME);    
//#endif
//    }
//    return buf;
    return 0;
  }    
  
  //**********************************************************************************************************************
  //
  // Copyright (C) 2011, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
  //
  //! @fn 			 	fk_i2c1_hw_check_timeout_func
  //
  //! @author 	 		Simon Lu
  //
  //! @date 		 		2011/12/01
  //
  //! @brief 		 	i2c byte write function
  //
  //! @param 		 	(?¾ç½®HTBC è¨ˆæ•¸Timeout)
  //
  //! @return 			None
  //
  //**********************************************************************************************************************
  void fk_i2c1_hw_check_timeout_func(void)
  {
   ////===(Simon MCP3422 Timeout check)
   //if(gb_fk_i2c1_hw_time_out_sw == 1)
   //{
   //  gb_fk_i2c1_hw_time_out_counter++;
   //  gb_fk_i2c1_hw_time_out_counter &= 0xFFFF;
   //}
  }
  
  //**********************************************************************************************************************
  //
  // Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
  //
  //! @fn 			 	iic_hw_task
  //
  //! @author 	 		Simon Lu
  //
  //! @date 		 		2011.12.12
  //
  //! @brief 		 	task function
  //
  //! @param 		 	None
  //
  //! @return 	 		None
  //
  //**********************************************************************************************************************
  UINT8 fk_i2c1_hw_timeout_check(void)
  {
    ////===(Only do once)
    //if(0 == gb_fk_i2c1_hw_repeat_flag)
    //{
    //  //===(Strat timeout switch in HTBC)
    //  gb_fk_i2c1_hw_time_out_sw 		= 1;
    //  gb_fk_i2c1_hw_repeat_flag 		= 1;
    //}
    //
    ////===(20ms timeout check)
    //if(gb_fk_i2c1_hw_time_out_counter >= 10)
    //{
    //  gb_fk_i2c1_hw_time_out_sw 		= 0;
    //  gb_fk_i2c1_hw_time_out_counter	= 0;
    //  gb_fk_i2c1_hw_repeat_flag 		= 0;
    //  return 0;
    //}
    return 1;
  }   
  
#ifdef __cplusplus
}
#endif

