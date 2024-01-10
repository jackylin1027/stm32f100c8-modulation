//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 fn_task.c
//
//! @author 	 Dean Huang
//
//! @date 		 2015/09/07
//
//  @brief 		 Task Subroutine
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S 
//
//**********************************************************************************************************************
#include "..\drv_src\fn_drv.h" 
#include "fn_glb_vars.h"
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
//! @fn 			 fn_task
//
//! @author 	 Dean Huang
//
//! @date 		 2015/09/07
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void fn_task()
{

}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 fn_bcd2asciiString_inverse
//
//! @author 	 Jacky Lin
//
//! @date 		 2022/08/11
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 0x12(BCD)¡B0x34(BCD) --> 0x31 0x32 0x33 0x34
//
//**********************************************************************************************************************
void fn_bcd2asciiString_inverse(UINT8* dst, UINT8* bcd, UINT8 length)
{
    UINT8 i;
    UINT8 hexTemp[10];
    
    for (i=0;i< length; i++)
        hexTemp[i]=(*(bcd+i) & 0x0F ) + ((*(bcd+i) >> 4) & 0x0F) * 10; 
    fn_hex2asciiString_inverse(dst,hexTemp,length);
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 fn_intValue2String
//
//! @author 	 Jacky Lin
//
//! @date 		 2022/08/11
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 0x12(HEX)¡B0x34(HEX) --> 0x31 0x32 0x33 0x34
//
//**********************************************************************************************************************
void fn_hex2asciiString_inverse(UINT8* dst, UINT8* hex, UINT8 length)
{
    UINT8 i;
    UINT8 hiByte, loByte;
    for (i=0;i< length; i++)
    {
        hiByte = (hex[i] >> 4) & 0xF;
        loByte = hex[i] & 0xF;
        if(hiByte<=0x9)
          *(dst+2*i+1) = hiByte + '0';
        if(hiByte>=0xA&&hiByte<=0xF)
          *(dst+2*i+1) = hiByte + 0x37;
        
        if(loByte<=0x9)
          *(dst+2*i) = loByte + '0';
        if(loByte>=0xA&&loByte<=0xF)
          *(dst+2*i) = loByte + 0x37;
    }
}

//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 fn_intValue2String
//
//! @author 	 Dean Huang
//
//! @date 		 2022/08/08
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void fn_intValue2String(UINT8* dst, UINT64 srcValue, UINT8 length)
{
    UINT8 i;
    UINT64 val=srcValue;
    for (i=0;i< length;i++,val/=10)
      dst[i]=val%10+'0';    
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 fn_intValue2String
//
//! @author 	 Dean Huang
//
//! @date 		 2022/08/08
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void fn_intValue2Number(UINT8* dst, UINT64 srcValue, UINT8 length)
{
    UINT8 i;
    UINT64 val=srcValue;
    for (i=0;i< length;i++,val/=10)
      dst[i]=val%10;    
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 fn_bcd2decString
//
//! @author 	 Jacky Lin
//
//! @date 		 2022/08/08
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 0x12(BCD)¡B0x34(BCD) --> 0x1234(UINT16)
//
//**********************************************************************************************************************
UINT16 fn_bcd2decString(UINT16 bcd)
{
    UINT16 dec=0;
    UINT16 mult;
    for (mult=1; bcd; bcd=bcd>>4,mult*=10)
        dec += (bcd & 0x0f) * mult;
    return dec;
}
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 fn_hex2bcd
//
//! @author	 Jacky Lin
//
//! @date 	 2020/07/09
//
//! @brief      0x12(BCD)¡B0x34(BCD) --> 0x1234(UINT16)
//
//********************************************************************************************************************** 
void fn_hex2bcd(UINT16 hex ,UINT8 *bcd, UINT8 length)
{
    UINT8 i;
    UINT16 temp;
    
    for(i = 0; i < length; i++)
    {
        temp=hex%100;
        *(bcd+i)=((temp/10) << 4) + ((temp % 10) & 0x0F);
        hex /= 100;
    }
}
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 fn_bcd2dec
//
//! @author	 Jacky Lin
//
//! @date 	 2020/12/22
//
//! @brief      0x12(BCD) --> 12(UINT16)
//
//********************************************************************************************************************** 
UINT16 fn_bcd2dec(UINT16 bcd)
{
    UINT16 dec=0;
    UINT16 mult;
    for (mult=1; bcd; bcd=bcd>>4,mult*=10)
        dec += (bcd & 0x0f) * mult;
    return dec;
}
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 fn_bcd2dec_u64
//
//! @author	 Jacky Lin
//
//! @date 	 2023/05/26
//
//! @brief      0x1212313213213132(BCD) --> 1212313213213132(UINT64)
//
//********************************************************************************************************************** 
UINT64 fn_bcd2dec_u64(UINT64 bcd)
{
    UINT64 dec=0;
    UINT64 mult;
    for (mult=1; bcd; bcd=bcd>>4,mult*=10)
        dec += (bcd & 0x0f) * mult;
    return dec;
}
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 fn_hex2bcd_u64
//
//! @author	 Jacky Lin
//
//! @date 	 2022/07/29
//
//! @brief      0x12(BCD)¡B0x34(BCD)¡B0x56(BCD)--> 0x1234567890123456(UINT64)
//
//********************************************************************************************************************** 
void fn_hex2bcd_u64(UINT64 hex ,UINT8 *bcd, UINT8 length)
{
    UINT8 i;
    UINT16 temp;
    
    for(i = 0; i < length; i++)
    {
        temp=hex%100;
        *(bcd+i)=((temp/10) << 4) + ((temp % 10) & 0x0F);
        hex /= 100;
    }
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 adc_task
//
//! @author 	 Dean Huang
//
//! @date 		 2014/08/26
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void fn_bubble_sort_u16(UINT16 *tbl,UINT16 size)
{
  UINT8 i,j;
  UINT16 temp=0;
  for(i=0;i<size-1;i++)
  {
    for(j=0;j<size-i;j++)
    {
      if(tbl[i]>tbl[i+1])
      {
             temp=tbl[i];
             tbl[i]=tbl[i+1];
             tbl[i+1]=temp;
      }
    }
  }
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	fn_Judge_u16_Data_Under
//
//! @author 	 Dean huang
//
//! @date 	2013/09/10
//
//! @brief 		 
//
//! @param 	None
//
//! @return 	 None
//
//**********************************************************************************************************************
UINT8 fn_Judge_u16_Data_Under(UINT16 Jdg_Value,UINT16 *Jdg_Tbl,UINT8 Jdg_Num)			
{
	UINT8 Result;
	for( Result=0; Result < Jdg_Num; Result++ ) {
		
		if( Jdg_Value <= Jdg_Tbl[Result] ) {			
			break ;
		}
	}
	return Result;	
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	fn_Judge_f32_Data_Under
//
//! @author 	 Dean huang
//
//! @date 	2013/09/10
//
//! @brief 		 
//
//! @param 	None
//
//! @return 	 None
//
//**********************************************************************************************************************
UINT8 fn_Judge_f32_Data_Under(FLOAT32 Jdg_Value,FLOAT32 *Jdg_Tbl,UINT8 Jdg_Num)			
{
	UINT8 Result;
	for( Result=0; Result < Jdg_Num; Result++ ) {
		
		if( Jdg_Value <= Jdg_Tbl[Result] ) {			
			break ;
		}
	}
	return Result;	
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	fn_Judge_f32_Data_Under
//
//! @author 	 Dean huang
//
//! @date 	2013/09/10
//
//! @brief 		 
//
//! @param 	None
//
//! @return 	 None
//
//**********************************************************************************************************************
UINT8 fn_Judge_f32_Data_Up(FLOAT32 Jdg_Value,FLOAT32 *Jdg_Tbl,UINT8 Jdg_Num)			
{
	UINT8 Result;
	for( Result=0; Result < Jdg_Num; Result++ ) {
		
		if( Jdg_Value >= Jdg_Tbl[Result] ) {			
			break ;
		}
	}
	return Result;	
}
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 fn_flag_set
//
//! @author	 dean huang
//
//! @date 	 2013/08/01
//
//! @brief 	 8 bit Flag Set
//
//! @param 	 UINT16 *FlagTbl,UINT16 bitmsk
//
//! @return 	 None
//
//**********************************************************************************************************************
void fn_flag_set(UINT8 *FlagTbl,UINT8 bitmsk)
{
//FlagTbl[0]={ 0x80(bitmsk=7)   | 0x40(bitmsk=6)  | 0x20(bitmsk=6)  | 0x10(bitmsk=6)  | 0x08(bitmsk=6)  | 0x04(bitmsk=6)  | 0x02(bitmsk=6) | 0x01(bitmsk=6)  }           
//FlagTbl[1]={ 0x80(bitmsk=15)  | 0x40(bitmsk=14) | 0x20(bitmsk=13) | 0x10(bitmsk=12) | 0x08(bitmsk=11) | 0x04(bitmsk=10) | 0x02(bitmsk=9) | 0x01(bitmsk=8)  }
//................................
	FlagTbl[bitmsk>>3] |= (UINT8)(1<<(bitmsk & 0x07));	
}

//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 fn_flag_clr
//
//! @author	 dean huang
//
//! @date 	 2013/08/01
//
//! @brief 	 8 bit Flag Set
//
//! @param 	 UINT16 *FlagTbl,UINT16 bitmsk
//
//! @return 	 None
//
//**********************************************************************************************************************
void fn_flag_clr(UINT8 *FlagTbl,UINT8 bitmsk)
{
//FlagTbl[0]={ 0x7F(bitmsk=7)   & 0xBF(bitmsk=6)  & 0xDF(bitmsk=6)  & 0xEF(bitmsk=6)  & 0xF7(bitmsk=6)  & 0xFB(bitmsk=6)  & 0xFD(bitmsk=6) & 0xFE(bitmsk=6)  }           
//FlagTbl[1]={ 0x7F(bitmsk=15)  & 0xBF(bitmsk=14) & 0xDF(bitmsk=13) & 0xEF(bitmsk=12) & 0xF7(bitmsk=11) & 0xFB(bitmsk=10) & 0xFD(bitmsk=9) & 0xFE(bitmsk=8)  }
//................................
	FlagTbl[bitmsk>>3] &= ~(UINT8)(1<<(bitmsk & 0x07));	
}

//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 fn_flag_chk
//
//! @author	 dean huang
//
//! @date 	 2013/08/01
//
//! @brief 	 8 bit Flag Set
//
//! @param 	 UINT16 *FlagTbl,UINT16 bitmsk
//
//! @return 	 None
//
//**********************************************************************************************************************
UINT8 fn_flag_chk(UINT8 *FlagTbl,UINT8 bitmsk)
{
	UINT8 wk_flg;
	if(!(FlagTbl[bitmsk >> 3] & (1 << (bitmsk & 0x07))))
	{
		wk_flg=0;
	}
	else
	{
		wk_flg=1;
	}
	return wk_flg;
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 io_link_memcpy_inverse
//
//! @author 	 Dean_Huang
//
//! @date 	 2016/01/26
//
//! @param 	 UINT8 *Dst,UINT8 *Src,
//
//! @return 	 UINT8 length
//
//**********************************************************************************************************************
UINT8 fn_memcpy_inverse(UINT8 *Dst,UINT8 *Src,UINT8 length)
{
  UINT8 i=0;
  for(i=0;i<length;i++)
     Dst[i] = Src[length-1-i]; 
  return i;
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 io_link_strcpy
//
//! @author 	 Dean_Huang
//
//! @date 	 2016/01/26
//
//! @param 	 UINT8 *target,UINT8 *src
//
//! @return 	 UINT8 length
//
//**********************************************************************************************************************
UINT8 fn_strcpy(UINT8 *target,UINT8 *src,UINT8 length)
{
   UINT8 i=0;
   for (i=0;i < length;i++)
         *(target+i)=*(src+i);
   return i;
}
#ifdef __cplusplus
}
#endif

