#ifndef FK_ADC_UDEF_H
#define FK_ADC_UDEF_H
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
//! @brief ADC Channel Setect Define
enum
{
    FK_ADC_CHANNEL0,
    FK_ADC_CHANNEL1,
    FK_ADC_CHANNEL2,
    FK_ADC_CHANNEL3,
    FK_ADC_CHANNEL4,
    FK_ADC_CHANNEL5,
    FK_ADC_CHANNEL6,
    FK_ADC_CHANNEL7,
    FK_ADC_CHANNEL8,
    FK_ADC_CHANNEL9,
    FK_ADC_CHANNEL10,
    FK_ADC_Temperature,
    FK_ADC_Vrefint,
    FK_ADC_TOTAL,
};
//**********************************************************************************************************************
//
// A P I   F O R   O T H E R   M O D U L E S
//
//**********************************************************************************************************************
// ADC Function
//**It is commonly used function*//
//! @brief The API for setting ADC1 in Single Mode with interrupt function
#define FK_SET_ADC1_SINGLE_INTERRUPT_API(channel,func)                      	fk_adc_functions(FK_ADC_SET1,channel,0,FK_ADC_INTERRUPT_FUNC,FK_ADC_SINGLE_MODE,func,0,0)

//! @brief The API for setting ADC1 in Continuous Mode with interrupt function
#define FK_SET_ADC1_CONTINUOUS_INTERRUPT_API(channel,func)                  	fk_adc_functions(FK_ADC_SET1,channel,0,FK_ADC_INTERRUPT_FUNC,FK_ADC_CONTINUOUS_MODE,func,0,0)

//! @brief The API for setting ADC1 in DMA mode with interrupt function
#define FK_SET_ADC1_DMA_API(adc_channel,buf,size,func)                      	fk_adc_functions(FK_ADC_SET1,adc_channel,FK_ADC1_DMA_CHANNEL,FK_ADC_DMA_FUNC,FK_ADC_CONTINUOUS_MODE,func,buf,size)

//! @brief The API for setting ADC1 in polling Mode
#define FK_SET_ADC1_POLLING_ENABLE_API(channel)                             	fk_adc_functions(FK_ADC_SET1,channel,0,FK_ADC_POLLING_FUNC,FK_ADC_SINGLE_MODE,fk_null,0,0)

//! @brief The API for starting ADC1 conversion
#define FK_ADC1_START_API()                                                 	ADC_SoftwareStartConvCmd((ADC_TypeDef*)gt_fk_adc_register[FK_ADC_SET1+FK_ADC_SET_TOTAL], ENABLE)

//! @brief The API for setting the result of ADC1 conversion
#define FK_ADC1_GET_VALUE_API()                                             	ADC_GetConversionValue((ADC_TypeDef*)gt_fk_adc_register[FK_ADC_SET1+FK_ADC_SET_TOTAL])

//! @brief The API for checking ADC1 is done or not
#define FK_ADC1_CHK_DONE_API()                                              	(ADC_GetFlagStatus((ADC_TypeDef*)gt_fk_adc_register[FK_ADC_SET1+FK_ADC_SET_TOTAL],ADC_FLAG_EOC)==SET)

//! @brief The API for clearing ADC1's "done flag"
#define FK_ADC1_CLR_DONE_API()                                              	ADC_ClearFlag((ADC_TypeDef*)gt_fk_adc_register[FK_ADC_SET1+FK_ADC_SET_TOTAL],ADC_FLAG_EOC)

//! @brief The API for clearing the interrupt pending flag of ADC1
#define FK_ADC1_CLR_INTERRUPT_FLAG_API()                                    	ADC_ClearITPendingBit((ADC_TypeDef*)gt_fk_adc_register[FK_ADC_SET1+FK_ADC_SET_TOTAL],ADC_IT_EOC)

//**It is not commonly used function*//  
//! @brief The API for setting ADC1 in Dual Mode with interrupt function
#define FK_SET_ADC1_DUAL_MODE_API(channel,channel2,buf,size,func)           	fk_adc_functions(FK_ADC_SET1,channel,channel2,FK_ADC_DUAL_DMA_FUNC,FK_ADC_CONTINUOUS_MODE,func,buf,size)

