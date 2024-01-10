#ifndef EPH_COMM_UDEF_H
#define EPH_COMM_UDEF_H
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
//! @file 		 eph_comm_udef.h
//
//! @author 	 Jacky Lin
//
//! @date 		 2022/07/26
//
//  @brief 		 Here define all API
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// E X T E R N A L   G L O B A L   C O N S T A N C E   /   V A R I A B L E S   I N   E E P R O M 
//
//**********************************************************************************************************************
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
#include "c_src/eph_comm_init.h"
#include "c_src\eph_comm_glb_vars.h"
#include "c_src\eph_comm_task.h"
enum EPH_COMM_RS485STA
{
    EPH_COMM_RS485STA_IDEL,
    EPH_COMM_RS485STA_IDENT,
    EPH_COMM_RS485STA_IDENT1,
    EPH_COMM_RS485STA_IDENT2,
    EPH_COMM_RS485STA_GROUP,
    EPH_COMM_RS485STA_GROUP1,
    EPH_COMM_RS485STA_STATION,
    EPH_COMM_RS485STA_STATION1,
    EPH_COMM_RS485STA_FUNC,
    EPH_COMM_RS485STA_FUNCREAD,
    EPH_COMM_RS485STA_FUNCMONITOR,
    EPH_COMM_RS485STA_FUNC_OK,
};  

enum 
{
    EPH_COMM_DISTRIBUTION_STATE_STOP,  
    EPH_COMM_DISTRIBUTION_STATE_IDEL,
    EPH_COMM_DISTRIBUTION_STATE_START,
};
//**********************************************************************************************************************
//
// A P I   F O R   O T H E R   M O D U L E S 
//
//**********************************************************************************************************************
#define	EPH_COMM_INIT_API()			        eph_comm_init()
//! @brief The API for call modbus master send data use EPH command
#define EPH_COMM_READ_REGISTER_API()                    eph_comm_read_register_cmd()
//! @brief The API for parsing information by receive data
#define EPH_COMM_RECEIVE_PARSING_API()                  eph_comm_receive_parsing()

#define EPH_COMM_CLR_DISTRIBUT_TABLE_API()              eph_comm_clean_distribut_table()

#define EPH_COMM_SET_COMMLICATION_API(id,mode)          eph_comm_set_commulication(id,mode)   

#define EPH_COMM_SET_DISTRIBUTION_STATE(state)          gb_eph_comm_distribution_state=state
#define EPH_COMM_CHK_DISTRIBUTION_STATE()               gb_eph_comm_distribution_state

#define EPH_COMM_READ_METERID_API(id)                   eph_comm_read_meterid_cmd(id,EPH_COMM_FUNC_READ_METERID,EPH_COMM_MODBUS_START_ADDRESS,10)
#define EPH_COMM_SET_DISTRIBUT_ID_API()                 eph_comm_set_distribution_id()
//**********************************************************************************************************************
//
// A P I   C A L L   F R O M   O T H E R   M O D U L E S 
//
//**********************************************************************************************************************
//! @brief The API for computing CRC code
#define EPH_COMM_CRC_CODE_API(data,len)		        CRC_GENERATE_API(data,len)    
//! @brief The API for register command for modbus(CHT type)   
#define EPH_COMM_REGISTER_COMMAND(cmd,len)              MODBUS_MASTER_REGISTER_COMMAND(cmd,len)
  //! @brief The Buffer mapping MODBUS_MASTER_BUFFER
#define EPH_COMM_BUFFER                                 MODBUS_MASTER_BUFFER
  //! @brief The Receive count mapping MODBUS_MASTER_PTR
#define EPH_COMM_REVC_COUNT                             MODBUS_MASTER_PTR
  //! @brief The API for get polling device setting 
#define EPH_COMM_GET_MAX_DEVICE_NUM()                   PFC_MODBUS_MASTER_MAX_DEVICE_NUM 
  //! @brief The API for transmitter process timeout 
#define EPH_COMM_TRANSMITTER_PROCESS_TIMEOUT(ms)        HBTC_SET_TIMER_API(HBTC_EPH_COMM_WAKEUP_TIMER,ms,eph_comm_transmitter_process) 
  //! @brief The Scan Rate Flag mapping gb_pfc_scanrate_flag
#define EPH_COMM_SET_SCANRATE_FLAG(flag)                gb_pfc_scanrate_flag=flag
//! @brief The API for reset timeout timer
#define EPH_COMM_RS485_RESET_TIMEOUT_TIMER_API(ms)	HBTC_SET_TIMER_API(HBTC_EPH_COMM_TIMER,ms,eph_comm_timeout_isr)  
//! @brief The API for setting write out  
#define EPH_COMM_SLAVE_SET_WRITE_OUT_API()              FK_SET_OUTPUT_PIN_HIGH_API(FK_PORTA,FK_PIN1) 
//! @brief The API for setting waitting for reading in  
#define EPH_COMM_SLAVE_SET_READ_IN_API()		FK_SET_OUTPUT_PIN_LOW_API(FK_PORTA,FK_PIN1)   
//! @brief The API for sending out data
#define EPH_COMM_SLAVE_SEND_OUT_API(data)               FK_UART2_SEND_BYTE_API(data);FK_UART2_TX_WAIT_API() 
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
#endif		// EPH_COMM_UDEF_H 
