//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 modbus_slave_glb_vars.c
//
//! @author 	 Willman Chen
//
//! @date 		 2009/11/10
//
//  @brief 		 Init globe variable
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#define MODBUS_SLAVE_ALLOC
#include "modbus_slave_glb_vars.h"
#undef MODBUS_SLAVE_ALLOC
#include "modbus_slave_idef.h"
#include "modbus_slave_task.h"
UINT16 gw_modbus_slave_reverse[]={0x0000};

const STC_MODBUS_SLAVE_COMMAND_INFO gt_modbus_slave_valid_function[MODBUS_SLAVE_MAX_COMMAND]=
{
  //  id code	max_register	max_value	return_byte_cnt	command length	action		supported
  {0x00	,0	,0	,0	,0	,modbus_slave_null_func			,MODBUS_SLAVE_SUPPORTED_CMD_NO},	//  Non
  {0x01	,0	,0	,0	,0	,modbus_slave_null_func			,MODBUS_SLAVE_SUPPORTED_CMD_NO},	//  Read Coils
  {0x02	,0	,0	,0	,0	,modbus_slave_null_func			,MODBUS_SLAVE_SUPPORTED_CMD_NO},	//  Read Discrete Inputs
  {0x03	,0xffff	,125	,2	,5	,modbus_slave_read_input_registers	,MODBUS_SLAVE_SUPPORTED_CMD_YES},	//  Read Holding Registers
  {0x04	,0	,0	,0	,0	,modbus_slave_null_func			,MODBUS_SLAVE_SUPPORTED_CMD_NO},	//  Read Input Registers
  {0x05	,0	,0	,0	,0	,modbus_slave_null_func			,MODBUS_SLAVE_SUPPORTED_CMD_NO},	//  Write Single Coil
  {0x06	,0xffff	,0xffff	,0	,5	,modbus_slave_write_single_register	,MODBUS_SLAVE_SUPPORTED_CMD_YES},	//  Write Single Register
  {0x07	,0	,0	,0	,0	,modbus_slave_null_func			,MODBUS_SLAVE_SUPPORTED_CMD_NO},	//	Read Exception Status
  {0x08	,0	,0	,0	,0	,modbus_slave_null_func			,MODBUS_SLAVE_SUPPORTED_CMD_NO},	//  Diagnostics
  {0x09	,0	,0	,0	,0	,modbus_slave_null_func			,MODBUS_SLAVE_SUPPORTED_CMD_NO},	//  not defined
  {0x0A	,0	,0	,0	,0	,modbus_slave_null_func			,MODBUS_SLAVE_SUPPORTED_CMD_NO},	//  not defined
  {0x0B	,0	,0	,0	,0	,modbus_slave_null_func			,MODBUS_SLAVE_SUPPORTED_CMD_NO},	//	Get Common Event Counter
  {0x0C	,0	,0	,0	,0	,modbus_slave_null_func			,MODBUS_SLAVE_SUPPORTED_CMD_NO},	//	Get common Event log
  {0x0D	,0	,0	,0	,0	,modbus_slave_null_func			,MODBUS_SLAVE_SUPPORTED_CMD_NO},	//  not defined
  {0x0E	,0	,0	,0	,0	,modbus_slave_null_func			,MODBUS_SLAVE_SUPPORTED_CMD_NO},	//  not defined
  {0x0F	,0	,0	,0	,0	,modbus_slave_null_func			,MODBUS_SLAVE_SUPPORTED_CMD_NO},	//  Write Multiple Coils
  {0x10	,0xffff	,0x7b	,1	,6	,modbus_slave_write_multi_register	,MODBUS_SLAVE_SUPPORTED_CMD_YES},	//	Write Multiple register
  {0x11	,0	,0	,0	,0	,modbus_slave_null_func			,MODBUS_SLAVE_SUPPORTED_CMD_NO},	//	Report Slave ID
  {0x12	,0	,0	,0	,0	,modbus_slave_null_func			,MODBUS_SLAVE_SUPPORTED_CMD_NO},	//  not defined
  {0x13	,0	,0	,0	,0	,modbus_slave_null_func			,MODBUS_SLAVE_SUPPORTED_CMD_NO},	//  not defined
  {0x14	,0	,0	,0	,0	,modbus_slave_null_func			,MODBUS_SLAVE_SUPPORTED_CMD_NO},	//	Read File Record
  {0x15	,0	,0	,0	,0	,modbus_slave_null_func			,MODBUS_SLAVE_SUPPORTED_CMD_NO},	//	Write File Record
  {0x16	,0	,0	,0	,0	,modbus_slave_null_func			,MODBUS_SLAVE_SUPPORTED_CMD_NO},	//	Mask Write Register
  {0x17	,0	,0	,0	,0	,modbus_slave_null_func			,MODBUS_SLAVE_SUPPORTED_CMD_NO},	//  Read/Write Multiple registers
  {0x18	,0	,0	,0	,0	,modbus_slave_null_func			,MODBUS_SLAVE_SUPPORTED_CMD_NO},	//	Read FIFO Queue
};

  const UINT16 gt_modbus_slave_ddf_file[MODBUS_SLAVE_DDF_LEN]=
  {
    0x4444,
  };

