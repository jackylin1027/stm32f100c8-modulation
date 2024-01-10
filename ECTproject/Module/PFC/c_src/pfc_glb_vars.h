#ifndef PFC_GLB_VARS_H
#define PFC_GLB_VARS_H
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 	 pfc_glb_vars.h
//
//! @author	 Willman Chen
//
//! @date 	 2009/06/19
//
// @brief 	 Here declare globe variable
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "pfc_idef.h"
#include "..\pfc_udef.h"
//**********************************************************************************************************************
//
// E X T E R N A L   V A R I A B L E   A L L O C
//
//**********************************************************************************************************************
#ifdef PFC_ALLOC
#define EXTERNAL
#else
#define EXTERNAL extern
#endif

typedef struct
{
  UINT16    modbus_id;
  UINT16    modbus_baudrate; 
  UINT16    modbus_bits:4;
  UINT16    modbus_stop_bits:2;
  UINT16    modbus_parity:2;
  UINT16    modbus_mode:1;
  UINT16    modbus_change:1;
  UINT16    null:6;
} STC_PFC_MODBUS_SETTING;

typedef struct
{
  UINT16   dac_3_dot_5_ma;			    //  The 3.5 ma current value
  UINT16   dac_4_ma;			            //  The 4 ma current value
  UINT16   dac_12_ma;				    //  The 12 ma current value
  UINT16   dac_20_ma;                              //  The 20 ma current value
  UINT16   dac_22_ma;				    //	The 22 ma current value
  UINT16   dac_4_ma_offset;			    //  The 4 ma user offset value
  UINT16   dac_20_ma_offset;			    //  The 20 ma user offset value
  UINT16   current_lock;
  UINT16   current_lock_value;
  UINT16   current_now;
  FLOAT32  current_ma;
  FLOAT32  current_offset_value;                
} STC_PFC_CURRENT_SETTING;

typedef struct
{
  UINT16        save_system_var_to_eeprom;
  UINT16        save_calibration_setting;
  UINT16        load_default_setting;
  UINT16        load_firmware_setting;
  UINT16        integral_measurement_time; // 0 sec~30 sec
} STC_PFC_SETTING_FLAG;

typedef struct
{
  UINT16    second;
  UINT16    minute;
  UINT16    hour;
  UINT16    day;
  UINT16    month;
  UINT16    year;   // start from 1900
} STC_PFC_CALANDAR_STATUS;

typedef struct
{
  UINT16                        key_task:1;
  UINT16                        uif_task:1;
  UINT16                        led_task:1;
  UINT16                        null:13;
  STC_PFC_CALANDAR_STATUS       calendar;  
  FLOAT32                       display_value1;             
  FLOAT32                       display_value2;             
  FLOAT32                       display_value3;
  FLOAT32                       display_value4;  
} STC_PFC_STATUS;

typedef struct
{
  UINT16   product_type;
  UINT16   product_number;
  UINT16   product_version;
} STC_PFC_AUTO_ID;

typedef struct
{
  UINT16   modbus:1;
  UINT16   hart:1;
  UINT16   profibus:1;
  UINT16   zigbee:1;
  UINT16   hart_wireless:1;
  UINT16   reserved:11;
} STC_PFC_COMMUCATION_INTERFACE;

typedef struct
{
  UINT8 sw;
  UINT32 cnt;
}STC_PFC_TIMER_CNT;

//! @brief The System variables struct
typedef struct
{
  STC_PFC_COMMUCATION_INTERFACE  communcation_setting;
  STC_PFC_SETTING_FLAG           setting_flag;
  STC_PFC_CURRENT_SETTING        current_setting;
  STC_PFC_MODBUS_SETTING         modbus_setting;
  UINT8                          firmware_version[12];        //韌體版本      //firmware_version[12]
  UINT8                          hardware_version[22];        //硬體版本      //hardware_version[22]
  UINT8                          product_serial[20];          //產品序號      //product_serial[32]
  UINT8                          product_Name[36];            //The product Name[36]   公司新版本長度
  UINT8                          product_date[12];             //生產日期
  UINT8                          sf_product_serial[14];        //半成品產品序號
  UINT8                          sf_product_date[12];         //半成品生產日期     
  UINT16                         language;  
  //===== Ver 1.0.05 =====
  UINT16                         zero_chksum;      //  the zero checksum,please always place this variable at the last one in this structure.
} STC_SYSTEM_INFO;

typedef struct
{
  UINT32                         parameter;            
  UINT16                         null;                                   
  UINT16                         zero_chksum;      //  the zero checksum,please always place this variable at the last one in this structure  
} STC_FACTORY_INFO;
//**********************************************************************************************************************
//
// D E C L A R E   G L O B E   V A R I A B L E
//
//**********************************************************************************************************************
//! @brief The System status flag
EXTERNAL STC_PFC_STATUS             	gs_pfc_status;
//! @brief The System Variables
EXTERNAL STC_SYSTEM_INFO            	gs_pfc_vars;
//! @brief The System Product Information
EXTERNAL STC_FACTORY_INFO               gs_pfc_factory;
extern STC_PFC_AUTO_ID                  gs_pfc_auto_id;
extern const UINT8                      gt_pfc_days_of_month[12];
EXTERNAL STC_PFC_TIMER_CNT              gs_pfc_timer[PFC_TOTAL_TIMER_CNT];
//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S
//
//**********************************************************************************************************************
void pfc_glb_vars_init();
void pfc_glb_vars_load_default();
void pfc_glb_vars_load_factory();
#undef EXTERNAL
#endif		// PFC_GLB_VARS_H 
