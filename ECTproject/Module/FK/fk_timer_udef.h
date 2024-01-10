#ifndef FK_TIMER_UDEF_H
#define FK_TIMER_UDEF_H
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
#define FK_1MS_SET		1
#define FK_2MS_SET		2
#define FK_4MS_SET		4
#define FK_8MS_SET		8
#define FK_10MS_SET	    10
//**********************************************************************************************************************
//
// A P I   F O R   O T H E R   M O D U L E S
//
//**********************************************************************************************************************
//! @brief The API for initial tim4 by interrupt continue mode           
#define FK_SET_MS_TIMER_INTERRUPT4_FUNC_CONTINUE_API(ms,func)                   fk_timer_interrupt_enable(FK_TIMER_INTERRUPT4,(HAL_RCC_GetPCLK1Freq()/1000),ms,func)
//! @brief The API for initial tim4 by interrupt continue mode           
#define FK_SET_MS_TIMER_INTERRUPT3_FUNC_CONTINUE_API(ms,func)                   fk_timer_interrupt_enable(FK_TIMER_INTERRUPT3,(HAL_RCC_GetPCLK1Freq()/1000),ms,func)
//============================================================================================================================//
// You Could configure FK_INTERRUPT_FUNC_TOTAL variable in fk_idef.h for changing the timer set
//============================================================================================================================//
#define FK_SET_TIMER_INPUT_CHANNEL_1_FALLING_EDGE_CAPTURE_FUNC_API(port,pin,func)     	        fk_timer_capture_enable(FK_INTERRUPT5_INPUT_CAPTURE,FK_TIMER_CHANNEL1,(UINT32)port,pin,FK_FALLING_EDGE,func)
#define FK_SET_TIMER_INPUT_CHANNEL_1_RASING_EDGE_CAPTURE_FUNC_API(port,pin,func)      	        fk_timer_capture_enable(FK_INTERRUPT5_INPUT_CAPTURE,FK_TIMER_CHANNEL1,(UINT32)port,pin,FK_RASING_EDGE,func)
#define FK_SET_TIMER_INPUT_CHANNEL_1_BOTH_EDGE_CAPTURE_FUNC_API(port,pin,func)        	        fk_timer_capture_enable(FK_INTERRUPT5_INPUT_CAPTURE,FK_TIMER_CHANNEL1,(UINT32)port,pin,FK_BOTH_EDGE,func)
#define FK_TIMER_INPUT_CHANNEL_1_CAPTURE_FUNC_DISABLE_API()                           		    TIM_ITConfig((TIM_TypeDef *)gt_fk_timer_register[FK_INTERRUPT5_INPUT_CAPTURE], TIM_IT_CC1,DISABLE);
#define FK_GET_TIMER_CHANNEL_1_CAPTURE_VALUE_API()                                    			TIM_GetCapture1((TIM_TypeDef *)gt_fk_timer_register[FK_INTERRUPT5_INPUT_CAPTURE])
#define FK_SET_TIMER_CHANNEL_1_CAPTURE_VALUE_API(value)                               			TIM_SetCompare1((TIM_TypeDef *)gt_fk_timer_register[FK_INTERRUPT5_INPUT_CAPTURE],value)

//! @brief The API for stop interrupt timer in once mode
#define FK_TIMER_INTERRUPT_ONCE_STOP(htim)                      HAL_TIM_Base_Stop_IT(htim)
//! @brief The API for start interrupt timer in once/continute mode
#define FK_TIMER_INTERRUPT_START(htim)                          HAL_TIM_Base_Start_IT(htim)  
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
#endif		// FK_TIMER_UDEF_H 
