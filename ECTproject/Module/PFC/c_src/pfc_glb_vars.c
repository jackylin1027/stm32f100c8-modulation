//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 	 pfc_glb_vars.c
//
//! @author  Willman Chen
//
//! @date 	 2009/06/19
//
// @brief 	 Init globe variable
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#define PFC_ALLOC
#include "pfc_glb_vars.h"
#undef PFC_ALLOC
#include "pfc_task.h"
#include "pfc_idef.h"
#include "..\drv_src\pfc_drv.h"
#include "..\pfc_udef.h"
#include <stdlib.h>
//===== Ver 1.0.06 =====
STC_PFC_AUTO_ID  gs_pfc_auto_id=
{
  0x4550,   // Product Type : "EP" 0x4550
  0x4804,   // Product number: 'U' 0x48 , serial 0x04
  0x0001    // Product version: 0x0001
};
const UINT8 gt_pfc_days_of_month[12]=
{
  // 1  2 3  4  5  6  7  8  9  10 11 12  month
  31,28,31,30,31,30,31,31,30,31,30,31,
};
void pfc_strcpy(UINT8 *target,UINT8 *src)
{
  UINT16 i;
  for (i=0;*(src+i);i++)
    *(target+i)=*(src+i);
}
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 pfc_glb_vars_load_factory
//
//! @author  Jacky Lin
//
//! @date 	 2009/06/19
//
//! @brief 	 task function
//
//**********************************************************************************************************************
void pfc_glb_vars_load_factory()
{
    UINT32 i;
    UINT8 *data=(UINT8*)&gs_pfc_factory;
    for (i=0; i<sizeof(gs_pfc_factory); i++)
      *(data+i)=0x00; 
    
    PFC_FACTORY_PARAMETER= 8013;
}
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 pfc_glb_vars_init
//
//! @author  Willman Chen
//
//! @date 	 2009/06/19
//
//! @brief 	 task function
//
//**********************************************************************************************************************
void pfc_glb_vars_load_default()
{
    UINT32 i;
    UINT8 *data=(UINT8*)&gs_pfc_vars;
    for (i=0; i<sizeof(gs_pfc_vars); i++)
      *(data+i)=0x00;
    
    PFC_USE_HART=1;
    PFC_USE_MODBUS=1;
    PFC_USE_ZIGBEE=1;
    PFC_USE_PROFIBUS=1;
    PFC_USE_HART_WIRELESS=1;
    
    PFC_SAVE_CALIBRATION_SETTING=0;
    PFC_LOAD_DEFAULT_SETTING=0;
    PFC_SAVE_SYSTEM_VAR_TO_EEPROM=0;
    PFC_LOAD_FIRMWARE_SETTING=0;
    
    PFC_CURRENT_LOCK_VALUE=0;
    //===== modbus slave parameter =====
    PFC_MODBUS_ID=1;
    PFC_MODBUS_BTIS=UART_WORDLENGTH_8B;
    PFC_MODBUS_STOP_BITS=UART_STOPBITS_1;
    PFC_MODBUS_PARITY=UART_PARITY_NONE;
    PFC_MODBUS_MODE=MODBUS_SLAVE_RTU_MODE;
    PFC_MODBUS_BAUDRATE=9600;
    
    //===== 成品相關參數 =====
    pfc_strcpy((UINT8*)&PFC_PRODUCT_NAME,"EPH-Transmitter");            //產品料號  需求24bytes
    pfc_strcpy((UINT8*)&PFC_PRODUCT_DATE,"TB1-22010344");
    pfc_strcpy((UINT8*)&PFC_PRODUCT_SERIAL,"20220224-00001");           //工單序號  需求12bytes
    pfc_strcpy((UINT8*)&PFC_FIRMWARE_VERSION,"Ver 1.0.10");
    pfc_strcpy((UINT8*)&PFC_HARDWARE_VERSION,"EPH10L1001 220701");      //硬體版本  需求17bytes        
    //===== 新增半成品生產相關參數 =====
    pfc_strcpy((UINT8*)&PFC_SF_PRODUCT_SERIAL,"20220224-00001");
    pfc_strcpy((UINT8*)&PFC_SF_PRODUCT_DATE,"TB1-22010344");      
}
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 	 pfc_glb_vars_init
//
//! @author  Willman Chen
//
//! @date 	 2009/06/19
//
//! @brief 	 task function
//
//**********************************************************************************************************************
void pfc_glb_vars_init()
{
    UINT16 i,chksum;   
    UINT16 *data=(UINT16*)&gs_pfc_factory;
    *((UINT32*)&gs_pfc_status)=0x00;
    
    PFC_READ_FACTORY_DATA_API();
    for (i=0,chksum=0; i<(sizeof(gs_pfc_factory)>>1); i++)
      chksum+=*(data+i);
    if (chksum||((*(data+i-1)==0)&&(*data==0)))
    {
        pfc_glb_vars_load_factory();         
        PFC_MAKE_FACTORY_EEPROM_ZERO_CHECKSUM_API();
        PFC_RESTORE_FACTORY_DATA_API();
    }   
    
    data=(UINT16*)&gs_pfc_vars;
    *((UINT32*)&gs_pfc_status)=0x00;
    
    PFC_READ_USER_DATA_API();
    for (i=0,chksum=0; i<(sizeof(gs_pfc_vars)>>1); i++)
      chksum+=*(data+i);
    // loading default setting from firmware if fail.
    if (chksum||((*(data+i-1)==0)&&(*data==0)))
    {
        pfc_glb_vars_load_default();
        PFC_MAKE_EEPROM_ZERO_CHECKSUM_API();
        PFC_RESTORE_USER_DATA_API();
    }      
    pfc_strcpy((UINT8*)&PFC_FIRMWARE_VERSION,"VER 1.0.10");
}