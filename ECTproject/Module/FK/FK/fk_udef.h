#ifndef FK_UDEF_H
#define FK_UDEF_H
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
//! @file 	 fk_udef.h
//
//! @author 	 Jacky Lin
//
//! @date 	 2024/01/10
//
//  @brief	 Here define all API
//
//**********************************************************************************************************************
#define UINT8                                         	unsigned char
#define INT8                                          	char
#define UINT16                                        	unsigned short int
#define INT16                                         	short int
#define UINT32                                        	unsigned int
#define INT32                                         	int
#define UINT64                                        	unsigned long long
#define INT64                                         	long long
#define FLOAT32                                       	float
#define FLOAT64                                       	double
#include "..\Inc\main.h"
//**********************************************************************************************************************
//
// E X T E R N A L   G L O B A L   C O N S T A N C E   /   V A R I A B L E S   I N   E E P R O M
//
//**********************************************************************************************************************
// Version Definition
#define FK_VERSION                                      "STM32100_FC_V01"
// Clock Definition
#if MAIN_USE_LSI == 1
#define FK_SUB_CLOCK                                    40000  
#else
#define FK_SUB_CLOCK                                    32768
#endif

#define FK_EXTERNAL_OSC_CLOCK                           8000000
#define FK_GPIO_SPEED                                   GPIO_SPEED_FREQ_MEDIUM

#define FK_TRIGGER_RASING			        GPIO_MODE_IT_RISING
#define FK_TRIGGER_FALLING			        GPIO_MODE_IT_FALLING
#define FK_TRIGGER_RASING_FALLING		        GPIO_MODE_IT_RISING_FALLING

#define FK_UART_8BITS_MODE				USART_WordLength_8b
#define FK_UART_9BITS_MODE				USART_WordLength_9b
#define FK_UART_ONE_STOP_BIT			        USART_StopBits_1
#define FK_UART_TWO_STOP_BITS			        USART_StopBits_2
#define FK_UART_PARITY_NONE			        USART_Parity_No
#define FK_UART_PARITY_EVEN			        USART_Parity_Even
#define FK_UART_PARITY_ODD			        USART_Parity_Odd

#define FK_MODBUS_ASCII_MODE		                0
#define FK_MODBUS_RTU_MODE			        1
  
#define FK_I2C_CH1				        I2C1
#define FK_I2C_CH2				        I2C2

// Interrupt Priority Definition
    enum FK_INTERRUPT_PRIORITY
    {
        FK_WWDG_PRIORITY,
        FK_PVD_PRIORITY,
        FK_TAMPER_PRIORITY,
        FK_UART1_PRIORITY,
        FK_UART2_PRIORITY,
        FK_UART3_PRIORITY,     
        FK_TIM4_PRIORITY,
        FK_TIM2_PRIORITY,
        FK_RTC_ALARM_PRIORITY,
        FK_RTC_PRIORITY,
        FK_FLASH_PRIORITY,
        FK_RCC_PRIORITY,
        FK_TIM1_CC_PRIORITY,
        FK_TIM1_BRK_PRIORITY,
        FK_TIM1_UP_PRIORITY,
        FK_TIM1_TRG_COM_PRIORITY,        
        FK_TIM3_PRIORITY,        
        FK_EXTI0_PRIORITY,
        FK_EXTI1_PRIORITY,
        FK_EXTI2_PRIORITY,
        FK_EXTI3_PRIORITY,
        FK_EXTI4_PRIORITY,
        FK_EXTI9_5_PRIORITY,
        FK_EXTI15_10_PRIORITY,
        FK_ADC1_2_PRIORITY,
        FK_I2C1_EV_PRIORITY,
        FK_I2C1_ER_PRIORITY,
        FK_I2C2_EV_PRIORITY,
        FK_I2C2_ER_PRIORITY,
        FK_SPI1_PRIORITY,
        FK_SPI2__PRIORITY,
        FK_OTG_FS_WAKUP__PRIORITY,    
        FK_TIM6_PRIORITY,
        FK_TIM7_PRIORITY,
        FK_DMA1_CHANNEL1_PRIORITY,
        FK_DMA1_CHANNEL2_PRIORITY,
        FK_DMA1_CHANNEL3_PRIORITY,
        FK_DMA1_CHANNEL4_PRIORITY,
        FK_DMA1_CHANNEL5_PRIORITY,
        FK_DMA1_CHANNEL6_PRIORITY,
        FK_DMA1_CHANNEL7_PRIORITY,        
        FK_ETH_PRIORITY,
        FK_ETH_WAKUP_PRIORITY,
        FK_OTG_FS_PRIORITY,
        FK_INTERRUPT_PRIORITY_TOTAL,
    } ;
   
