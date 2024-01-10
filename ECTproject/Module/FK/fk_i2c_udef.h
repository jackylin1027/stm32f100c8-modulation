#ifndef FK_I2C_UDEF_H
#define FK_I2C_UDEF_H
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
// E X T E R N A L   G L O B A L   C O N S T A N C E   /   V A R I A B L E S   I N   E E P R O M
//
//**********************************************************************************************************************
#define FK_I2C_SPEED_100K		100000
#define FK_I2C_SPEED_200K		200000
#define	FK_I2C_SPEED_300K		300000
#define	FK_I2C_SPEED_400K		400000
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "..\Inc\main.h"
//#include "stm32l1xx.h"
#include "c_src\fk_idef.h"
#include "c_src\fk_init.h"
#include "c_src\fk_task.h"
#include "c_src\fk_glb_vars.h"
//**********************************************************************************************************************
//
// C O N D I C T I O N   C O M P I L E
//
//**********************************************************************************************************************
//========================================================================================================//
//! @brief I2C1 Bus use H/W Driver
//========================================================================================================//
//#define	FK_IIC_HW_INIT_API()						                                 iic_hw_init()
#define FK_I2C1_HW_TASK_API() 						                                    fk_i2c1_hw_task()
#define	FK_I2C1_HW_CHECK_TIMEOUT_API()						                            fk_i2c1_hw_check_timeout_func()//HTBC
#define	FK_I2C1_HW_BYTE_WRITE_API(addr,counter,data)  				                    fk_i2c1_hw_byte_write(addr,counter,data)
#define	FK_I2C1_HW_BYTE_READ_API(Addr_Counter,Addr_buf,Read_Counter,iic_hw_read_buf)  	fk_i2c1_hw_byte_read(Addr_Counter,Addr_buf,Read_Counter,iic_hw_read_buf)

//========================================================================================================//
//! @brief I2C Bus use I/O simulation
//========================================================================================================//
//! @brief Send data use I/O simulation
#define FK_I2C_IO_SEND_API(device_addr,data,len)	        		        fk_i2c_master_send(device_addr,data,len)
//! @brief Read data I/O simulation
#define FK_I2C_IO_READ_API(device_addr,data,len)				        fk_i2c_master_receive(device_addr,data,len)
//========================================================================================================//
//**********************************************************************************************************************
// I / O   P O R T   D E F I N I T I O N
//
//********************************************************************************************************************** 
#define FK_I2C1_HW_ENABLE_API(I2C_SPEED)				FK_I2C1_ENABLE_API(I2C_SPEED)
#define FK_I2C1_HW_START_API() 		 					FK_I2C1_START_API()
#define FK_I2C1_HW_STOP_API()							FK_I2C1_STOP_API()
#define FK_I2C1_HW_WRITE_API(data)						FK_I2C1_WRITE_API(data)
#define FK_I2C1_HW_READ_API()							FK_I2C1_READ_API()
#define FK_I2C1_HW_CHK_START_API()						FK_I2C1_CHK_START_API()
#define FK_I2C1_HW_CHK_TX_API()		 					FK_I2C1_CHK_TRANSMITTED_API()
#define FK_I2C1_HW_CHK_RX_API()		 					FK_I2C1_CHK_RECEIVED_API()
#define FK_I2C1_HW_CHK_7BITADDR_API()					FK_I2C1_CHK_7BIT_API()
#define FK_I2C1_HW_CHK_ACK_API()						FK_I2C1_CHK_ACK_API()
#define FK_I2C1_HW_SEND7BIT_ADDR(m_addr)				FK_I2C1_SEND7BIT_ADDR(m_addr)
#define FK_I2C1_HW_ACK_ENABLE_API()						FK_I2C1_ACK_ENABLE()
#define FK_I2C1_HW_CLEAR_FLAG_API()						FK_I2C1_CLEAR_AF_FLAG_API()


#define FK_I2C_IO_HAS_DELAY_WITH_EACH_COMMAND           1
  
#define FK_I2C_IO_1_SCL_PORT                         	FK_PORTB
#define FK_I2C_IO_1_SCL_PIN                          	FK_PIN6
#define FK_I2C_IO_1_SCL_INIT()                       	FK_SET_PIN_OUPUT_PUSH_PUMP_API(FK_I2C_IO_1_SCL_PORT,FK_I2C_IO_1_SCL_PIN)
            
#define FK_I2C_IO_1_SDA_PORT                         	FK_PORTB
#define FK_I2C_IO_1_SDA_PIN                          	FK_PIN7
#define FK_I2C_IO_1_SDA_INIT()                       	FK_SET_PIN_OUPUT_PUSH_PUMP_API(FK_I2C_IO_1_SDA_PORT,FK_I2C_IO_1_SDA_PIN)
  
