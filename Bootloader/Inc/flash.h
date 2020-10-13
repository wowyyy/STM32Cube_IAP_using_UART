////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Create by AnKun on 2019/10/10
 */

#ifndef __FLASH_H
#define __FLASH_H

#include "main.h"

//////////////////////////////////////////// ��ֲ�޸��� ///////////////////////////////////////////////

/* FLASH��С��128K */
#define STM32FLASH_SIZE  0x00020000UL

/* FLASH��ʼ��ַ */
#define STM32FLASH_BASE  FLASH_BASE

/* FLASH������ַ */
#define STM32FLASH_END   (STM32FLASH_BASE | STM32FLASH_SIZE)

/* FLASHҳ��С��1K */
#define STM32FLASH_PAGE_SIZE FLASH_PAGE_SIZE

/* FLASH��ҳ�� */
#define STM32FLASH_PAGE_NUM  (STM32FLASH_SIZE / STM32FLASH_PAGE_SIZE)

/* ��ȡҳ��ַ��X=0~STM32FLASH_PAGE_NUM */
#define ADDR_FLASH_PAGE_X(X)    (STM32FLASH_BASE | (X * STM32FLASH_PAGE_SIZE))


///////////////////////////////////// Bootloader �����ֲ�޸��� /////////////////////////////////////

typedef struct
{
	uint32_t fearure;
	uint32_t filesize;
	char filename[64];
}env_t;

#define ENV_FEATURE ((uint32_t)0xA1B2C3D4)

/* ����������ŵ�ַ */
#define ENV_ADDRESS  ADDR_FLASH_PAGE_X(127)

/* Ӧ�ó����ŵ�ַ */
#define APPLICATION_ADDRESS  ADDR_FLASH_PAGE_X(16)

/* Ӧ�ó���������� */
#define USER_FLASH_SIZE      0x8000

env_t* env_load(void);
int env_save(void);


/////////////////////////////////////////// ������������ ////////////////////////////////////////////
void FLASH_Init(void);
uint32_t FLASH_Read(uint32_t Address, uint16_t *Buffer, uint32_t NumToRead);
uint32_t FLASH_Write(uint32_t Address, const uint16_t *Buffer, uint32_t NumToWrite);

#endif // !__FLASH_H

//////////////////////////////////////////////////////// end of file ////////////////////////////////////////////////////////////////
