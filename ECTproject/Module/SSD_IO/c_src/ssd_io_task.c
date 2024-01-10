//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 ssd_io_task.c
//
//! @author 	 Jacky Lin
//
//! @date 		 2021/12/28
//
//  @brief 		 Task Subroutine
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S 
//
//**********************************************************************************************************************
#include "..\drv_src\ssd_io_drv.h" 
#include "ssd_io_glb_vars.h"
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
//! @fn 			 ssd_io_task
//
//! @author 	 Jacky Lin
//
//! @date 		 2021/12/28
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void ssd_io_task()
{

}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	        ssd_io_write_data
//
//! @author 	        Jacky Lin
//
//! @date 		2021/12/30
//
//! @brief 	        task function
//
//! @param 	        None
//
//! @return 	        None
//
//**********************************************************************************************************************
void ssd_io_write_data(UINT8 led, UINT8 data,UINT8 color)
{
    STC_SSD_IO_STATUS* status = (STC_SSD_IO_STATUS*)&gs_ssd_io_status; 
    status->led[led]=data;
    status->color=color;
    status->state_ptr=SSD_IO_LED_1;
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	        ssd_io_screen_task
//
//! @author 	        Jacky Lin
//
//! @date 		2021/12/30
//
//! @brief 	        task function
//
//! @param 	        None
//
//! @return 	        None
//
//**********************************************************************************************************************
void ssd_io_screen_task()
{
    STC_SSD_IO_STATUS* status = (STC_SSD_IO_STATUS*)&gs_ssd_io_status; 
    if(++status->cnt>=SSD_IO_SCREEN_INTERVAL)
    {
        status->cnt=0;    
        if(status->flash[status->state_ptr]==0)
        {
            ssd_io_clean_data_output();
            ssd_io_data_output(status->led[status->state_ptr]);
            ssd_io_clean_state_output(status->color);
            ssd_io_state_output(status->state_ptr, status->color);      
        }
        else
        {
            ssd_io_clean_data_output();
            ssd_io_clean_state_output(status->color);
        }
        status->state_ptr++;
        if(status->state_ptr>=SSD_IO_LED_TOTAL)
            status->state_ptr=SSD_IO_LED_1;
    }           
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	        ssd_io_data_output
//
//! @author 	        Jacky Lin
//
//! @date 		2023/05/26
//
//! @brief 	        task function
//
//! @param 	        None
//
//! @return 	        None
//
//**********************************************************************************************************************
void ssd_io_data_output(UINT8 led_data)
{
    /*
      DSP_D0 „» A  „³LD1  /LD3   /LD5   /LD7
      DSP_D1 „» B  „³LD9  /LD11  /LD13  /LD15
      DSP_D2 „» C  „³LD17 /LD19  /LD21  /LD23
      DSP_D3 „» D  „³LD25 /LD27  /LD29  /LD31
      DSP_D4 „» E  „³LD2  /LD4   /LD6   /LD8
      DSP_D5 „» F  „³LD10 /LD12  /LD14  /LD16
      DSP_D6 „» G  „³LD18 /LD20  /LD22  /LD24
      DSP_D7 „» DP „³LD26  /LD28  /LD30  /LD32 */
  
    
    
    if(led_data&SSD_IO_A)
        SSD_IO_DATA0_HIGH();
    if(led_data&SSD_IO_B)
        SSD_IO_DATA1_HIGH();
    if(led_data&SSD_IO_C)
        SSD_IO_DATA2_HIGH();
    if(led_data&SSD_IO_D)
        SSD_IO_DATA3_HIGH();
    if(led_data&SSD_IO_E)
        SSD_IO_DATA4_HIGH();
    if(led_data&SSD_IO_F)
        SSD_IO_DATA5_HIGH();
    if(led_data&SSD_IO_G)
        SSD_IO_DATA6_HIGH();
    if(led_data&SSD_IO_DOT)
        SSD_IO_DATA7_HIGH();           
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	        ssd_io_clean_data_output
//
//! @author 	        Jacky Lin
//
//! @date 		2021/12/30
//
//! @brief 	        task function
//
//! @param 	        None
//
//! @return 	        None
//
//**********************************************************************************************************************
void ssd_io_clean_data_output()
{
    SSD_IO_DATA0_LOW();
    SSD_IO_DATA1_LOW();
    SSD_IO_DATA2_LOW();
    SSD_IO_DATA3_LOW();
    SSD_IO_DATA4_LOW();
    SSD_IO_DATA5_LOW();
    SSD_IO_DATA6_LOW();
    SSD_IO_DATA7_LOW();
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	        ssd_io_state_output
//
//! @author 	        Jacky Lin
//
//! @date 		2021/12/30
//
//! @brief 	        task function
//
//! @param 	        None
//
//! @return 	        None
//
//**********************************************************************************************************************
void ssd_io_state_output(UINT8 state_ptr, UINT8 color)
{
    if(state_ptr>=SSD_IO_LED_TOTAL)
        return;  
       
    if(color==SSD_IO_COLOR_RED)
    {       
        switch(state_ptr)
        {
            case SSD_IO_LED_5:
                SSD_IO_FIGURE4_HIGH();
                break;
            case SSD_IO_LED_6:
                SSD_IO_FIGURE5_HIGH();
                break;
            case SSD_IO_LED_7:
                SSD_IO_FIGURE6_HIGH();
                break;
            case SSD_IO_LED_8:
                SSD_IO_FIGURE7_HIGH();
                break;          
            case SSD_IO_LED_1:
                SSD_IO_FIGURE0_HIGH();
                break;
            case SSD_IO_LED_2:
                SSD_IO_FIGURE1_HIGH();
                break;
            case SSD_IO_LED_3:
                SSD_IO_FIGURE2_HIGH();
                break;
            case SSD_IO_LED_4:
                SSD_IO_FIGURE3_HIGH();
                break;               
        }
    }
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	        ssd_io_clean_state_output
//
//! @author 	        Jacky Lin
//
//! @date 		2021/12/30
//
//! @brief 	        task function
//
//! @param 	        None
//
//! @return 	        None
//
//**********************************************************************************************************************
void ssd_io_clean_state_output(UINT8 color)
{
    if(color==SSD_IO_COLOR_RED)
    {
        SSD_IO_FIGURE0_LOW();
        SSD_IO_FIGURE1_LOW();
        SSD_IO_FIGURE2_LOW();
        SSD_IO_FIGURE3_LOW();         
        SSD_IO_FIGURE4_LOW();
        SSD_IO_FIGURE5_LOW();
        SSD_IO_FIGURE6_LOW();
        SSD_IO_FIGURE7_LOW();
    }
}
void ssd_io_set_state_output_off(UINT8 state)
{
    gs_ssd_io_status.flash[state]=1;   
}
void ssd_io_set_state_output_full_off()
{   
    for(UINT8 i=0; i<SSD_IO_LED_TOTAL; i++)
        ssd_io_set_state_output_off(i);
}
void ssd_io_set_state_output_on(UINT8 state)
{
    gs_ssd_io_status.flash[state]=0;   
}
void ssd_io_set_state_output_full_on()
{   
    for(UINT8 i=0; i<SSD_IO_LED_TOTAL; i++)
        ssd_io_set_state_output_on(i);
}
void ssd_io_set_state_output_flash(UINT8 state,UINT8 flash_status,UINT8 mode)
{
    gs_ssd_io_status.flash[state]=flash_status; 
}
#ifdef __cplusplus
}
#endif

