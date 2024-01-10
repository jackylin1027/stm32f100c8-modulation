//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 modbus_master_drv.c
//
//! @author 	 Jacky Lin
//
//! @date 		 2022/07/25
//
//  @brief 		 Driver Subroutine
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S 
//
//**********************************************************************************************************************
#include "modbus_master_drv.h"
#include "..\modbus_master_udef.h"
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
//! @fn 			 modbus_master_sfr_init
//
//! @author 	 Jacky Lin
//
//! @date 		 2022/07/25
//
//! @brief 		 Register initial function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void modbus_master_sfr_init()
{
    //===== Ver 0.0.02 =====
    switch(PFC_MODBUS_MASTER_BAUDRATE)
    {   
        case 9600: 
            gb_modbus_master_byte_between_timeout=5;
            break;
        case 19200: 
        case 38400: 
        case 57600: 
            gb_modbus_master_byte_between_timeout=2;
            break;            
    }
    
    MODBUS_MASTER_DIRECTION_INIT();
    MODBUS_MASTER_SET_WRITE_OUT_API();
    MODBUS_MASTER_UART_INIT_API(MODBUS_MASTER_BAUDRATE,MODBUS_MASTER_BITS,PFC_MODBUS_STOP_BITS,MODBUS_MASTER_PARITY);
    MODBUS_MASTER_START_RX_API();
}
//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N 
//
//**********************************************************************************************************************
#ifdef __cplusplus
}
#endif

