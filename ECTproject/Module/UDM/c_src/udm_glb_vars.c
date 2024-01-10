//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 udm_glb_vars.c
//
//! @author 	 Willman Chen
//
//! @date 		 2009/07/14
//
//  @brief 		 Init globe variable
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#define UDM_ALLOC
#include "udm_glb_vars.h"
#undef UDM_ALLOC
#include "..\udm_udef.h"

#if UDM_USE_5X7_FONT == 1
#include "udm_font_5x7.h"
const FONT_INFO font5x7= {(UINT8 *)&udm_font_5x7,5,8};
#endif
#if UDM_USE_7X9_FONT == 1
#include "udm_font_7x9.h"
const FONT_INFO font7x9= {(UINT8 *)&udm_font_7x9,7,10};
#endif

const FONT_INFO * const udm_font[UDM_ALL_FONT]=
{
#if UDM_USE_5X7_FONT == 1
    (const FONT_INFO *)&font5x7,			/* SMALL_FONT	*/
#endif
#if UDM_USE_7X9_FONT == 1
    (const FONT_INFO *)&font7x9,			/*	BIG_FONT		*/
#endif
};

const UINT32 udm_big_num_table[]=
{
    UDM_BIG_0_SYMB,
    UDM_BIG_1_SYMB,
    UDM_BIG_2_SYMB,
    UDM_BIG_3_SYMB,
    UDM_BIG_4_SYMB,
    UDM_BIG_5_SYMB,
    UDM_BIG_6_SYMB,
    UDM_BIG_7_SYMB,
    UDM_BIG_8_SYMB,
    UDM_BIG_9_SYMB,
    UDM_BIG_DOT_SYMB,
};

#if UDM_USE_ROM_PROMPT == 1
const UINT8 gs_udm_rom_prompt[]=
{
// There're 47 prompts
	0x5E,0x00,0x6F,0x00,0x81,0x00,0x93,0x00,0xA7,0x00,0xBB,0x00,0xCD,0x00,0xD5,0x00,
	0xE0,0x00,0xE8,0x00,0xF1,0x00,0xF3,0x00,0xF6,0x00,0xF9,0x00,0xFE,0x00,0x01,0x01,
	0x0A,0x01,0x12,0x01,0x1E,0x01,0x25,0x01,0x34,0x01,0x3D,0x01,0x46,0x01,0x4F,0x01,
	0x52,0x01,0x59,0x01,0x65,0x01,0x73,0x01,0x7E,0x01,0x8C,0x01,0x90,0x01,0x98,0x01,
	0xA5,0x01,0xB4,0x01,0xC3,0x01,0xCE,0x01,0xD8,0x01,0xE2,0x01,0xF0,0x01,0xF9,0x01,
	0x04,0x02,0x15,0x02,0x22,0x02,0x2D,0x02,0x3B,0x02,0x4A,0x02,0x55,0x02,
	'B','A','S','I','C',' ','S','E','T','U','P',' ','M','E','N','U',0x00,
	'M','I','N',' ','D','I','S','P','L','A','Y',' ','V','A','L','U','E',0x00,
	'M','A','X',' ','D','I','S','P','L','A','Y',' ','V','A','L','U','E',0x00,
	'M','I','N',' ','C','A','L','I','B','R','A','T','E',' ','V','A','L','U','E',0x00,
	'M','A','X',' ','C','A','L','I','B','R','A','T','E',' ','V','A','L','U','E',0x00,
	'D','E','T','A','I','L',' ','S','E','T','U','P',' ','M','E','N','U',0x00,
	'D','I','S','P','L','A','Y',0x00,
	'P','E','R','C','E','N','T','A','G','E',0x00,
	'C','U','R','R','E','N','T',0x00,
	'D','I','S','T','A','N','C','E',0x00,
	'M',0x00,
	'C','M',0x00,
	'M','M',0x00,
	'I','N','C','H',0x00,
	'F','T',0x00,
	'L','A','N','G','U','A','G','E',0x00,
	'E','N','G','L','I','S','H',0x00,
	'T','R','A','D','I','T','I','O','N','A','L',0x00,
	'S','I','M','P','L','E',0x00,
	'C','U','R','R','E','N','T',' ','O','U','T','P','U','T',0x00,
	'M','A','X','I','M','U','S',':',0x00,
	'M','I','N','I','M','U','S',':',0x00,
	'E','R','R','O','R',' ',' ',':',0x00,
	'M','A',0x00,
	'F','I','L','T','E','R',0x00,
	'H','I','G','H',' ','F','I','L','T','E','R',0x00,
	'M','I','D','D','L','E',' ','F','I','L','T','E','R',0x00,
	'L','O','W',' ','F','I','L','T','E','R',0x00,
	'R','E','S','P','O','N','S','E',' ','T','I','M','E',0x00,
	'S','E','C',0x00,
	'H','A','R','T',' ','I','D',0x00,
	'R','E','S','E','T',' ','D','E','V','I','C','E',0x00,
	'D','E','V','I','C','E',' ','A','D','D','R','E','S','S',0x00,
	'D','I','A','G','N','O','S','I','S',' ','M','E','N','U',0x00,
	'P','E','E','K',' ','V','A','L','U','E',0x00,
	'M','I','N',' ','V','A','L','U','E',0x00,
	'M','A','X',' ','V','A','L','U','E',0x00,
	'S','E','N','S','O','R',' ','S','T','A','T','U','S',0x00,
	'O','S','C',' ','F','A','I','L',0x00,
	'O','V','E','R',' ','R','A','N','G','E',0x00,
	'I','N','F','O','R','M','A','T','I','O','N',' ','M','E','N','U',0x00,
	'M','A','N','U','F','A','C','T','U','R','E',':',0x00,
	'S','E','N','S','O','R',' ',' ',' ',':',0x00,
	'S','E','R','I','A','L',' ',' ',' ',' ',' ',' ',':',0x00,
	'D','A','T','E',' ',' ',' ',' ',' ',' ',' ',' ',' ',':',0x00,
	'V','E','R','S','I','O','N',' ',' ',':',0x00,
	'A','P','L','U','S',' ','F','I','N','E','T','E','K',0x00,
	
};
#endif

