//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 led7seg_glb_vars.c
//
//! @author 	 Jacky Lin
//
//! @date 		 2021/12/29
//
//  @brief 		 Init globe variable
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S 
//
//**********************************************************************************************************************
#define LED7SEG_ALLOC
#include "led7seg_glb_vars.h"
#undef LED7SEG_ALLOC
//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N 
//
//**********************************************************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif
  
const UINT8 gb_led7seg_font[]=
{
  0x00,						                                // Space
  LED7SEG_G,             							// -											
  LED7SEG_A|LED7SEG_B|LED7SEG_C|LED7SEG_D|LED7SEG_E|LED7SEG_F,  		// 0
  LED7SEG_B|LED7SEG_C,  							// 1
  LED7SEG_A|LED7SEG_B|LED7SEG_D|LED7SEG_E|LED7SEG_G,				// 2
  LED7SEG_A|LED7SEG_B|LED7SEG_C|LED7SEG_D|LED7SEG_G, 				// 3
  LED7SEG_B|LED7SEG_C|LED7SEG_F|LED7SEG_G,      				// 4
  LED7SEG_A|LED7SEG_C|LED7SEG_D|LED7SEG_F|LED7SEG_G,				// 5
  LED7SEG_A|LED7SEG_C|LED7SEG_D|LED7SEG_E|LED7SEG_F|LED7SEG_G,			// 6
  LED7SEG_A|LED7SEG_B|LED7SEG_C|LED7SEG_F,  					// 7
  LED7SEG_A|LED7SEG_B|LED7SEG_C|LED7SEG_D|LED7SEG_E|LED7SEG_F|LED7SEG_G,        // 8
  LED7SEG_A|LED7SEG_B|LED7SEG_C|LED7SEG_F|LED7SEG_G,  				// 9
  LED7SEG_A|LED7SEG_B|LED7SEG_C|LED7SEG_E|LED7SEG_F|LED7SEG_G,                  // A 
  LED7SEG_C|LED7SEG_D|LED7SEG_E|LED7SEG_F|LED7SEG_G,    		        // B
  LED7SEG_A|LED7SEG_D|LED7SEG_E|LED7SEG_F,      				// C
  LED7SEG_B|LED7SEG_C|LED7SEG_D|LED7SEG_E|LED7SEG_G,    		        // D
  LED7SEG_A|LED7SEG_D|LED7SEG_E|LED7SEG_F|LED7SEG_G|LED7SEG_H,		        // E
  LED7SEG_A|LED7SEG_E|LED7SEG_F|LED7SEG_G,      			        // F
  LED7SEG_A|LED7SEG_B|LED7SEG_C|LED7SEG_D|LED7SEG_F|LED7SEG_G,  	        // G
  LED7SEG_B|LED7SEG_C|LED7SEG_E|LED7SEG_F|LED7SEG_G,    		        // H
  LED7SEG_E,            							// I
  LED7SEG_B|LED7SEG_C|LED7SEG_D|LED7SEG_E,      			        // J 
  LED7SEG_B|LED7SEG_D|LED7SEG_E|LED7SEG_F|LED7SEG_G,    		        // K
  LED7SEG_D|LED7SEG_E|LED7SEG_F,        			                // L
  LED7SEG_A|LED7SEG_D|LED7SEG_E|LED7SEG_F|LED7SEG_G|LED7SEG_H,  	        // M
  LED7SEG_C|LED7SEG_E|LED7SEG_G,        				        // N
  LED7SEG_C|LED7SEG_D|LED7SEG_E|LED7SEG_G,      			        // O
  LED7SEG_A|LED7SEG_B|LED7SEG_E|LED7SEG_F|LED7SEG_G,    			// P
  LED7SEG_A|LED7SEG_B|LED7SEG_C|LED7SEG_F|LED7SEG_G|LED7SEG_H,  		// Q
  LED7SEG_E|LED7SEG_G,          						// R
  LED7SEG_A|LED7SEG_C|LED7SEG_D|LED7SEG_F|LED7SEG_G|LED7SEG_H,  		// S
  LED7SEG_D|LED7SEG_E|LED7SEG_F|LED7SEG_G,      			        // T 
  LED7SEG_B|LED7SEG_C|LED7SEG_D|LED7SEG_E|LED7SEG_F,    			// U
  LED7SEG_B|LED7SEG_C|LED7SEG_D|LED7SEG_E|LED7SEG_F|LED7SEG_H,  		// V
  LED7SEG_A|LED7SEG_B|LED7SEG_C|LED7SEG_D|LED7SEG_G|LED7SEG_H,  		// W
  LED7SEG_B|LED7SEG_C|LED7SEG_E|LED7SEG_F|LED7SEG_G|LED7SEG_H,  		// X
  LED7SEG_B|LED7SEG_C|LED7SEG_D|LED7SEG_F|LED7SEG_G,    			// Y
  LED7SEG_A|LED7SEG_B|LED7SEG_D|LED7SEG_E|LED7SEG_G|LED7SEG_H,  		// Z    
  LED7SEG_D,                                                                    // _
  LED7SEG_G|LED7SEG_C|LED7SEG_B,   
}; 
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 			 led7seg_glb_vars_init
//
//! @author 	 Jacky Lin
//
//! @date 		 2021/12/29
//
//! @brief 		 task function
//
//! @param 		 None
//
//! @return 	 None
//
//**********************************************************************************************************************
void led7seg_glb_vars_init()
{

}
//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N 
//
//**********************************************************************************************************************
#ifdef __cplusplus
}
#endif