//! @brief The API for starting ADC1 conversion and return the result
#define FK_ADC1_POLLING_API()                                               	fk_adc_polling(FK_ADC_SET1)
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
//**********************************************************************************************************************
//
// MARK Funnction
//
//**********************************************************************************************************************
////! @brief The API for setting ADC1 in Single Mode with interrupt function
//#define FK_SET_ADC2_SINGLE_INTERRUPT_API(channel,func)                     	fk_adc_functions(FK_ADC_SET2,channel,0,FK_ADC_INTERRUPT_FUNC,FK_ADC_SINGLE_MODE,func,0,0)
//
////! @brief The API for setting ADC1 in Continuous Mode with interrupt function
//#define FK_SET_ADC2_CONTINUOUS_INTERRUPT_API(channel,func)              		fk_adc_functions(FK_ADC_SET2,channel,0,FK_ADC_INTERRUPT_FUNC,FK_ADC_CONTINUOUS_MODE,func,0,0)
//
////! @brief The API for setting ADC1 in Single Mode with interrupt function
//#define FK_SET_ADC3_SINGLE_INTERRUPT_API(channel,func)                      	fk_adc_functions(FK_ADC_SET3,channel,0,FK_ADC_INTERRUPT_FUNC,FK_ADC_SINGLE_MODE,func,0,0)
//
////! @brief The API for setting ADC1 in Continuous Mode with interrupt function
//#define FK_SET_ADC3_CONTINUOUS_INTERRUPT_API(channel,func)               		fk_adc_functions(FK_ADC_SET3,channel,0,FK_ADC_INTERRUPT_FUNC,FK_ADC_CONTINUOUS_MODE,func,0,0)
//
////! @brief The API for setting ADC2 in DMA mode with interrupt function
//#define FK_SET_ADC2_DMA_API(adc_channel,buf,size,func)                      	fk_adc_functions(FK_ADC_SET2,adc_channel,FK_ADC2_DMA_CHANNEL,FK_ADC_DMA_FUNC,FK_ADC_CONTINUOUS_MODE,func,buf,size)
//
////! @brief The API for setting ADC3 in DMA mode with interrupt function
//#define FK_SET_ADC3_DMA_API(adc_channel,buf,size,func)                      	fk_adc_functions(FK_ADC_SET3,adc_channel,FK_ADC3_DMA_CHANNEL,FK_ADC_DMA_FUNC,FK_ADC_CONTINUOUS_MODE,func,buf,size)
//
////! @brief The API for setting ADC2 in polling Mode
//#define FK_SET_ADC2_POLLING_ENABLE_API(channel)                             	fk_adc_functions(FK_ADC_SET2,channel,0,FK_ADC_POLLING_FUNC,FK_ADC_SINGLE_MODE,fk_null,0,0)
//
////! @brief The API for setting ADC3 in polling Mode
//#define FK_SET_ADC3_POLLING_ENABLE_API(channel)                             	fk_adc_functions(FK_ADC_SET3,channel,0,FK_ADC_POLLING_FUNC,FK_ADC_SINGLE_MODE,fk_null,0,0)
//
////! @brief The API for starting ADC2 conversion
//#define FK_ADC2_START_API()                                                 	ADC_SoftwareStartConvCmd((ADC_TypeDef*)gt_fk_adc_register[FK_ADC_SET2+FK_ADC_SET_TOTAL], ENABLE)
//
////! @brief The API for starting ADC3 conversion
//#define FK_ADC3_START_API()                                                 	ADC_SoftwareStartConvCmd((ADC_TypeDef*)gt_fk_adc_register[FK_ADC_SET3+FK_ADC_SET_TOTAL], ENABLE)
//
////! @brief The API for setting the result of ADC2 conversion
//#define FK_ADC2_GET_VALUE_API()                                             	ADC_GetConversionValue((ADC_TypeDef*)gt_fk_adc_register[FK_ADC_SET2+FK_ADC_SET_TOTAL])
//
////! @brief The API for setting the result of ADC3 conversion
//#define FK_ADC3_GET_VALUE_API()                                             	ADC_GetConversionValue((ADC_TypeDef*)gt_fk_adc_register[FK_ADC_SET3+FK_ADC_SET_TOTAL])
//
////! @brief The API for checking ADC2 is done or not
//#define FK_ADC2_CHK_DONE_API()                                              	(ADC_GetFlagStatus((ADC_TypeDef*)gt_fk_adc_register[FK_ADC_SET2+FK_ADC_SET_TOTAL],ADC_FLAG_EOC)==SET)
//
////! @brief The API for checking ADC3 is done or not
//#define FK_ADC3_CHK_DONE_API()                                              	(ADC_GetFlagStatus((ADC_TypeDef*)gt_fk_adc_register[FK_ADC_SET3+FK_ADC_SET_TOTAL],ADC_FLAG_EOC)==SET)
//
////! @brief The API for clearing ADC2's "done flag"
//#define FK_ADC2_CLR_DONE_API()                                              	ADC_ClearFlag((ADC_TypeDef*)gt_fk_adc_register[FK_ADC_SET2+FK_ADC_SET_TOTAL],ADC_FLAG_EOC)
//
////! @brief The API for clearing ADC3's "done flag"
//#define FK_ADC3_CLR_DONE_API()                                              	ADC_ClearFlag((ADC_TypeDef*)gt_fk_adc_register[FK_ADC_SET3+FK_ADC_SET_TOTAL],ADC_FLAG_EOC)
//
////! @brief The API for setting ADC2 in Dual Mode with interrupt function
//#define FK_SET_ADC2_DUAL_MODE_API(channel,channel2,buf,size,func)             fk_adc_functions(FK_ADC_SET2,channel,channel2,FK_ADC_DUAL_DMA_FUNC,FK_ADC_CONTINUOUS_MODE,func,buf,size)
//
////! @brief The API for setting ADC3 in Dual Mode with interrupt function
//#define FK_SET_ADC3_DUAL_MODE_API(channel,channel2,buf,size,func)           	fk_adc_functions(FK_ADC_SET3,channel,channel2,FK_ADC_DUAL_DMA_FUNC,FK_ADC_CONTINUOUS_MODE,func,buf,size)
//
////! @brief The API for starting ADC2 conversion and return the result
//#define FK_ADC2_POLLING_API()                                               	fk_adc_polling(FK_ADC_SET2)
//
////! @brief The API for starting ADC3 conversion and return the result
//#define FK_ADC3_POLLING_API()                                              	 fk_adc_polling(FK_ADC_SET3)


#ifdef __cplusplus
}
#endif
#endif		// FK_ADC_UDEF_H 
