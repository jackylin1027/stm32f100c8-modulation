#ifndef FK_UART_UDEF_H
#define FK_UART_UDEF_H
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

//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "..\Inc\main.h"
#include "c_src\fk_idef.h"
#include "c_src\fk_init.h"
#include "c_src\fk_task.h"
#include "c_src\fk_glb_vars.h" 
//**********************************************************************************************************************
//
// C O N D I C T I O N   C O M P I L E
//
//**********************************************************************************************************************

//**********************************************************************************************************************
//
// A P I   F O R   O T H E R   M O D U L E S
//
//**********************************************************************************************************************
//**It is commonly used function*//
// UART Function
//! @brief Initial default UART1 function as interrupt mode
#define FK_UART1_INTERRUPT_API(baudrate,bits,stop_bits,parity,tx_func,rx_func)	fk_hal_uart_init(FK_UART1_DEFAULT,baudrate,bits,stop_bits,parity,FK_UART_INTERRUPT_MODE,(UINT8(*)())tx_func,rx_func)
//! @brief The API for Sending out data by default UART1 pins
#define FK_UART1_SEND_BYTE_API(byte)					        (&fk_usart1)->Instance->DR=byte	
//! @brief The API for UART1 Receving data
#define FK_UART1_GET_DATA_API()	                                                (&fk_usart1)->Instance->DR
//! @brief The API for starting UART1 transfer interrupt
#define FK_UART1_TX_INTERRUPT_ENABLE_API()					__HAL_UART_ENABLE_IT(&fk_usart1, UART_IT_TXE)
//! @brief The API for stoping UART1 transfer interrupt
#define FK_UART1_TX_INTERRUPT_DISABLE_API()					__HAL_UART_DISABLE_IT(&fk_usart1, UART_IT_TXE)
//! @brief The API for UART2 waitting send out finish
#define FK_UART1_TX_WAIT_API()					                while(__HAL_UART_GET_FLAG(&fk_usart1,UART_FLAG_TC) == RESET)
//! @brief The PI for starting USART1 receive interrupt and locate relation array 
#define FK_UART1_RX_INTERRUPT_ENABLE_API(array)                                 UART_Start_Receive_IT(&fk_usart1,array,sizeof(array))  
  
//! @brief Initial default UART2 function as interrupt mode
#define FK_UART2_INTERRUPT_API(baudrate,bits,stop_bits,parity,tx_func,rx_func)  fk_hal_uart_init(FK_UART2_DEFAULT,baudrate,bits,stop_bits,parity,FK_UART_INTERRUPT_MODE,(UINT8(*)())tx_func,rx_func)
//! @brief Sending out data by default UART2 pins
#define FK_UART2_SEND_BYTE_API(byte)                                            (&fk_usart2)->Instance->DR=byte	
//! @brief The API for UART2 Receving data
#define FK_UART2_GET_DATA_API()                                                 (&fk_usart2)->Instance->DR
//! @brief The API for starting UART1 transfer interrupt
#define FK_UART2_TX_INTERRUPT_ENABLE_API()                                      __HAL_UART_ENABLE_IT(&fk_usart2, UART_IT_TXE)
//! @brief The API for stoping UART1 transfer interrupt
#define FK_UART2_TX_INTERRUPT_DISABLE_API()                                     __HAL_UART_DISABLE_IT(&fk_usart2, UART_IT_TXE)
//! @brief The API for UART2 waitting send out finish
#define FK_UART2_TX_WAIT_API()                                                  while(__HAL_UART_GET_FLAG(&fk_usart2,UART_FLAG_TC) == RESET)
//! @brief The PI for starting USART2 receive interrupt and locate relation array 
#define FK_UART2_RX_INTERRUPT_ENABLE_API(array)                                 UART_Start_Receive_IT(&fk_usart2,array,sizeof(array))                      
  

//**It is not commonly used function*//  
//! @brief Initial default UART1 function as polling mode
#define FK_UART1_POLLING_API(baudrate,bits,stop_bits,parity)                          	fk_uart_init(FK_UART1_DEFAULT,baudrate,bits,stop_bits,parity,FK_UART_POLLING_MODE,(UINT8(*)())fk_null,fk_null)  
//! @brief Initial remap UART1 function as polling mode
#define FK_UART1_REMAP_POLLING_API(baudrate,bits,stop_bits,parity)                    	fk_uart_init(FK_UART1_REMAP,baudrate,bits,stop_bits,parity,FK_UART_POLLING_MODE,(UINT8(*)())fk_null,fk_null)
//! @brief Initial remap UART1 function as interrupt mode
#define FK_UART1_REMAP_INTERRUPT_API(baudrate,bits,stop_bits,parity,tx_func,rx_func)    fk_uart_init(FK_UART1_REMAP,baudrate,bits,stop_bits,parity,FK_UART_INTERRUPT_MODE,tx_func,rx_func)
//! @brief The API for Sending out data by remap UART1 pins
#define FK_UART1_REMAP_SEND_BYTE_API(byte)                                            	USART_SendData((USART_TypeDef*)gt_fk_uart_name[FK_UART1_REMAP],byte)
#define FK_UART1_REMAP_TX_DMA_API(baudrate,bits,stop_bits,parity,buf,size,func)         fk_uart_init(FK_UART1_REMAP,baudrate,bits,stop_bits,parity,FK_UART_POLLING_MODE,(UINT8(*)())fk_null,fk_null)//fk_uart_tx_dma_init(FK_UART1_REMAP,baudrate,bits,stop_bits,parity,FK_DMA_CHANNEL2,buf,size,func);  

  

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
#endif		// FK_UART_UDEF_H 
