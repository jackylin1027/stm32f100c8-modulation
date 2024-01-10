#ifndef LED7SEG_UDEF_H
#define LED7SEG_UDEF_H
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
//! @file 		 led7seg_udef.h
//
//! @author 	 Jacky Lin
//
//! @date 		 2021/12/29
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
#include "c_src\led7seg_init.h"
#include "c_src\led7seg_task.h"   
#include "..\ssd_io\ssd_io_udef.h"
//**********************************************************************************************************************
//
// A P I   F O R   O T H E R   M O D U L E S 
//
//**********************************************************************************************************************
//! @brief led7seg module initial API
#define	LED7SEG_INIT_API()                              led7seg_init()
//! @brief LED7SEG display string API  
#define LED7SEG_DIS_STR_API(str)                        led7seg_dis_str((UINT8*)str)  
//! @brief LED7SEG display number API  
#define LED7SEG_DIS_NUM_API(num)                        led7seg_dis_num(num)    
//! @brief  LED7SEG refresh all buffer API   
#define LED7SEG_REFRESH_API(dot_pos,color)              led7seg_refresh(dot_pos,color)  
//! @brief LED7SEG clean string and number API          
#define LED7SEG_CLR_API()                               led7seg_clr()
//! @brief LED7SEF XOR ,pde dosplay string API        
#define LED7SEG_XOR_DIS_STR_API(str)                    led7seg_xor_dis_str(str)
//! @brief LED7SEG get displaying string start position API
#define LED7SEG_GET_STR_START_POS_API()                 led7seg_get_str_start_position() 
//! @brief LED7SEG displaying diginum char API
#define LED7SEG_DIS_DIGINUM_API(digi)                   led7seg_dis_diginum(digi)
//**********************************************************************************************************************
//
// A P I   C A L L   F R O M   O T H E R   M O D U L E S 
//
//**********************************************************************************************************************
//! @brief The API for write date RX4X2X7SEG
#define LED7SEG_WRITE_DATA_API(led,data,color)          RX4X2X7SEG_WRITE_DATA_API(led,data,color)  
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
#endif		// LED7SEG_UDEF_H 
