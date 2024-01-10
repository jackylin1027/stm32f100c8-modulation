//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N 
//
//**********************************************************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif
#ifndef EPH_COMM_GLB_VARS_H
#define EPH_COMM_GLB_VARS_H
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 eph_comm_glb_vars.h
//
//! @author 	 Jacky Lin
//
//! @date 		 2022/07/26
//
//  @brief 		 Here declare globe variable
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S 
//
//**********************************************************************************************************************
#include "eph_comm_idef.h"
#include "..\eph_comm_udef.h"    
//**********************************************************************************************************************
//
// E X T E R N A L   V A R I A B L E   A L L O C 
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// T Y P E D E F   S T R U C T   D E F I N I T I O N 
//
//********************************************************************************************************************** 
#ifdef EPH_COMM_ALLOC
	#define EXTERNAL
#else
	#define EXTERNAL extern
#endif  
  
typedef struct
{
    UINT8   device_id;
    UINT8	function_code;
    UINT8	register_value_h;
    UINT8	register_value_l;
    UINT8       set_parameter[4];
    UINT16	crc_check;    
}STC_EPH_COMM_READ_WRITE_REGISTER_CMD_PACKAGE;

typedef struct
{
    UINT8       device_id;
    UINT8	function_code;
    UINT8	register_address_h;
    UINT8	register_address_l;
    UINT8	register_value_h;
    UINT8	register_value_l;
    UINT16	crc_check;
}STC_EPH_COMM_READ_WRITE_REGISTER_PACKAGE;

typedef struct
{
    UINT8	device_address;
    UINT8	function_code;
    UINT8	byte_count;
    UINT8       data;
}STC_EPH_COMM_MODBUS_RECEIVE_PACKAGE;

#pragma pack(push) 
#pragma pack(1)
typedef struct
{
    UINT32 timestamp;
    UINT8 meter_id[8];
    UINT8 b_day;
    UINT8 l_day;
    UINT8 n_day;
    UINT8 o_day;
    UINT8 u_day;
    UINT8 h_day;
    UINT32 reverse_totalizer;
    UINT8 total_volume_count;
    UINT32 volume;
    UINT8 caliber;
    UINT16 user_count;
    UINT16 overload_count;
    UINT8 wm_power;
    UINT16 firmware_version;
    UINT32 flow_rate;
    UINT32 plus_total_flow;
}STC_EPH_COMM_RECEIVE_INFO_PACKAGE;

typedef struct
{
    UINT8 id;
    UINT8 function_code;
    UINT16 address;
    UINT8 dump;
    UINT8 word_count;
    UINT8 byte_count;
    UINT8 meter_id[16]; 
    UINT16 distribut_id;
    UINT16 crc;
}STC_EPH_COMM_DISTRIBUT_ID_CMD;

#pragma pack(pop)
typedef struct
{
    UINT32 timestamp;
    UINT8 userNumber[12];
    UINT8 meterID[12];
    UINT16 firmwareVersionBCD;
    UINT16 caliberWmpowerBCD;
    INT64 volumeBCD_dotBCD;
    INT64 flowRateBCD_dotBCD;
    INT64 plusTotalFlowBCD_dotBCD;
    INT64 minusTotalFlowBCD_dotBCD;
    UINT16 bDayBCD;
    UINT16 lDayBCD;
    UINT16 nDayBCD;
    UINT16 oDayBCD;
    UINT16 uDayBCD;
    UINT16 hDayBCD;
    UINT16 userCountBCD;
    UINT16 overloadCountBCD;
    UINT16 statusBCD;
    UINT16 lDayBCD_nDayBCD;
    UINT16 oDayBCD_uDayBCD;
    UINT16 hDayBCD_bDayBCD;
}STC_EPH_COMM_TRANSMITTER_PACKAGE;
//===== 笆だ皌 id 盡ノ, Ver0.0.01 ======
typedef struct 
{
    UINT8 previous_id;
    UINT8 distribut_id;
    UINT8 meter_id[16];
}STC_EPH_COMM_METER_ID_ARRANGEMENT;

typedef struct
{
    UINT8 StartTag;                     //"*"
    UINT8 thisCommMode[2];              //"T4" or "T5"
    UINT8 DeviceType;                   //B MOS CMTR4 EError
    UINT8 UserNumberTag;                //Wノめ腹
    UINT8 UserNumber[12];               //12 byte(计癳じ0°9 のA°F)
}STC_EPH_COMM_RS485_HEADER;    
typedef struct
{
    UINT8 MeterIDTag;                   //M秖璸竟腹
    UINT8 MeterID[12];                  //12 byte(计癳じ0°9 のA°F)
}STC_EPH_COMM_RS485_METERID;
typedef struct
{
    UINT8 VolumeExponentialTag;         //V縩衡
    UINT8 VolumeExponential[12];        //12 byte(计癳じ0°9)     
}STC_EPH_COMM_RS485_VOLUME;   

