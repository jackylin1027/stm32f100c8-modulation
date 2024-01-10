#ifndef MODBUS_MASTER_UDEF_H
#define MODBUS_MASTER_UDEF_H
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
//! @file 		 modbus_master_udef.h
//
//! @author 	 Jacky Lin
//
//! @date 		 2022/07/25
//
//  @brief 		 Here define all API
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// E X T E R N A L   G L O B A L   C O N S T A N C E   /   V A R I A B L E S   I N   E E P R O M 
//
//**********************************************************************************************************************
#define MODBUS_MASTER_ID						         PFC_MODBUS_MASTER_ID
#define MODBUS_MASTER_BAUDRATE                                                   PFC_MODBUS_MASTER_BAUDRATE
#define MODBUS_MASTER_BITS                                                       PFC_MODBUS_MASTER_BTIS
#define MODBUS_MASTER_PARITY                                                     PFC_MODBUS_MASTER_PARITY
#define MODBUS_MASTER_MODE                                                       PFC_MODBUS_MASTER_MODE  
#define MODBUS_MASTER_RTU_MODE							 FK_MODBUS_RTU_MODE  
//**********************************************************************************************************************
//
// C O N D I C T I O N   C O M P I L E 
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S 
//
//**********************************************************************************************************************
#include "..\fk\fk_udef.h"
#include "..\crc\crc_udef.h"
#include "..\hbtc\hbtc_udef.h"
#include "..\pfc\pfc_udef.h"
#include "..\Inc\main.h"    
#include "c_src/modbus_master_init.h"
#include "c_src\modbus_master_glb_vars.h"
#include "c_src\modbus_master_task.h"
//**********************************************************************************************************************
//
// A P I   F O R   O T H E R   M O D U L E S 
//
//**********************************************************************************************************************
#define	MODBUS_MASTER_INIT_API()			                modbus_master_init()
#define MODBUS_MASTER_REGISTER_COMMAND(cmd,len)                         modbus_master_register_command(cmd,len)
#define MODBUS_MASTER_SET_STATE(state)                                  gb_modbus_master_state=state
#define MODBUS_MASTER_CHK_STATE()                                       gb_modbus_master_state
#define MODBUS_MASTER_BUFFER                                            gb_modbus_master_buffer
#define MODBUS_MASTER_PTR                                               gb_modbus_master_ptr
//**********************************************************************************************************************
//
// A P I   C A L L   F R O M   O T H E R   M O D U L E S 
//
//**********************************************************************************************************************
//! @brief The API for setting waitting for reading in
#define MODBUS_MASTER_SET_READ_IN_API()			                FK_SET_OUTPUT_PIN_LOW_API(FK_PORTA,FK_PIN11)   
//! @brief The API for reset timeout timer
#define MODBUS_MASTER_RESPONSE_TIMER_API()			        HBTC_SET_TIMER_API(HBTC_MODBUS_MASTER_RESPONSE_TIMER,PFC_MODBUS_MASTER_RESPONSE_TIME,modbus_master_response_timeout)  
//! @brief The API for reset timeout timer in between sending and receive 
#define MODBUS_MASTER_BYTE_BETWEEN_TIMER_API();                         HBTC_SET_TIMER_API(HBTC_MODBUS_MASTER_BYTE_BETWEEN_TIMER,gb_modbus_master_byte_between_timeout,modbus_master_byte_between_timeout)  
//! @brief The API for initial UART function
#define MODBUS_MASTER_UART_INIT_API(baudrate,bits,stop_bits,parity)     FK_UART1_INTERRUPT_API(baudrate,bits,stop_bits,parity,modbus_master_sending,modbus_master_receiving_and_checking)
//! @brief The API for starting UART transfer interrupt
#define MODBUS_MASTER_START_TX_API()                                    FK_UART1_TX_INTERRUPT_ENABLE_API()  
//! @brief The API for sending out data
#define MODBUS_MASTER_SEND_OUT_API(data)			        FK_UART1_SEND_BYTE_API(data) 
//! @brief The API for receiving data
#define MODBUS_MASTER_RECEIVE_API()				        FK_UART1_GET_DATA_API()   
//! @brief The API for setting write out
#define MODBUS_MASTER_SET_WRITE_OUT_API()		                FK_SET_OUTPUT_PIN_HIGH_API(FK_PORTA,FK_PIN11)    
//! @brief The API for computing CRC code
#define MODBUS_MASTER_CRC_CODE_API(data,len)		                CRC_GENERATE_API(data,len)    
//! @brief The API for set replay connection interval, In the case interval set 3000ms
#define MODBUS_MASTER_REPLAY_TIMEOUT();                                 HBTC_SET_TIMER_API(HBTC_MODBUS_MASTER_REPLAY_TIMER,1000,modbus_master_replay_timeout)  
//! @brief THe API for starting UART receive interrupt
#define MODBUS_MASTER_START_RX_API()                                    FK_UART1_RX_INTERRUPT_ENABLE_API(gb_modbus_master_buffer)  
//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S 
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N 
//
//**********************************************************************************************************************
#ifdef __cplusplus
}
#endif
#endif		// MODBUS_MASTER_UDEF_H 
