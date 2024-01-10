//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 led7seg_task.c
//
//! @author 	 Jacky Lin
//
//! @date 		 2021/12/29
//
//  @brief 		 Task Subroutine
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S 
//
//**********************************************************************************************************************
#include "..\drv_src\led7seg_drv.h" 
#include "led7seg_glb_vars.h"
#include "led7seg_idef.h"
#include "..\led7seg_udef.h"
#include "led7seg_task.h"
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
//! @fn 			 led7seg_task
//
//! @author 	 Jacky Lin
//
//! @date 		 2021/12/29
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void led7seg_task()
{

}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	        lcd4419_dis_str
//
//! @author 	        Jacky Lin
//
//! @date 		 2021/12/29
//
//! @brief 		 task function
//
//! @param 		 UINT8 *str
//
//! @return 	 None
//
//**********************************************************************************************************************
void led7seg_dis_str(UINT8 *str)
{      
  UINT8 i;
  
  for (i=0;i<LED7SEG_MAX_CHAR_NUM;i++)
  {   
      if (*str=='.')        // display a '.' if we met a '.',but can't be count.
      {
          gb_led7seg_refresh_str[i-1] |= LED7SEG_DOT;
          i--;
          str++;
      }
      else if(*str=='$')
      {
          gb_led7seg_refresh_str[i] = gb_led7seg_font[LED7SEG_CHAR_MIN_1];
          str++;
      }
      else
      {
          gb_led7seg_refresh_str[i] = led7seg_ascii2font(*str++);      
      }
  }  
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	        led7seg_xor_dis_str
//
//! @author 	        Jacky Lin
//
//! @date 		 2021/12/29
//
//! @brief 		 task function
//
//! @param 		 UINT8 *str
//
//! @return 	 None
//
//**********************************************************************************************************************
void led7seg_xor_dis_str(UINT8 *str)
{      
  UINT8 i;
  
  for (i=0;i<LED7SEG_MAX_CHAR_NUM;i++)
  {   
      if (*str=='.')        // display a '.' if we met a '.',but can't be count.
      {
          gb_led7seg_refresh_str[i] |= LED7SEG_DOT;
          str++;
      }
      else if(*str=='$')
      {
          gb_led7seg_refresh_str[i] |= gb_led7seg_font[LED7SEG_CHAR_MIN_1];
          str++;
      }
      else
      {
          gb_led7seg_refresh_str[i] |= led7seg_ascii2font(*str++);      
      }
  }  
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 led7seg_ascii2font
//
//! @author 	        Jacky Lin
//
//! @date 		 2021/12/29
//
//! @brief 		 task function
//
//! @param 		 UINT8 ascii : ascii transfer gb_led7seg_font table index
//                      
//! @return             UINT8 gb_led7seg_font[result] : gb_led7seg_font table value by index
//
//**********************************************************************************************************************
UINT8 led7seg_ascii2font(UINT8 ascii)
{
  UINT8 result=0xFF;
  if (ascii==' ')
    result=LED7SEG_CHAR_SPACE;
  if (ascii=='-')
    result=LED7SEG_CHAR_MINUS;    
  if (ascii=='_')
    result=LED7SEG_CAHR__;
  if (ascii>='0'&&ascii<='9')
    result=LED7SEG_CHAR_0+ascii-'0';
  if (ascii>='A'&&ascii<='Z')
    result=LED7SEG_CHAR_A+ascii-'A';       
  // That means someone wana showing a char we don't have
  if (result==0xFF)
    result=0;
  return gb_led7seg_font[result];
}

//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 led7seg_get_value_digits
//
//! @author 	 Willman Chen
//
//! @date 		 2009/07/31
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
UINT8 led7seg_get_value_digits(FLOAT32 value, UINT8 digi_max)
{
	FLOAT32 temp_value=value;
	UINT8	digits=0;
	
	for(digits=1;digits<=digi_max;digits++)
	{
		temp_value/=pow(10,1);
		if(temp_value<1)	
			break;
	}	
	return digits;
}
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 led7seg_dis_diginum
//
//! @author 	 Willman Chen
//
//! @date 		 2022/01/13
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void led7seg_dis_diginum(UINT8* digi)
{
    for(UINT8 i=0; i<LED7SEG_MAX_CHAR_NUM; i++)
    {
        gb_led7seg_refresh_str[i]=gb_led7seg_font[digi[i]+LED7SEG_CHAR_0];
    }   
}
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 led7seg_get_display_digits
//
//! @author 	 Willman Chen
//
//! @date 		 2009/07/31
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
UINT8 led7seg_get_display_digits(FLOAT32 value,UINT16 mode, UINT8 digi_max)
{
	UINT8	value_digits=led7seg_get_value_digits(value, digi_max);
        
        value_digits+=2;
        
	if(value_digits<digi_max)
		return value_digits;
	else
		return digi_max;
		
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 		 led7seg_dis_num
//
//! @author 	         Jacky Lin
//
//! @date 		 2021/12/29
//
//! @brief 		 task function
//
//! @param               FLOAT32 number : The number we wana displaying
//
//! @return 	         None
//
//**********************************************************************************************************************
/*void led7seg_dis_num(FLOAT32 number)
{
    UINT8 digi[LED7SEG_MAX_CHAR_NUM];
    UINT8 show_digits_number=led7seg_get_display_digits(number,0,LED7SEG_MAX_CHAR_NUM);
    UINT8 dot_pos=led7seg_get_value_digits(number,LED7SEG_MAX_CHAR_NUM);    
    UINT8 i,no_dot_flg=0;
    UINT32 val;
    
    //==顯數個數-數值位數=所需進位的位數
    val=(INT32)(number*pow(10,(show_digits_number-dot_pos)));
    for (i=0;i<show_digits_number;i++,val/=10)
            digi[i]=val%10;
    //判斷是否需要小數點
    if(dot_pos==show_digits_number)
          no_dot_flg=1; 
    
    //===========================================================================================//	
    //===(Print value)	
    //===========================================================================================//	
    for (i=0;i<show_digits_number;i++)
    {	
        UINT8 col_offset_pos=i+(LED7SEG_MAX_CHAR_NUM-show_digits_number); //需加上不需顯示位元位移數量 
        if((i>(dot_pos-1))||(no_dot_flg==1))
        {}//UIF_SET_CURSOR_API(row,col+UIF_SHOW_VALUE_DOT_OFFSET+(col_offset_pos*UIF_SHOW_VALUE_NUM_WIDTH));   
        gb_led7seg_refresh_num[i]=gb_led7seg_font[LED7SEG_CHAR_0+digi[show_digits_number-i-1]];
    }        
}*/
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 		 led7seg_dis_num
//
//! @author 	         Jacky Lin
//
//! @date 		 2022/1/13
//
//! @brief 		 task function
//
//! @param               FLOAT32 number : The number we wana displaying
//
//! @return 	         None
//
//**********************************************************************************************************************
void led7seg_dis_num(FLOAT32 number)
{
    INT8 digi[LED7SEG_MAX_CHAR_NUM+1];
    UINT8 show_digits_number=led7seg_get_display_digits(number,0,LED7SEG_MAX_CHAR_NUM);
    UINT8 dot_pos=led7seg_get_value_digits(number,LED7SEG_MAX_CHAR_NUM);    
    
    sprintf(digi, "%f",number);
    led7seg_dis_str((UINT8*)digi);  
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 led7seg_refresh
//
//! @author 	 Jacky Lin
//
//! @date 		 2021/12/30
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void led7seg_refresh(UINT8 dot_pos, UINT8 color)
{
    INT8 refresh_ascii[LED7SEG_MAX_CHAR_NUM],i, interger_zero=0;
    UINT16 dot_position=dot_pos;
    
    SSD_IO_CLEAN_STATE_OUTPUT(color^0x01);
    for(i=0;i<LED7SEG_MAX_CHAR_NUM;i++)
    {
        if(gb_led7seg_refresh_str[i]!=gb_led7seg_font[LED7SEG_CHAR_SPACE])
            refresh_ascii[i]=gb_led7seg_refresh_str[i];      
        else if(gb_led7seg_refresh_num[i]!=gb_led7seg_font[LED7SEG_CHAR_SPACE])
            refresh_ascii[i]=gb_led7seg_refresh_num[i];
        else
            refresh_ascii[i]=gb_led7seg_font[LED7SEG_CHAR_SPACE];
    }
    //===== 修正在不同單位的設定下, 顯示壓力值整數位顯示0的問題, Ver1.1.01===== 
    for(i=0;i<LED7SEG_MAX_CHAR_NUM-dot_position-1;i++)
    {
        if(i==0)
        {
            if(refresh_ascii[i]==gb_led7seg_font[LED7SEG_CHAR_0])
            {
                refresh_ascii[i]=gb_led7seg_font[LED7SEG_CHAR_SPACE];     
                interger_zero=i;
            }
        }
        else
        {
            if(refresh_ascii[i]==gb_led7seg_font[LED7SEG_CHAR_0]&&interger_zero==i-1)
            {
                refresh_ascii[i]=gb_led7seg_font[LED7SEG_CHAR_SPACE];     
                interger_zero=i;
            }            
        }
    } 
    for(i=0;i<LED7SEG_MAX_CHAR_NUM;i++)
    {
        SSD_IO_WRITE_DATA_API(i,refresh_ascii[i],color);
    }
          
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 led7seg_clr
//
//! @author 	 Jacky Lin
//
//! @date 		 2022/01/04
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void led7seg_clr()
{
    UINT8 i;
    for(i=0;i<LED7SEG_MAX_CHAR_NUM;i++)
    {
        gb_led7seg_refresh_str[i]=gb_led7seg_font[LED7SEG_CHAR_SPACE];
        gb_led7seg_refresh_num[i]=gb_led7seg_font[LED7SEG_CHAR_SPACE];
    }
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 led7seg_get_digital_start_position
//
//! @author 	 Jacky Lin
//
//! @date 		 2022/01/12
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
UINT8 led7seg_get_str_start_position()
{
    INT8 i, space_temp[LED7SEG_MAX_CHAR_NUM]={0xFF,0xFF,0xFF,0xFF}, space_index=0;
    
    for(i=LED7SEG_MAX_CHAR_NUM;i>0;i--)
    {
        if(gb_led7seg_refresh_str[i-1]==LED7SEG_CHAR_SPACE)
            space_temp[space_index++]=i-1;
    }
    for(i=LED7SEG_MAX_CHAR_NUM;i>0;i--)
    {
        if(space_temp[i-1]!=0xFF) 
            return i-1;
    }
    return 0;
}
#ifdef __cplusplus
}
#endif

