#ifndef EPH_COMM_IDEF_H
#define EPH_COMM_IDEF_H
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 eph_comm_idef.h
//
//! @author 	 Jacky Lin
//
//! @date 		 2022/07/26
//
//  @brief 		 Here define internal constant
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// E X T E R N A L   G L O B A L   C O N S T A N C E   /   V A R I A B L E S   I N   E E P R O M 
//
//**********************************************************************************************************************
enum EPH_COMM_DECRYPT_DATA
{
    EPH_COMM_DECRYPT_DATA_ADDRESS, 
    EPH_COMM_DECRYPT_DATA_FUNCTION,
    EPH_COMM_DECRYPT_DATA_START_BYTE,
};
enum EPH_COMM_FUNC
{
    EPH_COMM_FUNC_READ_METERID=0x00,
    EPH_COMM_FUNC_READ_REGISTER=0x03, 
    EPH_COMM_FUNC_WRITE_REGISTER=0x06,
};
enum EPH_COMM_ADDRESS
{
    EPH_COMM_ADDRESS_REALTIME=25101,
};
enum EPH_COMM_TRANSMITTER_STATE
{
    EPH_COMM_TRANSMITTER_STATE_WAKUP_HI,
    EPH_COMM_TRANSMITTER_STATE_WAKUP_LO,
    EPH_COMM_TRANSMITTER_STATE_SEND_CMD,
    EPH_COMM_TRANSMITTER_STATE_TOTAL,
};

enum EPH_COMM_RS485
{
    EPH_COMM_RS485_ADDRESS, 
    EPH_COMM_RS485_DEVICE_NUMBER,
    EPH_COMM_RS485_GROUP_NUMBER=4,
    EPH_COMM_RS485_STATION=6,
    EPH_COMM_RS485_FUNC=8,
};
enum EPH_COMM_METERID_REPEAT
{
    EPH_COMM_METERID_REPEAT_NO,
    EPH_COMM_METERID_REPEAT_YES,
};

#define EPH_COMM_MAX_COMMAND                                    25
#define EPH_COMM_BYTE_BITS				        8
#define EPH_COMM_WORD_BITS				        16
#define EPH_COMM_HIGH_BYTE_MASK					0xff00
#define EPH_COMM_LOW_BYTE_MASK					0xff
#define EPH_COMM_CRC_LEN				        2
#define EPH_COMM_DEVICE_NUM                                     8
#define EPH_COMM_DEVICE_DN40                                    0x40
#define EPH_COMM_DEVICE_DN40_DOT_POS                            4
#define EPH_COMM_DEVICE_NOT_DN40_DOT_POS                        5
#define EPH_COMM_ENCRYPT_BLOCK                                  7 
#define EPH_COMM_RS485_DATA_NUM                                 80
#define EPH_COMM_RS485_TAG                                      '*'
#define EPH_COMM_MODBUS_START_ADDRESS                           4096
#define EPH_COMM_DISCONNECT_ROUND                               3     


#define EPH_COMM_CHT2MODBUS_CMD                                 2123
//===== EPH水表A1029兩點校正以前的 modbus commlicatin mode addres 是 4167 , A1030整合版以後(包含七點校正)是4191
#define EPH_COMM_COMMLICATION_ADDRESS                           4191
#define EPH_COMM_DEFALUT_REPEAT                                 6
#endif		// EPH_COMM_IDEF_H 
