//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 uif_main_menu_state.c
//
//! @author 	 Jacky Lin
//
//! @date 		 2023/05/26
//
//  @brief 		 uif_main_menu_state functions
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
#include "uif_address_set_value_state.h"
#include "uif_demicel_place_set_value_state.h"
#include "uif_baudrate_set_value_state.h"
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @author 	 Jacky Lin
//
//! @date 		 2023/05/26
//
//! @brief 		 uif_main_menu Level list definition
//
//**********************************************************************************************************************
enum UIF_MAIN_MENU_LEVEL_LIST
{
	UIF_MAIN_MENU_ADDRESS_VALUE_LEVEL,
        UIF_MAIN_MENU_BAUDRATE_VALUE_LEVEL,
        UIF_MAIN_MENU_DEMICAL_PLACE_VALUE_LEVEL,
	UIF_MAIN_MENU_TOTAL,
};
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @author 	 Jacky Lin
//
//! @date 		 2023/05/26
//
//! @brief 		 uif_main_menu map definition
//
//**********************************************************************************************************************
const STC_UIF_MENU uif_main_menu_menu_map[]=
{
	UIF_NULL,UIF_NULL,
};
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @author 	 Jacky Lin
//
//! @date 		 2023/05/26
//
//! @brief 		 uif_main_menu map definition
//
//**********************************************************************************************************************
const STC_UIF_SETTING_MENU uif_main_menu_setting_menu_map[]=
{
    "ADD", UIF_NULL,   UIF_NULL,
    "BR", UIF_NULL,   UIF_NULL,
    "DEC", UIF_NULL,   UIF_NULL,
};
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 uif_main_menu_state_task
//
//! @author 	 Jacky Lin
//
//! @date 		 2023/05/26
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void uif_main_menu_state_task()
{
    if (UIF_GET_QUARTER_SEC_CNT_API()==0)
         UIF_SET_QUARTER_SEC_CNT_API(100);
    if (UIF_CHK_LEVEL_CHG_API())
    {
        UIF_CLR_LED_API();
        uif_display_setting_menu_item((UINT8*)uif_main_menu_setting_menu_map);
    }
    //===== LED 字型閃爍, Ver1.0.02 =====
    for(UINT8 i=0; i<8; i++)
        UIF_SET_LED_FLASH_API(i,(UIF_GET_QUARTER_SEC_CNT_API()%2), 0);    
    UIF_LED7SEG_REFRESH_API(0,0);
    
    //===== 修改設定選單的設定流程以及方法, Ver 1.0.04 =====
    if(UIF_KEY_CLICK_API(KEY_ENTER))
    {
        switch(gs_uif_status.menu_ptr)
        {
            case UIF_MAIN_MENU_ADDRESS_VALUE_LEVEL:           UIF_STATE_INSTALL_API(uif_address_set_value_state);break;
            case UIF_MAIN_MENU_BAUDRATE_VALUE_LEVEL:          UIF_STATE_INSTALL_API(uif_baudrate_set_value_state);break;
            case UIF_MAIN_MENU_DEMICAL_PLACE_VALUE_LEVEL:     UIF_STATE_INSTALL_API(uif_demicel_place_set_value_state);break;
        }    
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
//! @date 		 2023/05/26
//
//! @brief 		 main_menu keymap 
//
//**********************************************************************************************************************
const STC_UIF_KEYMAP uif_main_menu_keymap[]=
{  
    UIF_NULL_FUNC,    UIF_NULL,     // KEY_ENTER 
    UIF_LEVEL_NEXT_FUNC,    UIF_NULL,     // KEY_UP     
    UIF_STATE_REMOVE_FUNC,    UIF_NULL,	    // KEY_ESC  
};
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @author 	 Jacky Lin
//
//! @date 		 2023/05/26
//
//! @brief 		 MAIN_MENU state Table 
//
//**********************************************************************************************************************
const STC_UIF_STATE uif_main_menu_state=
{
/*        level                  item_cnt                     menu_func            menu_keymap   			max_line*/
	UIF_1ST_MENU_LEVEL       ,UIF_MAIN_MENU_TOTAL       ,uif_main_menu_state_task,       uif_main_menu_keymap		,3
};

