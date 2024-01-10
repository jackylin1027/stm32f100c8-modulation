//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 eph_comm_glb_vars.c
//
//! @author 	 Jacky Lin
//
//! @date 		 2022/07/26
//
//  @brief 		 Init globe variable
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S 
//
//**********************************************************************************************************************
#define EPH_COMM_ALLOC
#include "eph_comm_glb_vars.h"
#undef EPH_COMM_ALLOC
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
//! @fn 			 eph_comm_glb_vars_init
//
//! @author 	 Jacky Lin
//
//! @date 		 2022/07/26
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void eph_comm_glb_vars_init()
{
    gb_eph_comm_device_ptr=0;
    gb_eph_comm_transmitter_state=EPH_COMM_TRANSMITTER_STATE_WAKUP_HI;
    //===== gb_eph_comm_device_tlb 宣告使用自身FRAM需 disable write protect, Ver 0.0.08 =====
    //===== Ver 1.0.05 =====
    for(UINT8 i = 0; i < EPH_COMM_DEVICE_NUM; i++)
    {
        gb_eph_comm_device_tlb[i].commID=1;
        gb_eph_comm_device_tlb[i].recvIndex=i+1;
    }
    
    gb_eph_comm_rs485_state=EPH_COMM_RS485STA_IDEL;
    gb_eph_comm_rs485_ptr=0;
}
//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N 
//
//**********************************************************************************************************************
#ifdef __cplusplus
}
#endif