const UINT16* gt_modbus_slave_readonly[MODBUS_SLAVE_READONLY_NUM]=
{
  (UINT16*)&gw_modbus_slave_reverse             ,
};
const UINT16* gt_modbus_slave_read_write[MODBUS_SLAVE_READ_WRITE_NUM]=
{       
      (UINT16*)&PFC_PRODUCT_NAME                ,               //5408 (1)The product Name[36]
      (UINT16*)&PFC_PRODUCT_NAME+1              ,               //5409 (2) 
      (UINT16*)&PFC_PRODUCT_NAME+2              ,               //5410 (3) 
      (UINT16*)&PFC_PRODUCT_NAME+3              ,               //5411 (4) 
      (UINT16*)&PFC_PRODUCT_NAME+4              ,               //5412 (5) 
      (UINT16*)&PFC_PRODUCT_NAME+5              ,               //5413 (6) 
      (UINT16*)&PFC_PRODUCT_NAME+6              ,               //5414 (7) 
      (UINT16*)&PFC_PRODUCT_NAME+7              ,               //5415 (8) 
      (UINT16*)&PFC_PRODUCT_NAME+8              ,               //5416 (9) 
      (UINT16*)&PFC_PRODUCT_NAME+9              ,               //5417 (10) 
      (UINT16*)&PFC_PRODUCT_NAME+10             ,               //5418 (11) 
      (UINT16*)&PFC_PRODUCT_NAME+11             ,               //5419 (12) 
      (UINT16*)&PFC_PRODUCT_NAME+12             ,               //5420 (13) 
      (UINT16*)&PFC_PRODUCT_NAME+13             ,               //5421 (14) 
      (UINT16*)&PFC_PRODUCT_NAME+14             ,               //5422 (15) 
      (UINT16*)&PFC_PRODUCT_NAME+15             ,               //5423 (16) 
      (UINT16*)&PFC_PRODUCT_NAME+16             ,               //5424 (17) 
      (UINT16*)&PFC_PRODUCT_NAME+17             ,               //5425 (18) 
      (UINT16*)&PFC_PRODUCT_SERIAL                  ,             //5426 (1)產品序號[20] 
      (UINT16*)&PFC_PRODUCT_SERIAL+1                ,             //5427 (2) 
      (UINT16*)&PFC_PRODUCT_SERIAL+2                ,             //5428 (3) 
      (UINT16*)&PFC_PRODUCT_SERIAL+3                ,             //5429 (4) 
      (UINT16*)&PFC_PRODUCT_SERIAL+4                ,             //5430 (5) 
      (UINT16*)&PFC_PRODUCT_SERIAL+5                ,             //5431 (6) 
      (UINT16*)&PFC_PRODUCT_SERIAL+6                ,             //5432 (7) 
      (UINT16*)&PFC_PRODUCT_SERIAL+7                ,             //5433 (8) 
      (UINT16*)&PFC_PRODUCT_SERIAL+8                ,             //5434 (9) 
      (UINT16*)&PFC_PRODUCT_SERIAL+9                ,             //5435 (10) 
      (UINT16*)&PFC_FIRMWARE_VERSION              ,               //5436 (1)韌體版本[12]
      (UINT16*)&PFC_FIRMWARE_VERSION+1              ,               //5437 (2)
      (UINT16*)&PFC_FIRMWARE_VERSION+2              ,               //5438 (3)
      (UINT16*)&PFC_FIRMWARE_VERSION+3              ,               //5439 (4)
      (UINT16*)&PFC_FIRMWARE_VERSION+4              ,               //5440 (5)
      (UINT16*)&PFC_FIRMWARE_VERSION+5              ,               //5441 (6)
      (UINT16*)&PFC_HARDWARE_VERSION                ,             //5442 (1)硬體版本[22]                      
      (UINT16*)&PFC_HARDWARE_VERSION+1            ,               //5443 (2)
      (UINT16*)&PFC_HARDWARE_VERSION+2            ,               //5444 (3)   
      (UINT16*)&PFC_HARDWARE_VERSION+3            ,               //5445 (4)
      (UINT16*)&PFC_HARDWARE_VERSION+4            ,               //5446 (5)
      (UINT16*)&PFC_HARDWARE_VERSION+5            ,               //5447 (6)
      (UINT16*)&PFC_HARDWARE_VERSION+6            ,               //5448 (7)
      (UINT16*)&PFC_HARDWARE_VERSION+7            ,               //5449 (8)
      (UINT16*)&PFC_HARDWARE_VERSION+8            ,               //5450 (9)
      (UINT16*)&PFC_HARDWARE_VERSION+9            ,               //5451 (10)
      (UINT16*)&PFC_HARDWARE_VERSION+10           ,               //5452 (11)
      (UINT16*)&PFC_PRODUCT_DATE                  ,               //5453 (1)生產日期[12]
      (UINT16*)&PFC_PRODUCT_DATE+1                ,               //5454 (2)
      (UINT16*)&PFC_PRODUCT_DATE+2                ,               //5455 (3)
      (UINT16*)&PFC_PRODUCT_DATE+3                ,               //5456 (4)
      (UINT16*)&PFC_PRODUCT_DATE+4                ,               //5457 (5)
      (UINT16*)&PFC_PRODUCT_DATE+5                ,               //5458 (6)
      (UINT16*)&PFC_SF_PRODUCT_SERIAL             ,               //5459 (1)半成品產品序號[14]
      (UINT16*)&PFC_SF_PRODUCT_SERIAL+1           ,               //5460 (2)
      (UINT16*)&PFC_SF_PRODUCT_SERIAL+2           ,               //5461 (3)
      (UINT16*)&PFC_SF_PRODUCT_SERIAL+3           ,               //5462 (4)
      (UINT16*)&PFC_SF_PRODUCT_SERIAL+4           ,               //5463 (5)
      (UINT16*)&PFC_SF_PRODUCT_SERIAL+5           ,               //5464 (6)
      (UINT16*)&PFC_SF_PRODUCT_SERIAL+6           ,               //5465 (7)
      (UINT16*)&PFC_SF_PRODUCT_DATE               ,               //5466 (1)半成品生產日期[12]
      (UINT16*)&PFC_SF_PRODUCT_DATE+1           ,               //5467 (2)
      (UINT16*)&PFC_SF_PRODUCT_DATE+2           ,               //5468 (3)
      (UINT16*)&PFC_SF_PRODUCT_DATE+3           ,               //5469 (4)
      (UINT16*)&PFC_SF_PRODUCT_DATE+4           ,               //5470 (5)
      (UINT16*)&PFC_SF_PRODUCT_DATE+5           ,               //5471 (6)
      (UINT16*)&PFC_SAVE_CALIBRATION_SETTING            ,       //5489 
      (UINT16*)&PFC_LOAD_DEFAULT_SETTING                ,       //5490 
      (UINT16*)&PFC_SAVE_SYSTEM_VAR_TO_EEPROM             ,     //5491 
      (UINT16*)&PFC_LOAD_FIRMWARE_SETTING	        ,       //5492 
};

