//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 uif_demicel_place_set_value_state.c
//
//! @author 	 Jacky Lin
//
//! @date 		 2023/05/29
//
//  @brief 		 uif_demicel_place_set_value_state functions
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
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @author 	 Jacky Lin
//
//! @date 		 2023/05/29
//
//! @brief 		 uif_demicel_place_set_value Level list definition
//
//**********************************************************************************************************************
enum UIF_DEMICEL_PLACE_SET_VALUE_LEVEL_LIST
{
	UIF_DEMICEL_PLACE_SET_VALUE_DIGI1_LEVEL,
        UIF_DEMICEL_PLACE_SET_VALUE_DIGI2_LEVEL,
        UIF_DEMICEL_PLACE_SET_VALUE_DIGI3_LEVEL,
        UIF_DEMICEL_PLACE_SET_VALUE_DIGI4_LEVEL,
        UIF_DEMICEL_PLACE_SET_VALUE_DIGI5_LEVEL,
        UIF_DEMICEL_PLACE_SET_VALUE_DIGI6_LEVEL,
        UIF_DEMICEL_PLACE_SET_VALUE_DIGI7_LEVEL,
        UIF_DEMICEL_PLACE_SET_VALUE_DIGI8_LEVEL,
	UIF_DEMICEL_PLACE_SET_VALUE_TOTAL,
};
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @author 	 Jacky Lin
//
//! @date 		 2023/05/29
//
//! @brief 		 uif_demicel_place_set_value map definition
//
//**********************************************************************************************************************
const STC_UIF_MENU uif_demicel_place_set_value_menu_map[]=
{
	UIF_NULL,UIF_NULL,
};
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 uif_demicel_place_set_value_state_task
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
UINT8 m_demical_place_value;
void uif_demicel_place_set_value_state_task()
{
    UINT8 i;    
    
    if (UIF_GET_QUARTER_SEC_CNT_API()==0)
         UIF_SET_QUARTER_SEC_CNT_API(100);
    
    if (UIF_CHK_STATE_CHG_API())
    {      
        UINT16 temp=PFC_DISPLAY_DOT_NUM[PFC_1ST_DEVICE];   	       
        for (i=UIF_DEMICEL_PLACE_SET_VALUE_TOTAL;i>0;i--,temp/=10)
                gb_uif_digi_num[i-1]=temp%10;        
        m_demical_place_value=PFC_DISPLAY_DOT_NUM[PFC_1ST_DEVICE];             
        UIF_MENU_PTR=UIF_DEMICEL_PLACE_SET_VALUE_TOTAL-1;
        
    }    
    if (UIF_CHK_LEVEL_CHG_API())
    {
        UIF_CLR_LED_API();
        UIF_DIS_DIGINUM_API(gb_uif_digi_num);
    }      
    UIF_LED7SEG_REFRESH_API(0,0);   
    
    if (UIF_KEY_CLICK_API(KEY_ENTER))
    {          
        PFC_DISPLAY_DOT_NUM[PFC_1ST_DEVICE]=m_demical_place_value;
        PFC_SAVE_SYSTEM_VAR_TO_EEPROM=1;
        UIF_STATE_INSTALL_API(uif_main_menu_state);
        return;
    }
    if (UIF_KEY_CLICK_API(KEY_UP))
    {
        m_demical_place_value++;
        m_demical_place_value=(m_demical_place_value>5)?3:m_demical_place_value;
        UINT16 temp=m_demical_place_value;       
        for (i=UIF_DEMICEL_PLACE_SET_VALUE_TOTAL;i>0;i--,temp/=10)
            gb_uif_digi_num[i-1]=temp%10;         
        UIF_SET_LEVEL_CHG_API();
    }    
         
    if (UIF_KEY_CLICK_API(KEY_ESC))
    {
        m_demical_place_value--;
        m_demical_place_value=(m_demical_place_value<3)?5:m_demical_place_value;
        UINT16 temp=m_demical_place_value;   
        for (i=UIF_DEMICEL_PLACE_SET_VALUE_TOTAL;i>0;i--,temp/=10)
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
//! @brief 		 demicel_place_set_value keymap 
//
//**********************************************************************************************************************
const STC_UIF_KEYMAP uif_demicel_place_set_value_keymap[]=
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
//! @brief 		 DEMICEL_PLACE_SET_VALUE state Table 
//
//**********************************************************************************************************************
const STC_UIF_STATE uif_demicel_place_set_value_state=
{
/*        level                  item_cnt                     menu_func            menu_keymap   			max_line*/
	UIF_2ND_MENU_LEVEL       ,UIF_DEMICEL_PLACE_SET_VALUE_TOTAL       ,uif_demicel_place_set_value_state_task,       uif_demicel_place_set_value_keymap		,1
};

