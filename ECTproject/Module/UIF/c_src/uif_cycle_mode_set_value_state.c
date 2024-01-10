//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 uif_cycle_mode_set_value_state.c
//
//! @author 	 Jacky Lin
//
//! @date 		 2023/06/12
//
//  @brief 		 uif_cycle_mode_set_value_state functions
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
//! @brief 		 uif_cycle_mode_set_value Level list definition
//
//**********************************************************************************************************************
enum UIF_CYCLE_MODE_SET_VALUE_LEVEL_LIST
{
      UIF_CYCLE_MODE_SET_VALUE_NO_LEVEL,
      UIF_CYCLE_MODE_SET_VALUE_YES_LEVEL,
      UIF_CYCLE_MODE_SET_VALUE_TOTAL,
};
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @author 	 Jacky Lin
//
//! @date 		 2023/06/12
//
//! @brief 		 uif_cycle_mode_set_value map definition
//
//**********************************************************************************************************************
const STC_UIF_MENU uif_cycle_mode_set_value_menu_map[]=
{
	UIF_NULL,UIF_NULL,
};
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 uif_cycle_mode_set_value_state_task
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
INT16 m_cycle_mode_index;
void uif_cycle_mode_set_value_state_task()
{   
    if (UIF_GET_QUARTER_SEC_CNT_API()==0)
         UIF_SET_QUARTER_SEC_CNT_API(100);
    
    if (UIF_CHK_STATE_CHG_API())
    {
        m_cycle_mode_index=PFC_CYCLE_MODE;   	
    }    
    if (UIF_CHK_LEVEL_CHG_API())
    {
        UIF_CLR_LED_API();
        if(m_cycle_mode_index==PFC_CYCLE_MODE_NO)
            UIF_DIS_STR_API("      NO");
        else 
            UIF_DIS_STR_API("     YES");        
    }      
    UIF_LED7SEG_REFRESH_API(0,0);   
    
    if (UIF_KEY_CLICK_API(KEY_ENTER))
    {          
        PFC_CYCLE_MODE=m_cycle_mode_index;
        PFC_SAVE_SYSTEM_VAR_TO_EEPROM=1;
        UIF_STATE_INSTALL_API(uif_mutiple_end_main_menu_state);
    }
    if (UIF_KEY_CLICK_API(KEY_UP))
    {
        m_cycle_mode_index++;
        m_cycle_mode_index=(m_cycle_mode_index>PFC_CYCLE_MODE_YES)?PFC_CYCLE_MODE_NO:m_cycle_mode_index;
        UIF_SET_LEVEL_CHG_API();
    }    
         
    if (UIF_KEY_CLICK_API(KEY_ESC))
    {
        m_cycle_mode_index--;
        m_cycle_mode_index=(m_cycle_mode_index<0)?PFC_CYCLE_MODE_YES:m_cycle_mode_index;
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
//! @brief 		 cycle_mode_set_value keymap 
//
//**********************************************************************************************************************
const STC_UIF_KEYMAP uif_cycle_mode_set_value_keymap[]=
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
//! @brief 		 CYCLE_MODE_SET_VALUE state Table 
//
//**********************************************************************************************************************
const STC_UIF_STATE uif_cycle_mode_set_value_state=
{
/*        level                  item_cnt                     menu_func            menu_keymap   			max_line*/
	UIF_2ND_MENU_LEVEL       ,UIF_CYCLE_MODE_SET_VALUE_TOTAL       ,uif_cycle_mode_set_value_state_task,       uif_cycle_mode_set_value_keymap		,2
};

