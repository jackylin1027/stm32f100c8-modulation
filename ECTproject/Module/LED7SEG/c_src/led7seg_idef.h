#ifndef LED7SEG_IDEF_H
#define LED7SEG_IDEF_H
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 led7seg_idef.h
//
//! @author 	 Jacky Lin
//
//! @date 		 2021/12/29
//
//  @brief 		 Here define internal constant
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// E X T E R N A L   G L O B A L   C O N S T A N C E   /   V A R I A B L E S   I N   E E P R O M 
//
//**********************************************************************************************************************
/*
        0x01
       ______
      |      |       
 0x10 | 0x20 |  0x02
      |______|
      |      |
 0x40 |      |  0x04
      |______|  .   0x08 
        0x80
*/   
#define LED7SEG_A              0x01 	
#define LED7SEG_B              0x02		
#define LED7SEG_C              0x04		
#define LED7SEG_D              0x80		
#define LED7SEG_E              0x40		
#define LED7SEG_F              0x10		
#define LED7SEG_G              0x20		
#define LED7SEG_H              0x08		
#define LED7SEG_DOT            LED7SEG_H

//! @brief The font index
enum LED7SEG_CHAR_INDEX
{
  LED7SEG_CHAR_SPACE,
  LED7SEG_CHAR_MINUS,
  LED7SEG_CHAR_0,
  LED7SEG_CHAR_1, 
  LED7SEG_CHAR_2,
  LED7SEG_CHAR_3,
  LED7SEG_CHAR_4,
  LED7SEG_CHAR_5,
  LED7SEG_CHAR_6,
  LED7SEG_CHAR_7,  
  LED7SEG_CHAR_8,
  LED7SEG_CHAR_9,
  LED7SEG_CHAR_A,  
  LED7SEG_CHAR_B, 
  LED7SEG_CHAR_C, 
  LED7SEG_CHAR_D, 
  LED7SEG_CHAR_E, 
  LED7SEG_CHAR_F, 
  LED7SEG_CHAR_G, 
  LED7SEG_CHAR_H, 
  LED7SEG_CHAR_I, 
  LED7SEG_CHAR_J, 
  LED7SEG_CHAR_K, 
  LED7SEG_CHAR_L, 
  LED7SEG_CHAR_M, 
  LED7SEG_CHAR_N, 
  LED7SEG_CHAR_O,
  LED7SEG_CHAR_P, 
  LED7SEG_CHAR_Q, 
  LED7SEG_CHAR_R, 
  LED7SEG_CHAR_S, 
  LED7SEG_CHAR_T, 
  LED7SEG_CHAR_U,
  LED7SEG_CHAR_V, 
  LED7SEG_CHAR_W, 
  LED7SEG_CHAR_X, 
  LED7SEG_CHAR_Y,  
  LED7SEG_CHAR_Z,    
  LED7SEG_CAHR__,
  LED7SEG_CHAR_MIN_1,
};

#define LED7SEG_MAX_CHAR_NUM            8
#define LED7SEG_INTEGER_START_POSITION  LED7SEG_MAX_CHAR_NUM

#endif		// LED7SEG_IDEF_H 