/*PFC_MODBUS_BAUDRATE
PFC_MODBUS_ID*/
const UINT8 gt_modbus_slave_fine_tek_id[]= {'F','I','N','E','-','T','E','K'};
const UINT16 gw_modbus_slave_readonly_number=MODBUS_SLAVE_READONLY_NUM;
const UINT16 gw_modbus_slave_readwrite_number=MODBUS_SLAVE_READ_WRITE_NUM;
const UINT16 gw_modbus_slave_unit_type=0x501C;
const UINT16 gw_modbus_slave_ddf_start_address=MODBUS_SLAVE_DDF_START_ADDRESS;
const UINT16 gw_modbus_slave_readonly_remap_addr=MODBUS_SLAVE_READONLY_START_ADDRESS;
const UINT16 gw_modbus_slave_readwrite_remap_addr=MODBUS_SLAVE_READ_WRITE_START_ADDRESS;

const UINT16* gt_modbus_slave_header[MODBUS_SLAVE_HEADER_NUM]=
{
    (UINT16*)&gt_modbus_slave_fine_tek_id[0],				// 0x1000 ~ 0x1003 "FINE-TEK" company identified string
    (UINT16*)&gt_modbus_slave_fine_tek_id[2],
    (UINT16*)&gt_modbus_slave_fine_tek_id[4],
    (UINT16*)&gt_modbus_slave_fine_tek_id[6],
    (UINT16*)&PFC_PRODUCT_TYPE,			                        // 0x1004 : Product Type
    (UINT16*)&PFC_PRODUCT_NUMBER,			                // 0x1005 : Product number "FMCW 10G (0 ~ 30M)
    (UINT16*)&PFC_PRODUCT_VERSION,			                // 0x1006 : Product version 2010/10/01
    (UINT16*)&PFC_DISPLAY_VALUE1,					// 0x1007 : the first variable value (high)
    (UINT16*)&PFC_DISPLAY_VALUE1+1,					// 0x1008 : the first variable value (low)
    (UINT16*)&gw_modbus_slave_unit_type,                                // 0x1009 : the first variable unit
    (UINT16*)&PFC_DISPLAY_VALUE2,					// 0x100A : the second variable value (high)
    (UINT16*)&PFC_DISPLAY_VALUE2+1,					// 0x100B : the second variable value (low)
    (UINT16*)&gw_modbus_slave_unit_type,                                // 0x100C : the second variable unit (
    (UINT16*)&PFC_DISPLAY_VALUE3,					// 0x100D : the third variable value (high)
    (UINT16*)&PFC_DISPLAY_VALUE3+1,					// 0x100E : the third variable value (low)
    (UINT16*)&gw_modbus_slave_unit_type,                                // 0x100F : the third variable unit
    (UINT16*)&PFC_DISPLAY_VALUE4,					// 0x1010 : the fourth variable value (high)
    (UINT16*)&PFC_DISPLAY_VALUE4+1,					// 0x1011 : the fourth variable value (low)
    (UINT16*)&gw_modbus_slave_unit_type,                                // 0x1012 : the fourth variable unit
};
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 		 modbus_slave_glb_vars_init
//
//! @author 	 Willman Chen
//
//! @date 		 2009/11/10
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void modbus_slave_glb_vars_init()
{
  gb_modbus_slave_ptr=0;
  gs_modbus_slave_package_ptr=(STC_MODBUS_SLAVE_COMMAND_INFO*)&gt_modbus_slave_valid_function[0];
  gs_modbus_slave_error_package.error_code=0;
  gb_modbus_slave_response_length=0;
  gb_modbus_slave_state=MODBUS_SLAVE_STATE_STOP;
  gb_modbus_slave_char_ptr=0;
}