typedef struct
{
    UINT8 lDayTag;                      //L簗ぱ计
    UINT8 lDay[2];                      //2 byte(计癳计0°9)虫ぱ
    UINT8 nDayTag;                      //Nタ锣ぱ计
    UINT8 nDay[2];                      // 2 byte(计癳计0°9)虫ぱ
    UINT8 oDayTag;                      //O繰ゎぱ计
    UINT8 oDay[2];                      // 2 byte(计癳计0°9)虫ぱ
    UINT8 uDayTag;                      //Uは锣ぱ计
    UINT8 uDay[2];                      // 2 byte(计癳计0°9)虫ぱ
    UINT8 hDayTag;                      //H合ぱ计
    UINT8 hDay[2];                      // 2 byte(计癳计0°9)虫ぱ
    UINT8 bDayTag;                      //B筿ぃìぱ计
    UINT8 bDay[2];                      // 2 byte(计癳计0°9)虫ぱ
    UINT8 statusTag;                    //F篈篨夹
    UINT8 status[2];                    // 2 byteF1 F2
    UINT8 userCountTag;                 //C : 秨闽Ω计
    UINT8 userCount[4];                 // 4 byte(计癳计0°9)
}STC_EPH_COMM_RS485_EVENT;    

typedef struct
{
    UINT8 errorCodeTag;                 //E岿粇絏  
    UINT8 errorCode[1];                    //1byte
}STC_EPH_COMM_RS485_ERRORCODE;

typedef struct
{
    UINT8 reserveTag;                   //X玂痙絏(箇砞0)
    UINT8 reserve[6];                   //6 byte
    UINT8 CheckSumTag;                  //SCheck Sum
    UINT8 CheckSum[2];                  //2 byte干计, 眖’秨﹍羆…ぃCheck Sum 蛤’…
    UINT8 EndTag;                       //"…"
}STC_EPH_COMM_RS485_TAIL;

typedef struct
{
    UINT8 commID;
    UINT8 recvIndex;
}STC_EPH_COMM_DEVICE_QUENE;

//===== Ver 1.0.07 =====
typedef struct
{
    UINT32 volume;
    UINT32 flow_rate;
    UINT32 plus_total_flow;
    UINT32 reverse_totalizer;
    UINT16 dot_pos;
}STC_EPH_COMM_T_UINT32;
typedef struct
{
    FLOAT32 volume;
    FLOAT32 flow_rate;
    FLOAT32 plus_total_flow;
    FLOAT32 reverse_totalizer;
}STC_EPH_COMM_T_FLOAT32;
typedef struct
{
    FLOAT64 volume;
    FLOAT64 flow_rate;
    FLOAT64 plus_total_flow;
    FLOAT64 reverse_totalizer;
}STC_EPH_COMM_T_FLOAT64;
//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S 
//
//**********************************************************************************************************************



//**********************************************************************************************************************
//
// D E C L A R E   G L O B E   V A R I A B L E 
//
//**********************************************************************************************************************
EXTERNAL UINT8                                          gb_eph_comm_encrypt_fix_key[EPH_COMM_ENCRYPT_BLOCK];
EXTERNAL  STC_EPH_COMM_TRANSMITTER_PACKAGE              gs_eph_comm_transmitter[EPH_COMM_DEVICE_NUM];
EXTERNAL UINT8                                          gb_eph_comm_device_ptr;
EXTERNAL STC_EPH_COMM_DEVICE_QUENE                      gb_eph_comm_device_tlb[EPH_COMM_DEVICE_NUM];
//===== Ver 1.0.07 =====
EXTERNAL STC_EPH_COMM_T_UINT32                          gs_eph_comm_t_uint32[EPH_COMM_DEVICE_NUM];
EXTERNAL STC_EPH_COMM_T_FLOAT32                         gs_eph_comm_t_float32[EPH_COMM_DEVICE_NUM];
EXTERNAL STC_EPH_COMM_T_FLOAT64                         gs_eph_comm_t_float64[EPH_COMM_DEVICE_NUM];
//===== 笆だ皌 id 盡ノ, Ver0.0.01 ======
//===== Ver 0.0.05
EXTERNAL  STC_EPH_COMM_METER_ID_ARRANGEMENT             gs_eph_comm_arrangement[EPH_COMM_DEVICE_NUM];   
EXTERNAL UINT8                                          gb_eph_comm_distribution_state;
EXTERNAL UINT8                                          gb_eph_comm_transmitter_state;
EXTERNAL  STC_EPH_COMM_RS485_HEADER                     gs_eph_comm_rHeader;
EXTERNAL  STC_EPH_COMM_RS485_METERID                    gs_eph_comm_rMeterID;
EXTERNAL  STC_EPH_COMM_RS485_VOLUME                     gs_eph_comm_rVolume;
EXTERNAL  STC_EPH_COMM_RS485_EVENT                      gs_eph_comm_rEvent;
EXTERNAL  STC_EPH_COMM_RS485_ERRORCODE                  gs_eph_comm_rErrCode;
EXTERNAL  STC_EPH_COMM_RS485_TAIL                       gs_eph_comm_rTail;
EXTERNAL UINT8                                          gb_eph_comm_rs485_response[EPH_COMM_RS485_DATA_NUM];
EXTERNAL UINT8                                          gb_eph_comm_rs485_ptr;
EXTERNAL UINT8                                          gb_eph_comm_rs485_state;
EXTERNAL UINT8                                          gb_eph_comm_rs485_func;
EXTERNAL UINT8                                          gb_eph_comm_disconnect_round;
//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N 
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S 
//
//**********************************************************************************************************************
void eph_comm_glb_vars_init();

#undef EXTERNAL
#ifdef __cplusplus
}
#endif
#endif		// EPH_COMM_GLB_VARS_H 
