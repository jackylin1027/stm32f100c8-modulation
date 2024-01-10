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

UINT16 eph_comm_decrypt_func(UINT8* source_data, UINT16 length)
{
    UINT16 g_decrypt_datalen, g_srcBuf_length=0, i,j,k;
    UINT8 g_addBuf[EPH_COMM_ENCRYPT_BLOCK],g_xorBuf[EPH_COMM_ENCRYPT_BLOCK],g_exchangeBuf[EPH_COMM_ENCRYPT_BLOCK],g_exdb[2];
    UINT8 slave_id=*(source_data);
    UINT8 function_code=*(source_data+1);
    UINT16 byte_count=*(source_data+2)+(*(source_data+3)<<EPH_COMM_BYTE_BITS);
    UINT8 leading_code=*(source_data+4);
    UINT8* tmep_data=(UINT8*)(source_data+5);
    
    g_decrypt_datalen = byte_count - 1 + 2;
    for(i = 0; i < leading_code; i++)
    {
        for (k = 0; k < 7; k++) 
            g_exchangeBuf[k] = *(tmep_data+i * 7 + k);
        
        if ((i%2) == 0) // odd block.
        {
            // Exchange
            g_xorBuf[0] = g_exchangeBuf[0];
            g_exdb[0] = (byte)((g_exchangeBuf[1] >> 4) & 0x0F);
            g_exdb[1] = (byte)(g_exchangeBuf[1] & 0x0F);
            g_xorBuf[1] = (byte)((g_exdb[1] << 4) + g_exdb[0]);
            g_xorBuf[2] = g_exchangeBuf[2];
            g_exdb[0] = (byte)((g_exchangeBuf[3] >> 4) & 0x0F);
            g_exdb[1] = (byte)(g_exchangeBuf[3] & 0x0F);
            g_xorBuf[3] = (byte)((g_exdb[1] << 4) + g_exdb[0]);
            g_xorBuf[4] = g_exchangeBuf[4];
            g_exdb[0] = (byte)((g_exchangeBuf[5] >> 4) & 0x0F);
            g_exdb[1] = (byte)(g_exchangeBuf[5] & 0x0F);
            g_xorBuf[5] = (byte)((g_exdb[1] << 4) + g_exdb[0]);
            g_xorBuf[6] = g_exchangeBuf[6];
            // Add
            g_addBuf[1] = g_xorBuf[1];
            g_addBuf[2] = (byte)(g_xorBuf[1] ^ g_xorBuf[2]);
            g_addBuf[3] = (byte)(g_xorBuf[2] ^ g_xorBuf[3]);
            g_addBuf[4] = (byte)(g_xorBuf[3] ^ g_xorBuf[4]);
            g_addBuf[5] = (byte)(g_xorBuf[4] ^ g_xorBuf[5]);
            g_addBuf[6] = (byte)(g_xorBuf[5] ^ g_xorBuf[6]);
            g_addBuf[0] = (byte)(g_xorBuf[6] ^ g_xorBuf[0]);
            
            if(i==0)
            {
                memcpy(gb_eph_comm_encrypt_fix_key,gb_eph_comm_encrypt_public_key,EPH_COMM_ENCRYPT_BLOCK);// Load initial fix key.               
                for (k = 0; k < 7; k++) { ptargetBuf[i*7 + k + 2] = (byte)(g_addBuf[k] - gb_eph_comm_encrypt_fix_key[k]); }
            }       
            else
            {
                for (k = 0; k < 7; k++) { ptargetBuf[i * 7 + k + 2] = (byte)(g_addBuf[k] - gb_eph_comm_encrypt_fix_key[k]); }                        
            }  
        }
        else // even block
        {
            // Exchange
            g_exdb[0] = (byte)((g_exchangeBuf[0] >> 4) & 0x0F);
            g_exdb[1] = (byte)(g_exchangeBuf[0] & 0x0F);
            g_xorBuf[0] = (byte)((g_exdb[1] << 4) + g_exdb[0]);
            g_xorBuf[1] = g_exchangeBuf[1];
            g_exdb[0] = (byte)((g_exchangeBuf[2] >> 4) & 0x0F);
            g_exdb[1] = (byte)(g_exchangeBuf[2] & 0x0F);
            g_xorBuf[2] = (byte)((g_exdb[1] << 4) + g_exdb[0]);
            g_xorBuf[3] = g_exchangeBuf[3];
            g_exdb[0] = (byte)((g_exchangeBuf[4] >> 4) & 0x0F);
            g_exdb[1] = (byte)(g_exchangeBuf[4] & 0x0F);
            g_xorBuf[4] = (byte)((g_exdb[1] << 4) + g_exdb[0]);
            g_xorBuf[5] = g_exchangeBuf[5];
            g_exdb[0] = (byte)((g_exchangeBuf[6] >> 4) & 0x0F);
            g_exdb[1] = (byte)(g_exchangeBuf[6] & 0x0F);
            g_xorBuf[6] = (byte)((g_exdb[1] << 4) + g_exdb[0]);
            // Add
            g_addBuf[0] = g_xorBuf[0];
            g_addBuf[1] = (byte)(g_xorBuf[0] ^ g_xorBuf[1]);
            g_addBuf[2] = (byte)(g_xorBuf[1] ^ g_xorBuf[2]);
            g_addBuf[3] = (byte)(g_xorBuf[2] ^ g_xorBuf[3]);
            g_addBuf[4] = (byte)(g_xorBuf[3] ^ g_xorBuf[4]);
            g_addBuf[5] = (byte)(g_xorBuf[4] ^ g_xorBuf[5]);
            g_addBuf[6] = (byte)(g_xorBuf[5] ^ g_xorBuf[6]);
        
            for (k = 0; k < 7; k++) { ptargetBuf[i * 7 + k + 2] = (byte)(g_addBuf[k] - gb_eph_comm_encrypt_fix_key[k]); }
            for (k = 0; k < 7; k++) { gb_eph_comm_encrypt_fix_key[k] = g_xorBuf[k]; } // Upadte random key.
        }            
    }
    return g_decrypt_datalen;
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
    STC_EPH_COMM_RECEIVE_PACKAGE* recieve_data=(STC_EPH_COMM_RECEIVE_PACKAGE*)&EPH_COMM_BUFFER[0];
    eph_comm_decrypt_func((UINT8*)&EPH_COMM_BUFFER[0], EPH_COMM_REVC_COUNT);
    
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
void eph_comm_send_command()
{
    STC_EPH_COMM_READ_WRITE_REGISTER_CMD_PACKAGE cmd;
    UINT16 register_value=25000;
    cmd.device_id=0x01;
    cmd.function_code=0x03;
    cmd.register_value_h=(UINT8)((register_value&EPH_COMM_HIGH_BYTE_MASK)>>EPH_COMM_BYTE_BITS);
    cmd.register_value_l=(UINT8)(register_value&EPH_COMM_LOW_BYTE_MASK);
    cmd.set_parameter[0]=0x00;
    cmd.set_parameter[1]=0x00;
    cmd.set_parameter[2]=0x00;
    cmd.set_parameter[3]=0x00;
    cmd.crc_check=EPH_COMM_CRC_CODE_API((UINT8*)&cmd,sizeof(cmd)-EPH_COMM_CRC_LEN);
    EPH_COMM_REGISTER_COMMAND(&cmd, sizeof(cmd));
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
void eph_comm_task()
{

}
#ifdef __cplusplus
}
#endif

