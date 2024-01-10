#ifndef LED7SEG_TASK_H
#define LED7SEG_TASK_H
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
//! @file 		 led7seg_task.h
//
//! @author 	 Jacky Lin
//
//! @date 		 2021/12/29
//
//  @brief 		 Here declare task function
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S 
//
//**********************************************************************************************************************
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
void led7seg_task();
void led7seg_dis_str(UINT8 *str);
void led7seg_dis_num(FLOAT32 num);
UINT8 led7seg_ascii2font(UINT8 ascii);
void led7seg_refresh(UINT8 dot_pos, UINT8 color);
void led7seg_clr();
void led7seg_xor_dis_str(UINT8 *str);
UINT8 led7seg_get_str_start_position();
void led7seg_dis_diginum(UINT8* digi);
//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N 
//
//**********************************************************************************************************************
#ifdef __cplusplus
}
#endif
#endif		// LED7SEG_TASK_H 