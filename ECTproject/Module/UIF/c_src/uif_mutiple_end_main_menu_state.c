//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 uif_mutiple_end_main_menu_state.c
//
//! @author 	 Jacky Lin
//
//! @date 		 2023/06/12
//
//  @brief 		 Task Subroutine
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S 
//
//**********************************************************************************************************************
#include "..\drv_src\uif_drv.h" 
#include "uif_glb_vars.h"
#include "uif_address_set_value_state.h"
#include "uif_baudrate_set_value_state.h"
#include "uif_demical_place_1_set_value_state.h"
#include "uif_demical_place_2_set_value_state.h"
#include "uif_demical_place_3_set_value_state.h"
#include "uif_demical_place_4_set_value_state.h"
#include "uif_demical_place_5_set_value_state.h"
#include "uif_demical_place_6_set_value_state.h"
#include "uif_demical_place_7_set_value_state.h"
#include "uif_demical_place_8_set_value_state.h"
#include "uif_cycle_mode_set_value_state.h"
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @author 	 Jacky Lin
//
//! @date 		 2023/06/12
//
//! @brief 		 uif_main_menu Level list definition
//
//**********************************************************************************************************************
enum UIF_MUTIPLE_END_MAIN_MENU_LEVEL_LIST
{
	UIF_MUTIPLE_END_MAIN_MENU_ADDRESS_VALUE_LEVEL,
        UIF_MUTIPLE_END_MAIN_MENU_BAUDRATE_VALUE_LEVEL,
        UIF_MUTIPLE_END_MAIN_MENU_DEMICAL_PLACE1_VALUE_LEVEL,
        UIF_MUTIPLE_END_MAIN_MENU_DEMICAL_PLACE2_VALUE_LEVEL,
        UIF_MUTIPLE_END_MAIN_MENU_DEMICAL_PLACE3_VALUE_LEVEL,
        UIF_MUTIPLE_END_MAIN_MENU_DEMICAL_PLACE4_VALUE_LEVEL,
        UIF_MUTIPLE_END_MAIN_MENU_DEMICAL_PLACE5_VALUE_LEVEL,
        UIF_MUTIPLE_END_MAIN_MENU_DEMICAL_PLACE6_VALUE_LEVEL,
        UIF_MUTIPLE_END_MAIN_MENU_DEMICAL_PLACE7_VALUE_LEVEL,
        UIF_MUTIPLE_END_MAIN_MENU_DEMICAL_PLACE8_VALUE_LEVEL,
        UIF_MUTIPLE_END_MAIN_MENU_CYCLE_MODE_VALUE_LEVEL,
	UIF_MUTIPLE_END_MAIN_MENU_TOTAL,
};
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @author 	 Jacky Lin
//
//! @date 		 2023/06/12
//
//! @brief 		 uif_main_menu map definition
//
//**********************************************************************************************************************
const STC_UIF_MENU uif_mutiple_end_main_menu_menu_map[]=
{
	UIF_NULL,UIF_NULL,
};
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @author 	 Jacky Lin
//
//! @date 		 2023/06/12
//
//! @brief 		 uif_main_menu map definition
//
//**********************************************************************************************************************
const STC_UIF_SETTING_MENU uif_mutiple_end_main_menu_setting_menu_map[]=
{
    "ADD", UIF_NULL,   &uif_address_set_value_state,
    "BR", UIF_NULL,   &uif_baudrate_set_value_state,
    "DEC-1", UIF_NULL,   &uif_demical_place_1_set_value_state,
    "DEC-2", UIF_NULL,   &uif_demical_place_2_set_value_state,
    "DEC-3", UIF_NULL,   &uif_demical_place_3_set_value_state,
    "DEC-4", UIF_NULL,   &uif_demical_place_4_set_value_state,
    "DEC-5", UIF_NULL,   &uif_demical_place_5_set_value_state,
    "DEC-6", UIF_NULL,   &uif_demical_place_6_set_value_state,
    "DEC-7", UIF_NULL,   &uif_demical_place_7_set_value_state,
    "DEC-8", UIF_NULL,   &uif_demical_place_8_set_value_state,
    "CYC", UIF_NULL,   &uif_cycle_mode_set_value_state,
};
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
//! @fn 			 uif_mutiple_end_main_menu_state_task
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
void uif_mutiple_end_main_menu_state_task()
{
    if (UIF_GET_QUARTER_SEC_CNT_API()==0)
         UIF_SET_QUARTER_SEC_CNT_API(100);
    if (UIF_CHK_LEVEL_CHG_API())
    {
        UIF_CLR_LED_API();
        uif_display_setting_menu_item((UINT8*)uif_mutiple_end_main_menu_setting_menu_map);
    }
    for(UINT8 i=0; i<8; i++)
        UIF_SET_LED_FLASH_API(i,(UIF_GET_QUARTER_SEC_CNT_API()%2), 0);    
    UIF_LED7SEG_REFRESH_API(0,0);    
    //===== 修改設定選單的設定流程以及方法, Ver 1.0.05 =====
    if(UIF_KEY_CLICK_API(KEY_ENTER))
    {
        //switch(gs_uif_status.menu_ptr)
        //{
        //    case UIF_MAIN_MENU_ADDRESS_VALUE_LEVEL:           UIF_STATE_INSTALL_API(uif_address_set_value_state);break;
        //    case UIF_MAIN_MENU_BAUDRATE_VALUE_LEVEL:          UIF_STATE_INSTALL_API(uif_baudrate_set_value_state);break;
        //    case UIF_MAIN_MENU_DEMICAL_PLACE_VALUE_LEVEL:     UIF_STATE_INSTALL_API(uif_demicel_place_set_value_state);break;
        //}    
    }    
    if(UIF_KEY_CLICK_API(KEY_UP))
    {
    }    
    if(UIF_KEY_CLICK_API(KEY_ESC))
    {
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
//! @brief 		 main_menu keymap 
//
//**********************************************************************************************************************
const STC_UIF_KEYMAP uif_mutiple_end_main_menu_keymap[]=
{  
    UIF_STATE_NEXT_FUNC,    uif_mutiple_end_main_menu_setting_menu_map,     // KEY_ENTER 
    UIF_LEVEL_NEXT_FUNC,    UIF_NULL,     // KEY_UP     
    UIF_STATE_REMOVE_FUNC,    UIF_NULL,	    // KEY_ESC  
};
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @author 	 Jacky Lin
//
//! @date 		 2023/06/12
//
//! @brief 		 MAIN_MENU state Table 
//
//**********************************************************************************************************************
const STC_UIF_STATE uif_mutiple_end_main_menu_state=
{
/*        level                  item_cnt                     menu_func            menu_keymap   			max_line*/
	UIF_1ST_MENU_LEVEL       ,UIF_MUTIPLE_END_MAIN_MENU_TOTAL       ,uif_mutiple_end_main_menu_state_task,       uif_mutiple_end_main_menu_keymap		,UIF_MUTIPLE_END_MAIN_MENU_TOTAL
};
#ifdef __cplusplus
}
#endif

