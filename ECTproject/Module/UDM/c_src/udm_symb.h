#ifndef UDM_SYMB_H
#define UDM_SYMB_H
/***********************************************************************************************************************
 *
 * Copyright (C) 2009, FINE-TEK CO.,LTD.   All Rights Reserved
 *
 * @file udm_symb.h
 *
 * @author Willman Chen
 *
 * @date 2009/03/17
 *
 * @brief Here declare task function prototype
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *
 * I N C L U D E   F I L E S  /  E X T E R N A L   V A R I A B L E S
 *
 **********************************************************************************************************************/
#define	UDM_CHAR_SIZE				1
#define	UDM_NCHAR2_SIZE				2
#define	UDM_ICON_SIZE				5
#define	UDM_ICON2_SIZE				10
#define	UDM_ICON3_SIZE				15
#define	UDM_ICON_H					8

#define	UDM_PATTERN_W				0
#define	UDM_PATTERN_H				(UDM_PATTERN_W+1)
#define	UDM_PATTERN_DATA			(UDM_PATTERN_H+1)

#define UDM_BASE_PATTERN_START		0x100
#define UDM_CHAR_TB(i)				udm_icon_table[i-UDM_BASE_PATTERN_START]
#define UDM_PAT_W(i)				udm_icon_table[i+UDM_PATTERN_W-UDM_BASE_PATTERN_START]
#define UDM_PAT_H(i)				udm_icon_table[i+UDM_PATTERN_H-UDM_BASE_PATTERN_START]
#define UDM_PAT_DATA(i)				(UINT8 *)&udm_icon_table[i+UDM_PATTERN_DATA-UDM_BASE_PATTERN_START]
#define UDM_ICON_TB(i)				(UINT8 *)&udm_icon_table[i-UDM_BASE_PATTERN_START]
/* Auto ReIndex Start */

    /* =====================	CHAR SYMBOL START	===================== */
#define UDM_CHAR_SYMBOL_START				UDM_NULL_SYMB
#define UDM_NULL_SYMB              UDM_BASE_PATTERN_START                  		/*	0x100	*/
#define UDM_ZERO_SYMB              (UDM_NULL_SYMB + UDM_CHAR_SIZE)         		/*	0x101	*/
#define UDM_ONE_SYMB               (UDM_ZERO_SYMB + UDM_CHAR_SIZE)         		/*	0x102	*/
#define UDM_TWO_SYMB               (UDM_ONE_SYMB + UDM_CHAR_SIZE)          		/*	0x103	*/
#define UDM_THREE_SYMB             (UDM_TWO_SYMB + UDM_CHAR_SIZE)          		/*	0x104	*/
#define UDM_FOUR_SYMB              (UDM_THREE_SYMB + UDM_CHAR_SIZE)        		/*	0x105	*/
#define UDM_FIVE_SYMB              (UDM_FOUR_SYMB + UDM_CHAR_SIZE)         		/*	0x106	*/
#define UDM_SIX_SYMB               (UDM_FIVE_SYMB + UDM_CHAR_SIZE)         		/*	0x107	*/
#define UDM_SEVEN_SYMB             (UDM_SIX_SYMB + UDM_CHAR_SIZE)          		/*	0x108	*/
#define UDM_EIGHT_SYMB             (UDM_SEVEN_SYMB + UDM_CHAR_SIZE)        		/*	0x109	*/
#define UDM_NINE_SYMB              (UDM_EIGHT_SYMB + UDM_CHAR_SIZE)        		/*	0x10A	*/
#define UDM_QUESTION_SYMB          (UDM_NINE_SYMB + UDM_CHAR_SIZE)         		/*	0x10B	*/
#define UDM_COLON_SYMB             (UDM_QUESTION_SYMB + UDM_CHAR_SIZE)     		/*	0x10C	*/
#define UDM_SLASH_SYMB             (UDM_COLON_SYMB + UDM_CHAR_SIZE)        		/*	0x10D	*/
#define UDM_A_ALPHABET_SYMB        (UDM_SLASH_SYMB + UDM_CHAR_SIZE)        		/*	0x10E	*/
#define UDM_B_ALPHABET_SYMB        (UDM_A_ALPHABET_SYMB + UDM_CHAR_SIZE)   		/*	0x10F	*/
#define UDM_C_ALPHABET_SYMB        (UDM_B_ALPHABET_SYMB + UDM_CHAR_SIZE)   		/*	0x110	*/
#define UDM_D_ALPHABET_SYMB        (UDM_C_ALPHABET_SYMB + UDM_CHAR_SIZE)   		/*	0x111	*/

    /* =====================	NCHAR2 SYMBOL START	===================== */
