#ifndef PFC_DRV_H
#define PFC_DRV_H
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 	 pfc_drv.h
//
//! @author	 Willman Chen
//
//! @date 	 2009/06/19
//
// @brief 	 Here declare driver function
//
//**********************************************************************************************************************
//=================== Definntion below for input gpio is detectable of hareware version  
#define PFC_DETECT_HARDWARE_VER_PORT            FK_PORTB
#define PFC_DETECT_HARDWARE_VER_PIN             FK_PIN7
//#define PFC_DETECT_HARDWARE_VER_INIT()          FK_SET_PIN_INPUT_NOPULL_API(KEY_KEY1_PORT,KEY_KEY1_PIN)
#define PFC_DETECT_HARDWARE_VER_CHK()           FK_CHK_PIN_STATE_API(PFC_DETECT_HARDWARE_VER_PORT,PFC_DETECT_HARDWARE_VER_PIN)
//=================== Definntion below for ADG1607 selectable pin 
#define PFC_ADG1607_A0_PORT                     FK_PORTA
#define PFC_ADG1607_A0_PIN                      FK_PIN4
#define PFC_ADG1607_A0_HIGH()                   FK_SET_OUTPUT_PIN_HIGH_API(PFC_ADG1607_A0_PORT,PFC_ADG1607_A0_PIN)
#define PFC_ADG1607_A0_LOW()                    FK_SET_OUTPUT_PIN_LOW_API(PFC_ADG1607_A0_PORT,PFC_ADG1607_A0_PIN)
#define PFC_ADG1607_A1_PORT                     FK_PORTA
#define PFC_ADG1607_A1_PIN                      FK_PIN5
#define PFC_ADG1607_A1_HIGH()                   FK_SET_OUTPUT_PIN_HIGH_API(PFC_ADG1607_A1_PORT,PFC_ADG1607_A1_PIN)
#define PFC_ADG1607_A1_LOW()                    FK_SET_OUTPUT_PIN_LOW_API(PFC_ADG1607_A1_PORT,PFC_ADG1607_A1_PIN)
#define PFC_ADG1607_A2_PORT                     FK_PORTA
#define PFC_ADG1607_A2_PIN                      FK_PIN6
#define PFC_ADG1607_A2_HIGH()                   FK_SET_OUTPUT_PIN_HIGH_API(PFC_ADG1607_A2_PORT,PFC_ADG1607_A2_PIN)
#define PFC_ADG1607_A2_LOW()                    FK_SET_OUTPUT_PIN_LOW_API(PFC_ADG1607_A2_PORT,PFC_ADG1607_A2_PIN)
#define PFC_ADG1607_EN_PORT                     FK_PORTA
#define PFC_ADG1607_EN_PIN                      FK_PIN7
#define PFC_ADG1607_EN_HIGH()                   FK_SET_OUTPUT_PIN_HIGH_API(PFC_ADG1607_EN_PORT,PFC_ADG1607_EN_PIN)
#define PFC_ADG1607_EN_LOW()                    FK_SET_OUTPUT_PIN_LOW_API(PFC_ADG1607_EN_PORT,PFC_ADG1607_EN_PIN)
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S
//
//**********************************************************************************************************************
void pfc_sfr_init();
#endif		// PFC_DRV_H 
