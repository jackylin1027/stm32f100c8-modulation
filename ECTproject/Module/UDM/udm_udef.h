#ifndef UDM_UDEF_H
#define UDM_UDEF_H
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 udm_udef.h
//
//! @author 	 Willman Chen
//
//! @date 		 2009/07/14
//
//  @brief 		 Here define all API
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// E X T E R N A L   G L O B A L   C O N S T A N C E   /   V A R I A B L E S   I N   E E P R O M
//
//**********************************************************************************************************************
enum UDM_FONT
{
    UDM_ASC5X7,
    UDM_ASC7X9,
    UDM_ALL_FONT,
    UDM_ASCII_START=0x20,
};

//**********************************************************************************************************************
//
// C O N D I C T I O N   C O M P I L E
//
//**********************************************************************************************************************
#define	UDM_USE_5X7_FONT							1
#define	UDM_USE_7X9_FONT							1
#define	UDM_USE_ROM_PROMPT							1
#define	UDM_USE_SYMB								1
#define UDM_USE_TRADITIONAL_CHINESE						1
#define UDM_USE_SIMPLE_CHINESE	                                                1
enum UDM_LANGUAGE_LIST
{
    UDM_ENGLISH,
    UDM_TRADICTIONAL,
    UDM_SIMPLE,
};
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "..\fk\fk_udef.h"
#include "..\pfc\pfc_udef.h"
#include "c_src\udm_init.h"
#include "c_src\udm_glb_vars.h"
#include "c_src\udm_symb.h"
#include "c_src\udm_prompt.h"
#include "c_src\udm_task.h"
//**********************************************************************************************************************
//
// E X T E R N A L   G L O B A L   C O N S T A N C E   /   V A R I A B L E S   I N   E E P R O M
//
//**********************************************************************************************************************
enum UDM_LANGUAGE
{
    UDM_ENGLISH_LANGUAGE = UDM_PROMPT_START,
    UDM_TRADICTIONAL_LANGUAGE =UDM_TC001_SYMB,
    UDM_SIMPLE_LANGUAGE=UDM_PATTERN_END_SYMB,
};
//**********************************************************************************************************************
//
// A P I   F O R   O T H E R   M O D U L E S
//
//**********************************************************************************************************************
#define	UDM_INIT_API()								udm_init()
#define UDM_GET_FONT_TABLE(font_type)						((FONT_INFO *)udm_font[font_type])
#define UDM_GET_FONT_W_API(font)						(((FONT_INFO *)udm_font[font])->font_w)
#define UDM_GET_FONT_H_API(font)						(((FONT_INFO *)udm_font[font])->font_h)
#define UDM_GET_PROMPT_LEN_API(i)						udm_get_prompt_len(i,PFC_LANGUAGE)
#define UDM_GET_PROMPT_STR_API(i)						udm_prompt_string(i,PFC_LANGUAGE)
#define UDM_GET_SYMB_W_API(symb)						udm_get_symb_w(symb)
#define UDM_GET_SYMB_H_API(symb)						udm_get_symb_h(symb)
#define UDM_GET_BIG_NUM_API(num)                                                udm_big_num_table[num]
#define UDM_TASK_API()								udm_task()
//**********************************************************************************************************************
//
// A P I   C A L L   F R O M   O T H E R   M O D U L E S
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S
//
//**********************************************************************************************************************
#endif		// UDM_UDEF_H 
