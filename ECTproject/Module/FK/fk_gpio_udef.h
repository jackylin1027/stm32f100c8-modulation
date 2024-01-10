#ifndef FK_GPIO_UDEF_H
#define FK_GPIO_UDEF_H
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
// E X T E R N A L   G L O B A L   C O N S T A N C E   /   V A R I A B L E S   I N   E E P R O M
//
//**********************************************************************************************************************

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
//**********************************************************************************************************************
//
// C O N D I C T I O N   C O M P I L E
//
//**********************************************************************************************************************
// GPIO Pin Definition
#define FK_PORTA                                      	GPIOA
#define FK_PORTB                                      	GPIOB
#define FK_PORTC                                      	GPIOC
#define FK_PORTD                                      	GPIOD
#define FK_PORTE                                      	GPIOE
#define FK_PORT_TOTAL                                   5

#define FK_PIN0	                                      	GPIO_PIN_0 
#define FK_PIN1	                                      	GPIO_PIN_1 
#define FK_PIN2	                                      	GPIO_PIN_2 
#define FK_PIN3	                                      	GPIO_PIN_3 
#define FK_PIN4	                                      	GPIO_PIN_4 
#define FK_PIN5	                                      	GPIO_PIN_5 
#define FK_PIN6	                                      	GPIO_PIN_6 
#define FK_PIN7	                                      	GPIO_PIN_7 
#define FK_PIN8	                                      	GPIO_PIN_8 
#define FK_PIN9	                                      	GPIO_PIN_9 
#define FK_PIN10	                              	GPIO_PIN_10
#define FK_PIN11	                              	GPIO_PIN_11
#define FK_PIN12	                              	GPIO_PIN_12
#define FK_PIN13	                              	GPIO_PIN_13
#define FK_PIN14	                              	GPIO_PIN_14
#define FK_PIN15	                              	GPIO_PIN_15
#define FK_ALLPIN	                                GPIO_PIN_All
#define FK_PIN_TOTAL									16

/** @defgroup GPIO_speed_define Speed definition
  * @brief GPIO Output Maximum frequency
  * @{ 
  *     GPIO_SPEED_FREQ_LOW              ((uint32_t)0x00000000U)  !< range up to 0.4 MHz, please refer to the product datasheet 
  *     GPIO_SPEED_FREQ_MEDIUM           ((uint32_t)0x00000001U)  !< range 0.4 MHz to 2 MHz, please refer to the product datasheet 
  *     GPIO_SPEED_FREQ_HIGH             ((uint32_t)0x00000002U)  !< range   2 MHz to 10 MHz, please refer to the product datasheet 
  *     GPIO_SPEED_FREQ_VERY_HIGH        ((uint32_t)0x00000003U)  !< range  10 MHz to 35 MHz, please refer to the product datasheet 
  * @}
  */   
#define FK_GPIO_SPEED_LOW                               GPIO_SPEED_FREQ_LOW 
#define FK_GPIO_SPEED_MEDIUM                            GPIO_SPEED_FREQ_MEDIUM
#define FK_GPIO_SPEED_HIGH                              GPIO_SPEED_FREQ_HIGH
#define FK_GPIO_SPEED_VERY_HIGH                         GPIO_SPEED_FREQ_VERY_HIGH  
/** @defgroup GPIO_mode_define Mode definition
  * @brief GPIO Configuration Mode 
  *        Elements values convention: 0xX0yz00YZ
  *           - X  : GPIO mode or EXTI Mode
  *           - y  : External IT or Event trigger detection 
  *           - z  : IO configuration on External IT or Event
  *           - Y  : Output type (Push Pull or Open Drain)
  *           - Z  : IO Direction mode (Input, Output, Alternate or Analog)
  * @{
  */    
