/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "fk/fk_udef.h"
#include "hbtc/hbtc_udef.h"
#include "modbus_slave/modbus_slave_udef.h"
#include "pfc/pfc_udef.h"
#include "crc/crc_udef.h"  
#include "btc/btc_udef.h"  
#include "fn/fn_udef.h"
#include "math.h"
#include "string.h"
#include "stdio.h"  
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define RS485_EN_Pin GPIO_PIN_1
#define RS485_EN_GPIO_Port GPIOA
#define ADC_RDY_Pin GPIO_PIN_12
#define ADC_RDY_GPIO_Port GPIOB
#define ADC_RDY_EXTI_IRQn EXTI15_10_IRQn
#define AO_SYNC_Pin GPIO_PIN_8
#define AO_SYNC_GPIO_Port GPIOA
#define SYNC2_Pin GPIO_PIN_9
#define SYNC2_GPIO_Port GPIOA
#define HEAT_CLK_Pin GPIO_PIN_11
#define HEAT_CLK_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */
#define IGNORE_CUBEMX_CREATE            1
#define MAIN_USE_UIF                    0
#define MAIN_USE_KEY                    0
#define MAIN_USE_LED                    0
#if MAIN_USE_KEY == 1
    #include "key/key_udef.h" 
#endif

#if MAIN_USE_UIF == 1
    #include "uif/uif_udef.h" 
    #include "udm/udm_udef.h" 
    #include "gdm/gdm_udef.h" 
    #include "st7565/st7565_udef.h" 
#endif
#if MAIN_USE_LED == 1
#include "led/led_udef.h"
#endif

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
