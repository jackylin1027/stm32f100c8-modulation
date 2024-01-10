#ifndef MODBUS_MASTER_IDEF_H
#define MODBUS_MASTER_IDEF_H
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 modbus_master_idef.h
//
//! @author 	 Jacky Lin
//
//! @date 		 2022/07/25
//
//  @brief 		 Here define internal constant
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// E X T E R N A L   G L O B A L   C O N S T A N C E   /   V A R I A B L E S   I N   E E P R O M 
//
//**********************************************************************************************************************
enum MODBUS_MASTER_STATE
{
    MODBUS_MASTER_STATE_IDEL,
    MODBUS_MASTER_STATE_SENDING,
    MODBUS_MASTER_STATE_RECV_WAITING,
    MODBUS_MASTER_STATE_RECIVING_AND_CHECKING,
    MODBUS_MASTER_STATE_PARSING,
    MODBUS_MASTER_STATE_REPLAY,
    MODBUS_MASTER_STATE_BACK_TO_STOP,
};
enum MODBUS_MASTER_BYTE_NAME
{
    MODBUS_MASTER_BYTE_NAME_ADDRESS,
    MODBUS_MASTER_BYTE_NAME_FUNCTION_BYTE,
};

enum MODBUS_MASTER_REPLAY_FLAG
{
    MODBUS_MASTER_REPLAY_FLAG_DISABLE,
    MODBUS_MASTER_REPLAY_FLAG_ENABLE,
};

enum MODBUS_MASTER_ERROR
{
    MODBUS_MASTER_ERROR_NORMAL,
    MODBUS_MASTER_ERROR_STATE_INCORRECT, 
    MODBUS_MASTER_ERROR_FUNCTION,
    MODBUS_MASTER_ERROR_NAME_ADDRESS,
    MODBUS_MASTER_ERROR_RESPONSE_TIMEOUT,
    MODBUS_MASTER_ERROR_SENDING_TIMEOUT,
    MODBUS_MASTER_ERROR_CRC_FAIL,
};
#define MODBUS_MASTER_MAX_BUFFER_SIZE                                   128
#define MODBUS_MASTER_CRC_LEN						2
#define MODBUS_MASTER_BYTE_BITS						8
#define MODBUS_MASTER_HIGH_BYTE_MASK					0xff00
#define MODBUS_MASTER_LOW_BYTE_MASK					0xff
#define MODBUS_MASTER_CRC_HI_BYTE_POS					1
#define MODBUS_MASTER_CRC_LOW_BYTE_POS					2
#endif		// MODBUS_MASTER_IDEF_H 