//! @brief Check SDA state is high or low.                             
#define FK_I2C_IO_CHK_SDA_STATE()                    	FK_CHK_PIN_STATE_API(FK_I2C_IO_1_SDA_PORT,FK_I2C_IO_1_SDA_PIN) 
//! @brief Set SDA as output pin                                       
#define FK_I2C_IO_SET_SDA_OUT()                      	FK_SET_PIN_OUPUT_PUSH_PUMP_API(FK_I2C_IO_1_SDA_PORT,FK_I2C_IO_1_SDA_PIN)
//! @brief Set SDA as input pin                                        
#define FK_I2C_IO_SET_SDA_IN()                       	FK_SET_PIN_INPUT_FLOATING_API(FK_I2C_IO_1_SDA_PORT,FK_I2C_IO_1_SDA_PIN)
//! @brief Set SCL as output pin                                       
#define FK_I2C_IO_SET_SCL_OUT()                 		FK_SET_PIN_OUPUT_PUSH_PUMP_API(FK_I2C_IO_1_SCL_PORT,FK_I2C_IO_1_SCL_PIN) 
//! @brief Set SCL as input pin                                        
#define FK_I2C_IO_SET_SCL_IN()                       	FK_SET_PIN_INPUT_FLOATING_API(FK_I2C_IO_1_SCL_PORT,FK_I2C_IO_1_SCL_PIN) 
//! @brief Set high SCL pin                         
#define FK_I2C_IO_SCL_H()                            	FK_SET_OUTPUT_PIN_HIGH_API(FK_I2C_IO_1_SCL_PORT,FK_I2C_IO_1_SCL_PIN)
//! @brief Set low SCL pin                                             
#define FK_I2C_IO_SCL_L()                  				FK_SET_OUTPUT_PIN_LOW_API(FK_I2C_IO_1_SCL_PORT,FK_I2C_IO_1_SCL_PIN)
//! @brief Set high SDA pin                                            
#define FK_I2C_IO_SDA_H()                           	FK_SET_OUTPUT_PIN_HIGH_API(FK_I2C_IO_1_SDA_PORT,FK_I2C_IO_1_SDA_PIN)
//! @brief Set low SDA pin                                             
#define FK_I2C_IO_SDA_L()                            	FK_SET_OUTPUT_PIN_LOW_API(FK_I2C_IO_1_SDA_PORT,FK_I2C_IO_1_SDA_PIN)
//**********************************************************************************************************************
//
// A P I   F O R   O T H E R   M O D U L E S
//
//**********************************************************************************************************************
//**********************************************************************************************************************    
// I2C Function
#define FK_I2C1_ENABLE_API(speed)						fk_i2c_init(FK_I2C1,speed)
#define FK_I2C1_START_API()								I2C_GenerateSTART(I2C1,ENABLE)
#define FK_I2C1_STOP_API()								I2C_GenerateSTOP(I2C1,ENABLE)
#define FK_I2C1_WRITE_API(data)							I2C_SendData(I2C1,data)
#define FK_I2C1_READ_API()								I2C_ReceiveData(I2C1)
#define FK_I2C1_CHK_TRANSMITTED_API()					I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED)
#define FK_I2C1_CHK_RECEIVED_API()						I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_RECEIVED)
#define FK_I2C1_CHK_START_API()							I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT)
#define FK_I2C1_CHK_7BIT_API()							I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED)
#define FK_I2C1_ACK_ENABLE()							I2C_AcknowledgeConfig(I2C1, ENABLE);
#define FK_I2C1_ACK_DISABLE()							I2C_AcknowledgeConfig(I2C1,DISABLE);
#define FK_I2C1_SEND7BIT_ADDR(m_addr)					I2C_Send7bitAddress(I2C1,m_addr,I2C_Direction_Transmitter);
#define FK_I2C1_CHK_ACK_API()							I2C_CheckEvent(I2C1, I2C_EVENT_SLAVE_ACK_FAILURE)
#define FK_I2C1_CLEAR_AF_FLAG_API()						I2C_ClearFlag(I2C1,I2C_FLAG_AF);

#define FK_I2C2_ENABLE_API(speed)						fk_i2c_init(FK_I2C2,speed)
#define FK_I2C2_START_API()								I2C_GenerateSTART(I2C2,ENABLE)
#define FK_I2C2_STOP_API()								I2C_GenerateSTOP(I2C2,ENABLE)
#define FK_I2C2_WRITE_API(data)							I2C_SendData(I2C2,data)
#define FK_I2C2_READ_API()								I2C_ReceiveData(I2C2)
#define FK_I2C2_CHK_TRANSMITTED_API()					I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_TRANSMITTED)
#define FK_I2C2_CHK_RECEIVED_API()						I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_RECEIVED)
#define FK_I2C2_CHK_START_API()							I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_MODE_SELECT)
#define FK_I2C2_CHK_7BIT_API()							I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED)
#define FK_I2C2_ACK_ENABLE()							I2C_AcknowledgeConfig(I2C2, ENABLE)
#define FK_I2C2_ACK_DISABLE()							I2C_AcknowledgeConfig(I2C2,DISABLE)
#define FK_I2C2_SEND7BIT_ADDR(m_addr)					I2C_Send7bitAddress(I2C2,m_addr,I2C_Direction_Transmitter)
#define FK_I2C2_CHK_ACK_API()							I2C_CheckEvent(I2C2, I2C_EVENT_SLAVE_ACK_FAILURE)
#define FK_I2C2_CLEAR_AF_FLAG_API()						I2C_ClearFlag(I2C2,I2C_FLAG_AF)
#define FK_I2C_TOTAL_ENABLE_API(speed)					fk_i2c_init(FK_I2C_TOTAL,UINT32 speed)
//**********************************************************************************************************************
//
// A P I   F O R   O T H E R   M O D U L E S
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// F U N C T I O N   P R O T O T Y P E S
//
//**********************************************************************************************************************

//**********************************************************************************************************************
//
// C   P L U S   P L U S   C O M P A T I A B L E   D E F I N I T I O N
//
//**********************************************************************************************************************
#ifdef __cplusplus
}
#endif
#endif		// FK_I2C_UDEF_H 
