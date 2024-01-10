//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N 
//
//**********************************************************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif
#ifndef MODBUS_MASTER_GLB_VARS_H
#define MODBUS_MASTER_GLB_VARS_H
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 modbus_master_glb_vars.h
//
//! @author 	 Jacky Lin
//
//! @date 		 2022/07/25
//
//  @brief 		 Here declare globe variable
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S 
//
//**********************************************************************************************************************
#include "modbus_master_idef.h"
#include "..\modbus_master_udef.h"    
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
//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S 
//
//**********************************************************************************************************************

#ifdef MODBUS_MASTER_ALLOC
	#define EXTERNAL
#else
	#define EXTERNAL extern
#endif
//**********************************************************************************************************************
//
// D E C L A R E   G L O B E   V A R I A B L E 
//
//**********************************************************************************************************************
EXTERNAL UINT8 	                        gb_modbus_master_buffer[MODBUS_MASTER_MAX_BUFFER_SIZE];
EXTERNAL UINT16			        gb_modbus_master_ptr;
EXTERNAL UINT8		                gb_modbus_master_state;
EXTERNAL UINT8				gb_modbus_master_char_ptr;
EXTERNAL UINT8                          gb_modbus_master_command_length;
EXTERNAL UINT8                          gb_modbus_master_polling_id;
EXTERNAL UINT8                          gb_modbus_master_polling_function;
EXTERNAL UINT8                          gb_modbus_master_error_code;
EXTERNAL UINT8                          gb_modbus_master_replay_times;
EXTERNAL UINT8                          gb_modbus_master_byte_between_timeout;            
EXTERNAL UINT8                          gb_modbus_master_replay_flag;
//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N 
//
//**********************************************************************************************************************
void modbus_master_glb_vars_init();

#undef EXTERNAL
#ifdef __cplusplus
}
#endif
#endif		// MODBUS_MASTER_GLB_VARS_H 