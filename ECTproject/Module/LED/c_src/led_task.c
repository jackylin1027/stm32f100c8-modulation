//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 led_task.c
//
//! @author 	 Jacky Lin
//
//! @date 		 2023/06/09
//
//  @brief 		 Task Subroutine
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S 
//
//**********************************************************************************************************************
#include "..\drv_src\led_drv.h" 
#include "led_glb_vars.h"
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
//! @fn 			 led_take_effect_high
//
//! @author 	 Jacky Lin
//
//! @date 		 2023/06/09
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************   
  void led_take_effect_high(UINT8 index)
  {
      switch(index)
      {
        case LED_INSTANCE_POWER: LED_POWER_HIGH(); break;
        case LED_INSTANCE_TRANSMITTER: LED_TRANSMITTER_HIGH(); break;
        case LED_INSTANCE_RESPONSE_CHANNEL1: LED_RESPONSE_CHANNEL1_HIGH(); break;
        case LED_INSTANCE_RESPONSE_CHANNEL2: LED_RESPONSE_CHANNEL2_HIGH(); break;
        case LED_INSTANCE_RESPONSE_CHANNEL3: LED_RESPONSE_CHANNEL3_HIGH(); break;
        case LED_INSTANCE_RESPONSE_CHANNEL4: LED_RESPONSE_CHANNEL4_HIGH(); break;
        case LED_INSTANCE_RESPONSE_CHANNEL5: LED_RESPONSE_CHANNEL5_HIGH(); break;
        case LED_INSTANCE_RESPONSE_CHANNEL6: LED_RESPONSE_CHANNEL6_HIGH(); break;
        case LED_INSTANCE_RESPONSE_CHANNEL7: LED_RESPONSE_CHANNEL7_HIGH(); break;
        case LED_INSTANCE_RESPONSE_CHANNEL8: LED_RESPONSE_CHANNEL8_HIGH(); break;
      }
  }
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 led_take_effect_low
//
//! @author 	 Jacky Lin
//
//! @date 		 2023/06/09
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************   
  void led_take_effect_low(UINT8 index)
  {
      switch(index)
      {
        case LED_INSTANCE_POWER: LED_POWER_LOW(); break;
        case LED_INSTANCE_TRANSMITTER: LED_TRANSMITTER_LOW(); break;
        case LED_INSTANCE_RESPONSE_CHANNEL1: LED_RESPONSE_CHANNEL1_LOW(); break;
        case LED_INSTANCE_RESPONSE_CHANNEL2: LED_RESPONSE_CHANNEL2_LOW(); break;
        case LED_INSTANCE_RESPONSE_CHANNEL3: LED_RESPONSE_CHANNEL3_LOW(); break;
        case LED_INSTANCE_RESPONSE_CHANNEL4: LED_RESPONSE_CHANNEL4_LOW(); break;
        case LED_INSTANCE_RESPONSE_CHANNEL5: LED_RESPONSE_CHANNEL5_LOW(); break;
        case LED_INSTANCE_RESPONSE_CHANNEL6: LED_RESPONSE_CHANNEL6_LOW(); break;
        case LED_INSTANCE_RESPONSE_CHANNEL7: LED_RESPONSE_CHANNEL7_LOW(); break;
        case LED_INSTANCE_RESPONSE_CHANNEL8: LED_RESPONSE_CHANNEL8_LOW(); break;
      }
  }  
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 led_take_effect_low
//
//! @author 	 Jacky Lin
//
//! @date 		 2023/06/09
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************   
  void led_take_effect_toggle(UINT8 index)
  {
      switch(index)
      {
        case LED_INSTANCE_POWER: LED_POWER_TOGGLE(); break;
        case LED_INSTANCE_TRANSMITTER: LED_TRANSMITTER_TOGGLE(); break;
        case LED_INSTANCE_RESPONSE_CHANNEL1: LED_RESPONSE_CHANNEL1_TOGGLE(); break;
        case LED_INSTANCE_RESPONSE_CHANNEL2: LED_RESPONSE_CHANNEL2_TOGGLE(); break;
        case LED_INSTANCE_RESPONSE_CHANNEL3: LED_RESPONSE_CHANNEL3_TOGGLE(); break;
        case LED_INSTANCE_RESPONSE_CHANNEL4: LED_RESPONSE_CHANNEL4_TOGGLE(); break;
        case LED_INSTANCE_RESPONSE_CHANNEL5: LED_RESPONSE_CHANNEL5_TOGGLE(); break;
        case LED_INSTANCE_RESPONSE_CHANNEL6: LED_RESPONSE_CHANNEL6_TOGGLE(); break;
        case LED_INSTANCE_RESPONSE_CHANNEL7: LED_RESPONSE_CHANNEL7_TOGGLE(); break;
        case LED_INSTANCE_RESPONSE_CHANNEL8: LED_RESPONSE_CHANNEL8_TOGGLE(); break;
      }
  }    
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 led_task
//
//! @author 	 Jacky Lin
//
//! @date 		 2023/06/09
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************  
void led_set_activity(UINT8 index, UINT8 behavior, UINT16 delay)
{
    STC_LED_INFO* info = (STC_LED_INFO *)&gs_led_info[index];
    info->behavior=behavior;
    info->delay_times=delay;
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 led_task
//
//! @author 	 Jacky Lin
//
//! @date 		 2023/06/09
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void led_task()
{
    STC_LED_INFO* info = (STC_LED_INFO *)&gs_led_info[0];
    for(UINT8 i=0;i<LED_MAX_NUM;i++,info++)
    {       
        
        if(info->behavior==LED_BEHAVIOUS_BRIGHT_AFTER_DELAY)
        {
            if((--info->delay_times)<=0)
            {
                info->repeat_times=0;
                info->delay_times=0;
                led_take_effect_high(i);
            }
        }
        if(info->behavior==LED_BEHAVIOUS_BRIGHT_AFTER_DELAY_WITH_REPEAT)
        {
            if((--info->delay_times)<=0)
            {
                if(++info->repeat_times>=10)
                {
                    led_take_effect_low(i);
                    info->repeat_times=0;
                    info->behavior=0;
                    info->delay_times=0;
                }
                else
                {
                    led_take_effect_toggle(i);
                }
            }
        }      
    }
    
}
#ifdef __cplusplus
}
#endif

