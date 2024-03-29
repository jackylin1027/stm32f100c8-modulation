//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 uif_baudrate_set_state.c
//
//! @author 	 Jacky Lin
//
//! @date 		 2023/05/29
//
//  @brief 		 uif_baudrate_set_state functions
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
#include "uif_baudrate_set_value_state.h"
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @author 	 Jacky Lin
//
//! @date 		 2023/05/29
//
//! @brief 		 uif_baudrate_set Level list definition
//
//**********************************************************************************************************************
enum UIF_BAUDRATE_SET_LEVEL_LIST
{
	UIF_BAUDRATE_SET_LEVEL,
	UIF_BAUDRATE_SET_TOTAL,
};
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @author 	 Jacky Lin
//
//! @date 		 2023/05/29
//
//! @brief 		 uif_baudrate_set map definition
//
//**********************************************************************************************************************
const STC_UIF_MENU uif_baudrate_set_menu_map[]=
{
	UIF_NULL,UIF_NULL,
};
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @author 	 Jacky Lin
//
//! @date 		 2023/05/29
//
//! @brief 		 uif_main_menu map definition
//
//**********************************************************************************************************************
const STC_UIF_SETTING_MENU uif_baudrate_set_setting_menu_map[]=
{
    "BR", UIF_NULL,   UIF_NULL,
};
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 uif_baudrate_set_state_task
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
void uif_baudrate_set_state_task()
{
    if (UIF_GET_QUARTER_SEC_CNT_API()==0)
         UIF_SET_QUARTER_SEC_CNT_API(100);
    if (UIF_CHK_LEVEL_CHG_API())
    {
        UIF_CLR_LED_API();
        uif_display_setting_menu_item((UINT8*)uif_baudrate_set_setting_menu_map);
    }
    UIF_LED7SEG_REFRESH_API(0,0);
    
    if(UIF_KEY_CLICK_API(KEY_ENTER))
    {
        UIF_STATE_INSTALL_API(uif_baudrate_set_value_state);
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
//! @date 		 2023/05/29
//
//! @brief 		 baudrate_set keymap 
//
//**********************************************************************************************************************
const STC_UIF_KEYMAP uif_baudrate_set_keymap[]=
{
    UIF_NULL_FUNC,    UIF_NULL,     // KEY_ENTER 
    UIF_NULL_FUNC,    UIF_NULL,     // KEY_UP     
    UIF_STATE_REMOVE_FUNC,    UIF_NULL,	    // KEY_ESC
};
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @author 	 Jacky Lin
//
//! @date 		 2023/05/29
//
//! @brief 		 BAUDRATE_SET state Table 
//
//**********************************************************************************************************************
const STC_UIF_STATE uif_baudrate_set_state=
{
/*        level                  item_cnt                     menu_func            menu_keymap   			max_line*/
	UIF_2ND_MENU_LEVEL       ,UIF_BAUDRATE_SET_TOTAL       ,uif_baudrate_set_state_task,       uif_baudrate_set_keymap		,1
};

