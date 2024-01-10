#ifndef KEY_DRV_H
#define KEY_DRV_H
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 	 key_drv.h
//
//! @author 	 Willman Chen
//
//! @date 	 2009/06/23
//
//  @brief 	 Here declare driver function
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "..\key_udef.h"
//**********************************************************************************************************************
//
// I / O   P O R T   D E F I N I T I O N
//
//**********************************************************************************************************************
//! @brief the input port state register
#define KEY_COM1_PORT		      FK_PORTC
#define KEY_COM1_PIN                  FK_PIN0
#define KEY_COM1_HIGH()               FK_SET_OUTPUT_PIN_HIGH_API(KEY_COM1_PORT,KEY_COM1_PIN)
#define KEY_COM1_LOW()                FK_SET_OUTPUT_PIN_LOW_API(KEY_COM1_PORT,KEY_COM1_PIN)
#define KEY_COM1_INIT()               FK_SET_PIN_OUPUT_PUSH_PUMP_API(KEY_COM1_PORT,KEY_COM1_PIN);KEY_COM1_HIGH()
#define KEY_COM2_PORT                 FK_PORTC
#define KEY_COM2_PIN                  FK_PIN1
#define KEY_COM2_HIGH()               FK_SET_OUTPUT_PIN_HIGH_API(KEY_COM2_PORT,KEY_COM2_PIN)
#define KEY_COM2_LOW()                FK_SET_OUTPUT_PIN_LOW_API(KEY_COM2_PORT,KEY_COM2_PIN)
#define KEY_COM2_INIT()               FK_SET_PIN_OUPUT_PUSH_PUMP_API(KEY_COM2_PORT,KEY_COM2_PIN);KEY_COM2_HIGH()
#define KEY_KEY1_PORT                 FK_PORTB
#define KEY_KEY1_PIN                  FK_PIN4
#define KEY_KEY1_INIT()               FK_SET_PIN_INPUT_PULL_HIGH_API(KEY_KEY1_PORT,KEY_KEY1_PIN)
#define KEY_KEY1_CHK()                FK_CHK_PIN_STATE_API(KEY_KEY1_PORT,KEY_KEY1_PIN)
#define KEY_KEY2_PORT                 FK_PORTA
#define KEY_KEY2_PIN                  FK_PIN15
#define KEY_KEY2_INIT()               FK_SET_PIN_INPUT_PULL_HIGH_API(KEY_KEY2_PORT,KEY_KEY2_PIN)
#define KEY_KEY2_CHK()                FK_CHK_PIN_STATE_API(KEY_KEY2_PORT,KEY_KEY2_PIN)
#define KEY_KEY3_PORT                 FK_PORTB
#define KEY_KEY3_PIN                  FK_PIN3
#define KEY_KEY3_INIT()               FK_SET_PIN_INPUT_PULL_HIGH_API(KEY_KEY3_PORT,KEY_KEY3_PIN)
#define KEY_KEY3_CHK()                FK_CHK_PIN_STATE_API(KEY_KEY3_PORT,KEY_KEY3_PIN)
//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S
//
//**********************************************************************************************************************
void key_sfr_init();
#endif		// KEY_DRV_H 
