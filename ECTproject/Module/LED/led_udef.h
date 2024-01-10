#ifndef LED_UDEF_H
#define LED_UDEF_H
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
//! @file 		 led_udef.h
//
//! @author 	 Jacky Lin
//
//! @date 		 2023/06/09
//
//  @brief 		 Here define all API
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// E X T E R N A L   G L O B A L   C O N S T A N C E   /   V A R I A B L E S   I N   E E P R O M 
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// C O N D I C T I O N   C O M P I L E 
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S 
//
//**********************************************************************************************************************
#include "..\fk\fk_udef.h"
#include "..\crc\crc_udef.h"
#include "..\hbtc\hbtc_udef.h"
#include "..\pfc\pfc_udef.h"
#include "..\Inc\main.h"    
#include "c_src/led_init.h"
#include "c_src\led_glb_vars.h"
#include "c_src\led_task.h"
enum LED_INSTANCES
{
    LED_INSTANCE_POWER,
    LED_INSTANCE_TRANSMITTER,
    LED_INSTANCE_RESPONSE_CHANNEL1,
    LED_INSTANCE_RESPONSE_CHANNEL2,
    LED_INSTANCE_RESPONSE_CHANNEL3,
    LED_INSTANCE_RESPONSE_CHANNEL4,
    LED_INSTANCE_RESPONSE_CHANNEL5,
    LED_INSTANCE_RESPONSE_CHANNEL6,
    LED_INSTANCE_RESPONSE_CHANNEL7,
    LED_INSTANCE_RESPONSE_CHANNEL8,
    LED_INSTANCE_TOTAL,
};  

enum LED_BEHAVIOUS
{
    LED_BEHAVIOUS_DARK,
    LED_BEHAVIOUS_BRIGHT_AFTER_DELAY,
    LED_BEHAVIOUS_BRIGHT_AFTER_DELAY_WITH_REPEAT,
    LED_BEHAVIOUS_RESPONSE_CHANNEL2,
    LED_BEHAVIOUS_RESPONSE_CHANNEL3,
    LED_BEHAVIOUS_RESPONSE_CHANNEL4,
    LED_BEHAVIOUS_RESPONSE_CHANNEL5,
    LED_BEHAVIOUS_RESPONSE_CHANNEL6,
    LED_BEHAVIOUS_RESPONSE_CHANNEL7,
    LED_BEHAVIOUS_RESPONSE_CHANNEL8,
    LED_BEHAVIOUS_TOTAL,
};  
//**********************************************************************************************************************
//
// A P I   F O R   O T H E R   M O D U L E S 
//
//**********************************************************************************************************************
#define	LED_INIT_API()		                led_init()
#define LED_TASK_API()                          led_task()
//**********************************************************************************************************************
//
// A P I   C A L L   F R O M   O T H E R   M O D U L E S 
//
//**********************************************************************************************************************
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
#endif		// LED_UDEF_H 