#define FK_GPIO_MODE_INPUT                      GPIO_MODE_INPUT                        /*!< Input Floating Mode                   */
#define FK_GPIO_MODE_OUTPUT_PP                  GPIO_MODE_OUTPUT_PP                    /*!< Output Push Pull Mode                 */
#define FK_GPIO_MODE_OUPTUT_OD                  GPIO_MODE_OUTPUT_OD                    /*!< Output Open Drain Mode                */
#define FK_GPIO_MODE_AF_PP                      GPIO_MODE_AF_PP                        /*!< Alternate Function Push Pull Mode     */
#define FK_GPIO_MODE_AF_OD                      GPIO_MODE_AF_OD                        /*!< Alternate Function Open Drain Mode    */

#define FK_GPIO_MODE_ANALOG                     GPIO_MODE_ANALOG                       /*!< Analog Mode  */
    
#define FK_GPIO_MODE_INTERRUPT_RISING           GPIO_MODE_IT_RISING                    /*!< External Interrupt Mode with Rising edge trigger detection          */
#define FK_GPIO_MODE_INTERRUPT_FALLING          GPIO_MODE_IT_FALLING                   /*!< External Interrupt Mode with Falling edge trigger detection         */
#define FK_GPIO_MODE_INTERRUPT_RISING_FALLING   GPIO_MODE_IT_RISING_FALLING            /*!< External Interrupt Mode with Rising/Falling edge trigger detection  */
 
#define FK_GPIO_MODE_EVENT_RISING               GPIO_MODE_EVT_RISING                   /*!< External Event Mode with Rising edge trigger detection               */
#define FK_GPIO_MODE_EVENT_FALLING              GPIO_MODE_EVT_FALLING                  /*!< External Event Mode with Falling edge trigger detection              */
#define FK_GPIO_MODE_EVENT_RISING_FALLING       GPIO_MODE_EVT_RISING_FALLING           /*!< External Event Mode with Rising/Falling edge trigger detection       */

 /** @defgroup GPIO_pull_define Pull definition
   * @brief GPIO Pull-Up or Pull-Down Activation
   * @{
   */  
  
#define FK_GPIO_PULL_NO                         GPIO_NOPULL                             /*!< No Pull-up or Pull-down activation  */
#define FK_GPIO_PULL_UP                         GPIO_PULLUP                             /*!< Pull-up activation                  */
#define FK_GPIO_PULL_DOWN                       GPIO_PULLDOWN                           /*!< Pull-down activation                */    
//**********************************************************************************************************************
//
// A P I   F O R   O T H E R   M O D U L E S
//
//**********************************************************************************************************************
// GPIO Function
//===(GPIO的速度是指I/O驅動電路的速度而不是輸出訊號的速度,輸出訊號的速度取決於使用者的需求與程序)
//! @brief Setting I/O pin as output ( Push Pump Mode : 25mA max ,I/O Speed: as FK_GPIO_SPEED )
#define FK_SET_PIN_OUPUT_PUSH_PUMP_API(port,pin)                     	        fk_set_io((UINT32)port,pin,FK_GPIO_SPEED_MEDIUM,FK_GPIO_MODE_OUTPUT_PP,FK_GPIO_PULL_UP)
//! @brief Setting I/O pin as output ( Push Pump Mode : 25mA max ,I/O Speed: as FK_GPIO_SPEED )
#define FK_SET_PIN_OUPUT_PUSH_PUMP_HIGH_SPEED_API(port,pin)                     fk_set_io((UINT32)port,pin,FK_GPIO_SPEED_HIGH,FK_GPIO_MODE_OUTPUT_PP,FK_GPIO_PULL_UP)
  
