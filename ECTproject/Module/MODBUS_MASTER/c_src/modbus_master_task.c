//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 modbus_master_task.c
//
//! @author 	 Jacky Lin
//
//! @date 		 2022/07/25
//
//  @brief 		 Task Subroutine
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S 
//
//**********************************************************************************************************************
#include "..\drv_src\modbus_master_drv.h" 
#include "modbus_master_glb_vars.h"
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
//! @fn 			 modbus_master_replay_timeout
//
//! @author 	 Jacky Lin
//
//! @date 		 2022/07/25
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void modbus_master_replay_timeout()
{
    //===== modbus master 加入 replay(retry)的機制, Ver 0.0.02 =====      
    if(gb_modbus_master_replay_times>=PFC_MODBUS_MASTER_REPLAY_TIMES)
    {
        gb_modbus_master_replay_times=0;
        //===== 此處放入replay(retry)失敗後的事件, 這邊是將 eph 接收的資料都清"0", 然後往下一台 eph 送出 command, Ver 0.0.02 ======
        memset((UINT8*)&gs_eph_comm_transmitter[gb_eph_comm_device_ptr],0x00,sizeof(gs_eph_comm_transmitter[gb_eph_comm_device_ptr]));
        //===== Ver 0.0.03 =====
        eph_comm_polls_device_judge();     
    }
    else
    {
        gb_modbus_master_replay_flag=MODBUS_MASTER_REPLAY_FLAG_ENABLE;
        gb_modbus_master_replay_times++;
    }
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 modbus_master_sending
//
//! @author 	 Jacky Lin
//
//! @date 		 2022/07/25
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void modbus_master_register_command(void* cmd, UINT8 len)
{
    if(MODBUS_MASTER_CHK_STATE()==MODBUS_MASTER_STATE_IDEL)
    {
        memcpy((UINT8*)&gb_modbus_master_buffer[0],(UINT8*)cmd, len );
        gb_modbus_master_polling_id=gb_modbus_master_buffer[MODBUS_MASTER_BYTE_NAME_ADDRESS];
        gb_modbus_master_polling_function=gb_modbus_master_buffer[MODBUS_MASTER_BYTE_NAME_FUNCTION_BYTE];
        gb_modbus_master_ptr=0;
        gb_modbus_master_command_length=len;
        MODBUS_MASTER_SET_STATE(MODBUS_MASTER_STATE_SENDING);  
        MODBUS_MASTER_START_TX_API();
    }
    else
    {
        gb_modbus_master_error_code=MODBUS_MASTER_ERROR_STATE_INCORRECT;
    }
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 modbus_master_sending
//
//! @author 	 Jacky Lin
//
//! @date 		 2022/07/25
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
UINT8 modbus_master_sending()
{
    if (MODBUS_MASTER_CHK_STATE()==MODBUS_MASTER_STATE_SENDING)
    {
        if (MODBUS_MASTER_MODE==MODBUS_MASTER_RTU_MODE)
        {        
            if (gb_modbus_master_ptr!=gb_modbus_master_command_length )
            {
                MODBUS_MASTER_SEND_OUT_API(gb_modbus_master_buffer[gb_modbus_master_ptr++]);
                MODBUS_MASTER_BYTE_BETWEEN_TIMER_API();
                return 1;
            }
            if (gb_modbus_master_ptr==gb_modbus_master_command_length)
            {        
                MODBUS_MASTER_BYTE_BETWEEN_TIMER_API();              
                MODBUS_MASTER_RESPONSE_TIMER_API();
                MODBUS_MASTER_SET_STATE(MODBUS_MASTER_STATE_RECV_WAITING);
            }
        }
    }
    return 0;
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 modbus_master_receiving_and_checking
//
//! @author 	 Jacky Lin
//
//! @date 		 2022/07/25
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void modbus_master_receiving_and_checking()
{
    UINT8 byte_value;
      
    MODBUS_MASTER_BYTE_BETWEEN_TIMER_API();
    byte_value=MODBUS_MASTER_RECEIVE_API(); 
    if(MODBUS_MASTER_CHK_STATE()!=MODBUS_MASTER_STATE_RECV_WAITING&&MODBUS_MASTER_CHK_STATE()!=MODBUS_MASTER_STATE_RECIVING_AND_CHECKING)
        return;
    
    gb_modbus_master_ptr%=MODBUS_MASTER_MAX_BUFFER_SIZE;
    if (MODBUS_MASTER_MODE==MODBUS_MASTER_RTU_MODE)
        gb_modbus_master_buffer[gb_modbus_master_ptr++]=byte_value;    
    
    switch (gb_modbus_master_ptr-1)
    {
        case MODBUS_MASTER_BYTE_NAME_ADDRESS:
        {
            if (gb_modbus_master_buffer[MODBUS_MASTER_BYTE_NAME_ADDRESS]!=gb_modbus_master_polling_id)
            {
                MODBUS_MASTER_SET_STATE(MODBUS_MASTER_STATE_BACK_TO_STOP);
                MODBUS_MASTER_REPLAY_TIMEOUT();
                gb_modbus_master_error_code=MODBUS_MASTER_ERROR_NAME_ADDRESS;                
            }     
            else
            {
                MODBUS_MASTER_SET_STATE(MODBUS_MASTER_STATE_RECIVING_AND_CHECKING);               
            } 
            break;
        }
        case MODBUS_MASTER_BYTE_NAME_FUNCTION_BYTE:
        {
            if (byte_value!=gb_modbus_master_polling_function )
            {
                gb_modbus_master_error_code=MODBUS_MASTER_ERROR_FUNCTION;
                MODBUS_MASTER_REPLAY_TIMEOUT();
                MODBUS_MASTER_SET_STATE(MODBUS_MASTER_STATE_BACK_TO_STOP);
            }        
            break;
        }       
        default:
            break;
    }
        
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 modbus_master_response_timeout
//
//! @author 	 Jacky Lin
//
//! @date 		 2022/07/25
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void modbus_master_response_timeout()
{   
    if(MODBUS_MASTER_CHK_STATE()==MODBUS_MASTER_STATE_RECIVING_AND_CHECKING)
        return;
    
    if(MODBUS_MASTER_CHK_STATE()==MODBUS_MASTER_STATE_RECV_WAITING)
    {
        gb_modbus_master_error_code=MODBUS_MASTER_ERROR_RESPONSE_TIMEOUT;     
        MODBUS_MASTER_REPLAY_TIMEOUT();
        MODBUS_MASTER_SET_STATE(MODBUS_MASTER_STATE_BACK_TO_STOP);
        //===== 在 modbus_master_response_timeout 中 加入自動分配ID的 exception 機制, Ver 0.0.04 =====
        if(EPH_COMM_CHK_DISTRIBUTION_STATE()==EPH_COMM_DISTRIBUTION_STATE_START)
            eph_comm_distribut_exception();
    }
    if(MODBUS_MASTER_CHK_STATE()==MODBUS_MASTER_STATE_BACK_TO_STOP)      
    {
        MODBUS_MASTER_INIT_API();
        MODBUS_MASTER_SET_STATE(MODBUS_MASTER_STATE_IDEL);
    }    
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 modbus_master_byte_between_timeout
//
//! @author 	 Jacky Lin
//
//! @date 		 2022/07/25
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void modbus_master_byte_between_timeout()
{
    UINT8 check_pass=0;
     
    if(MODBUS_MASTER_CHK_STATE()==MODBUS_MASTER_STATE_RECV_WAITING)
    {       
        gb_modbus_master_ptr=0;
        MODBUS_MASTER_SET_READ_IN_API();                   
    }
    if(MODBUS_MASTER_CHK_STATE()==MODBUS_MASTER_STATE_SENDING)
        gb_modbus_master_error_code=MODBUS_MASTER_ERROR_SENDING_TIMEOUT;  
    
    if(MODBUS_MASTER_CHK_STATE()==MODBUS_MASTER_STATE_RECIVING_AND_CHECKING)
    {
        UINT32 crc,hi_byte,low_byte;
        crc=MODBUS_MASTER_CRC_CODE_API(gb_modbus_master_buffer,gb_modbus_master_ptr-MODBUS_MASTER_CRC_LEN);
        hi_byte=(crc&MODBUS_MASTER_HIGH_BYTE_MASK)>>MODBUS_MASTER_BYTE_BITS;
        low_byte=crc&MODBUS_MASTER_LOW_BYTE_MASK;
        // crc pass
        if (hi_byte==gb_modbus_master_buffer[gb_modbus_master_ptr-MODBUS_MASTER_CRC_HI_BYTE_POS] && low_byte==gb_modbus_master_buffer[gb_modbus_master_ptr-MODBUS_MASTER_CRC_LOW_BYTE_POS])
          check_pass=1;   
        
        if (check_pass==1)
        {
            gb_modbus_master_state=MODBUS_MASTER_STATE_PARSING;
            gb_modbus_master_error_code=MODBUS_MASTER_ERROR_NORMAL;
            gb_modbus_master_replay_times=0;           
        }        
        else	// crc or lrc fail
        {
            gb_modbus_master_error_code=MODBUS_MASTER_ERROR_CRC_FAIL;
            MODBUS_MASTER_REPLAY_TIMEOUT();
            MODBUS_MASTER_INIT_API();     
            MODBUS_MASTER_SET_STATE(MODBUS_MASTER_STATE_IDEL);
        }  
    }
    
    if(MODBUS_MASTER_CHK_STATE()==MODBUS_MASTER_STATE_BACK_TO_STOP)      
    {
        MODBUS_MASTER_INIT_API();
        MODBUS_MASTER_SET_STATE(MODBUS_MASTER_STATE_IDEL);
    }    
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 modbus_master_task
//
//! @author 	 Jacky Lin
//
//! @date 		 2022/07/25
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void modbus_master_task()
{

}
#ifdef __cplusplus
}
#endif

