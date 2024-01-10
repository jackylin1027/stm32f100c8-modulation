#ifndef LED_DRV_H
#define LED_DRV_H
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
//! @file 		 led_drv.h
//
//! @author 	 Jacky Lin
//
//! @date 		 2023/06/09
//
//  @brief 		 Here declare driver function
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S 
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I / O   P O R T   D E F I N I T I O N 
//
//**********************************************************************************************************************
//=================== Difination below for eph-transmitter specicificion connect to only one eph-watermeter  
#define LED_POWER_PORT                          FK_PORTB                                      
#define LED_POWER_PIN                           FK_PIN0
#define LED_POWER_HIGH()                        FK_SET_OUTPUT_PIN_HIGH_API(LED_POWER_PORT,LED_POWER_PIN)
#define LED_POWER_LOW()                         FK_SET_OUTPUT_PIN_LOW_API(LED_POWER_PORT,LED_POWER_PIN)
#define LED_POWER_TOGGLE()                      FK_SET_OUTPUT_PIN_TOGGLE_API(LED_POWER_PORT,LED_POWER_PIN)  
#define LED_TRANSMITTER_PORT                    FK_PORTB                                      
#define LED_TRANSMITTER_PIN                     FK_PIN1
#define LED_TRANSMITTER_HIGH()                  FK_SET_OUTPUT_PIN_HIGH_API(LED_TRANSMITTER_PORT,LED_TRANSMITTER_PIN)
#define LED_TRANSMITTER_LOW()                   FK_SET_OUTPUT_PIN_LOW_API(LED_TRANSMITTER_PORT,LED_TRANSMITTER_PIN)
#define LED_TRANSMITTER_TOGGLE()                FK_SET_OUTPUT_PIN_TOGGLE_API(LED_TRANSMITTER_PORT,LED_TRANSMITTER_PIN)  
#define LED_RESPONSE_CHANNEL1_PORT              FK_PORTC                                      
#define LED_RESPONSE_CHANNEL1_PIN               FK_PIN10
#define LED_RESPONSE_CHANNEL1_HIGH()            FK_SET_OUTPUT_PIN_HIGH_API(LED_RESPONSE_CHANNEL1_PORT,LED_RESPONSE_CHANNEL1_PIN)
#define LED_RESPONSE_CHANNEL1_LOW()             FK_SET_OUTPUT_PIN_LOW_API(LED_RESPONSE_CHANNEL1_PORT,LED_RESPONSE_CHANNEL1_PIN)    
#define LED_RESPONSE_CHANNEL1_TOGGLE()          FK_SET_OUTPUT_PIN_TOGGLE_API(LED_RESPONSE_CHANNEL1_PORT,LED_RESPONSE_CHANNEL1_PIN)  
#define LED_RESPONSE_CHANNEL2_PORT              FK_PORTC                                      
#define LED_RESPONSE_CHANNEL2_PIN               FK_PIN11
#define LED_RESPONSE_CHANNEL2_HIGH()            FK_SET_OUTPUT_PIN_HIGH_API(LED_RESPONSE_CHANNEL2_PORT,LED_RESPONSE_CHANNEL2_PIN)
#define LED_RESPONSE_CHANNEL2_LOW()             FK_SET_OUTPUT_PIN_LOW_API(LED_RESPONSE_CHANNEL2_PORT,LED_RESPONSE_CHANNEL2_PIN)    
#define LED_RESPONSE_CHANNEL2_TOGGLE()          FK_SET_OUTPUT_PIN_TOGGLE_API(LED_RESPONSE_CHANNEL2_PORT,LED_RESPONSE_CHANNEL2_PIN)    
#define LED_RESPONSE_CHANNEL3_PORT              FK_PORTC                                      
#define LED_RESPONSE_CHANNEL3_PIN               FK_PIN12
#define LED_RESPONSE_CHANNEL3_HIGH()            FK_SET_OUTPUT_PIN_HIGH_API(LED_RESPONSE_CHANNEL3_PORT,LED_RESPONSE_CHANNEL3_PIN)
#define LED_RESPONSE_CHANNEL3_LOW()             FK_SET_OUTPUT_PIN_LOW_API(LED_RESPONSE_CHANNEL3_PORT,LED_RESPONSE_CHANNEL3_PIN)    
#define LED_RESPONSE_CHANNEL3_TOGGLE()          FK_SET_OUTPUT_PIN_TOGGLE_API(LED_RESPONSE_CHANNEL3_PORT,LED_RESPONSE_CHANNEL3_PIN)      
#define LED_RESPONSE_CHANNEL4_PORT              FK_PORTB                                      
#define LED_RESPONSE_CHANNEL4_PIN               FK_PIN6
#define LED_RESPONSE_CHANNEL4_HIGH()            FK_SET_OUTPUT_PIN_HIGH_API(LED_RESPONSE_CHANNEL4_PORT,LED_RESPONSE_CHANNEL4_PIN)
#define LED_RESPONSE_CHANNEL4_LOW()             FK_SET_OUTPUT_PIN_LOW_API(LED_RESPONSE_CHANNEL4_PORT,LED_RESPONSE_CHANNEL4_PIN)  
#define LED_RESPONSE_CHANNEL4_TOGGLE()          FK_SET_OUTPUT_PIN_TOGGLE_API(LED_RESPONSE_CHANNEL4_PORT,LED_RESPONSE_CHANNEL4_PIN)  
#define LED_RESPONSE_CHANNEL5_PORT              FK_PORTB                                      
#define LED_RESPONSE_CHANNEL5_PIN               FK_PIN5
#define LED_RESPONSE_CHANNEL5_HIGH()            FK_SET_OUTPUT_PIN_HIGH_API(LED_RESPONSE_CHANNEL5_PORT,LED_RESPONSE_CHANNEL5_PIN)
#define LED_RESPONSE_CHANNEL5_LOW()             FK_SET_OUTPUT_PIN_LOW_API(LED_RESPONSE_CHANNEL5_PORT,LED_RESPONSE_CHANNEL5_PIN)  
#define LED_RESPONSE_CHANNEL5_TOGGLE()          FK_SET_OUTPUT_PIN_TOGGLE_API(LED_RESPONSE_CHANNEL5_PORT,LED_RESPONSE_CHANNEL5_PIN)    
#define LED_RESPONSE_CHANNEL6_PORT              FK_PORTC                                      
#define LED_RESPONSE_CHANNEL6_PIN               FK_PIN13
#define LED_RESPONSE_CHANNEL6_HIGH()            FK_SET_OUTPUT_PIN_HIGH_API(LED_RESPONSE_CHANNEL6_PORT,LED_RESPONSE_CHANNEL6_PIN)
#define LED_RESPONSE_CHANNEL6_LOW()             FK_SET_OUTPUT_PIN_LOW_API(LED_RESPONSE_CHANNEL6_PORT,LED_RESPONSE_CHANNEL6_PIN)  
#define LED_RESPONSE_CHANNEL6_TOGGLE()          FK_SET_OUTPUT_PIN_TOGGLE_API(LED_RESPONSE_CHANNEL6_PORT,LED_RESPONSE_CHANNEL6_PIN)     
#define LED_RESPONSE_CHANNEL7_PORT              FK_PORTC                                      
#define LED_RESPONSE_CHANNEL7_PIN               FK_PIN8
#define LED_RESPONSE_CHANNEL7_HIGH()            FK_SET_OUTPUT_PIN_HIGH_API(LED_RESPONSE_CHANNEL7_PORT,LED_RESPONSE_CHANNEL7_PIN)
#define LED_RESPONSE_CHANNEL7_LOW()             FK_SET_OUTPUT_PIN_LOW_API(LED_RESPONSE_CHANNEL7_PORT,LED_RESPONSE_CHANNEL7_PIN)  
#define LED_RESPONSE_CHANNEL7_TOGGLE()          FK_SET_OUTPUT_PIN_TOGGLE_API(LED_RESPONSE_CHANNEL7_PORT,LED_RESPONSE_CHANNEL7_PIN)      
#define LED_RESPONSE_CHANNEL8_PORT              FK_PORTC                                      
#define LED_RESPONSE_CHANNEL8_PIN               FK_PIN9
#define LED_RESPONSE_CHANNEL8_HIGH()            FK_SET_OUTPUT_PIN_HIGH_API(LED_RESPONSE_CHANNEL8_PORT,LED_RESPONSE_CHANNEL8_PIN)
#define LED_RESPONSE_CHANNEL8_LOW()             FK_SET_OUTPUT_PIN_LOW_API(LED_RESPONSE_CHANNEL8_PORT,LED_RESPONSE_CHANNEL8_PIN)  
#define LED_RESPONSE_CHANNEL8_TOGGLE()          FK_SET_OUTPUT_PIN_TOGGLE_API(LED_RESPONSE_CHANNEL8_PORT,LED_RESPONSE_CHANNEL8_PIN)    
//**********************************************************************************************************************
//
// M A C R O   D E F I N I T I O N 
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S 
//
//**********************************************************************************************************************
void led_sfr_init();
//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N 
//
//**********************************************************************************************************************
#ifdef __cplusplus
}
#endif
#endif		// LED_DRV_H 