////! @brief Setting I/O pin as output ( Push Pump Mode : 25mA max ,I/O Speed: 50MHz )
//#define FK_SET_PIN_OUPUT_PUSH_PUMP_HIGH_SPEED_50MHZ_API(port,pin)    		    fk_set_io((UINT32)port,pin,GPIO_Speed_50MHz,GPIO_Mode_Out_PP)
//
////! @brief Setting I/O pin as output ( Push Pump Mode : 25mA max ,I/O Speed: 10MHz )
//#define FK_SET_PIN_OUPUT_PUSH_PUMP_MID_SPEED_10MHZ_API(port,pin)     		    fk_set_io((UINT32)port,pin,GPIO_Speed_10MHz,GPIO_Mode_Out_PP)
//
////! @brief Setting I/O pin as output ( Push Pump Mode : 25mA max ,I/O Speed: 2MHz )
//#define FK_SET_PIN_OUPUT_PUSH_PUMP_LOW_SPEED_2MHZ_API(port,pin)      		    fk_set_io((UINT32)port,pin,GPIO_Speed_2MHz,GPIO_Mode_Out_PP)
//
////! @brief Setting I/O pin as output ( Open Drain Mode ,I/O Speed: as FK_GPIO_SPEED )
//#define FK_SET_PIN_OUTPUT_OPEN_DRAIN_API(port,pin)                   			fk_set_io((UINT32)port,pin,FK_GPIO_SPEED,GPIO_Mode_Out_OD)
//
////! @brief Setting I/O pin as output ( Open Drain Mode ,I/O Speed: 50MHz )
//#define FK_SET_PIN_OUTPUT_OPEN_DRAIN_HIGH_SPEED_50MHZ_API(port,pin)  		    fk_set_io((UINT32)port,pin,GPIO_Speed_50MHz,GPIO_Mode_Out_OD)
//
////! @brief Setting I/O pin as output ( Open Drain Mode ,I/O Speed: 10MHz )
//#define FK_SET_PIN_OUTPUT_OPEN_DRAIN_MID_SPEED_10MHZ_API(port,pin)   		    fk_set_io((UINT32)port,pin,GPIO_Speed_10MHz,GPIO_Mode_Out_OD)
//
////! @brief Setting I/O pin as output ( Open Drain Mode ,I/O Speed: 2MHz )
//#define FK_SET_PIN_OUTPUT_OPEN_DRAIN_LOW_SPEED_2MHZ_API(port,pin)    		    fk_set_io((UINT32)port,pin,GPIO_Speed_2MHz,GPIO_Mode_Out_OD)
//
////! @brief Setting I/O pin as input ( Floating Mode ,I/O Speed: as FK_GPIO_SPEED )
#define FK_SET_PIN_INPUT_FLOATING_API(port,pin)                      		    fk_set_io((UINT32)port,pin,FK_GPIO_SPEED_MEDIUM,FK_GPIO_MODE_INPUT,FK_GPIO_PULL_NO)

////! @brief Setting I/O pin as input ( Floating Mode ,I/O Speed: 50MHz )
//#define FK_SET_PIN_INPUT_FLOATING_HIGH_SPEED_50MHZ_API(port,pin)     		    fk_set_io((UINT32)port,pin,GPIO_Speed_50MHz,GPIO_Mode_IN_FLOATING)
//
////! @brief Setting I/O pin as input ( Floating Mode ,I/O Speed: 10MHz )
//#define FK_SET_PIN_INPUT_FLOATING_MID_SPEED_10MHZ_API(port,pin)      		    fk_set_io((UINT32)port,pin,GPIO_Speed_10MHz,GPIO_Mode_IN_FLOATING)
//
////! @brief Setting I/O pin as input ( Floating Mode ,I/O Speed: 20MHz )
//#define FK_SET_PIN_INPUT_FLOATING_LOW_SPEED_2MHZ_API(port,pin)       		    fk_set_io((UINT32)port,pin,GPIO_Speed_2MHz,GPIO_Mode_IN_FLOATING)
//
////! @brief Setting I/O pin as input ( Pull Down Mode ,I/O Speed: as FK_GPIO_SPEED )
//#define FK_SET_PIN_INPUT_PULL_DOWN_API(port,pin)                     			fk_set_io((UINT32)port,pin,FK_GPIO_SPEED,GPIO_Mode_IPD)
//
////! @brief Setting I/O pin as input ( Pull Down Mode ,I/O Speed: 50MHz )
//#define FK_SET_PIN_INPUT_PULL_DOWN_HIGH_SPEED_50MHZ_API(port,pin)    		    fk_set_io((UINT32)port,pin,GPIO_Speed_50MHz,GPIO_Mode_IPD)
//
////! @brief Setting I/O pin as input ( Pull Down Mode ,I/O Speed: 10MHz )
//#define FK_SET_PIN_INPUT_PULL_DOWN_MID_SPEED_10MHZ_API(port,pin)     		    fk_set_io((UINT32)port,pin,GPIO_Speed_10MHz,GPIO_Mode_IPD)
//
////! @brief Setting I/O pin as input ( Pull Down Mode ,I/O Speed: 2MHz )
#define FK_SET_PIN_INPUT_NOPULL_API(port,pin)      		                        fk_set_io((UINT32)port,pin,FK_GPIO_SPEED_MEDIUM,FK_GPIO_MODE_INPUT,GPIO_NOPULL)
//
//! @brief Setting I/O pin as input ( Push High Mode ,I/O Speed: as FK_GPIO_SPEED )
#define FK_SET_PIN_INPUT_PULL_HIGH_API(port,pin)                     		        fk_set_io((UINT32)port,pin,FK_GPIO_SPEED_MEDIUM,FK_GPIO_MODE_INPUT,FK_GPIO_PULL_UP)

