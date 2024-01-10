//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 modbus_slave_drv.c
//
//! @author 	 Willman Chen
//
//! @date 		 2009/11/10
//
//  @brief 		 Driver Subroutine
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "modbus_slave_drv.h"
#include "..\modbus_slave_udef.h"
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 modbus_sfr_init
//
//! @author 	 Willman Chen
//
//! @date 		 2009/10/26
//
//! @brief 		 Register initial function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void modbus_slave_sfr_init()
{
    MODBUS_SLAVE_SET_READ_IN_API();
    MODBUS_UART_INIT_API(PFC_MODBUS_BAUDRATE,PFC_MODBUS_BTIS,PFC_MODBUS_STOP_BITS,PFC_MODBUS_PARITY);
    MODBUS_SLAVE_START_RX_API();   
}

