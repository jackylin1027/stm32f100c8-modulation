#ifndef FK_FLASH_UDEF_H
#define FK_FLASH_UDEF_H
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
// FLASH Function
//! @brief The API for writting data into flash ( user space )
#define FK_WRITE_USER_DATA_API(buf,size)                          	            fk_write_flash(FK_USER_START_PAGE,buf,size)

//! @brief The API for reading data from flash ( user space )
#define FK_READ_USER_DATA_API(buf,size)                           	            fk_read_flash(FK_USER_START_PAGE,buf,size)

//! @brief The API for writting data into flash ( factory space )
#define FK_WRITE_FACTORY_DATA_API(buf,size)                       	            fk_write_flash(FK_FACTORY_START_PAGE,buf,size)

//! @brief The API for reading data from flash ( factory space )
#define FK_READ_FACTORY_DATA_API(buf,size)                        	            fk_read_flash(FK_FACTORY_START_PAGE,buf,size)

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
#endif		// FK_FLASH_UDEF_H 