#define UDM_NCHAR2_SYMBOL_START				UDM_DASH_SYMB
#define UDM_DASH_SYMB              (UDM_D_ALPHABET_SYMB + UDM_CHAR_SIZE)   		/*	0x112	*/

    /* =====================	ICON SYMBOL START	===================== */
#define UDM_ICON_SYMBOL_START				UDM_BLANK_SYMB
#define UDM_BLANK_SYMB             (UDM_DASH_SYMB + UDM_NCHAR2_SIZE)       		/*	0x114	*/
#define UDM_SMALL_0_SYMB           (UDM_BLANK_SYMB + UDM_ICON_SIZE)        		/*	0x119	*/
#define UDM_SMALL_1_SYMB           (UDM_SMALL_0_SYMB + UDM_ICON_SIZE)      		/*	0x11E	*/
#define UDM_SMALL_2_SYMB           (UDM_SMALL_1_SYMB + UDM_ICON_SIZE)      		/*	0x123	*/
#define UDM_SMALL_3_SYMB           (UDM_SMALL_2_SYMB + UDM_ICON_SIZE)      		/*	0x128	*/
#define UDM_SMALL_4_SYMB           (UDM_SMALL_3_SYMB + UDM_ICON_SIZE)      		/*	0x12D	*/
#define UDM_SMALL_5_SYMB           (UDM_SMALL_4_SYMB + UDM_ICON_SIZE)      		/*	0x132	*/
#define UDM_SMALL_6_SYMB           (UDM_SMALL_5_SYMB + UDM_ICON_SIZE)      		/*	0x137	*/
#define UDM_SMALL_7_SYMB           (UDM_SMALL_6_SYMB + UDM_ICON_SIZE)      		/*	0x13C	*/
#define UDM_SMALL_8_SYMB           (UDM_SMALL_7_SYMB + UDM_ICON_SIZE)      		/*	0x141	*/
#define UDM_SMALL_9_SYMB           (UDM_SMALL_8_SYMB + UDM_ICON_SIZE)      		/*	0x146	*/
#define UDM_SMALL_SLASH_SYMB       (UDM_SMALL_9_SYMB + UDM_ICON_SIZE)      		/*	0x14B	*/
#define UDM_SMALL_SLIENT_SYMB      (UDM_SMALL_SLASH_SYMB + UDM_ICON_SIZE)  		/*	0x150	*/
#define UDM_SMALL_PRIVATE_TIME_SYMB (UDM_SMALL_SLIENT_SYMB + UDM_ICON_SIZE) 		/*	0x155	*/
#define UDM_SMALL_LEFT_ARROW_SYMB  (UDM_SMALL_PRIVATE_TIME_SYMB + UDM_ICON_SIZE)		/*	0x15A	*/
#define UDM_SMALL_RIGHT_ARROW_SYMB (UDM_SMALL_LEFT_ARROW_SYMB + UDM_ICON_SIZE)		/*	0x15F	*/
#define UDM_LEFT_ARROW_SYMB        (UDM_SMALL_RIGHT_ARROW_SYMB + UDM_ICON_SIZE)		/*	0x164	*/
#define UDM_RIGHT_ARROW_SYMB       (UDM_LEFT_ARROW_SYMB + UDM_ICON_SIZE)   		/*	0x169	*/
#define UDM_TICK_SYMB              (UDM_RIGHT_ARROW_SYMB + UDM_ICON_SIZE)  		/*	0x16E	*/

    /* =====================	ICON2 SYMBOL START	===================== */
