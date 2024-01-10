//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 uif_demical_place_1_set_value_state.c
//
//! @author 	 Jacky Lin
//
//! @date 		 2023/06/12
//
//  @brief 		 uif_demical_place_1_set_value_state functions
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
#include "uif_mutiple_end_main_menu_state.h"
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @author 	 Jacky Lin
//
//! @date 		 2023/06/12
//
//! @brief 		 uif_demical_place_1_set_value Level list definition
//
//**********************************************************************************************************************
enum UIF_DEMICAL_PLACE_1_SET_VALUE_LEVEL_LIST
{
	UIF_DEMICEL_PLACE_1_SET_VALUE_DIGI1_LEVEL,
        UIF_DEMICEL_PLACE_1_SET_VALUE_DIGI2_LEVEL,
        UIF_DEMICEL_PLACE_1_SET_VALUE_DIGI3_LEVEL,
        UIF_DEMICEL_PLACE_1_SET_VALUE_DIGI4_LEVEL,
        UIF_DEMICEL_PLACE_1_SET_VALUE_DIGI5_LEVEL,
        UIF_DEMICEL_PLACE_1_SET_VALUE_DIGI6_LEVEL,
        UIF_DEMICEL_PLACE_1_SET_VALUE_DIGI7_LEVEL,
        UIF_DEMICEL_PLACE_1_SET_VALUE_DIGI8_LEVEL,
	UIF_DEMICAL_PLACE_1_SET_VALUE_TOTAL,        
};
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @author 	 Jacky Lin
//
//! @date 		 2023/06/12
//
//! @brief 		 uif_demical_place_1_set_value map definition
//
//**********************************************************************************************************************
const STC_UIF_MENU uif_demical_place_1_set_value_menu_map[]=
{
	UIF_NULL,UIF_NULL,
};
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 uif_demical_place_1_set_value_state_task
//
//! @author 	 Jacky Lin
//
//! @date 		 2023/06/12
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
UINT8 demical_place_1_temp;
void uif_demical_place_1_set_value_state_task()
{
    UINT8 i;    
    
    if (UIF_GET_QUARTER_SEC_CNT_API()==0)
         UIF_SET_QUARTER_SEC_CNT_API(100);
    
    if (UIF_CHK_STATE_CHG_API())
    {      
        UINT16 temp=PFC_DISPLAY_DOT_NUM[PFC_1ST_DEVICE];   	       
        for (i=UIF_DEMICAL_PLACE_1_SET_VALUE_TOTAL;i>0;i--,temp/=10)
                gb_uif_digi_num[i-1]=temp%10;        
        demical_place_1_temp=PFC_DISPLAY_DOT_NUM[PFC_1ST_DEVICE];             
        UIF_MENU_PTR=UIF_DEMICAL_PLACE_1_SET_VALUE_TOTAL-1;
        
    }    
    if (UIF_CHK_LEVEL_CHG_API())
    {
        UIF_CLR_LED_API();
        UIF_DIS_DIGINUM_API(gb_uif_digi_num);
    }      
    UIF_LED7SEG_REFRESH_API(0,0);   
    //===== 修正設定選單用 press button long term 的方法, 接改用 click button 即可, Ver 1.0.08 =====
    if (UIF_KEY_CLICK_API(KEY_ENTER))
    {          
        PFC_DISPLAY_DOT_NUM[PFC_1ST_DEVICE]=demical_place_1_temp;
        PFC_SAVE_SYSTEM_VAR_TO_EEPROM=1;
        UIF_STATE_INSTALL_API(uif_mutiple_end_main_menu_state);
        return;
    }
    if (UIF_KEY_CLICK_API(KEY_UP))
    {
        demical_place_1_temp++;
        demical_place_1_temp=(demical_place_1_temp>5)?3:demical_place_1_temp;
        UINT16 temp=demical_place_1_temp;       
        for (i=UIF_DEMICAL_PLACE_1_SET_VALUE_TOTAL;i>0;i--,temp/=10)
            gb_uif_digi_num[i-1]=temp%10;         
        UIF_SET_LEVEL_CHG_API();
    }    
         
    if (UIF_KEY_CLICK_API(KEY_ESC))
    {
        demical_place_1_temp--;
        demical_place_1_temp=(demical_place_1_temp<3)?5:demical_place_1_temp;
        UINT16 temp=demical_place_1_temp;   
        for (i=UIF_DEMICAL_PLACE_1_SET_VALUE_TOTAL;i>0;i--,temp/=10)
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
//! @date 		 2023/06/12
//
//! @brief 		 demical_place_1_set_value keymap 
//
//**********************************************************************************************************************
const STC_UIF_KEYMAP uif_demical_place_1_set_value_keymap[]=
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
//! @date 		 2023/06/12
//
//! @brief 		 DEMICAL_PLACE_1_SET_VALUE state Table 
//
//**********************************************************************************************************************
const STC_UIF_STATE uif_demical_place_1_set_value_state=
{
/*        level                  item_cnt                     menu_func            menu_keymap   			max_line*/
	UIF_2ND_MENU_LEVEL       ,UIF_DEMICAL_PLACE_1_SET_VALUE_TOTAL       ,uif_demical_place_1_set_value_state_task,       uif_demical_place_1_set_value_keymap		,1
};