#define FK_ADC1_DMA_CHANNEL					FK_DMA_CHANNEL1
#define FK_SPI1_RX_DMA_CHANNEL				FK_DMA_CHANNEL2
#define FK_SPI1_TX_DMA_CHANNEL				FK_DMA_CHANNEL3
#define FK_SPI2_RX_DMA_CHANNEL				FK_DMA_CHANNEL4
#define FK_SPI2_TX_DMA_CHANNEL				FK_DMA_CHANNEL5
#define FK_I2C2_TX_DMA_CHANNEL				FK_DMA_CHANNEL4
#define FK_I2C2_RX_DMA_CHANNEL				FK_DMA_CHANNEL5
#define FK_I2C1_TX_DMA_CHANNEL				FK_DMA_CHANNEL6
#define FK_I2C1_RX_DMA_CHANNEL				FK_DMA_CHANNEL7
#define FK_ADC3_DMA_CHANNEL					FK_DMA_CHANNEL12    
    
    enum
    {
        FK_TIMER_CHANNEL1,
        FK_TIMER_CHANNEL2,
        FK_TIMER_CHANNEL3,
        FK_TIMER_CHANNEL4,
    };

#define FK_FALLING_EDGE                TIM_ICPolarity_Falling
#define FK_RASING_EDGE                 TIM_ICPolarity_Rising
#define FK_BOTH_EDGE                   TIM_ICPolarity_BothEdge
    
    

//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "..\Inc\main.h"
#include "c_src\fk_idef.h"
#include "c_src\fk_init.h"
#include "c_src\fk_task.h"
#include "c_src\fk_glb_vars.h" 
#include "fk_adc_udef.h"    
#include "fk_dac_udef.h"   
#include "fk_dma_udef.h"   
#include "fk_flash_udef.h"   
#include "fk_gpio_udef.h"   
#include "fk_i2c_udef.h"       
#include "fk_nvic_udef.h"   
#include "fk_power_udef.h"   
#include "fk_rtc_udef.h"   
#include "fk_spi_udef.h"       
#include "fk_system_udef.h"   
#include "fk_timer_udef.h"   
#include "fk_uart_udef.h"       
#include "fk_watch_dog_udef.h"   
//**********************************************************************************************************************
//
// C O N D I C T I O N   C O M P I L E
//
//**********************************************************************************************************************
// Version Definition
#define FK_M3_FLASH_START		        0x8000000
#define	FK_FLASH_SIZE           		(64*1024)
#define FK_FLASH_PAGE_SIZE    		        ((uint16_t)0x400)
   
#define FK_TOTAL_PAGE           	         (FK_FLASH_SIZE/FK_FLASH_PAGE_SIZE)
#define FK_NEED_PAGE            	         1       
#define FK_USER_START_PAGE      	         (FK_TOTAL_PAGE-2*FK_NEED_PAGE)
#define FK_FACTORY_START_PAGE   	         (FK_USER_START_PAGE+FK_NEED_PAGE)
//**********************************************************************************************************************
//
// A P I   F O R   O T H E R   M O D U L E S
//
//**********************************************************************************************************************
// CRC
//! @brief The API for getting CRC result by hardware computting.
#define FK_GET_CRC_VALUE_API(data,size)                                         fk_get_crc((UINT32*)data,size)
//**********************************************************************************************************************
//
// A P I   C A L L   F R O M   O T H E R   M O D U L E S
//
//**********************************************************************************************************************
#define FK_ENABLE_CRC_API()                                                     RCC_AHBPeriphClockCmd(RCC_AHBPeriph_CRC, ENABLE)
#define FK_DISABLE_CRC_API()                                                    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_CRC, DISABLE)
//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S
//
//**********************************************************************************************************************

//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N
//
//**********************************************************************************************************************
#ifdef __cplusplus
}
#endif
#endif		// FK_UDEF_H 