#if UDM_USE_TRADITIONAL_CHINESE ==1
const UINT32 gw_udm_traditional_chinese_prompt[]=
{
    UDM_TC001_SYMB,
    UDM_TC002_SYMB,
    UDM_TC003_SYMB,
    UDM_TC004_SYMB,
    UDM_TC005_SYMB,
    UDM_TC006_SYMB,
    UDM_TC007_SYMB,
    UDM_TC008_SYMB,
    UDM_TC009_SYMB,
    UDM_TC010_SYMB,
    UDM_TC011_SYMB,
    UDM_TC012_SYMB,
    UDM_TC013_SYMB,
    UDM_TC014_SYMB,
    UDM_TC015_SYMB,
    UDM_TC016_SYMB,
    UDM_TC017_SYMB,
    UDM_TC018_SYMB,
    UDM_TC019_SYMB,
    UDM_TC020_SYMB,
    UDM_TC021_SYMB,
    UDM_TC022_SYMB,
    UDM_TC023_SYMB,
    UDM_TC024_SYMB,
    UDM_TC025_SYMB,
    UDM_TC026_SYMB,
    UDM_TC027_SYMB,
    UDM_TC028_SYMB,
    UDM_TC029_SYMB,
    UDM_TC030_SYMB,
    UDM_TC031_SYMB,
    UDM_TC032_SYMB,
    UDM_TC033_SYMB,
    UDM_TC034_SYMB,
    UDM_TC035_SYMB,
    UDM_TC036_SYMB,
    UDM_TC037_SYMB,
    UDM_TC038_SYMB,
    UDM_TC039_SYMB,
    UDM_TC040_SYMB,
    UDM_TC041_SYMB,
    UDM_TC042_SYMB,
    UDM_TC043_SYMB,
    UDM_TC044_SYMB,
    UDM_TC045_SYMB,
    UDM_TC046_SYMB,
    UDM_TC047_SYMB,
};
#endif

#if UDM_USE_SIMPLE_CHINESE ==1
const UINT32 gw_udm_simple_chinese_prompt[]=
{
    UDM_SC001_SYMB,
    UDM_SC002_SYMB,
    UDM_SC003_SYMB,
    UDM_SC004_SYMB,
    UDM_SC005_SYMB,
    UDM_SC006_SYMB,
    UDM_SC007_SYMB,
    UDM_SC008_SYMB,
    UDM_SC009_SYMB,
    UDM_SC010_SYMB,
    UDM_SC011_SYMB,
    UDM_SC012_SYMB,
    UDM_SC013_SYMB,
    UDM_SC014_SYMB,
    UDM_SC015_SYMB,
    UDM_SC016_SYMB,
    UDM_SC017_SYMB,
    UDM_SC018_SYMB,
    UDM_SC019_SYMB,
    UDM_SC020_SYMB,
    UDM_SC021_SYMB,
    UDM_SC022_SYMB,
    UDM_SC023_SYMB,
    UDM_SC024_SYMB,
    UDM_SC025_SYMB,
    UDM_SC026_SYMB,
    UDM_SC027_SYMB,
    UDM_SC028_SYMB,
    UDM_SC029_SYMB,
    UDM_SC030_SYMB,
    UDM_SC031_SYMB,
    UDM_SC032_SYMB,
    UDM_SC033_SYMB,
    UDM_SC034_SYMB,
    UDM_SC035_SYMB,
    UDM_SC036_SYMB,
    UDM_SC037_SYMB,
    UDM_SC038_SYMB,
    UDM_SC039_SYMB,
    UDM_SC040_SYMB,
    UDM_SC041_SYMB,
    UDM_SC042_SYMB,
    UDM_SC043_SYMB,
    UDM_SC044_SYMB,
    UDM_SC045_SYMB,
    UDM_SC046_SYMB,
    UDM_SC047_SYMB,
};
#endif

//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 		 udm_glb_vars_init
//
//! @author 	 Willman Chen
//
//! @date 		 2009/07/14
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void udm_glb_vars_init()
{

}
