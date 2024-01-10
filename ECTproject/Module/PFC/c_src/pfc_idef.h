#ifndef PFC_IDEF_H
#define PFC_IDEF_H
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 	 pfc_idef.h
//
//! @author	 Willman Chen
//
//! @date 	 2009/06/19
//
// @brief 	 Here define internal constant
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// E X T E R N A L   G L O B A L   C O N S T A N C E   /   V A R I A B L E S   I N   E E P R O M
//
//**********************************************************************************************************************

#define PFC_IF_DATA_LENGTH					512      //test
enum
{
    PFC_ENGLISH,
    PFC_TRADICTIONAL,
    PFC_SIMPLE,
};

enum
{
    PFC_AD7172_CH1,
    PFC_AD7172_CH2,
    PFC_AD7172_CH3,
    PFC_AD7172_CH4,
    PFC_AD7172_TOTAL,
};

enum 
{
    PFC_OPERATOIN_TRAND,
    PFC_OPERATOIN_ENGINEER,
};

enum
{
    PFC_INTEGRAL_MODE_1S,
    PFC_INTEGRAL_MODE_5S,
    PFC_INTEGRAL_MODE_30S,
    PFC_INTEGRAL_MODE_60S,
    PFC_INTEGRAL_MODE_360S,
    PFC_INTEGRAL_MODE_900S,
    PFC_INTEGRAL_MODE_3600S,
};

enum 
{
    PFC_SYSTEM_WORK_NORMAL,
    PFC_SYSTEM_WORK_CALIBRATION,
    PFC_SYSTEM_WORK_EXTERN,
};

enum 
{
    PFC_SIMULATION_DISABLE, 
    PFC_SIMULATION_ENABLE,
};

enum 
{
    PFC_CURRENT_4_20MA,
    PFC_CURRENT_20_4MA,
};

enum
{
    PFC_DISPLAY_DIGITAL,
    PFC_DISPLAY_GRAPHIC,
};

enum 
{
    PFC_ALGORITHM_WAVELET,
    PFC_ALGORITHM_RAW_DATA,
};

enum 
{
    PFC_AUTOSET_STATE_IDEL,
    PFC_AUTOSET_STATE_INIT,
    PFC_AUTOSET_STATE_RECEIVING_DATA, 
    PFC_AUTOSET_STATE_CHECKING_DATA,
    PFC_AUTOSET_STATE_FAILURE,
    PFC_AUTOSET_STATE_SET_PERAMETER,
    PFC_AUTOSET_STATE_COMPLETE,
};

enum
{
    PFC_AUTOSET_PROCESS_DISABLE,
    PFC_AUTOSET_PROCESS_ENABLE,
};

enum 
{
    PFC_SYSTEM_STATUS_NORMAL, 
    PFC_SYSTEM_STATUS_ALERT, 
    PFC_SYSTEM_STATUS_ALARM, 
    PFC_SYSTEM_STATUS_AUTO_SETUP,
    PFC_SYSTEM_STATUS_FAILURE,
};

enum 
{
    PFC_DEVICE_STATES_INACTION,
    PFC_DEVICE_STATES_ACTION,
};

enum PFC_COMPENSATE_STATES
{
    PFC_COMPENSATE_STATE_NORMAL,
    PFC_COMPENSATE_STATE_OVER_THRESHOLE,
    PFC_COMPENSATE_STATE_REVERSE,
};

enum PFC_DETECTED_HARDWARES
{
    PFC_DETECTED_HARDWARE_SINGLE_END,
    PFC_DETECTED_HARDWARE_MULTIPLE_END,
};

enum PFC_COMMUNICATION_ENABLES
{
    PFC_COMMUNICATION_ENABLE_FALSE,
    PFC_COMMUNICATION_ENABLE_TRUE,
};
#define PFC_ERROR_NORMAL                                        0x00
#define PFC_ERROR_AUTOSET_FAILURE                               0x01
#define PFC_ERROR_MEASURE_FAILURE                               (PFC_ERROR_AUTOSET_FAILURE<<1)
#define PFC_ERROR_PROBE_SHORT                                   (PFC_ERROR_MEASURE_FAILURE<<1)
#define PFC_Modbus_BardRate_1200bps				1200
#define PFC_Modbus_BardRate_2400bps				2400
#define PFC_Modbus_BardRate_4800bps				4800
#define PFC_Modbus_BardRate_9600bps				9600
#define PFC_Modbus_BardRate_19200bps				19200
#define PFC_Modbus_BardRate_38400bps				38400
#define PFC_Modbus_BardRate_57600bps				57600
#define PFC_SYSTEM_SET_MODBUS_COMM_ID_LIMIT_UP					255
#define PFC_SYSTEM_SET_MODBUS_COMM_ID_LIMIT_DOWN				1

#define PFC_GET_SEC_LCM_RESET_TIMER_CNT                         gs_pfc_sec_cnt[PFC_SEC_LCM_RESET_TIMER].cnt
#define PFC_SEC_LCM_RESET_TIMER_ENABLE()                        (gs_pfc_sec_cnt[PFC_SEC_LCM_RESET_TIMER].sw=1,gs_pfc_sec_cnt[PFC_SEC_LCM_RESET_TIMER].cnt=0)
#define PFC_SEC_LCM_RESET_TIMER_DISABLE()                       (gs_pfc_sec_cnt[PFC_SEC_LCM_RESET_TIMER].sw=0,gs_pfc_sec_cnt[PFC_SEC_LCM_RESET_TIMER].cnt=0)
#define PFC_SEC_LCM_RESET_TIMER_RESET()                         (gs_pfc_sec_cnt[PFC_SEC_LCM_RESET_TIMER].cnt=0)

#define PFC_TIMER_7SEC                                          7
#define PFC_TIMER_5SEC                                          5
#define PFC_TIMER_3SEC                                          3
#define FREQ_CHK_START                                          0
#define FREQ_CHK_END                                            1
#define PFC_VALUE_COUNTS					80


#define PFC_CALIBRATION_WAIT_TIME				60              //
#define PFC_CALIBRATION_CONC_TIME				480             //
#define PFC_CALIBRATION_TREND_TIME				480             //
#define PFC_CALIBRATION_SWITCH_TIME				480             //
#define PFC_CAL_ADC_AVG                                         128             //
#define PFC_ADC_VOLTAGE_UNIT                                    0.00000059      //
#define PFC_CAL_TREND_ERR_VOLTAGE                               0.01            //
#define PFC_CAL_TREND_SELECT_VOLTAGE                            0.005           //
#define PFC_ADC_SPS_VALUE                                       100//(Hz)       //
#define PFC_WIND_SPEED_BUF_LEN                                  5208            //210730
#define PFC_ADC_MAX_COUNT                                       8388607
#define PFC_PERCENTAGE_MAGNIFICATION                            100
#define PFC_ALARM_CURRENT_MA                                    22.0
#define PFC_COMPENSATE_NUMBER_MAX                               11
#endif		// PFC_IDEF_H 
