//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 	 uif_show_value_state.c
//
//! @author 	 Willman Chen
//
//! @date 	 2009/07/31
//
//  @brief 	 uif_show_value_state functions
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
//! @author 	 Willman Chen
//
//! @date 		 2009/07/31
//
//! @brief 		 uif_show_value Level list definition
//
//**********************************************************************************************************************
enum UIF_SHOW_VALUE_LEVEL_LIST
{
    UIF_SHOW_VALUE_DIGI1_LEVEL,
    UIF_SHOW_VALUE_DIGI2_LEVEL,
    UIF_SHOW_VALUE_DIGI3_LEVEL,
    UIF_SHOW_VALUE_DIGI4_LEVEL,
    UIF_SHOW_VALUE_DIGI5_LEVEL,
    UIF_SHOW_VALUE_DIGI6_LEVEL,
    UIF_SHOW_VALUE_DIGI7_LEVEL,
    UIF_SHOW_VALUE_DIGI8_LEVEL,    
    UIF_SHOW_VALUE_TOTAL,
};
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @author 	 Willman Chen
//
//! @date 		 2009/07/31
//
//! @brief 		 uif_show_value map definition
//
//**********************************************************************************************************************
const STC_UIF_MENU uif_show_value_menu_map[]=
{
//   Prompt     	 	next state  		var index		var_type
    UIF_NULL			,UIF_NULL			,UIF_NULL			,UIF_NULL
};
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 uif_show_value_state_task
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
UINT8 channel_prompt[8]={' ',' ',' ',' ',' ', 'C','H','1'};
void uif_show_value_state_task()
{
    UINT64 temp_value;
    UINT8 i, dot_offset=0;

    if (UIF_GET_HALF_SEC_CNT_API()==0)
        UIF_SET_HALF_SEC_CNT_API(100);
    
    UIF_CLR_LED_API(); 
    
    if (PFC_SHOW_VALUE_TYPE==PFC_SHOW_VALUE_MAIN)
    {
        //===== 判斷EPH口徑的小數位, DN40跟菲DN40的都不會一樣, 必須在顯示上特別處理, Ver 1.0.03 =====
        if((gs_eph_comm_transmitter[PFC_DISPLAY_DEVICE].volumeBCD_dotBCD&PFC_BCD_VOLUME_DOT_MASK)==PFC_EPH_ABOVE_DN40_DOT)
        {
            dot_offset=1;
            PFC_DISPLAY_DOT_NUM[PFC_DISPLAY_DEVICE]=(PFC_DISPLAY_DOT_NUM[PFC_DISPLAY_DEVICE]>=5)?4:PFC_DISPLAY_DOT_NUM[PFC_DISPLAY_DEVICE];
        }    
        temp_value=FN_BCD2DEC_U64_API((gs_eph_comm_transmitter[PFC_DISPLAY_DEVICE].volumeBCD_dotBCD&PFC_BCD_VOLUME_MASK)>>
                  (PFC_BCD_VOLUME_SHIFT+(PFC_BCD_VOLUME_OFFSET_UNIT*((PFC_DOT_NUM_REF-dot_offset)-PFC_DISPLAY_DOT_NUM[PFC_1ST_DEVICE]))));
            
        for (i=UIF_SHOW_VALUE_TOTAL;i>0;i--,temp_value/=10)
            gb_uif_digi_num[i-1]=temp_value%10;        
        UIF_DIS_DIGINUM_API(gb_uif_digi_num);
        uif_display_dot_position(PFC_DISPLAY_DOT_NUM[PFC_DISPLAY_DEVICE]);    
    }
    else if (PFC_SHOW_VALUE_TYPE==PFC_SHOW_VALUE_CHANNEL)
    {   
        channel_prompt[7]=PFC_DISPLAY_DEVICE+1+'0';
        UIF_DIS_STR_API(channel_prompt);
    }
    UIF_LED7SEG_REFRESH_API(gb_uif_digital_dot_pos,0); //===== 0: red led
    
    if(UIF_KEY_CLICK_API(KEY_ENTER))
    {
        if(PFC_DETECTED_HARDWARE_VERSION==PFC_DETECTED_HARDWARE_MULTIPLE_END)
            UIF_STATE_INSTALL_API(uif_mutiple_end_main_menu_state);
        else
            UIF_STATE_INSTALL_API(uif_main_menu_state);
    }

    if(UIF_KEY_CLICK_API(KEY_UP))
    {
    }    
    
    if(UIF_KEY_CLICK_API(KEY_ESC))
    {
        //===== 新增手動變更顯示 channel 的功能(1對8), Ver 1.0.05 =====
        PFC_MANUAL_CHANGE_CHANNEL_TASK_API();
    }     
}
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @author 	 Willman Chen
//
//! @date 		 2009/07/31
//
//! @brief 		 show_value keymap
//
//**********************************************************************************************************************
const STC_UIF_KEYMAP uif_show_value_keymap[]=
{
    UIF_NULL_FUNC,    UIF_NULL,     // KEY_ENTER 
    UIF_NULL_FUNC,    UIF_NULL,     // KEY_UP     
    UIF_NULL_FUNC,    UIF_NULL,	    // KEY_ESC
};
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @author 	 Willman Chen
//
//! @date 		 2009/07/31
//
//! @brief 		 SHOW_VALUE state Table
//
//**********************************************************************************************************************
const STC_UIF_STATE uif_show_value_state=
{
    /*        level                  item_cnt                     menu_func           			 menu_keymap   			max_line*/
    UIF_STATUS_LEVEL       ,UIF_SHOW_VALUE_TOTAL       ,uif_show_value_state_task,       uif_show_value_keymap	,0
};

