#ifndef UDM_PROMPT_H
#define UDM_PROMPT_H
enum
{
  BASIC_MENU_PROMPT=UDM_ICON_ARRAY_SIZE,
  MIN_DISPLAY_VALUE_PROMPT,
  MAX_DISPLAY_VALUE_PROMPT,
  LOW_POINT_ADJUSTMENT_PROMPT,
  HIGH_POINT_ADJUSTMENT_PROMPT,
  DETAIL_MENU_PROMPT,
  DISPLAY_CONTEXT_PROMPT,
  PERCENTAGE_PROMPT,
  CURRENT_VALUE_PROMPT,
  DISTANCE_PROMPT,
  M_PROMPT,
  CM_PROMPT,
  MM_PROMPT,
  INCH_PROMPT,
  FEET_PROMPT,
  LANGUAGE_PROMPT,
  ENGLISH_PROMPT,
  TRADITIONAL_CHINESE_PROMPT,
  SIMPLE_CHINESE_PROMPT,
  CURRENT_SETUP_PROMPT,
  MAX_CURRENT_PROMPT,
  MIN_CURRENT_PROMPT,
  ERROR_CURRENT_PROMPT,
  MA_PROMPT,
  FILTER_PROMPT,
  HIGH_LEVEL_PROMPT,
  MID_LEVEL_PROMPT,
  LOW_LEVEL_PROMPT,
  RESPONSE_TIME_PROMPT,
  SECOND_PROMPT,
  HART_ID_PROMPT,
  RESET_DEVICE_PROMPT,
  DEVICE_ADDRESS_PROMPT,
  DIAGNOSIS_PROMPT,
  PEEK_PROMPT,
  MIN_VALUE_PROMPT,
  MAX_VALUE_PROMPT,
  SENSOR_STATUS_PROMPT,
  OSC_FAIL_PROMPT,
  OVER_RANGE_PROMPT,
  INFO_MENU_PROMPT,
  MANUFACTURE_PROMPT,
  SENSOR_PROMPT,
  SERIAL_PROMPT,
  DATE_PROMPT,
  VERSION_PROMPT,
  COMPANY_PROMPT,
  UDM_OPERATION_PROMPT_END=COMPANY_PROMPT,  
};

#define UDM_PROMPT_START			UDM_ICON_ARRAY_SIZE
#define	UDM_OPERATION_PROMPT			(UDM_OPERATION_PROMPT_END+1-UDM_PROMPT_START)
#endif // END UDM_PROMPT_H

