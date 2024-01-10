#ifndef FN_UDEF_H
#define FN_UDEF_H
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
//! @file 		 fn_udef.h
//
//! @author 	 Dean Huang
//
//! @date 		 2015/09/07
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
#define FN_GET_BIGEND_INT16(ptr) \
  (INT16)(((((UINT8 *)(ptr))[0]) << 8) \
          + ((((UINT8 *)(ptr))[1])))

#define FN_GET_BIGEND_UINT16(ptr) \
  (UINT16)(((((UINT8 *)(ptr))[0]) << 8) \
           + ((((UINT8 *)(ptr))[1])))
    
//! @brief The API for get max value    
#define FN_GET_MAX_API(data1,data2)     ((data1 > data2)?(data1):(data2))
 //! @brief The API for get min value 
#define FN_GET_MIN_API(data1,data2)     ((data1 < data2)?(data1):(data2))
 //! @brief The API for  check data max and min range   
#define FN_CHK_MINMAX_API(data,min,max)                    \
  data=(data<min)?(min):(data);                        \
  data=(data>max)?(max):(data)        
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S 
//
//**********************************************************************************************************************
#include "..\fk\fk_udef.h"
#include "c_src\fn_init.h"
#include "c_src\fn_task.h"
//**********************************************************************************************************************
//
// A P I   F O R   O T H E R   M O D U L E S 
//
//**********************************************************************************************************************
#define	FN_INIT_API()						fn_init()
//! @brief The API for bubble sort function  
#define FN_BUBBLE_SORT_U16_API(tbl,size)                        fn_bubble_sort_u16(tbl,size)
//! @brief The API for judge Values which range in Table
#define FN_JUDGE_U16_DATA_UNDER_API(Value,Tbl,Num)              fn_Judge_u16_Data_Under(Value,Tbl,Num)
#define FN_JUDGE_F32_DATA_UNDER_API(Value,Tbl,Num)              fn_Judge_f32_Data_Under(Value,Tbl,Num)	
#define FN_JUDGE_F32_DATA_UP_API(Value,Tbl,Num)                 fn_Judge_f32_Data_Up(Value,Tbl,Num)	
//----------ERROR FLAG SET/CLR/CHK-------------------------------------------------------------------------------
#define FN_ERROR_FLAG_SET_API(tbl,bitmsk)			fn_flag_set(tbl,bitmsk)
#define FN_ERROR_FLAG_CLR_API(tbl,bitmsk)		        fn_flag_clr(tbl,bitmsk)
#define FN_ERROR_FLAG_CHK_API(tbl,bitmsk)			fn_flag_chk(tbl,bitmsk)
//! @brief The api for copy memory and inverse it
#define FN_MEMCPY_INVERSE_API(Dst,Src,len)                      fn_memcpy_inverse(Dst,Src,len)
//! @brief The api for copy string data
#define FN_STRCPY_API(target,src,len)                           fn_strcpy(target,src,len) 
    
#define FN_HEX2BCD_API(hex,bcd,len)                             fn_hex2bcd(hex,bcd,len)
#define FN_HEX2BCD_U64_API(hex,bcd,len)                         fn_hex2bcd_u64(hex,bcd,len)
#define FN_BCD2DEC_API(bcd)                                     fn_bcd2dec(bcd)
#define FN_BCD2DEC_U64_API(bcd)                                 fn_bcd2dec_u64(bcd)
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
#endif		// FN_UDEF_H 
