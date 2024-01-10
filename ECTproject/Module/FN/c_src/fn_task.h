#ifndef FN_TASK_H
#define FN_TASK_H
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
//! @file 		 fn_task.h
//
//! @author 	 Dean Huang
//
//! @date 		 2015/09/07
//
//  @brief 		 Here declare task function
//
//**********************************************************************************************************************
void  fn_bubble_sort_u16(UINT16 *tbl,UINT16 size);
UINT8 fn_Judge_u16_Data_Under(UINT16 Jdg_Value,UINT16 *Jdg_Tbl,UINT8 Jdg_Num);
UINT8 fn_Judge_f32_Data_Under(FLOAT32 Jdg_Value,FLOAT32 *Jdg_Tbl,UINT8 Jdg_Num);
UINT8 fn_Judge_f32_Data_Up(FLOAT32 Jdg_Value,FLOAT32 *Jdg_Tbl,UINT8 Jdg_Num);	
void  fn_flag_set(UINT8 *FlagTbl,UINT8 bitmsk);
void  fn_flag_clr(UINT8 *FlagTbl,UINT8 bitmsk);
UINT8 fn_flag_chk(UINT8 *FlagTbl,UINT8 bitmsk);
UINT8 fn_memcpy_inverse(UINT8 *Dst,UINT8 *Src,UINT8 length);
UINT8 fn_strcpy(UINT8 *target,UINT8 *src,UINT8 length);
void fn_hex2bcd(UINT16 hex ,UINT8 *bcd, UINT8 length);
void fn_hex2bcd_u64(UINT64 hex ,UINT8 *bcd, UINT8 length);
void fn_intValue2String(UINT8* dst, UINT64 srcValue, UINT8 length);
UINT16 fn_bcd2decString(UINT16 bcd);
void fn_intValue2Number(UINT8* dst, UINT64 srcValue, UINT8 length);
void fn_hex2asciiString_inverse(UINT8* dst, UINT8* hex, UINT8 length);
void fn_bcd2asciiString_inverse(UINT8* dst, UINT8* bcd, UINT8 length);
UINT16 fn_bcd2dec(UINT16 bcd);
UINT64 fn_bcd2dec_u64(UINT64 bcd);
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
void fn_task();
//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N 
//
//**********************************************************************************************************************
#ifdef __cplusplus
}
#endif
#endif		// FN_TASK_H 
