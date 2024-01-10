//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 uif_baudrate_set_value_state.c
//
//! @author 	 Jacky Lin
//
//! @date 		 2023/05/29
//
//  @brief 		 uif_baudrate_set_value_state functions
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S 
//
//**********************************************************************************************************************
#include "uif_glb_vars.h"
#include "uif_idef.h"
#include "..\uif_udef.h"
#include "uif_main_menu_state.h"
#include "uif_mutiple_end_main_menu_state.h"
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @author 	 Jacky Lin
//
//! @date 		 2023/05/29
//
//! @brief 		 uif_baudrate_set_value Level list definition
//
//**********************************************************************************************************************
enum UIF_BAUDRATE_SET_VALUE_LEVEL_LIST
{
	UIF_BAUDRATE_SET_VALUE_DIGI1_LEVEL,
        UIF_BAUDRATE_SET_VALUE_DIGI2_LEVEL,
        UIF_BAUDRATE_SET_VALUE_DIGI3_LEVEL,
        UIF_BAUDRATE_SET_VALUE_DIGI4_LEVEL,
        UIF_BAUDRATE_SET_VALUE_DIGI5_LEVEL,
        UIF_BAUDRATE_SET_VALUE_DIGI6_LEVEL,
        UIF_BAUDRATE_SET_VALUE_DIGI7_LEVEL,
        UIF_BAUDRATE_SET_VALUE_DIGI8_LEVEL,
	UIF_BAUDRATE_SET_VALUE_TOTAL,
};
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @author 	 Jacky Lin
//
//! @date 		 2023/05/29
//
//! @brief 		 uif_baudrate_set_value map definition
//
//**********************************************************************************************************************
const STC_UIF_MENU uif_baudrate_set_value_menu_map[]=
{
	UIF_NULL,UIF_NULL,
};

UINT8 uif_get_baudrate_index(UINT16 parameter, const UINT16* list, UINT8 len)
{
    UINT8 item_index;
    for(item_index=0;item_index<len;item_index++)
    {
        if(parameter==*(list+item_index))
        {
              break;
        }
    }
    return item_index;
}
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 uif_baudrate_set_value_state_task
//
//! @author 	 Jacky Lin
//
//! @date 		 2023/05/29
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
INT16 m_baudrate_index;
#define BAUDRATE_LIST_ITEM              4
void uif_baudrate_set_value_state_task()
{
    UINT8 i;    
    const UINT16 m_baudrate_list[BAUDRATE_LIST_ITEM] =  {1200,2400,4800,9600};
     
    if (UIF_GET_QUARTER_SEC_CNT_API()==0)
         UIF_SET_QUARTER_SEC_CNT_API(100);
    if (UIF_CHK_STATE_CHG_API())
    {
        m_baudrate_index = uif_get_baudrate_index(PFC_MODBUS_BAUDRATE,m_baudrate_list,BAUDRATE_LIST_ITEM);
        UINT16 temp=m_baudrate_list[m_baudrate_index];   	
        
        for (i=UIF_BAUDRATE_SET_VALUE_TOTAL;i>0;i--,temp/=10)
                gb_uif_digi_num[i-1]=temp%10;                
        UIF_MENU_PTR=UIF_BAUDRATE_SET_VALUE_TOTAL-1;
    }    
    if (UIF_CHK_LEVEL_CHG_API())
    {
        UIF_CLR_LED_API();
        UIF_DIS_DIGINUM_API(gb_uif_digi_num);
    }      
    UIF_LED7SEG_REFRESH_API(0,0);   
    
    if (UIF_KEY_CLICK_API(KEY_ENTER))
    {          
        UINT16 temp_var=0;
        for (i=0;i<UIF_BAUDRATE_SET_VALUE_TOTAL;i++)
            temp_var=temp_var*10+gb_uif_digi_num[i];
        PFC_MODBUS_BAUDRATE=temp_var;
        PFC_SAVE_SYSTEM_VAR_TO_EEPROM=1;
        //===== 新增1對8的設定主選單, Ver 1.0.05 =====
        if(PFC_DETECTED_HARDWARE_VERSION==PFC_DETECTED_HARDWARE_MULTIPLE_END)
            UIF_STATE_INSTALL_API(uif_mutiple_end_main_menu_state);
        else
            UIF_STATE_INSTALL_API(uif_main_menu_state);
        return;
    }
    if (UIF_KEY_CLICK_API(KEY_UP))
    {
        m_baudrate_index++;
        if(m_baudrate_index>=BAUDRATE_LIST_ITEM)
            m_baudrate_index=0;
        UINT16 temp=m_baudrate_list[m_baudrate_index];    
        for (i=UIF_BAUDRATE_SET_VALUE_TOTAL;i>0;i--,temp/=10)
            gb_uif_digi_num[i-1]=temp%10;         
        UIF_SET_LEVEL_CHG_API();
    }    
         
    if (UIF_KEY_CLICK_API(KEY_ESC))
    {
        m_baudrate_index--;
        if(m_baudrate_index<0)
            m_baudrate_index=BAUDRATE_LIST_ITEM-1;
        UINT16 temp=m_baudrate_list[m_baudrate_index];     
        for (i=UIF_BAUDRATE_SET_VALUE_TOTAL;i>0;i--,temp/=10)
            gb_uif_digi_num[i-1]=temp%10;          
        UIF_SET_LEVEL_CHG_API();
    }  
}
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @author 	 Jacky Lin
//
//! @date 		 2023/05/29
//
//! @brief 		 baudrate_set_value keymap 
//
//**********************************************************************************************************************
const STC_UIF_KEYMAP uif_baudrate_set_value_keymap[]=
{
	UIF_NULL_FUNC,UIF_NULL,
	UIF_NULL_FUNC,UIF_NULL,
	UIF_NULL_FUNC,UIF_NULL,
};
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @author 	 Jacky Lin
//
//! @date 		 2023/05/29
//
//! @brief 		 BAUDRATE_SET_VALUE state Table 
//
//**********************************************************************************************************************
const STC_UIF_STATE uif_baudrate_set_value_state=
{
/*        level                  item_cnt                     menu_func            menu_keymap   			max_line*/
	UIF_2ND_MENU_LEVEL       ,UIF_BAUDRATE_SET_VALUE_TOTAL       ,uif_baudrate_set_value_state_task,       uif_baudrate_set_value_keymap		,1
};

