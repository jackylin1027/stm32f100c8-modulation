//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 	 uif_welcome_state.c
//
//! @author 	 Willman Chen
//
//! @date 	 2009/06/23
//
// @brief 	 After power on,show "FINE-TEK"
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "uif_idef.h"
#include "uif_welcome_state.h"
#include "uif_main_menu_state.h"
#include "..\uif_udef.h"
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @author  Willman Chen
//
//! @date 	 2009/06/23
//
//! @brief 	 Welcome Level Definition
//
//**********************************************************************************************************************
enum WELCOME_LEVEL_LIST
{
    WELCOME_FINE,
    WELCOME_TOTAL,
};
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 uif_welcome_state_task
//
//! @author  Willman Chen
//
//! @date 	 2009/06/23
//
//! @brief 	 task function
//
//**********************************************************************************************************************
#define UIF_WE_ARE_FINETEK              1
#define UIF_WE_ARE_APLUSFINE            0

#if UIF_WE_ARE_FINETEK ==1 
  const UINT8 uif_welcome_str[]="  FINE  ";
#endif
#if UIF_WE_ARE_APLUSFINE == 1
  const UINT8 uif_welcome_str[]="FINE";
  const UINT8 uif_company_str[]="APLUS FINETEK SENSOR";
#endif
void uif_welcome_fine_task()
{
    if (UIF_GET_HALF_SEC_CNT_API()==0)
        UIF_SET_HALF_SEC_CNT_API(64);

    if (UIF_GET_HALF_SEC_CNT_API()==1)
    {
        UIF_STATE_REMOVE_API();
        return ;
    }
    
        UIF_CLR_LED_API();
        switch(UIF_GET_HALF_SEC_CNT_API())
        {
          case 64:
          UIF_DIS_STR_API(uif_welcome_str);
          UIF_LED7SEG_REFRESH_API(0,0);
          break;
          case 48:
          UIF_DIS_STR_API(&PFC_FIRMWARE_VERSION);
          UIF_LED7SEG_REFRESH_API(0,0);
          break;          
          case 32:
          UIF_DIS_STR_API("88888888");
          UIF_XOR_DIS_STR_API("........");
          UIF_LED7SEG_REFRESH_API(0,0);
          break;
          case 16:
          UIF_DIS_STR_API("--------");
          UIF_LED7SEG_REFRESH_API(0,0);
          break;           
        }    
}

//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @author  Willman Chen
//
//! @date 	 2009/06/23
//
//! @brief 	 Keymap Table List
//
//**********************************************************************************************************************
const STC_UIF_KEYMAP uif_welcome_keymap[]=
{
    UIF_NULL_FUNC,    UIF_NULL,     // KEY_ENTER 
    UIF_NULL_FUNC,    UIF_NULL,     // KEY_UP     
    UIF_NULL_FUNC,    UIF_NULL,	    // KEY_ESC
};
const STC_UIF_STATE  uif_welcome_state=
{
    /*        level              item_cnt           menu_func                   menu_keymap                  			max_line*/
    UIF_SWAP_MENU_LEVEL   ,WELCOME_TOTAL  ,uif_welcome_fine_task    ,(const STC_UIF_KEYMAP*)&uif_welcome_keymap     ,0
};