#define UDM_ICON2_SYMBOL_START				UDM_BLACK_WHITE_SYMB
#define UDM_BLACK_WHITE_SYMB       (UDM_TICK_SYMB + UDM_ICON_SIZE)         		/*	0x173	*/

    /* =====================	ICON3 SYMBOL START	===================== */
#define UDM_ICON3_SYMBOL_START				UDM_BATTERY_FULL_SYMB
#define UDM_BATTERY_FULL_SYMB      (UDM_BLACK_WHITE_SYMB + UDM_ICON2_SIZE) 		/*	0x17D	*/

    /* =====================	PATTERN SYMBOL START	===================== */
#define UDM_PATTERN_SYMBOL_START				UDM_POWERUP_LOGO_SYMB
#define UDM_POWERUP_LOGO_LEN				1026
#define UDM_POWERUP_LOGO_SYMB      (UDM_BATTERY_FULL_SYMB + UDM_ICON3_SIZE)		/*	0x18C	*/
#define UDM_A_F_LEN				642
#define UDM_A_F_SYMB               (UDM_POWERUP_LOGO_SYMB + UDM_POWERUP_LOGO_LEN)		/*	0x58E	*/
#define UDM_BIG_0_LEN				162
#define UDM_BIG_0_SYMB             (UDM_A_F_SYMB + UDM_A_F_LEN)            		/*	0x810	*/
#define UDM_BIG_1_LEN				162
#define UDM_BIG_1_SYMB             (UDM_BIG_0_SYMB + UDM_BIG_0_LEN)        		/*	0x8B2	*/
#define UDM_BIG_2_LEN				162
#define UDM_BIG_2_SYMB             (UDM_BIG_1_SYMB + UDM_BIG_1_LEN)        		/*	0x954	*/
#define UDM_BIG_3_LEN				162
#define UDM_BIG_3_SYMB             (UDM_BIG_2_SYMB + UDM_BIG_2_LEN)        		/*	0x9F6	*/
#define UDM_BIG_4_LEN				162
#define UDM_BIG_4_SYMB             (UDM_BIG_3_SYMB + UDM_BIG_3_LEN)        		/*	0xA98	*/
#define UDM_BIG_5_LEN				162
#define UDM_BIG_5_SYMB             (UDM_BIG_4_SYMB + UDM_BIG_4_LEN)        		/*	0xB3A	*/
#define UDM_BIG_6_LEN				162
#define UDM_BIG_6_SYMB             (UDM_BIG_5_SYMB + UDM_BIG_5_LEN)        		/*	0xBDC	*/
#define UDM_BIG_7_LEN				162
#define UDM_BIG_7_SYMB             (UDM_BIG_6_SYMB + UDM_BIG_6_LEN)        		/*	0xC7E	*/
#define UDM_BIG_8_LEN				162
#define UDM_BIG_8_SYMB             (UDM_BIG_7_SYMB + UDM_BIG_7_LEN)        		/*	0xD20	*/
#define UDM_BIG_9_LEN				162
#define UDM_BIG_9_SYMB             (UDM_BIG_8_SYMB + UDM_BIG_8_LEN)        		/*	0xDC2	*/
#define UDM_BIG_DOT_LEN				162
#define UDM_BIG_DOT_SYMB           (UDM_BIG_9_SYMB + UDM_BIG_9_LEN)        		/*	0xE64	*/
#define UDM_TC001_LEN				150
#define UDM_TC001_SYMB             (UDM_BIG_DOT_SYMB + UDM_BIG_DOT_LEN)    		/*	0xF06	*/
#define UDM_TC002_LEN				222
#define UDM_TC002_SYMB             (UDM_TC001_SYMB + UDM_TC001_LEN)        		/*	0xF9C	*/
#define UDM_TC003_LEN				222
#define UDM_TC003_SYMB             (UDM_TC002_SYMB + UDM_TC002_LEN)        		/*	0x107A	*/
#define UDM_TC004_LEN				198
#define UDM_TC004_SYMB             (UDM_TC003_SYMB + UDM_TC003_LEN)        		/*	0x1158	*/
#define UDM_TC005_LEN				198
#define UDM_TC005_SYMB             (UDM_TC004_SYMB + UDM_TC004_LEN)        		/*	0x121E	*/
#define UDM_TC006_LEN				198
#define UDM_TC006_SYMB             (UDM_TC005_SYMB + UDM_TC005_LEN)        		/*	0x12E4	*/
#define UDM_TC007_LEN				198
#define UDM_TC007_SYMB             (UDM_TC006_SYMB + UDM_TC006_LEN)        		/*	0x13AA	*/
#define UDM_TC008_LEN				198
#define UDM_TC008_SYMB             (UDM_TC007_SYMB + UDM_TC007_LEN)        		/*	0x1470	*/
#define UDM_TC009_LEN				198
#define UDM_TC009_SYMB             (UDM_TC008_SYMB + UDM_TC008_LEN)        		/*	0x1536	*/
#define UDM_TC010_LEN				198
#define UDM_TC010_SYMB             (UDM_TC009_SYMB + UDM_TC009_LEN)        		/*	0x15FC	*/
#define UDM_TC011_LEN				198
#define UDM_TC011_SYMB             (UDM_TC010_SYMB + UDM_TC010_LEN)        		/*	0x16C2	*/
#define UDM_TC012_LEN				198
#define UDM_TC012_SYMB             (UDM_TC011_SYMB + UDM_TC011_LEN)        		/*	0x1788	*/
#define UDM_TC013_LEN				198
#define UDM_TC013_SYMB             (UDM_TC012_SYMB + UDM_TC012_LEN)        		/*	0x184E	*/
#define UDM_TC014_LEN				198
#define UDM_TC014_SYMB             (UDM_TC013_SYMB + UDM_TC013_LEN)        		/*	0x1914	*/
#define UDM_TC015_LEN				198
#define UDM_TC015_SYMB             (UDM_TC014_SYMB + UDM_TC014_LEN)        		/*	0x19DA	*/
#define UDM_TC016_LEN				198
#define UDM_TC016_SYMB             (UDM_TC015_SYMB + UDM_TC015_LEN)        		/*	0x1AA0	*/
#define UDM_TC017_LEN				198
#define UDM_TC017_SYMB             (UDM_TC016_SYMB + UDM_TC016_LEN)        		/*	0x1B66	*/
#define UDM_TC018_LEN				198
#define UDM_TC018_SYMB             (UDM_TC017_SYMB + UDM_TC017_LEN)        		/*	0x1C2C	*/
#define UDM_TC019_LEN				100
#define UDM_TC019_SYMB             (UDM_TC018_SYMB + UDM_TC018_LEN)        		/*	0x1CF2	*/
#define UDM_TC020_LEN				198
#define UDM_TC020_SYMB             (UDM_TC019_SYMB + UDM_TC019_LEN)        		/*	0x1D56	*/
#define UDM_TC021_LEN				174
#define UDM_TC021_SYMB             (UDM_TC020_SYMB + UDM_TC020_LEN)        		/*	0x1E1C	*/
#define UDM_TC022_LEN				174
#define UDM_TC022_SYMB             (UDM_TC021_SYMB + UDM_TC021_LEN)        		/*	0x1ECA	*/
#define UDM_TC023_LEN				174
#define UDM_TC023_SYMB             (UDM_TC022_SYMB + UDM_TC022_LEN)        		/*	0x1F78	*/
#define UDM_TC024_LEN				124
#define UDM_TC024_SYMB             (UDM_TC023_SYMB + UDM_TC023_LEN)        		/*	0x2026	*/
#define UDM_TC025_LEN				198
#define UDM_TC025_SYMB             (UDM_TC024_SYMB + UDM_TC024_LEN)        		/*	0x20A2	*/
#define UDM_TC026_LEN				198
#define UDM_TC026_SYMB             (UDM_TC025_SYMB + UDM_TC025_LEN)        		/*	0x2168	*/
#define UDM_TC027_LEN				100
#define UDM_TC027_SYMB             (UDM_TC026_SYMB + UDM_TC026_LEN)        		/*	0x222E	*/
#define UDM_TC028_LEN				174
#define UDM_TC028_SYMB             (UDM_TC027_SYMB + UDM_TC027_LEN)        		/*	0x2292	*/
#define UDM_TC029_LEN				100
#define UDM_TC029_SYMB             (UDM_TC028_SYMB + UDM_TC028_LEN)        		/*	0x2340	*/
#define UDM_TC030_LEN				198
#define UDM_TC030_SYMB             (UDM_TC029_SYMB + UDM_TC029_LEN)        		/*	0x23A4	*/
#define UDM_TC031_LEN				198
#define UDM_TC031_SYMB             (UDM_TC030_SYMB + UDM_TC030_LEN)        		/*	0x246A	*/
#define UDM_TC032_LEN				100
#define UDM_TC032_SYMB             (UDM_TC031_SYMB + UDM_TC031_LEN)        		/*	0x2530	*/
#define UDM_TC033_LEN				198
#define UDM_TC033_SYMB             (UDM_TC032_SYMB + UDM_TC032_LEN)        		/*	0x2594	*/
#define UDM_TC034_LEN				198
#define UDM_TC034_SYMB             (UDM_TC033_SYMB + UDM_TC033_LEN)        		/*	0x265A	*/
#define UDM_TC035_LEN				198
#define UDM_TC035_SYMB             (UDM_TC034_SYMB + UDM_TC034_LEN)        		/*	0x2720	*/
#define UDM_TC036_LEN				198
#define UDM_TC036_SYMB             (UDM_TC035_SYMB + UDM_TC035_LEN)        		/*	0x27E6	*/
#define UDM_TC037_LEN				198
#define UDM_TC037_SYMB             (UDM_TC036_SYMB + UDM_TC036_LEN)        		/*	0x28AC	*/
#define UDM_TC038_LEN				198
#define UDM_TC038_SYMB             (UDM_TC037_SYMB + UDM_TC037_LEN)        		/*	0x2972	*/
#define UDM_TC039_LEN				198
#define UDM_TC039_SYMB             (UDM_TC038_SYMB + UDM_TC038_LEN)        		/*	0x2A38	*/
#define UDM_TC040_LEN				198
#define UDM_TC040_SYMB             (UDM_TC039_SYMB + UDM_TC039_LEN)        		/*	0x2AFE	*/
#define UDM_TC041_LEN				198
#define UDM_TC041_SYMB             (UDM_TC040_SYMB + UDM_TC040_LEN)        		/*	0x2BC4	*/
#define UDM_TC042_LEN				198
#define UDM_TC042_SYMB             (UDM_TC041_SYMB + UDM_TC041_LEN)        		/*	0x2C8A	*/
#define UDM_TC043_LEN				198
#define UDM_TC043_SYMB             (UDM_TC042_SYMB + UDM_TC042_LEN)        		/*	0x2D50	*/
#define UDM_TC044_LEN				198
#define UDM_TC044_SYMB             (UDM_TC043_SYMB + UDM_TC043_LEN)        		/*	0x2E16	*/
#define UDM_TC045_LEN				246
#define UDM_TC045_SYMB             (UDM_TC044_SYMB + UDM_TC044_LEN)        		/*	0x2EDC	*/
#define UDM_TC046_LEN				198
#define UDM_TC046_SYMB             (UDM_TC045_SYMB + UDM_TC045_LEN)        		/*	0x2FD2	*/
#define UDM_TC047_LEN				100
#define UDM_TC047_SYMB             (UDM_TC046_SYMB + UDM_TC046_LEN)        		/*	0x3098	*/
#define UDM_SC001_LEN				150
#define UDM_SC001_SYMB             (UDM_TC047_SYMB + UDM_TC047_LEN)        		/*	0x30FC	*/
#define UDM_SC002_LEN				124
#define UDM_SC002_SYMB             (UDM_SC001_SYMB + UDM_SC001_LEN)        		/*	0x3192	*/
#define UDM_SC003_LEN				124
#define UDM_SC003_SYMB             (UDM_SC002_SYMB + UDM_SC002_LEN)        		/*	0x320E	*/
#define UDM_SC004_LEN				124
#define UDM_SC004_SYMB             (UDM_SC003_SYMB + UDM_SC003_LEN)        		/*	0x328A	*/
#define UDM_SC005_LEN				124
#define UDM_SC005_SYMB             (UDM_SC004_SYMB + UDM_SC004_LEN)        		/*	0x3306	*/
#define UDM_SC006_LEN				150
#define UDM_SC006_SYMB             (UDM_SC005_SYMB + UDM_SC005_LEN)        		/*	0x3382	*/
#define UDM_SC007_LEN				100
#define UDM_SC007_SYMB             (UDM_SC006_SYMB + UDM_SC006_LEN)        		/*	0x3418	*/
#define UDM_SC008_LEN				76
#define UDM_SC008_SYMB             (UDM_SC007_SYMB + UDM_SC007_LEN)        		/*	0x347C	*/
#define UDM_SC009_LEN				76
#define UDM_SC009_SYMB             (UDM_SC008_SYMB + UDM_SC008_LEN)        		/*	0x34C8	*/
#define UDM_SC010_LEN				50
#define UDM_SC010_SYMB             (UDM_SC009_SYMB + UDM_SC009_LEN)        		/*	0x3514	*/
#define UDM_SC011_LEN				50
#define UDM_SC011_SYMB             (UDM_SC010_SYMB + UDM_SC010_LEN)        		/*	0x3546	*/
#define UDM_SC012_LEN				50
#define UDM_SC012_SYMB             (UDM_SC011_SYMB + UDM_SC011_LEN)        		/*	0x3578	*/
#define UDM_SC013_LEN				50
#define UDM_SC013_SYMB             (UDM_SC012_SYMB + UDM_SC012_LEN)        		/*	0x35AA	*/
#define UDM_SC014_LEN				50
#define UDM_SC014_SYMB             (UDM_SC013_SYMB + UDM_SC013_LEN)        		/*	0x35DC	*/
#define UDM_SC015_LEN				50
#define UDM_SC015_SYMB             (UDM_SC014_SYMB + UDM_SC014_LEN)        		/*	0x360E	*/
#define UDM_SC016_LEN				50
#define UDM_SC016_SYMB             (UDM_SC015_SYMB + UDM_SC015_LEN)        		/*	0x3640	*/
#define UDM_SC017_LEN				50
#define UDM_SC017_SYMB             (UDM_SC016_SYMB + UDM_SC016_LEN)        		/*	0x3672	*/
#define UDM_SC018_LEN				100
#define UDM_SC018_SYMB             (UDM_SC017_SYMB + UDM_SC017_LEN)        		/*	0x36A4	*/
#define UDM_SC019_LEN				100
#define UDM_SC019_SYMB             (UDM_SC018_SYMB + UDM_SC018_LEN)        		/*	0x3708	*/
#define UDM_SC020_LEN				150
#define UDM_SC020_SYMB             (UDM_SC019_SYMB + UDM_SC019_LEN)        		/*	0x376C	*/
#define UDM_SC021_LEN				198
#define UDM_SC021_SYMB             (UDM_SC020_SYMB + UDM_SC020_LEN)        		/*	0x3802	*/
#define UDM_SC022_LEN				174
#define UDM_SC022_SYMB             (UDM_SC021_SYMB + UDM_SC021_LEN)        		/*	0x38C8	*/
#define UDM_SC023_LEN				198
#define UDM_SC023_SYMB             (UDM_SC022_SYMB + UDM_SC022_LEN)        		/*	0x3976	*/
#define UDM_SC024_LEN				76
#define UDM_SC024_SYMB             (UDM_SC023_SYMB + UDM_SC023_LEN)        		/*	0x3A3C	*/
#define UDM_SC025_LEN				100
#define UDM_SC025_SYMB             (UDM_SC024_SYMB + UDM_SC024_LEN)        		/*	0x3A88	*/
#define UDM_SC026_LEN				100
#define UDM_SC026_SYMB             (UDM_SC025_SYMB + UDM_SC025_LEN)        		/*	0x3AEC	*/
#define UDM_SC027_LEN				100
#define UDM_SC027_SYMB             (UDM_SC026_SYMB + UDM_SC026_LEN)        		/*	0x3B50	*/
#define UDM_SC028_LEN				100
#define UDM_SC028_SYMB             (UDM_SC027_SYMB + UDM_SC027_LEN)        		/*	0x3BB4	*/
#define UDM_SC029_LEN				100
#define UDM_SC029_SYMB             (UDM_SC028_SYMB + UDM_SC028_LEN)        		/*	0x3C18	*/
#define UDM_SC030_LEN				26
#define UDM_SC030_SYMB             (UDM_SC029_SYMB + UDM_SC029_LEN)        		/*	0x3C7C	*/
#define UDM_SC031_LEN				198
#define UDM_SC031_SYMB             (UDM_SC030_SYMB + UDM_SC030_LEN)        		/*	0x3C96	*/
#define UDM_SC032_LEN				100
#define UDM_SC032_SYMB             (UDM_SC031_SYMB + UDM_SC031_LEN)        		/*	0x3D5C	*/
#define UDM_SC033_LEN				100
#define UDM_SC033_SYMB             (UDM_SC032_SYMB + UDM_SC032_LEN)        		/*	0x3DC0	*/
#define UDM_SC034_LEN				150
#define UDM_SC034_SYMB             (UDM_SC033_SYMB + UDM_SC033_LEN)        		/*	0x3E24	*/
#define UDM_SC035_LEN				100
#define UDM_SC035_SYMB             (UDM_SC034_SYMB + UDM_SC034_LEN)        		/*	0x3EBA	*/
#define UDM_SC036_LEN				76
#define UDM_SC036_SYMB             (UDM_SC035_SYMB + UDM_SC035_LEN)        		/*	0x3F1E	*/
#define UDM_SC037_LEN				76
#define UDM_SC037_SYMB             (UDM_SC036_SYMB + UDM_SC036_LEN)        		/*	0x3F6A	*/
#define UDM_SC038_LEN				100
#define UDM_SC038_SYMB             (UDM_SC037_SYMB + UDM_SC037_LEN)        		/*	0x3FB6	*/
#define UDM_SC039_LEN				150
#define UDM_SC039_SYMB             (UDM_SC038_SYMB + UDM_SC038_LEN)        		/*	0x401A	*/
#define UDM_SC040_LEN				150
#define UDM_SC040_SYMB             (UDM_SC039_SYMB + UDM_SC039_LEN)        		/*	0x40B0	*/
#define UDM_SC041_LEN				150
#define UDM_SC041_SYMB             (UDM_SC040_SYMB + UDM_SC040_LEN)        		/*	0x4146	*/
#define UDM_SC042_LEN				100
#define UDM_SC042_SYMB             (UDM_SC041_SYMB + UDM_SC041_LEN)        		/*	0x41DC	*/
#define UDM_SC043_LEN				150
#define UDM_SC043_SYMB             (UDM_SC042_SYMB + UDM_SC042_LEN)        		/*	0x4240	*/
#define UDM_SC044_LEN				150
#define UDM_SC044_SYMB             (UDM_SC043_SYMB + UDM_SC043_LEN)        		/*	0x42D6	*/
#define UDM_SC045_LEN				150
#define UDM_SC045_SYMB             (UDM_SC044_SYMB + UDM_SC044_LEN)        		/*	0x436C	*/
#define UDM_SC046_LEN				198
#define UDM_SC046_SYMB             (UDM_SC045_SYMB + UDM_SC045_LEN)        		/*	0x4402	*/
#define UDM_SC047_LEN				100
#define UDM_SC047_SYMB             (UDM_SC046_SYMB + UDM_SC046_LEN)        		/*	0x44C8	*/
#define UDM_PATTERN_END_LEN				2
#define UDM_PATTERN_END_SYMB       (UDM_SC047_SYMB + UDM_SC047_LEN)        		/*	0x452C	*/
/* Auto ReIndex Stop */
#define UDM_ICON_ARRAY_SIZE			(UDM_PATTERN_END_SYMB)
#include "..\udm_udef.h"
UINT8 udm_get_symb_w (UINT32 symb);
UINT8 udm_get_symb_h (UINT32 symb);
#endif // END UIF_SYMB_H


























































































































































































































































































































