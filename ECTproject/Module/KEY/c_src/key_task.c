//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 	 key_task.c
//
//! @author  Willman Chen
//
//! @date 	 2009/06/23
//
//  @brief 	 Task Subroutine
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "..\drv_src\key_drv.h"
#include "key_glb_vars.h"
#include "key_idef.h"
#include "key_task.h"
#include "..\key_udef.h"
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn      key_scan_key
//
//! @author  Willman Chen
//
//! @date    2009/06/23
//
//! @brief   Clear key I/O Buffer
//
//**********************************************************************************************************************
UINT8 key_scan_key()
{
    UINT8 key=0,mask,i;
    for (i=0,mask=0x01; i<KEY_KEY_NUM; i++)
    {
        if (i==0 && !KEY_KEY1_CHK())
            key|=mask;
        else if (i==1 && !KEY_KEY2_CHK())
            key|=mask;
        else if (i==2 && !KEY_KEY3_CHK())
            key|=mask;
        mask<<=1;
    }
    return key;
}
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn      key_scan_task
//
//! @author  Willman Chen
//
//! @date    2009/06/23
//
//! @brief   Clear key I/O Buffer
//
//**********************************************************************************************************************
UINT16 key_scan_task()
{
    UINT16 key=0;
    //KEY_COM1_LOW();
    //key=key_scan_key();
    //key<<=KEY_KEY_NUM;
    //KEY_COM1_HIGH();
    //KEY_COM2_LOW();
    key|=key_scan_key();
    //KEY_COM2_HIGH();
    return key;
}
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 key_do_buf_clr
//
//! @author  Willman Chen
//
//! @date 	 2009/06/23
//
//! @brief 	 Clear key I/O Buffer
//
//**********************************************************************************************************************
void key_do_buf_clr()
{
    UINT8 i;
    gb_key_curr=gb_key_click=0x00;
    for (i=KEY_START; i<KEY_TOTAL; i++)
    {
        gs_key_pressed[i].key_expired=gs_key_pressed[i].key_timer=0;
        gs_key_repeat[i].key_expired=gs_key_repeat[i].key_timer=0;
    }
}
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 key_buf_clr
//
//! @author  Willman Chen
//
//! @date 	 2009/06/23
//
//! @brief 	 Clear key I/O Buffer
//
//**********************************************************************************************************************
void key_buf_clr()
{
    if (key_scan_task())   // if user didn't release keys,just raising the flag
    {
        gb_key_clr_buf=1;
    }
    else
    {
        gb_key_clr_buf=0;
        key_do_buf_clr();
    }
}
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 key_click_chk
//
//! @author  Willman Chen
//
//! @date 	 2009/06/23
//
//! @brief 	 the function for checking click key
//
// @param 	 key_index  The index of the keymap for expiring the event .
//
// @return 	 result     click or not
//
//**********************************************************************************************************************
UINT8 key_click_chk(UINT8 key_index)
{
    UINT8 result=(gb_key_click&KEY_OP(key_index));
    gb_key_click&=~(KEY_OP(key_index));
    return result;
}
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 key_pressed_chk
//
//! @author	 Willman Chen
//
//! @date 	 2009/06/23
//
//! @brief 	 the function for checking pressed key
//
//! @param 	 key_index  The index of the keymap for expiring the event.
//
//! @return	 result   pressed or not
//
//**********************************************************************************************************************
UINT8 key_pressed_chk(UINT8 key_index)
{
    UINT8 result=gs_key_pressed[key_index].key_expired;
    gs_key_pressed[key_index].key_expired=0;
    return result;
}
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 key_repeat_chk
//
//! @author  Willman Chen
//
//! @date 	 2009/06/23
//
//! @brief 	 The function for checking repeat key.
//
//! @param 	 key_index  the index of keymap for expiring repeat event.
//
//! @return  result repeat or not
//
//**********************************************************************************************************************
UINT8 key_repeat_chk(UINT8 key_index)
{
    UINT8 result=gs_key_repeat[key_index].key_expired;
    gs_key_repeat[key_index].key_expired=0;
    return result;
}
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
// @fn 		 key_task
//
// @author 	 Willman Chen
//
// @date 	 2009/06/23
//
// @brief 	 The task function place in the main loop of pfc,for detecting the key events.
//
//**********************************************************************************************************************
void key_task()
{
    UINT16 key_pad=key_scan_task();
#if KEY_HAS_REPEAT||KEY_HAS_PRESSED
    UINT8 i;
#endif

    if (gb_key_clr_buf && !key_pad)   // if the flag on,and user release the keys. it's time to clear the key buffer.
    {
        gb_key_clr_buf=0;
        key_do_buf_clr();
    }

#if KEY_HAS_CLICK == 1
    gb_key_click=gb_key_curr^key_pad;
    gb_key_click=gb_key_click&key_pad;   // Down expired.
    if (gb_key_click)
    {
        KEY_UIF_ACTION_API();
        KEY_TURN_ON_BACKLIGHT_API();
    }
#endif

#if KEY_HAS_PRESSED == 1
    STC_KEY *pressed_ptr=&gs_key_pressed[0];
    for (i=0; i<KEY_TOTAL; i++,pressed_ptr++)
    {
        if(key_pad&KEY_OP(i) && !pressed_ptr->key_expired)
        {
            if (pressed_ptr->key_timer<KEY_MAX_BUF_TIME)
                pressed_ptr->key_timer++;
            if (pressed_ptr->key_timer>KEY_PRESSED_TIME)
            {
                pressed_ptr->key_expired=1;
                pressed_ptr->key_timer=0;     // it's good to clear the timer conveniently.
                KEY_UIF_ACTION_API();
                KEY_TURN_ON_BACKLIGHT_API();
            }
        }
        else
        {
            pressed_ptr->key_timer=0;
        }
    }  // end for (i=0;i<KEY_TOTAL;i++,pressed_ptr++)
#endif
#if KEY_HAS_REPEAT == 1
    STC_KEY *repeat_ptr=&gs_key_repeat[0];
    for (i=0; i<KEY_TOTAL; i++,repeat_ptr++)
    {
        if(key_pad&KEY_OP(i) && !repeat_ptr->key_expired)
        {
            if (repeat_ptr->key_timer<KEY_MAX_BUF_TIME)
                repeat_ptr->key_timer++;
            if (repeat_ptr->key_timer>KEY_REPEAT_START_TIME)
            {
                UINT8 repeat_timing=repeat_ptr->key_timer-KEY_REPEAT_START_TIME;
                if (repeat_timing>KEY_REPEAT_INTERVAL)
                {
                    repeat_ptr->key_expired=1;
                    repeat_ptr->key_timer=KEY_REPEAT_START_TIME;
                    KEY_UIF_ACTION_API();
                    KEY_TURN_ON_BACKLIGHT_API();
                }
            }
        }
        else  // if user release the key ,we need to clear the timer
        {
            repeat_ptr->key_timer=0x00;
            repeat_ptr->key_expired=0;
        }
    }  // end for (i=0;i<KEY_TOTAL;i++,pressed_ptr)
#endif
    gb_key_curr=key_pad;
}
