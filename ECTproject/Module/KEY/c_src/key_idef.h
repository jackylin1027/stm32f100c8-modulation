#ifndef KEY_IDEF_H
#define KEY_IDEF_H
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 	 key_idef.h
//
//! @author 	 Willman Chen
//
//! @date 	 2009/06/23
//
//  @brief 	 Here define internal constant
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// E X T E R N A L   G L O B A L   C O N S T A N C E   /   V A R I A B L E S   I N   E E P R O M
//
//**********************************************************************************************************************
//! @brief define the timing of a pressed event.
#define   KEY_PRESSED_TIME           80        // This value can't over KEY_MAX_BUF_TIME,take care time unit.
//! @brief define the timing of a repeat event
#define   KEY_REPEAT_START_TIME      16       // This value can't over KEY_MAX_BUF_TIME,take care time unit.
//! @brief after expire the timming of a repeat event,how many times will touch repeat event again.
#define   KEY_REPEAT_INTERVAL        1        // This value can't over KEY_REPEAT_START_TIME       
//! @brief the max value of the timing unit,usually we don't need to change it.
#define   KEY_MAX_BUF_TIME           127      // Take care timer data type.
#endif		// KEY_IDEF_H 
