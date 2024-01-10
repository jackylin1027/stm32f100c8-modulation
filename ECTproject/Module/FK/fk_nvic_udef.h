#ifndef FK_NVIC_UDEF_H
#define FK_NVIC_UDEF_H
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
// E X T E R N A L   G L O B A L   C O N S T A N C E   /   V A R I A B L E S   I N   E E P R O M
//
//**********************************************************************************************************************

//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "..\Inc\main.h"
#include "c_src\fk_idef.h"
#include "c_src\fk_init.h"
#include "c_src\fk_task.h"
#include "c_src\fk_glb_vars.h" 
//**********************************************************************************************************************
//
// C O N D I C T I O N   C O M P I L E
//
//**********************************************************************************************************************

//**********************************************************************************************************************
//
// A P I   F O R   O T H E R   M O D U L E S
//
//**********************************************************************************************************************

// NVIC
#define FK_INTERRUPT_DISABLE_API(channel)                                             fk_nvic_disable(channel)
/*
     The table below gives the allowed values of the pre-emption priority and subpriority according
     to the Priority Grouping configuration performed by NVIC_PriorityGroupConfig function
      ============================================================================================================================
        NVIC_PriorityGroup   | NVIC_IRQChannelPreemptionPriority | NVIC_IRQChannelSubPriority  | Description
      ============================================================================================================================
       NVIC_PriorityGroup_0  |                0                  |            0-15             |   0 bits for pre-emption priority
                             |                                   |                             |   4 bits for subpriority
      ----------------------------------------------------------------------------------------------------------------------------
       NVIC_PriorityGroup_1  |                0-1                |            0-7              |   1 bits for pre-emption priority
                             |                                   |                             |   3 bits for subpriority
      ----------------------------------------------------------------------------------------------------------------------------
       NVIC_PriorityGroup_2  |                0-3                |            0-3              |   2 bits for pre-emption priority
                             |                                   |                             |   2 bits for subpriority
      ----------------------------------------------------------------------------------------------------------------------------
       NVIC_PriorityGroup_3  |                0-7                |            0-1              |   3 bits for pre-emption priority
                             |                                   |                             |   1 bits for subpriority
      ----------------------------------------------------------------------------------------------------------------------------
       NVIC_PriorityGroup_4  |                0-15               |            0                |   4 bits for pre-emption priority
                             |                                   |                             |   0 bits for subpriority
      ============================================================================================================================
*/
#define FK_SET_PRIORITY_GROUP_0_API()                                                 NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0)
#define FK_SET_PRIORITY_GROUP_1_API()                                                 NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1)
#define FK_SET_PRIORITY_GROUP_2_API()                                                 NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2)
#define FK_SET_PRIORITY_GROUP_3_API()                                                 NVIC_PriorityGroupConfig(NVIC_PriorityGroup_3)
#define FK_SET_PRIORITY_GROUP_4_API()                                                 NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4)

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
#endif		// FK_NVIC_UDEF_H 
