#ifndef SSD_IO_DRV_H
#define SSD_IO_DRV_H
//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N 
//
//**********************************************************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif
//**********************************************************************************************************************
//
// Copyright (C) 2010, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 ssd_io_drv.h
//
//! @author 	 Jacky Lin
//
//! @date 		 2021/12/28
//
//  @brief 		 Here declare driver function
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S 
//
//**********************************************************************************************************************
#include "..\..\fk\fk_udef.h"  
//**********************************************************************************************************************
//
// I / O   P O R T   D E F I N I T I O N 
//
//**********************************************************************************************************************
//====== 綠色7段顯示器共陰極control port 0 ~ 3 =====
#define SSD_IO_FIGURE0_PORT                     FK_PORTB
#define SSD_IO_FIGURE0_PIN                      FK_PIN8
#define SSD_IO_FIGURE0_LOW()                    FK_SET_OUTPUT_PIN_LOW_API(SSD_IO_FIGURE0_PORT,SSD_IO_FIGURE0_PIN)
#define SSD_IO_FIGURE0_HIGH()                   FK_SET_OUTPUT_PIN_HIGH_API(SSD_IO_FIGURE0_PORT,SSD_IO_FIGURE0_PIN)
#define SSD_IO_FIGURE0_TOGGLE()                 FK_SET_OUTPUT_PIN_TOGGLE_API(SSD_IO_FIGURE0_PORT,SSD_IO_FIGURE0_PIN)
#define SSD_IO_FIGURE0_INIT()                   SSD_IO_FIGURE0_HIGH()
#define SSD_IO_FIGURE1_PORT                     FK_PORTB
#define SSD_IO_FIGURE1_PIN                      FK_PIN9
#define SSD_IO_FIGURE1_LOW()                    FK_SET_OUTPUT_PIN_LOW_API(SSD_IO_FIGURE1_PORT,SSD_IO_FIGURE1_PIN)
#define SSD_IO_FIGURE1_HIGH()                   FK_SET_OUTPUT_PIN_HIGH_API(SSD_IO_FIGURE1_PORT,SSD_IO_FIGURE1_PIN)
#define SSD_IO_FIGURE1_TOGGLE()                 FK_SET_OUTPUT_PIN_TOGGLE_API(SSD_IO_FIGURE1_PORT,SSD_IO_FIGURE1_PIN)
#define SSD_IO_FIGURE1_INIT()                   SSD_IO_FIGURE1_HIGH()
#define SSD_IO_FIGURE2_PORT                     FK_PORTB
#define SSD_IO_FIGURE2_PIN                      FK_PIN10
#define SSD_IO_FIGURE2_LOW()                    FK_SET_OUTPUT_PIN_LOW_API(SSD_IO_FIGURE2_PORT,SSD_IO_FIGURE2_PIN)
#define SSD_IO_FIGURE2_HIGH()                   FK_SET_OUTPUT_PIN_HIGH_API(SSD_IO_FIGURE2_PORT,SSD_IO_FIGURE2_PIN)
#define SSD_IO_FIGURE2_TOGGLE()                 FK_SET_OUTPUT_PIN_TOGGLE_API(SSD_IO_FIGURE2_PORT,SSD_IO_FIGURE2_PIN)
#define SSD_IO_FIGURE2_INIT()                   SSD_IO_FIGURE2_HIGH()  
#define SSD_IO_FIGURE3_PORT                     FK_PORTB
#define SSD_IO_FIGURE3_PIN                      FK_PIN11
#define SSD_IO_FIGURE3_LOW()                    FK_SET_OUTPUT_PIN_LOW_API(SSD_IO_FIGURE3_PORT,SSD_IO_FIGURE3_PIN)
#define SSD_IO_FIGURE3_HIGH()                   FK_SET_OUTPUT_PIN_HIGH_API(SSD_IO_FIGURE3_PORT,SSD_IO_FIGURE3_PIN)
#define SSD_IO_FIGURE3_TOGGLE()                 FK_SET_OUTPUT_PIN_TOGGLE_API(SSD_IO_FIGURE3_PORT,SSD_IO_FIGURE3_PIN)
#define SSD_IO_FIGURE3_INIT()                   SSD_IO_FIGURE3_HIGH()
#define SSD_IO_FIGURE4_PORT                     FK_PORTB
#define SSD_IO_FIGURE4_PIN                      FK_PIN12
#define SSD_IO_FIGURE4_LOW()                    FK_SET_OUTPUT_PIN_LOW_API(SSD_IO_FIGURE4_PORT,SSD_IO_FIGURE4_PIN)
#define SSD_IO_FIGURE4_HIGH()                   FK_SET_OUTPUT_PIN_HIGH_API(SSD_IO_FIGURE4_PORT,SSD_IO_FIGURE4_PIN)
#define SSD_IO_FIGURE4_TOGGLE()                 FK_SET_OUTPUT_PIN_TOGGLE_API(SSD_IO_FIGURE4_PORT,SSD_IO_FIGURE4_PIN)
#define SSD_IO_FIGURE4_INIT()                   SSD_IO_FIGURE4_HIGH()
#define SSD_IO_FIGURE5_PORT                     FK_PORTB
#define SSD_IO_FIGURE5_PIN                      FK_PIN13
#define SSD_IO_FIGURE5_LOW()                    FK_SET_OUTPUT_PIN_LOW_API(SSD_IO_FIGURE5_PORT,SSD_IO_FIGURE5_PIN)
#define SSD_IO_FIGURE5_HIGH()                   FK_SET_OUTPUT_PIN_HIGH_API(SSD_IO_FIGURE5_PORT,SSD_IO_FIGURE5_PIN)
#define SSD_IO_FIGURE5_TOGGLE()                 FK_SET_OUTPUT_PIN_TOGGLE_API(SSD_IO_FIGURE5_PORT,SSD_IO_FIGURE5_PIN)
#define SSD_IO_FIGURE5_INIT()                   SSD_IO_FIGURE5_HIGH()
#define SSD_IO_FIGURE6_PORT                     FK_PORTB
#define SSD_IO_FIGURE6_PIN                      FK_PIN14
#define SSD_IO_FIGURE6_LOW()                    FK_SET_OUTPUT_PIN_LOW_API(SSD_IO_FIGURE6_PORT,SSD_IO_FIGURE6_PIN)
#define SSD_IO_FIGURE6_HIGH()                   FK_SET_OUTPUT_PIN_HIGH_API(SSD_IO_FIGURE6_PORT,SSD_IO_FIGURE6_PIN)
#define SSD_IO_FIGURE6_TOGGLE()                 FK_SET_OUTPUT_PIN_TOGGLE_API(SSD_IO_FIGURE6_PORT,SSD_IO_FIGURE6_PIN)
#define SSD_IO_FIGURE6_INIT()                   SSD_IO_FIGURE6_HIGH()
#define SSD_IO_FIGURE7_PORT                     FK_PORTB
#define SSD_IO_FIGURE7_PIN                      FK_PIN15
#define SSD_IO_FIGURE7_LOW()                    FK_SET_OUTPUT_PIN_LOW_API(SSD_IO_FIGURE7_PORT,SSD_IO_FIGURE7_PIN)
#define SSD_IO_FIGURE7_HIGH()                   FK_SET_OUTPUT_PIN_HIGH_API(SSD_IO_FIGURE7_PORT,SSD_IO_FIGURE7_PIN)
#define SSD_IO_FIGURE7_TOGGLE()                 FK_SET_OUTPUT_PIN_TOGGLE_API(SSD_IO_FIGURE7_PORT,SSD_IO_FIGURE7_PIN)
#define SSD_IO_FIGURE7_INIT()                   SSD_IO_FIGURE7_HIGH()  
//=================================================
//====== 7段顯示器DATA PIN0 ~ PIN7 =====  
#define SSD_IO_DATA0_PORT                       FK_PORTC     
#define SSD_IO_DATA0_PIN                        FK_PIN0
#define SSD_IO_DATA0_LOW()                      FK_SET_OUTPUT_PIN_LOW_API(SSD_IO_DATA0_PORT,SSD_IO_DATA0_PIN)
#define SSD_IO_DATA0_HIGH()                     FK_SET_OUTPUT_PIN_HIGH_API(SSD_IO_DATA0_PORT,SSD_IO_DATA0_PIN)
#define SSD_IO_DATA0_TOGGLE()                   FK_SET_OUTPUT_PIN_TOGGLE_API(SSD_IO_DATA0_PORT,SSD_IO_DATA0_PIN)  
#define SSD_IO_DATA0_INIT()                     SSD_IO_DATA0_HIGH() //initial with CubeMX 
#define SSD_IO_DATA1_PORT                       FK_PORTC     
#define SSD_IO_DATA1_PIN                        FK_PIN1
#define SSD_IO_DATA1_LOW()                      FK_SET_OUTPUT_PIN_LOW_API(SSD_IO_DATA1_PORT,SSD_IO_DATA1_PIN)
#define SSD_IO_DATA1_HIGH()                     FK_SET_OUTPUT_PIN_HIGH_API(SSD_IO_DATA1_PORT,SSD_IO_DATA1_PIN)
#define SSD_IO_DATA1_TOGGLE()                   FK_SET_OUTPUT_PIN_TOGGLE_API(SSD_IO_DATA1_PORT,SSD_IO_DATA1_PIN)  
#define SSD_IO_DATA1_INIT()                     SSD_IO_DATA1_HIGH() //initial with CubeMX 
#define SSD_IO_DATA2_PORT                       FK_PORTC     
#define SSD_IO_DATA2_PIN                        FK_PIN2
#define SSD_IO_DATA2_LOW()                      FK_SET_OUTPUT_PIN_LOW_API(SSD_IO_DATA2_PORT,SSD_IO_DATA2_PIN)
#define SSD_IO_DATA2_HIGH()                     FK_SET_OUTPUT_PIN_HIGH_API(SSD_IO_DATA2_PORT,SSD_IO_DATA2_PIN)
#define SSD_IO_DATA2_TOGGLE()                   FK_SET_OUTPUT_PIN_TOGGLE_API(SSD_IO_DATA2_PORT,SSD_IO_DATA2_PIN)  
#define SSD_IO_DATA2_INIT()                     SSD_IO_DATA2_HIGH() //initial with CubeMX 
#define SSD_IO_DATA3_PORT                       FK_PORTC     
#define SSD_IO_DATA3_PIN                        FK_PIN3
#define SSD_IO_DATA3_LOW()                      FK_SET_OUTPUT_PIN_LOW_API(SSD_IO_DATA3_PORT,SSD_IO_DATA3_PIN)
#define SSD_IO_DATA3_HIGH()                     FK_SET_OUTPUT_PIN_HIGH_API(SSD_IO_DATA3_PORT,SSD_IO_DATA3_PIN)
#define SSD_IO_DATA3_TOGGLE()                   FK_SET_OUTPUT_PIN_TOGGLE_API(SSD_IO_DATA3_PORT,SSD_IO_DATA3_PIN)  
#define SSD_IO_DATA3_INIT()                     SSD_IO_DATA3_HIGH() //initial with CubeMX 
#define SSD_IO_DATA4_PORT                       FK_PORTC     
#define SSD_IO_DATA4_PIN                        FK_PIN4
#define SSD_IO_DATA4_LOW()                      FK_SET_OUTPUT_PIN_LOW_API(SSD_IO_DATA4_PORT,SSD_IO_DATA4_PIN)
#define SSD_IO_DATA4_HIGH()                     FK_SET_OUTPUT_PIN_HIGH_API(SSD_IO_DATA4_PORT,SSD_IO_DATA4_PIN)
#define SSD_IO_DATA4_TOGGLE()                   FK_SET_OUTPUT_PIN_TOGGLE_API(SSD_IO_DATA4_PORT,SSD_IO_DATA4_PIN)  
#define SSD_IO_DATA4_INIT()                     SSD_IO_DATA4_HIGH() //initial with CubeMX 
#define SSD_IO_DATA5_PORT                       FK_PORTC     
#define SSD_IO_DATA5_PIN                        FK_PIN5
#define SSD_IO_DATA5_LOW()                      FK_SET_OUTPUT_PIN_LOW_API(SSD_IO_DATA5_PORT,SSD_IO_DATA5_PIN)
#define SSD_IO_DATA5_HIGH()                     FK_SET_OUTPUT_PIN_HIGH_API(SSD_IO_DATA5_PORT,SSD_IO_DATA5_PIN)
#define SSD_IO_DATA5_TOGGLE()                   FK_SET_OUTPUT_PIN_TOGGLE_API(SSD_IO_DATA5_PORT,SSD_IO_DATA5_PIN)  
#define SSD_IO_DATA5_INIT()                     SSD_IO_DATA5_HIGH() //initial with CubeMX 
#define SSD_IO_DATA6_PORT                       FK_PORTC     
#define SSD_IO_DATA6_PIN                        FK_PIN6
#define SSD_IO_DATA6_LOW()                      FK_SET_OUTPUT_PIN_LOW_API(SSD_IO_DATA6_PORT,SSD_IO_DATA6_PIN)
#define SSD_IO_DATA6_HIGH()                     FK_SET_OUTPUT_PIN_HIGH_API(SSD_IO_DATA6_PORT,SSD_IO_DATA6_PIN)
#define SSD_IO_DATA6_TOGGLE()                   FK_SET_OUTPUT_PIN_TOGGLE_API(SSD_IO_DATA6_PORT,SSD_IO_DATA6_PIN)  
#define SSD_IO_DATA6_INIT()                     SSD_IO_DATA6_HIGH() //initial with CubeMX 
#define SSD_IO_DATA7_PORT                       FK_PORTC     
#define SSD_IO_DATA7_PIN                        FK_PIN7
#define SSD_IO_DATA7_LOW()                      FK_SET_OUTPUT_PIN_LOW_API(SSD_IO_DATA7_PORT,SSD_IO_DATA7_PIN)
#define SSD_IO_DATA7_HIGH()                     FK_SET_OUTPUT_PIN_HIGH_API(SSD_IO_DATA7_PORT,SSD_IO_DATA7_PIN)
#define SSD_IO_DATA7_TOGGLE()                   FK_SET_OUTPUT_PIN_TOGGLE_API(SSD_IO_DATA7_PORT,SSD_IO_DATA7_PIN)  
#define SSD_IO_DATA7_INIT()                     SSD_IO_DATA7_HIGH() //initial with CubeMX 
//==========================================   
//**********************************************************************************************************************
//
// M A C R O   D E F I N I T I O N 
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S 
//
//**********************************************************************************************************************
void ssd_io_sfr_init();
//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N 
//
//**********************************************************************************************************************
#ifdef __cplusplus
}
#endif
#endif		// SSD_IO_DRV_H 
