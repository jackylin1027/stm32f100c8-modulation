//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 eph_comm_task.c
//
//! @author 	 Jacky Lin
//
//! @date 		 2022/07/26
//
//  @brief 		 Task Subroutine
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S 
//
//**********************************************************************************************************************
#include "..\drv_src\eph_comm_drv.h" 
#include "eph_comm_glb_vars.h"
//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N 
//
//**********************************************************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif
  
const UINT8 gb_eph_comm_encrypt_public_key[]={0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F, 0x00};
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 eph_comm_delay_time
//
//! @author 	 Jacky Lin
//
//! @date 		 2022/08/15
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void eph_comm_delay_time(UINT32 delay)
{
    for(UINT32 i=0;i<delay;i++){}
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 eph_comm_polls_device_judge
//
//! @author 	 Jacky Lin
//
//! @date 		 2022/08/09
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//********************************************************************************************************************** 
void eph_comm_polls_device_judge()
{
    //===== eph comm 加入 封包解析最大數量的判斷機制, Ver0.0.02 =====
    if(++gb_eph_comm_device_ptr >= EPH_COMM_GET_MAX_DEVICE_NUM())
    {       
        //===== 小循環(delay polls)結束後, 將 SCANRATE flag 設定成 inactive, 等待下次 SCANRATE active, Ver0.0.02 ====
        EPH_COMM_SET_SCANRATE_FLAG(PFC_SCANRATE_INACTIVE);
        gb_eph_comm_device_ptr=0;
    } 
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 eph_comm_rs485_receiving_and_checking
//
//! @author 	 Jacky Lin
//
//! @date 		 2022/08/09
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//********************************************************************************************************************** 
void eph_comm_rs485_receiving_and_checking(UINT8 byte)
{
    UINT8 result[2];
    if(PFC_OPERATION_MODE_CHK()<PFC_OPERATION_COMREAD)
        return;
    //===== 修正multi write 會當機的問題, 原因為 rs485 模式的 buffer 溢位, Ver 1.0.09 =====
    gb_eph_comm_rs485_ptr %= EPH_COMM_RS485_DATA_NUM;
    gb_eph_comm_rs485_response[gb_eph_comm_rs485_ptr++]=byte;
    EPH_COMM_RS485_RESET_TIMEOUT_TIMER_API(5);   
    
   switch(gb_eph_comm_rs485_state)
   {
   case EPH_COMM_RS485STA_IDEL:
       if(gb_eph_comm_rs485_response[EPH_COMM_RS485_ADDRESS]==EPH_COMM_RS485_TAG)
           gb_eph_comm_rs485_state=EPH_COMM_RS485STA_IDENT;           
     break;
     //===== 水廠模式取值的裝置碼判斷方式修改, 對應PFC_RS485_ADDRESS, Ver 0.0.05 =====
   case EPH_COMM_RS485STA_IDENT:
       fn_hex2asciiString_inverse(result,(UINT8*)&gb_eph_comm_rs485_response[EPH_COMM_RS485_DEVICE_NUMBER],1);
       if(result[1]==PFC_RS485_ADDRESS[0]&&result[0]==PFC_RS485_ADDRESS[1])
           gb_eph_comm_rs485_state=EPH_COMM_RS485STA_IDENT1;
       else
           MODBUS_SLAVE_INIT_API();
       break;
   case EPH_COMM_RS485STA_IDENT1:
       fn_hex2asciiString_inverse(result,(UINT8*)&gb_eph_comm_rs485_response[EPH_COMM_RS485_DEVICE_NUMBER+1],1);
       if(result[1]==PFC_RS485_ADDRESS[2]&&result[0]==PFC_RS485_ADDRESS[3])      
           gb_eph_comm_rs485_state=EPH_COMM_RS485STA_IDENT2;
       else
           MODBUS_SLAVE_INIT_API();        
       break;        
   case EPH_COMM_RS485STA_IDENT2:
       fn_hex2asciiString_inverse(result,(UINT8*)&gb_eph_comm_rs485_response[EPH_COMM_RS485_DEVICE_NUMBER]+2,1);
       if(result[1]==PFC_RS485_ADDRESS[4]&&result[0]==PFC_RS485_ADDRESS[5])            
         gb_eph_comm_rs485_state=EPH_COMM_RS485STA_GROUP;
       else
           MODBUS_SLAVE_INIT_API();        
       break;           
   case EPH_COMM_RS485STA_GROUP:    
       if(gb_eph_comm_rs485_response[EPH_COMM_RS485_GROUP_NUMBER]==0x00)
           gb_eph_comm_rs485_state=EPH_COMM_RS485STA_GROUP1;
       break;
   case EPH_COMM_RS485STA_GROUP1:    
       if(gb_eph_comm_rs485_response[EPH_COMM_RS485_GROUP_NUMBER+1]==0xFF)
           gb_eph_comm_rs485_state=EPH_COMM_RS485STA_STATION;
       break;
   case EPH_COMM_RS485STA_STATION:    
       if(gb_eph_comm_rs485_response[EPH_COMM_RS485_STATION]==0x00)
           gb_eph_comm_rs485_state=EPH_COMM_RS485STA_STATION1; 
       break;
   case EPH_COMM_RS485STA_STATION1:    
       if(gb_eph_comm_rs485_response[EPH_COMM_RS485_STATION+1]==0xFF)
           gb_eph_comm_rs485_state=EPH_COMM_RS485STA_FUNC;
       break;
   case EPH_COMM_RS485STA_FUNC:    
       if(gb_eph_comm_rs485_response[EPH_COMM_RS485_FUNC]==0x11)
           gb_eph_comm_rs485_state=EPH_COMM_RS485STA_FUNCREAD;
       else if(gb_eph_comm_rs485_response[EPH_COMM_RS485_FUNC]==0x22)
           gb_eph_comm_rs485_state=EPH_COMM_RS485STA_FUNCMONITOR;         
     break;    
   case EPH_COMM_RS485STA_FUNCREAD:    
       if(gb_eph_comm_rs485_response[EPH_COMM_RS485_FUNC+1]==0xEE)
       {
           gb_eph_comm_rs485_state=EPH_COMM_RS485STA_FUNC_OK;    
           gb_eph_comm_rs485_func=EPH_COMM_RS485STA_FUNCREAD;
       }
       //===== 新增競爭廠商功能 - RS-485讀取模式, Ver 0.0.03 =====
       PFC_EPH_COMM_TRANSMITTER_PROCESS_TIMEOUT(1);
     break;       
   case EPH_COMM_RS485STA_FUNCMONITOR:    
       if(gb_eph_comm_rs485_response[EPH_COMM_RS485_FUNC+1]==0xDD)
       {
           gb_eph_comm_rs485_state=EPH_COMM_RS485STA_FUNC_OK;        
           gb_eph_comm_rs485_func=EPH_COMM_RS485STA_FUNCMONITOR;
       }
       //===== 新增競爭廠商功能 - RS-485監控模式, Ver 0.0.07 =====
       PFC_EPH_COMM_TRANSMITTER_PROCESS_TIMEOUT(1);
     break;         
   }
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 eph_comm_receive_parsing
//
//! @author 	 Jacky Lin
//
//! @date 		 2022/07/28
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//********************************************************************************************************************** 
UINT16 eph_comm_decrypt_func(UINT8* source_data, UINT16 length)
{
    UINT16 g_decrypt_datalen,i,k;
    UINT8 g_addBuf[EPH_COMM_ENCRYPT_BLOCK],g_xorBuf[EPH_COMM_ENCRYPT_BLOCK],g_exchangeBuf[EPH_COMM_ENCRYPT_BLOCK],g_exdb[2];
    UINT16 byte_count=*(source_data+2)+(*(source_data+3)<<EPH_COMM_BYTE_BITS);
    UINT8 leading_code=*(source_data+4);
    UINT8* tmep_data=(UINT8*)(source_data+5);
    
    g_decrypt_datalen = byte_count - 1 + 2;
    for(i = 0; i < leading_code; i++)
    {
        for (k = 0; k < EPH_COMM_ENCRYPT_BLOCK; k++) 
            g_exchangeBuf[k] = *(tmep_data + i * EPH_COMM_ENCRYPT_BLOCK + k);
        
        if ((i%2) == 0) // odd block.
        {
            // Exchange
            g_xorBuf[0] = g_exchangeBuf[0];
            g_exdb[0] = (UINT8)((g_exchangeBuf[1] >> 4) & 0x0F);
            g_exdb[1] = (UINT8)(g_exchangeBuf[1] & 0x0F);
            g_xorBuf[1] = (UINT8)((g_exdb[1] << 4) + g_exdb[0]);
            g_xorBuf[2] = g_exchangeBuf[2];
            g_exdb[0] = (UINT8)((g_exchangeBuf[3] >> 4) & 0x0F);
            g_exdb[1] = (UINT8)(g_exchangeBuf[3] & 0x0F);
            g_xorBuf[3] = (UINT8)((g_exdb[1] << 4) + g_exdb[0]);
            g_xorBuf[4] = g_exchangeBuf[4];
            g_exdb[0] = (UINT8)((g_exchangeBuf[5] >> 4) & 0x0F);
            g_exdb[1] = (UINT8)(g_exchangeBuf[5] & 0x0F);
            g_xorBuf[5] = (UINT8)((g_exdb[1] << 4) + g_exdb[0]);
            g_xorBuf[6] = g_exchangeBuf[6];
            // Add
            g_addBuf[1] = g_xorBuf[1];
            g_addBuf[2] = (UINT8)(g_xorBuf[1] ^ g_xorBuf[2]);
            g_addBuf[3] = (UINT8)(g_xorBuf[2] ^ g_xorBuf[3]);
            g_addBuf[4] = (UINT8)(g_xorBuf[3] ^ g_xorBuf[4]);
            g_addBuf[5] = (UINT8)(g_xorBuf[4] ^ g_xorBuf[5]);
            g_addBuf[6] = (UINT8)(g_xorBuf[5] ^ g_xorBuf[6]);
            g_addBuf[0] = (UINT8)(g_xorBuf[6] ^ g_xorBuf[0]);
            //===== FINETEK加密模式解密的時候DEC, (跟中華電信的ADD加密不同), Ver 0.0.06 =====
            if(i==0)
            {
                memcpy(gb_eph_comm_encrypt_fix_key,gb_eph_comm_encrypt_public_key,EPH_COMM_ENCRYPT_BLOCK);// Load initial fix key.               
                for (k = 0; k < EPH_COMM_ENCRYPT_BLOCK; k++) { *(source_data + i * EPH_COMM_ENCRYPT_BLOCK + k + 2) = (UINT8)(g_addBuf[k] + gb_eph_comm_encrypt_fix_key[k]); }
            }       
            else
            {
                for (k = 0; k < EPH_COMM_ENCRYPT_BLOCK; k++) { *(source_data + i * EPH_COMM_ENCRYPT_BLOCK + k + 2) = (UINT8)(g_addBuf[k] + gb_eph_comm_encrypt_fix_key[k]); }                        
            }  
            for (k = 0; k < EPH_COMM_ENCRYPT_BLOCK; k++) { gb_eph_comm_encrypt_fix_key[k] = g_xorBuf[k]; } // Upadte random key.
        }
        else // even block
        {
            // Exchange
            g_exdb[0] = (UINT8)((g_exchangeBuf[0] >> 4) & 0x0F);
            g_exdb[1] = (UINT8)(g_exchangeBuf[0] & 0x0F);
            g_xorBuf[0] = (UINT8)((g_exdb[1] << 4) + g_exdb[0]);
            g_xorBuf[1] = g_exchangeBuf[1];
            g_exdb[0] = (UINT8)((g_exchangeBuf[2] >> 4) & 0x0F);
            g_exdb[1] = (UINT8)(g_exchangeBuf[2] & 0x0F);
            g_xorBuf[2] = (UINT8)((g_exdb[1] << 4) + g_exdb[0]);
            g_xorBuf[3] = g_exchangeBuf[3];
            g_exdb[0] = (UINT8)((g_exchangeBuf[4] >> 4) & 0x0F);
            g_exdb[1] = (UINT8)(g_exchangeBuf[4] & 0x0F);
            g_xorBuf[4] = (UINT8)((g_exdb[1] << 4) + g_exdb[0]);
            g_xorBuf[5] = g_exchangeBuf[5];
            g_exdb[0] = (UINT8)((g_exchangeBuf[6] >> 4) & 0x0F);
            g_exdb[1] = (UINT8)(g_exchangeBuf[6] & 0x0F);
            g_xorBuf[6] = (UINT8)((g_exdb[1] << 4) + g_exdb[0]);
            // Add
            g_addBuf[0] = g_xorBuf[0];
            g_addBuf[1] = (UINT8)(g_xorBuf[0] ^ g_xorBuf[1]);
            g_addBuf[2] = (UINT8)(g_xorBuf[1] ^ g_xorBuf[2]);
            g_addBuf[3] = (UINT8)(g_xorBuf[2] ^ g_xorBuf[3]);
            g_addBuf[4] = (UINT8)(g_xorBuf[3] ^ g_xorBuf[4]);
            g_addBuf[5] = (UINT8)(g_xorBuf[4] ^ g_xorBuf[5]);
            g_addBuf[6] = (UINT8)(g_xorBuf[5] ^ g_xorBuf[6]);
            //===== FINETEK加密模式解密的時候DEC, (跟中華電信的ADD加密不同), Ver 0.0.06 =====
            for (k = 0; k < EPH_COMM_ENCRYPT_BLOCK; k++) 
            { 
                *(source_data + i * EPH_COMM_ENCRYPT_BLOCK + k + 2) = (UINT8)(g_addBuf[k] + gb_eph_comm_encrypt_fix_key[k]); 
            }
            for (k = 0; k < EPH_COMM_ENCRYPT_BLOCK; k++) 
            { 
                gb_eph_comm_encrypt_fix_key[k] = g_xorBuf[k]; 
            }
            // Upadte random key.
        }            
    }
    return g_decrypt_datalen;
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 eph_comm_rs485_recv_parse
//
//! @author 	 Jacky Lin
//
//! @date 		 2022/08/08
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//********************************************************************************************************************** 
void eph_comm_rs485_recv_parse()
{
    UINT8 i;
    UINT16 chksum=0;
    UINT16 response_format;
    UINT8 system_status=0x80;
    UINT8 user_count_align[2];
    UINT8 system_error=0;
    UINT8 reverse[6]={0,0,0,0,0,0};
    
    eph_comm_decrypt_func((UINT8*)&EPH_COMM_BUFFER[0], EPH_COMM_REVC_COUNT);
    STC_EPH_COMM_RECEIVE_INFO_PACKAGE* recv = (STC_EPH_COMM_RECEIVE_INFO_PACKAGE*)&EPH_COMM_BUFFER[EPH_COMM_DECRYPT_DATA_START_BYTE];
          
    //==================== STC_EPH_COMM_RS485_HEADER ==================
    gs_eph_comm_rHeader.StartTag=EPH_COMM_RS485_TAG;
    
    //===== 競爭廠商功能 - RS-485讀取模式&監控模式回復封包判斷, Ver 0.0.03 =====
    //===== 修正 競爭廠商功能 - RS-485讀取模式&監控模式回復封包判斷, Ver 0.0.07 =====
    //if(PFC_OPERATION_MODE==PFC_OPERATION_COMREADINST)
    {
        if(gb_eph_comm_rs485_func==EPH_COMM_RS485STA_FUNCREAD)
        {
            memcpy(gs_eph_comm_rHeader.thisCommMode, "T4", sizeof(gs_eph_comm_rHeader.thisCommMode));
            response_format=0;
        }
        else if(gb_eph_comm_rs485_func==EPH_COMM_RS485STA_FUNCMONITOR)
        {
            memcpy(gs_eph_comm_rHeader.thisCommMode, "T5", sizeof(gs_eph_comm_rHeader.thisCommMode));
            response_format=1;
        }
    }
    /*else
    {
        if(!(PFC_OPERATION_MODE%2))
        {
          memcpy(gs_eph_comm_rHeader.thisCommMode, "T4", sizeof(gs_eph_comm_rHeader.thisCommMode));
          response_format=0;
        }
        else
        {
          memcpy(gs_eph_comm_rHeader.thisCommMode, "T5", sizeof(gs_eph_comm_rHeader.thisCommMode)); 
          response_format=1;
        }
    }*/
    
    gs_eph_comm_rHeader.DeviceType='G';    
    gs_eph_comm_rHeader.UserNumberTag='W';
    //===== 修正競品RS485通訊的格式, Ver0.0.04 =====
    //===== 回應水廠模式訊息中的UserNumber改使用傳訊器的PFC_RS485_NUMBER(6碼內容傳送3bytes), Ver 0.0.05 =====
    fn_memcpy_inverse(gs_eph_comm_rHeader.UserNumber,PFC_RS485_NUMBER,sizeof(gs_eph_comm_rHeader.UserNumber));
    //==================== STC_EPH_COMM_RS485_HEADER ==================
    
    //==================== STC_EPH_COMM_RS485_METERID ==================
    gs_eph_comm_rMeterID.MeterIDTag='M';
    //===== 修正競品RS485通訊的格式, Ver0.0.04 =====
    fn_hex2asciiString_inverse(gs_eph_comm_rMeterID.MeterID,(UINT8*)&recv->meter_id[1],sizeof(gs_eph_comm_rMeterID.MeterID)/2);
    //==================== STC_EPH_COMM_RS485_METERID ==================
    
    //==================== STC_EPH_COMM_RS485_VOLUME ==================
    gs_eph_comm_rVolume.VolumeExponentialTag='V';
    fn_intValue2String(gs_eph_comm_rVolume.VolumeExponential,recv->volume,sizeof(gs_eph_comm_rVolume.VolumeExponential));
    gs_eph_comm_rVolume.VolumeExponential[9]='e';
    gs_eph_comm_rVolume.VolumeExponential[10]='-';
    gs_eph_comm_rVolume.VolumeExponential[11]=((recv->caliber==EPH_COMM_DEVICE_DN40) ? EPH_COMM_DEVICE_DN40_DOT_POS : EPH_COMM_DEVICE_NOT_DN40_DOT_POS)+'0';  
    //==================== STC_EPH_COMM_RS485_VOLUME ==================
    
    
    //==================== STC_EPH_COMM_RS485_EVENT ==================
    gs_eph_comm_rEvent.lDayTag='L';
    fn_hex2asciiString_inverse(gs_eph_comm_rEvent.lDay,&(recv->l_day),sizeof(gs_eph_comm_rEvent.lDay)/2);   
    gs_eph_comm_rEvent.nDayTag='N';
    fn_hex2asciiString_inverse(gs_eph_comm_rEvent.nDay,&(recv->n_day),sizeof(gs_eph_comm_rEvent.nDay)/2);
    gs_eph_comm_rEvent.oDayTag='O';
    fn_hex2asciiString_inverse(gs_eph_comm_rEvent.oDay,&(recv->o_day),sizeof(gs_eph_comm_rEvent.oDay)/2);
    gs_eph_comm_rEvent.uDayTag='U';
    fn_hex2asciiString_inverse(gs_eph_comm_rEvent.uDay,&(recv->u_day),sizeof(gs_eph_comm_rEvent.uDay)/2);
    gs_eph_comm_rEvent.hDayTag='H';
    fn_hex2asciiString_inverse(gs_eph_comm_rEvent.hDay,&(recv->h_day),sizeof(gs_eph_comm_rEvent.hDay)/2);
    gs_eph_comm_rEvent.bDayTag='B';
    fn_hex2asciiString_inverse(gs_eph_comm_rEvent.bDay,&(recv->b_day),sizeof(gs_eph_comm_rEvent.bDay)/2);    
    gs_eph_comm_rEvent.statusTag='F';
    fn_hex2asciiString_inverse(gs_eph_comm_rEvent.status,&system_status,sizeof(gs_eph_comm_rEvent.status)/2);  
    user_count_align[0]=recv->user_count&0xFF;
    user_count_align[1]=(recv->user_count>>EPH_COMM_BYTE_BITS)&0xFF;
    gs_eph_comm_rEvent.userCountTag='C';
    fn_hex2asciiString_inverse(gs_eph_comm_rEvent.userCount,&user_count_align[0],sizeof(gs_eph_comm_rEvent.userCount)/2); 
    //==================== STC_EPH_COMM_RS485_EVENT ==================
    
    //==================== STC_EPH_COMM_RS485_ERRORCODE ==================
    gs_eph_comm_rErrCode.errorCodeTag='E';
    gs_eph_comm_rErrCode.errorCode[0] = system_error + '0'; 
    //==================== STC_EPH_COMM_RS485_ERRORCODE ==================
        
    //==================== STC_EPH_COMM_RS485_TAIL ==================
    gs_eph_comm_rTail.reserveTag='X';
    fn_hex2asciiString_inverse(gs_eph_comm_rTail.reserve,&reverse[0],sizeof(gs_eph_comm_rTail.reserve)/2);       
    gs_eph_comm_rTail.CheckSumTag='S';
    fn_intValue2Number(gs_eph_comm_rTail.CheckSum,fn_bcd2decString(0x00),sizeof(gs_eph_comm_rTail.CheckSum)); 
    gs_eph_comm_rTail.EndTag='#';
    //==================== STC_EPH_COMM_RS485_TAIL ==================
    
    UINT8 response_length=0;
    //===== 競爭廠商功能 - RS-485讀取模式&監控模式回復封包判斷, Ver 0.0.03 =====  
    if(response_format==0)
    {
        memcpy((UINT8*)&gb_eph_comm_rs485_response[0],(UINT8*)&gs_eph_comm_rHeader.StartTag,sizeof(gs_eph_comm_rHeader));
        response_length+=sizeof(gs_eph_comm_rHeader);
        memcpy((UINT8*)&gb_eph_comm_rs485_response[response_length],(UINT8*)&gs_eph_comm_rMeterID.MeterIDTag,sizeof(gs_eph_comm_rMeterID));
        response_length+=sizeof(gs_eph_comm_rMeterID);
        memcpy((UINT8*)&gb_eph_comm_rs485_response[response_length],(UINT8*)&gs_eph_comm_rVolume.VolumeExponentialTag,sizeof(gs_eph_comm_rVolume));
        response_length+=sizeof(gs_eph_comm_rVolume);
        memcpy((UINT8*)&gb_eph_comm_rs485_response[response_length],(UINT8*)&gs_eph_comm_rEvent.lDayTag,sizeof(gs_eph_comm_rEvent));
        response_length+=sizeof(gs_eph_comm_rEvent);
        memcpy((UINT8*)&gb_eph_comm_rs485_response[response_length],(UINT8*)&gs_eph_comm_rTail.reserveTag,sizeof(gs_eph_comm_rTail));
        response_length+=sizeof(gs_eph_comm_rTail);
    }
    else if(response_format==1)
    {
        memcpy((UINT8*)&gb_eph_comm_rs485_response[0],(UINT8*)&gs_eph_comm_rHeader.StartTag,sizeof(gs_eph_comm_rHeader));
        response_length+=sizeof(gs_eph_comm_rHeader);
        memcpy((UINT8*)&gb_eph_comm_rs485_response[response_length],(UINT8*)&gs_eph_comm_rMeterID.MeterIDTag,sizeof(gs_eph_comm_rMeterID));
        response_length+=sizeof(gs_eph_comm_rMeterID);
        memcpy((UINT8*)&gb_eph_comm_rs485_response[response_length],(UINT8*)&gs_eph_comm_rVolume.VolumeExponentialTag,sizeof(gs_eph_comm_rVolume));
        response_length+=sizeof(gs_eph_comm_rVolume);     
        memcpy((UINT8*)&gb_eph_comm_rs485_response[response_length],(UINT8*)&gs_eph_comm_rTail.reserveTag,sizeof(gs_eph_comm_rTail));
        response_length+=sizeof(gs_eph_comm_rTail);
    }
    //===== 從＊以後開始加總至＃，不含Check Sum 跟＊、＃ ======//   
    for( i=1;i<response_length-1;i++)
        chksum+=gb_eph_comm_rs485_response[i];    
    //===== 修正競品RS485通訊的checksum 計算方法(以驗證), Ver 0.0.04 =====
    fn_hex2asciiString_inverse(gs_eph_comm_rTail.CheckSum,(UINT8*)&chksum,sizeof(gs_eph_comm_rTail.CheckSum)/2);
    gb_eph_comm_rs485_response[response_length-3]=gs_eph_comm_rTail.CheckSum[0];
    gb_eph_comm_rs485_response[response_length-2]=gs_eph_comm_rTail.CheckSum[1];
    
    //====== 往PC端傳送資料 =====
    EPH_COMM_SLAVE_SET_WRITE_OUT_API();
    for (i=0;i<response_length;i++)
        EPH_COMM_SLAVE_SEND_OUT_API(gb_eph_comm_rs485_response[i]);
    EPH_COMM_SLAVE_SET_READ_IN_API();    
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 eph_comm_new_version_converter
//
//! @author 	 Jacky Lin
//
//! @date 		 2023/06/21
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//********************************************************************************************************************** 
void eph_comm_new_version_converter(STC_EPH_COMM_RECEIVE_INFO_PACKAGE* recv, UINT8 ptr, UINT16 dot_pos)
{
    STC_EPH_COMM_T_UINT32* type_uint32 = (STC_EPH_COMM_T_UINT32*)&gs_eph_comm_t_uint32[ptr];
    STC_EPH_COMM_T_FLOAT32* type_float32 = (STC_EPH_COMM_T_FLOAT32*)&gs_eph_comm_t_float32[ptr];
    STC_EPH_COMM_T_FLOAT64* type_float64 = (STC_EPH_COMM_T_FLOAT64*)&gs_eph_comm_t_float64[ptr];
    
#define EPH_CALIBER_DN40                0x40
#define EPH_DEMICAL_SLOPE_ABOVE_DN40    0.0001 
#define EPH_DEMICAL_SLOPE_BELOW_DN40    0.00001
    
    FLOAT64 demical_slope=(recv->caliber>=EPH_CALIBER_DN40)?EPH_DEMICAL_SLOPE_ABOVE_DN40:EPH_DEMICAL_SLOPE_BELOW_DN40;
         
    type_uint32->volume=recv->volume;   
    type_uint32->plus_total_flow=recv->plus_total_flow;
    type_uint32->reverse_totalizer=recv->reverse_totalizer;
    type_uint32->flow_rate=recv->flow_rate;
    type_uint32->dot_pos=dot_pos;

    type_float32->volume=(FLOAT32)(recv->volume*demical_slope);
    type_float32->plus_total_flow=(FLOAT32)(recv->plus_total_flow*demical_slope);
    type_float32->reverse_totalizer=(FLOAT32)(recv->reverse_totalizer*demical_slope);   
    type_float32->flow_rate=(FLOAT32)(recv->flow_rate*EPH_DEMICAL_SLOPE_BELOW_DN40);

    type_float64->volume=(FLOAT64)(recv->volume*demical_slope);  
    type_float64->plus_total_flow=(FLOAT64)(recv->reverse_totalizer*demical_slope);
    type_float64->reverse_totalizer=(FLOAT64)(recv->reverse_totalizer*demical_slope);     
    type_float64->flow_rate=(FLOAT64)(recv->flow_rate*EPH_DEMICAL_SLOPE_BELOW_DN40);
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 eph_comm_receive_parsing
//
//! @author 	 Jacky Lin
//
//! @date 		 2022/07/28
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//********************************************************************************************************************** 
void eph_comm_receive_parsing()
{
    UINT8 dotPosition=0x00;
    UINT8 recv_index=gb_eph_comm_device_tlb[gb_eph_comm_device_ptr].recvIndex;
    eph_comm_decrypt_func((UINT8*)&EPH_COMM_BUFFER[0], EPH_COMM_REVC_COUNT);
    STC_EPH_COMM_RECEIVE_INFO_PACKAGE* recv = (STC_EPH_COMM_RECEIVE_INFO_PACKAGE*)&EPH_COMM_BUFFER[EPH_COMM_DECRYPT_DATA_START_BYTE];
    STC_EPH_COMM_TRANSMITTER_PACKAGE* transmitter=(STC_EPH_COMM_TRANSMITTER_PACKAGE*)&gs_eph_comm_transmitter[recv_index-1];
   
    /*      目前 transmitter 未使用                          */
    transmitter->timestamp=(UINT32)recv->timestamp;
    /*      0x1020	4129	0~9/A~F	水號1~4	        用戶水號
            0x1021	4130	0~9/A~F	水號5~8	
            0x1022	4131	0~9/A~F	水號9~12	
            0x1023	4132	0~9/A~F	水號13~16	
            0x1024	4133	0~9/A~F	水號17~20	
            0x1025	4134	0~9/A~F	水號21~24	*/
    FN_MEMCPY_INVERSE_API((UINT8*)&transmitter->userNumber, recv->meter_id, sizeof(recv->meter_id));
    /*      0x1026	4135	0~9/A~F	器號1~4	        水量計器號
            0x1027	4136	0~9/A~F	器號5~8	
            0x1028	4137	0~9/A~F	器號9~12	
            0x1029	4138	0~9/A~F	器號13~16	
            0x102A	4139	0~9/A~F	器號17~20	
            0x102B	4140	0~9/A~F	器號21~24	*/  
    FN_MEMCPY_INVERSE_API((UINT8*)&transmitter->meterID, recv->meter_id, sizeof(recv->meter_id));   
    /*      0x102C	4141	0000~9999	Ver 1030	版本      */
    transmitter->firmwareVersionBCD=(UINT16)recv->firmware_version;
    /*      0x102D	4142	0000~9999	"高位: 口徑
                                                低位: 電池電壓"	        */
    transmitter->caliberWmpowerBCD=((recv->caliber)<<EPH_COMM_BYTE_BITS)|recv->wm_power;
    //===== 依照水表口徑決定小數點的位數, Ver0.0.01 =====
    dotPosition=(recv->caliber==EPH_COMM_DEVICE_DN40) ? EPH_COMM_DEVICE_DN40_DOT_POS : EPH_COMM_DEVICE_NOT_DN40_DOT_POS;       
    /*      0x102E	4143	0000~0099	總積算值10~9	總積算值
            0x102F	4144	0000~9999	總積算值8~5	
            0x1030	4145	0000~9999	總積算值4~1	
            0x1031	4146	0002~0004	小數點位數	                */  
    FN_HEX2BCD_U64_API(recv->volume, (UINT8*)&transmitter->volumeBCD_dotBCD, sizeof(transmitter->volumeBCD_dotBCD));   
    transmitter->volumeBCD_dotBCD=(transmitter->volumeBCD_dotBCD<<EPH_COMM_WORD_BITS)|dotPosition;
    /*      0x1032	4147	0000~0099	瞬間值6~5	瞬間值
            0x1033	4148	0000~9999	瞬間值4~1	
            0x1034	4149	0002~0004	小數點位數	                */
    //===== 瞬間值的小數點固定為5位, Ver0.0.01 =====
    FN_HEX2BCD_U64_API(recv->flow_rate, (UINT8*)&transmitter->flowRateBCD_dotBCD, sizeof(transmitter->flowRateBCD_dotBCD));   
    transmitter->flowRateBCD_dotBCD=(transmitter->flowRateBCD_dotBCD<<EPH_COMM_WORD_BITS)|(0x05); 
    /*      0x1035	4150	0000~0099	正積算值10~9	正積算值
            0x1036	4151	0000~9999	正積算值8~5	
            0x1037	4152	0000~9999	正積算值4~1	
            0x1038	4153	0002~0004	小數點位數	                */  
    //===== 正積算值計算使用讀取回來的 總積算值 - 反積算值, 如果為負數就等於 0x00, Ver0.0.01 =====   
    FN_HEX2BCD_U64_API(recv->plus_total_flow, (UINT8*)&transmitter->plusTotalFlowBCD_dotBCD, sizeof(transmitter->plusTotalFlowBCD_dotBCD));
    transmitter->plusTotalFlowBCD_dotBCD=(transmitter->plusTotalFlowBCD_dotBCD<<EPH_COMM_WORD_BITS)|dotPosition;
    /*      0x1039	4154	0000~0099	反積算值10~9	反積算值
            0x103A	4155	0000~9999	反積算值8~5	
            0x103B	4156	0000~9999	反積算值4~1	
            0x103C	4157	0002~0004	小數點位數	        */
    FN_HEX2BCD_U64_API(recv->reverse_totalizer, (UINT8*)&transmitter->minusTotalFlowBCD_dotBCD, sizeof(transmitter->minusTotalFlowBCD_dotBCD));   
    transmitter->minusTotalFlowBCD_dotBCD=(transmitter->minusTotalFlowBCD_dotBCD<<EPH_COMM_WORD_BITS)|dotPosition;
    //===== 新增解析不同型態總累積量、正/反總累積量、流率的功能, Ver 1.0.07 ======
    eph_comm_new_version_converter(recv,recv_index-1,dotPosition);
    transmitter->lDayBCD=(UINT16)recv->l_day;
    transmitter->nDayBCD=(UINT16)recv->n_day;
    transmitter->oDayBCD=(UINT16)recv->o_day;
    transmitter->uDayBCD=(UINT16)recv->u_day;
    transmitter->hDayBCD=(UINT16)recv->h_day;
    transmitter->bDayBCD=(UINT16)recv->b_day;
    transmitter->userCountBCD=(UINT16)recv->user_count;
    transmitter->statusBCD=0x0001;   
    transmitter->lDayBCD_nDayBCD=((UINT16)recv->l_day<<EPH_COMM_BYTE_BITS)|recv->n_day;
    transmitter->oDayBCD_uDayBCD=((UINT16)recv->o_day<<EPH_COMM_BYTE_BITS)|recv->u_day;
    transmitter->hDayBCD_bDayBCD=((UINT16)recv->h_day<<EPH_COMM_BYTE_BITS)|recv->b_day;

}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 eph_comm_read_register_cmd
//
//! @author 	 Jacky Lin
//
//! @date 		 2022/07/26
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void eph_comm_read_register_cmd(UINT8 ptr)
{
    STC_EPH_COMM_READ_WRITE_REGISTER_CMD_PACKAGE cmd;
    UINT16 register_value=EPH_COMM_ADDRESS_REALTIME;
    cmd.device_id=gb_eph_comm_device_tlb[ptr].commID;
    cmd.function_code=EPH_COMM_FUNC_READ_REGISTER;
    cmd.register_value_h=(UINT8)((register_value&EPH_COMM_HIGH_BYTE_MASK)>>EPH_COMM_BYTE_BITS);
    cmd.register_value_l=(UINT8)(register_value&EPH_COMM_LOW_BYTE_MASK);
    memset(cmd.set_parameter,0x00,sizeof(cmd.set_parameter)); //===== eph 訊號轉換器沒有timestamp, 所以都設定為"0"
    cmd.crc_check=EPH_COMM_CRC_CODE_API((UINT8*)&cmd,sizeof(cmd)-EPH_COMM_CRC_LEN);
    EPH_COMM_REGISTER_COMMAND(&cmd, sizeof(cmd));
}  
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 eph_comm_wake_toggle
//
//! @author 	 Jacky Lin
//
//! @date 		 2022/08/02
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void eph_comm_transmitter_process()
{
    static UINT8 distribution_id;
    //===== 與EPH通訊的process, wakeup(HI)->1ms->wakeup(LO)->1ms->send_command, Ver 0.0.02 =====
    switch(gb_eph_comm_transmitter_state)
    {
    case EPH_COMM_TRANSMITTER_STATE_WAKUP_HI:       
        EPH_COMM_WAKEUP_HIGH();
        //===== 將 wakeup 的 hhigh level 延長至5ms(原本為1ms), Ver 1.0.09 =====
        EPH_COMM_TRANSMITTER_PROCESS_TIMEOUT(5);        
      break;
    case EPH_COMM_TRANSMITTER_STATE_WAKUP_LO:        
        EPH_COMM_WAKEUP_LOW(); 
        EPH_COMM_TRANSMITTER_PROCESS_TIMEOUT(1);
      break;
    case EPH_COMM_TRANSMITTER_STATE_SEND_CMD:
            //===== wakeup函式中加入 自動分配ID的功能, Ver 0.0.04 =====
            if(PFC_OPERATION_MODE==PFC_OPERATION_DISTRIBUTION)
            {
                eph_comm_set_commulication(distribution_id+1, PFC_COMMULICATION_MODBUS);  
                if(++distribution_id>=PFC_DUSTRIBUT_MAX_DEVICE)
                {
                    distribution_id=0;                    
                    EPH_COMM_SET_DISTRIBUTION_STATE(EPH_COMM_DISTRIBUTION_STATE_START); 
                    gb_eph_comm_transmitter_state=EPH_COMM_TRANSMITTER_STATE_WAKUP_HI;
                    return ;
                }
                EPH_COMM_TRANSMITTER_PROCESS_TIMEOUT(700);
            }
            else
            {    
                //===== 競爭廠商RS485模式下, 讀取命令都只針對ID1的EPH水表, Ver 0.0.03 =====
                if(gb_eph_comm_rs485_state==EPH_COMM_RS485STA_FUNC_OK)
                    eph_comm_read_register_cmd(0);
                else
                    eph_comm_read_register_cmd(gb_eph_comm_device_ptr);
            }
      break;
    }
    if(++gb_eph_comm_transmitter_state>=EPH_COMM_TRANSMITTER_STATE_TOTAL)
      gb_eph_comm_transmitter_state=EPH_COMM_TRANSMITTER_STATE_WAKUP_HI;
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 eph_comm_timeout_isr
//
//! @author 	 Jacky Lin
//
//! @date 		 2022/08/09
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void eph_comm_timeout_isr()
{
    if(gb_eph_comm_rs485_state==EPH_COMM_RS485STA_FUNC_OK)
      return;
    
    gb_eph_comm_rs485_state=EPH_COMM_RS485STA_IDEL;   
    gb_eph_comm_rs485_ptr=0;
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 eph_comm_task
//
//! @author 	 Jacky Lin
//
//! @date 		 2022/07/26
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 modbus_master_response_timeout_isr
//
//! @author 	 Jacky Lin
//
//! @date 		 2022/08/12
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void eph_comm_clean_distribut_table()
{
    memset(gs_eph_comm_arrangement,0,sizeof(gs_eph_comm_arrangement)); 
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 eph_comm_set_commulicatoin
//
//! @author 	 Jacky Lin
//
//! @date 		 2022/08/12
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void eph_comm_set_commulication(UINT8 id, UINT8 mode)
{
    UINT16 register_value;   
    UINT8 i;
    //===== 新增傳訊器可以切換水表通訊模式的功能(MODBUS or CHT)Ver 0.0.04 =====
    if(mode==PFC_COMMULICATION_MODBUS)         
    {
        STC_EPH_COMM_READ_WRITE_REGISTER_CMD_PACKAGE cmd;
        register_value=EPH_COMM_CHT2MODBUS_CMD;             
        cmd.device_id=(UINT8)(id);
        cmd.function_code=EPH_COMM_FUNC_READ_REGISTER;
        cmd.register_value_h=(UINT8)((register_value&EPH_COMM_HIGH_BYTE_MASK)>>EPH_COMM_BYTE_BITS);
        cmd.register_value_l=(UINT8)(register_value&EPH_COMM_LOW_BYTE_MASK);
        memset(cmd.set_parameter,0x00,sizeof(cmd.set_parameter)); //===== eph 訊號轉換器沒有timestamp, 所以都設定為"0"
        cmd.crc_check=EPH_COMM_CRC_CODE_API((UINT8*)&cmd,sizeof(cmd)-EPH_COMM_CRC_LEN);      
        //===== CHT 切換成 MODBUS模式使用 master uart interrupt 的方法, Ver 0.0.04 =====
        EPH_COMM_REGISTER_COMMAND(&cmd, sizeof(cmd));        
    }
    else if(mode==PFC_COMMULICATION_CHT)
    {
        STC_EPH_COMM_READ_WRITE_REGISTER_PACKAGE cmd;
        register_value=EPH_COMM_COMMLICATION_ADDRESS;
        cmd.device_id=(UINT8)(id);
        cmd.function_code=EPH_COMM_FUNC_WRITE_REGISTER;
        cmd.register_address_h=(UINT8)((register_value&EPH_COMM_HIGH_BYTE_MASK)>>EPH_COMM_BYTE_BITS);
        cmd.register_address_l=(UINT8)(register_value&EPH_COMM_LOW_BYTE_MASK);
        cmd.register_value_h=(UINT8)((mode&EPH_COMM_HIGH_BYTE_MASK)>>EPH_COMM_BYTE_BITS);;
        cmd.register_value_l=(UINT8)(mode&EPH_COMM_LOW_BYTE_MASK);;
        cmd.crc_check=EPH_COMM_CRC_CODE_API((UINT8*)&cmd,sizeof(cmd)-EPH_COMM_CRC_LEN);    
        //===== MODBUS 切換成 CHT模式使用 master uart polling 的方法, 花費時間會較少, Ver 0.0.04 =====
         //====== 往水表端傳送資料, 使用的是 master 的 uart =====
        FK_UART1_TX_WAIT_API();
        FK_SET_OUTPUT_PIN_HIGH_API(FK_PORTA,FK_PIN11);
        eph_comm_delay_time(0x3FFF);     //6ms 
        for(i=0; i<sizeof(cmd); i++)
        {
            FK_UART1_SEND_BYTE_API(*(((UINT8*)&cmd)+i));
            FK_UART1_TX_WAIT_API();
        }               
        FK_SET_OUTPUT_PIN_LOW_API(FK_PORTA,FK_PIN11);
        //===== 切換通訊模式(modbus -> cht)每一台間隔時間修正, 0x8FFFF -> 0xAFFFF, Ver 0.0.05 =====
        eph_comm_delay_time(0xAFFFF);      //6ms 
    }
        
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 eph_comm_read_meterid_cmd
//
//! @author 	 Jacky Lin
//
//! @date 		 2021/10/08
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void eph_comm_read_meterid_cmd(UINT8 device_id, UINT8 function, UINT16 address, UINT16 count)
{
    //if(gb_modbus_master_commulication_state==MODBUS_MASTER_COMM_STATE_EPH_DISTRIBUT)
    //    return;
    
    STC_EPH_COMM_READ_WRITE_REGISTER_PACKAGE cmd;
    cmd.device_id=device_id;
    cmd.function_code=function;
    cmd.register_address_h=(UINT8)((address&EPH_COMM_HIGH_BYTE_MASK)>>EPH_COMM_BYTE_BITS);
    cmd.register_address_l=(UINT8)(address&EPH_COMM_LOW_BYTE_MASK);
    cmd.register_value_h=(UINT8)((count&EPH_COMM_HIGH_BYTE_MASK)>>EPH_COMM_BYTE_BITS);
    cmd.register_value_l=(UINT8)(count&EPH_COMM_LOW_BYTE_MASK);   
    cmd.crc_check=EPH_COMM_CRC_CODE_API((UINT8*)&cmd,sizeof(cmd)-EPH_COMM_CRC_LEN);
    //gb_modbus_master_commulication_state=MODBUS_MASTER_COMM_STATE_SENDING;
    //gb_modbus_master_commulication_length=sizeof(STC_MODBUS_MASTER_READ_WRITE_REGISTER_PACKAGE);
    //gb_modbus_master_commulication_ptr=0;  
    EPH_COMM_REGISTER_COMMAND(&cmd, sizeof(cmd));   
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 eph_comm_distribut_exception
//
//! @author 	 Jacky Lin
//
//! @date 		 2022/08/15
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void eph_comm_distribut_exception()
{
    static UINT8 last_complete_number;
    if(++PFC_DUSTRIBUT_ERROR_COUNT>=PFC_DUSTRIBUT_ERROR_TARGET)
    {
        PFC_DUSTRIBUT_ERROR_COUNT=0;
        if(++PFC_DUSTRIBUT_POLLING_ID>PFC_DUSTRIBUT_MAX_DEVICE)
        {
            eph_comm_rearrange_meterid();    
            //===== 新增分配ID時, 如果多次都分配不到目標值, 將自動停止自動分配ID, 並回到桓達通訊模式, Ver 0.0.08 =====
            if(last_complete_number!=PFC_DUSTRIBUT_DEVICE_COMPLETE_NUM)
            {
                last_complete_number=PFC_DUSTRIBUT_DEVICE_COMPLETE_NUM;
                gb_eph_comm_disconnect_round=0;
            }
            else
            {
                if(++gb_eph_comm_disconnect_round>=EPH_COMM_DISCONNECT_ROUND)
                {
                    gb_eph_comm_disconnect_round=0;
                    PFC_SET_DISTRIBUTION_HALT_API();
                }                
            }
            //===== Ver 0.0.08 =====
        }
        if(PFC_DUSTRIBUT_POLLING_ID>EPH_COMM_DEVICE_NUM)
        {
            pfc_distribut_param_init();
        }
    }
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 eph_comm_distribut_parse
//
//! @author 	 Jacky Lin
//
//! @date 		 2022/08/15
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void eph_comm_distribut_parse()
{
    UINT8 word_count,high_byte,low_byte,i,repeat_target;  
    UINT16 *data_ptr, ModbusIDtemp;
    UINT8 MeterIDtemp[16],repeat=EPH_COMM_METERID_REPEAT_NO;
    STC_EPH_COMM_METER_ID_ARRANGEMENT *table=(STC_EPH_COMM_METER_ID_ARRANGEMENT*)&gs_eph_comm_arrangement[0];
    STC_EPH_COMM_MODBUS_RECEIVE_PACKAGE *receive=(STC_EPH_COMM_MODBUS_RECEIVE_PACKAGE*)&EPH_COMM_BUFFER[0];
 
    //gs_modbus_master_eph_meter_id_tlb.
    word_count=receive->byte_count/2;
    PFC_DUSTRIBUT_ERROR_COUNT=0;
    repeat_target=(PFC_DUSTRIBUT_POLLING_ID==1)?PFC_DUSTRIBUT_FIRST_REPEAT_TARGET:EPH_COMM_DEFALUT_REPEAT;

    for(i=0; i<word_count; i++)
    {
        data_ptr=((UINT16*)&(receive->data)+i);   
        high_byte=(*(data_ptr)&EPH_COMM_HIGH_BYTE_MASK)>>EPH_COMM_BYTE_BITS;
        low_byte=(*(data_ptr)&EPH_COMM_LOW_BYTE_MASK);
        if(i<=7)   
        {            
            MeterIDtemp[i*2]=high_byte;
            MeterIDtemp[1+i*2]=low_byte;
        }     
        else if(i>=8)
        {
            ModbusIDtemp=high_byte|low_byte;
        }          
    }
    if(!PFC_DUSTRIBUT_DEVICE_PTR)
    {
        (table+PFC_DUSTRIBUT_DEVICE_PTR)->previous_id=ModbusIDtemp;
        memcpy((table+PFC_DUSTRIBUT_DEVICE_PTR)->meter_id,MeterIDtemp, sizeof(MeterIDtemp));
        PFC_DUSTRIBUT_DEVICE_PTR++;    
    }
    
    for(i=0; i<PFC_DUSTRIBUT_DEVICE_PTR; i++)
    {
        if(!strcmp(MeterIDtemp,(table+i)->meter_id))
        {
            repeat=EPH_COMM_METERID_REPEAT_YES;
            if(++PFC_DUSTRIBUT_REPEAT_COUNT>=repeat_target)
            {
                PFC_DUSTRIBUT_REPEAT_COUNT=0;
                PFC_DUSTRIBUT_POLLING_ID++;
                if(PFC_DUSTRIBUT_DEVICE_PTR==PFC_DUSTRIBUT_MAX_DEVICE || PFC_DUSTRIBUT_POLLING_ID>PFC_DUSTRIBUT_MAX_DEVICE)
                {
                    eph_comm_rearrange_meterid();
                }
            }
            break;
        }
    }
    if(repeat==EPH_COMM_METERID_REPEAT_NO)
    {
        (table+PFC_DUSTRIBUT_DEVICE_PTR)->previous_id=ModbusIDtemp;
        memcpy((table+PFC_DUSTRIBUT_DEVICE_PTR)->meter_id,MeterIDtemp, sizeof(MeterIDtemp));
        PFC_DUSTRIBUT_DEVICE_PTR++;
        PFC_DUSTRIBUT_REPEAT_COUNT=0;
    }  
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 eph_comm_rearrange_meterid
//
//! @author 	 Jacky Lin
//
//! @date 		 2022/08/15
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void eph_comm_rearrange_meterid()
{   
    UINT8 i,j,MeterIDtemp[16],PreviousIDtemp;
    STC_EPH_COMM_METER_ID_ARRANGEMENT *table=(STC_EPH_COMM_METER_ID_ARRANGEMENT*)&gs_eph_comm_arrangement[0];
           
    for( i=0; i<PFC_DUSTRIBUT_DEVICE_PTR; i++)
    {
        for( j=i+1; j<PFC_DUSTRIBUT_DEVICE_PTR; j++)
        {
            if(strcmp((table+i)->meter_id,(table+j)->meter_id)>0)
            {
                memcpy(MeterIDtemp,(table+j)->meter_id, sizeof(MeterIDtemp));
                PreviousIDtemp=(table+j)->previous_id;
                memcpy((table+j)->meter_id,(table+i)->meter_id, sizeof((table+j)->meter_id));
                (table+j)->previous_id=(table+i)->previous_id;
                memcpy((table+i)->meter_id,MeterIDtemp, sizeof((table+i)->meter_id));
                (table+i)->previous_id=PreviousIDtemp;
            }
        }
        (table+i)->distribut_id=(i+1);
    }
    //===== 即時搜尋到的
    if(PFC_DUSTRIBUT_DEVICE_PTR>=PFC_DUSTRIBUT_DEVICE_COMPLETE_NUM)
    {
        PFC_DUSTRIBUT_DEVICE_COMPLETE_NUM=PFC_DUSTRIBUT_DEVICE_PTR;
        EPH_COMM_SET_DISTRIBUTION_STATE(EPH_COMM_DISTRIBUTION_STATE_IDEL);
        PFC_SET_WRITE_DISTRIBUT_FLAG();
    }     
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 modbus_master_set_distribution_id
//
//! @author 	 Jacky Lin
//
//! @date 		 2022/08/15
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void eph_comm_set_distribution_id()
{
    UINT16* data_ptr;
    UINT8 high_byte,low_byte,word_count,send_length=0;    
    STC_EPH_COMM_DISTRIBUT_ID_CMD* cmd=(STC_EPH_COMM_DISTRIBUT_ID_CMD*)&EPH_COMM_BUFFER[0];
    STC_EPH_COMM_METER_ID_ARRANGEMENT* table=(STC_EPH_COMM_METER_ID_ARRANGEMENT*)&gs_eph_comm_arrangement[0];
    
    cmd->address=0x00;
    cmd->dump=0x00;
    cmd->function_code=0x01;
    cmd->byte_count=18;
    cmd->word_count=cmd->byte_count/2;
    word_count=cmd->byte_count/2;
    send_length=cmd->byte_count+9;
    
    //====== 往水表端傳送資料, 使用的是master 的 direction pin =====
    FK_SET_OUTPUT_PIN_HIGH_API(FK_PORTA,FK_PIN11);
    eph_comm_delay_time(0x2FF);
    for(UINT8 i=0; i<PFC_DUSTRIBUT_DEVICE_PTR; i++)    
    {         
        cmd->id=(table+i)->previous_id;
        for(UINT8 j=0; j<word_count; j++)
        {     
            if(j<=7)   
            { 
                data_ptr=((UINT16*)&((table+i)->meter_id)+j);   
                high_byte=(*(data_ptr)&EPH_COMM_HIGH_BYTE_MASK)>>EPH_COMM_BYTE_BITS;
                low_byte=(*(data_ptr)&EPH_COMM_LOW_BYTE_MASK);                
                cmd->meter_id[j*2]=high_byte;
                cmd->meter_id[1+j*2]=low_byte;
            }     
            else if(j>=8)
            {
                low_byte=*((UINT8*)&((table+i)->distribut_id)); 
                high_byte=0x00;
                //===== 修正 cmd->distribut_id  assert value 的方法, 不可取位址, 因為 cmd struct 沒對齊, Ver 0.0.04 =====
                cmd->distribut_id=((UINT16)low_byte<<EPH_COMM_BYTE_BITS)|(high_byte&EPH_COMM_LOW_BYTE_MASK);      
            }                
        }
        cmd->crc=EPH_COMM_CRC_CODE_API(EPH_COMM_BUFFER,sizeof(STC_EPH_COMM_DISTRIBUT_ID_CMD)-EPH_COMM_CRC_LEN);              
         //====== 往水表端傳送資料, 使用的是 master 的 uart =====
        for(UINT8 k=0;k<send_length;k++)
        {
            FK_UART1_SEND_BYTE_API(EPH_COMM_BUFFER[k]);
            FK_UART1_TX_WAIT_API();
        }   
        eph_comm_delay_time(0x2FFFFF);
    }    
}
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 eph_comm_task
//
//! @author 	 Jacky Lin
//
//! @date 		 2021/10/20
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void eph_comm_task()
{

}
#ifdef __cplusplus
}
#endif

