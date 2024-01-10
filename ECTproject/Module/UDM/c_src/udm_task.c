//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @file 		 udm_task.c
//
//! @author 	 Willman Chen
//
//! @date 		 2009/07/14
//
//  @brief 		 Task Subroutine
//
//**********************************************************************************************************************
//**********************************************************************************************************************
//
// I N C L U D E   F I L E S   /   E X T E R N A L   V A R I A B L E S
//
//**********************************************************************************************************************
#include "..\drv_src\udm_drv.h"
#include "udm_glb_vars.h"
//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 		 udm_prompt_string
//
//! @author 	 Willman Chen
//
//! @date 		 2009/07/14
//
//! @brief 		 Get Prompt string by the prompt index
//
//! @param 		 prompt the prompt index
//
//! @return 	 the address of the string
//
//**********************************************************************************************************************
UINT8* udm_prompt_string(UINT32 prompt,UINT8 language)
{
    UINT8 *str;
    UINT32 offset;
    UINT32 addr;
    switch (language)
    {
    case UDM_ENGLISH:
    {
        addr=prompt-UDM_PROMPT_START;
        addr<<=1;
        offset=(gs_udm_rom_prompt[addr+1]<<8)|gs_udm_rom_prompt[addr];
        str=(UINT8 *)&gs_udm_rom_prompt[offset];
        break;
    }
#if UDM_USE_TRADITIONAL_CHINESE ==1
    case UDM_TRADICTIONAL:
    {
        str=(UINT8*)gw_udm_traditional_chinese_prompt[prompt-UDM_PROMPT_START];
        break;
    }
#endif
#if UDM_USE_SIMPLE_CHINESE == 1
    case UDM_SIMPLE:
    {
        str=(UINT8*)gw_udm_simple_chinese_prompt[prompt-UDM_PROMPT_START];
        break;
    }
#endif
    }
    return str;
}

//**********************************************************************************************************************
//
// Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved
//
//! @fn 		 udm_get_prompt_len
//
//! @author 	 Willman Chen
//
//! @date 		 2009/07/14
//
//! @brief 		 Get the length of prompt string
//
//! @param 		 prompt the prompt index
//
//! @return 	 the length of the prompt string
//
//**********************************************************************************************************************
UINT8 udm_get_prompt_len(UINT32 prompt,UINT8 language)
{
    UINT8 len;
    UINT8 *str=udm_prompt_string(prompt,language);
    switch (language)
    {
    case UDM_ENGLISH:
    {
        for (len=0; *str; str++)
            len++;
        break;
    }
#if UDM_USE_TRADITIONAL_CHINESE ==1
    case UDM_TRADICTIONAL:
    {
        len=UDM_GET_SYMB_W_API(gw_udm_traditional_chinese_prompt[prompt-UDM_PROMPT_START]);
        break;
    }
#endif
#if UDM_USE_SIMPLE_CHINESE ==1
    case UDM_SIMPLE:
    {
        len=UDM_GET_SYMB_W_API(gw_udm_simple_chinese_prompt[prompt-UDM_PROMPT_START]);
        break;
    }
#endif
    }
    return len;
}