////! @brief Setting I/O pin as input ( Push High Mode ,I/O Speed: as FK_GPIO_SPEED )
//#define FK_SET_PIN_INPUT_PULL_HIGH_HIGH_SPEED_50MHZ_API(port,pin)    		    fk_set_io((UINT32)port,pin,GPIO_Speed_50MHz,GPIO_Mode_IPU)
//
////! @brief Setting I/O pin as input ( Push High Mode ,I/O Speed: as FK_GPIO_SPEED )
//#define FK_SET_PIN_INPUT_PULL_HIGH_MID_SPEED_10MHZ_API(port,pin)     		    fk_set_io((UINT32)port,pin,GPIO_Speed_10MHz,GPIO_Mode_IPU)
//
////! @brief Setting I/O pin as input ( Push High Mode ,I/O Speed: as FK_GPIO_SPEED )
//#define FK_SET_PIN_INPUT_PULL_HIGH_LOW_SPEED_2MHZ_API(port,pin)     		    fk_set_io((UINT32)port,pin,GPIO_Speed_2MHz,GPIO_Mode_IPU)
//
//! @brief Getting I/O Pin state
#define FK_CHK_PIN_STATE_API(port,pin)                            		        HAL_GPIO_ReadPin(port,pin)

//! @brief Setting I/O Pin output High
#define FK_SET_OUTPUT_PIN_HIGH_API(port,pin)                      			HAL_GPIO_WritePin(port,pin,GPIO_PIN_SET)

//! @brief Setting I/O pin output Low
#define FK_SET_OUTPUT_PIN_LOW_API(port,pin)                       			HAL_GPIO_WritePin(port,pin,GPIO_PIN_RESET)

//! @brief Toggle I/O pin state
#define FK_SET_OUTPUT_PIN_TOGGLE_API(port,pin)                    			HAL_GPIO_TogglePin(port,pin)

////! @brief Setting Interrupt Pin Function ( Rasing Interrupt )
//#define FK_SET_RASING_INTERRUPT_PIN_API(port,pin,func)            				fk_set_io_interrupt((UINT32)port,pin,FK_TRIGGER_RASING,func,ENABLE)
//
//! @brief Setting Interrupt Pin Function ( Falling Interrupt )
#define FK_SET_FALLING_INTERRUPT_PIN_API(port,pin,func)           				fk_set_io_interrupt((UINT32)port,pin,FK_TRIGGER_FALLING,func,ENABLE)

////! @brief Setting Interrupt Pin Function ( Rasing && Falling Interrupt )
//#define FK_SET_RASING_FALLING_INTERRUPT_PIN_API(port,pin,func)                                  fk_set_io_interrupt((UINT32)port,pin,FK_TRIGGER_RASING_FALLING,func,ENABLE)
//
////! @brief Disable Interrupt Pin Function
//#define FK_SET_DISABLE_INTERRUPT_PIN_API(port,pin)                				fk_set_io_interrupt((UINT32)port,pin,FK_TRIGGER_RASING_FALLING,fk_null,DISABLE)
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
#endif		// FK_GPIO_UDEF_H 
