#ifndef SSD_IO_IDEF_H
#define SSD_IO_IDEF_H
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 ssd_io_idef.h
//
//! @author 	 Jacky Lin
//
//! @date 		 2021/12/28
//
//  @brief 		 Here define internal constant
//
//**********************************************************************************************************************
enum SSD_IO_COLOR
{
    //SSD_IO_COLOR_GREEN,
    SSD_IO_COLOR_RED,  
    //SSD_IO_COLOR_GREENRED,
};
enum SSD_IO_LED
{
    SSD_IO_LED_1, 
    SSD_IO_LED_2, 
    SSD_IO_LED_3, 
    SSD_IO_LED_4, 
    SSD_IO_LED_5, 
    SSD_IO_LED_6, 
    SSD_IO_LED_7, 
    SSD_IO_LED_8, 
    SSD_IO_LED_TOTAL, 
};
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
#define SSD_IO_A              0x01 	
#define SSD_IO_B              0x02		
#define SSD_IO_C              0x04		
#define SSD_IO_D              0x80		
#define SSD_IO_E              0x40		
#define SSD_IO_F              0x10		
#define SSD_IO_G              0x20		
#define SSD_IO_H              0x08		
#define SSD_IO_DOT            SSD_IO_H

#define SSD_IO_SCREEN_INTERVAL      1 //³æ¦ì 1ms
//**********************************************************************************************************************
//
// E X T E R N A L   G L O B A L   C O N S T A N C E   /   V A R I A B L E S   I N   E E P R O M 
//
//**********************************************************************************************************************
#endif		// SSD_IO_IDEF_H 
