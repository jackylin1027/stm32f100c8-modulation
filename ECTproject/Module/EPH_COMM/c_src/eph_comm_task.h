#ifndef EPH_COMM_TASK_H
#define EPH_COMM_TASK_H
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
//! @file 		 eph_comm_task.h
//
//! @author 	 Jacky Lin
//
//! @date 		 2022/07/26
//
//  @brief 		 Here declare task function
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S 
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// M A C R O   D E F I N I T I O N 
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S 
//
//**********************************************************************************************************************
void eph_comm_task();
void eph_comm_read_register_cmd(UINT8 ptr);
void eph_comm_receive_parsing();
void eph_comm_transmitter_process();
void eph_comm_rs485_recv_parse();
void eph_comm_rs485_receiving_and_checking(UINT8 byte);
void eph_comm_timeout_isr();
void eph_comm_polls_device_judge();
//===== 新增自動分配ID的相關功能, Ver 0.0.04 =====
void eph_comm_clean_distribut_table();
void eph_comm_set_commulication(UINT8 id, UINT8 mode);
void eph_comm_read_meterid_cmd(UINT8 device_id, UINT8 function, UINT16 address, UINT16 count);
void eph_comm_distribut_parse();
void eph_comm_rearrange_meterid();
void eph_comm_set_distribution_id();
void eph_comm_delay_time(UINT32 delay);
//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N 
//
//**********************************************************************************************************************
#ifdef __cplusplus
}
#endif
#endif		// EPH_COMM_TASK_H 
