/*
 * flashchange.c
 *
 *  Created on: May 3, 2018
 *      Author: Joel
 */
#include <string.h>
#include "stm32l4xx_hal.h"
//#include "stm32l4xx_nucleo.h"
//#include "gpio_defines.h"
#include "stm32l4xx_hal_flash.h"
//#include "aux.h"
#include "flashchange.h"


#define FLASH_BASE_ADDR	0x08000000
#define FLASH_WORD_SIZE 4

//extern FLASH_OBProgramInitTypeDef    *pOBInit;
//extern CRC_HandleTypeDef hcrc;


/*
 * @brief Change bank of flash memory to load new firmware at next reboot
 * @param None
 * @retval None
 */
void change_bank()
{
	FLASH_OBProgramInitTypeDef  OBInit;
	FLASH_OBProgramInitTypeDef  *pOBInit = &OBInit;
	/* Set BFB2 bit to enable boot from Flash Bank2 */
	HAL_FLASH_Unlock();								/* Allow Access to Flash control registers and user Flash */
	__HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_OPTVERR);		/* Clear OPTVERR bit set on virgin samples */
	//__HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_ALL_ERRORS);
	HAL_FLASH_OB_Unlock();							/* Allow Access to option bytes sector */
	HAL_FLASHEx_OBGetConfig(pOBInit);				/* Get the Dual boot configuration status */

	/* Enable/Disable dual boot feature */
	pOBInit->OptionType = OPTIONBYTE_USER;
	pOBInit->USERType   = OB_USER_BFB2;

	if (((pOBInit->USERConfig) & (OB_BFB2_ENABLE)) == OB_BFB2_ENABLE)
	{
		_debug("Dual boot is enabled... disable");
		pOBInit->USERConfig = OB_BFB2_DISABLE;
	}
	else
	{
		_debug("Dual boot is disabled ... enable");
		pOBInit->USERConfig = OB_BFB2_ENABLE;
	}

	if(HAL_FLASHEx_OBProgram (pOBInit) != HAL_OK)
	{
		/*
        Error occurred while setting option bytes configuration.
        User can add here some code to deal with this error.
        To know the code error, user can call function 'HAL_FLASH_GetError()'
		 */
		/* Infinite loop */
		while (1)
		{
			_debug("Error");
			/* Make LED2 blink (100ms on, 2s off) to indicate error */
			//BSP_LED_On(LED2);
			HAL_Delay(100);
			//BSP_LED_Off(LED2);
			HAL_Delay(2000);
		}
	}
	else {
		HAL_FLASHEx_OBGetConfig(pOBInit);
		if (((pOBInit->USERConfig) & (OB_BFB2_ENABLE)) == OB_BFB2_ENABLE)
		{_debug("Dual boot is enabled now");}
		else
		{_debug("Dual boot is disabled now");}
	}

	/* Start the Option Bytes programming process */
	if (HAL_FLASH_OB_Launch() != HAL_OK)
	{
		/*
        Error occurred while reloading option bytes configuration.
        User can add here some code to deal with this error.
        To know the code error, user can call function 'HAL_FLASH_GetError()'
		 */
		/* Infinite loop */
		while (1)
		{
			_debug("Error");
			/* Make LED2 blink (100ms on, 2s off) to indicate error */
			//BSP_LED_On(LED2);
			HAL_Delay(100);
			//BSP_LED_Off(LED2);
			HAL_Delay(2000);
		}
	}
}


uint32_t read_flash_register(uint32_t addr)
{
	return *((uint32_t *) addr);
}


/**
 * @brief  Gets the bank of a given address
 * @param  Addr: Address of the FLASH Memory
 * @retval The bank of a given address
 */
uint32_t get_current_bank()
{
  uint32_t bank = (READ_BIT(SYSCFG->MEMRMP, SYSCFG_MEMRMP_FB_MODE)) ? FLASH_BANK_2 : FLASH_BANK_1;
  return bank;
}

uint32_t read_flash_word(uint32_t page_number, uint32_t word_number)
{
	uint32_t address = FLASH_BASE_ADDR + page_number*FLASH_PAGE_SIZE + FLASH_WORD_SIZE*word_number;
	return *((uint32_t *) address);
}

uint8_t other_bank_flash_page_erase(uint8_t page_number) {
	uint8_t status = 0;
	//	uint32_t FirstPage = 0;
	uint32_t NbOfPages = 0, BankNumber = 0;
	//	uint32_t Address = 0;
	uint32_t PAGEError = 0;
	FLASH_EraseInitTypeDef EraseInitStruct;

	HAL_FLASH_Unlock();
	__HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_OPTVERR);/* Clear OPTVERR bit set on virgin samples */
	//FirstPage = GetPage(FLASH_USER_START_ADDR);/* Get the 1st page to erase */
	//_debug_uint32_val(FirstPage);
	NbOfPages = 1; //GetPage(FLASH_USER_END_ADDR) - FirstPage + 1;/* Get the number of pages to erase from 1st page */
	/* Get the bank */

	BankNumber = (FLASH_BANK_1==get_current_bank()) ? FLASH_BANK_2 : FLASH_BANK_1;
	uint32_t page_start_addr = FLASH_BASE_ADDR + page_number*FLASH_PAGE_SIZE;
	if (FLASH_BANK_2 == BankNumber) {
		page_start_addr += FLASH_BANK_SIZE;  // write to bank 2 page
	}
	/* Fill EraseInit structure*/
	EraseInitStruct.TypeErase   = FLASH_TYPEERASE_PAGES;
	EraseInitStruct.Banks       = BankNumber;
	EraseInitStruct.Page        = (uint32_t) page_number;
	EraseInitStruct.NbPages     = NbOfPages;

	/* Note: If an erase operation in Flash memory also concerns data in the data or instruction cache,
     you have to make sure that these data are rewritten before they are accessed during code
     execution. If this cannot be done safely, it is recommended to flush the caches by setting the
     DCRST and ICRST bits in the FLASH_CR register. */
	if (HAL_FLASHEx_Erase(&EraseInitStruct, &PAGEError) != HAL_OK)
	{
		/*
      Error occurred while page erase.
      User can add here some code to deal with this error.
      PAGEError will contain the faulty page and then to know the code error on this page,
      user can call function 'HAL_FLASH_GetError()'
		 */
		/* Infinite loop */
		status = 1;
		/*while (1)
		{
			BSP_LED_On(LED2);
			HAL_Delay(100);
			BSP_LED_Off(LED2);
			HAL_Delay(2000);
		}*/
	}
	else {
	}
	HAL_FLASH_Lock();
	return status;
}

uint8_t other_bank_flash_page_program(uint8_t *pbuf, uint32_t buf_len, uint8_t page_number)
{
	/*if ((buf_len > FLASH_PAGE_SIZE) || (0==buf_len))
	{
		return ERROR_BUF_LEN;
	}

	if (page_number > FLASH_LAST_PAGE)
	{
		return ERROR_FLASH_PAGE_NUMBER;
	}*/

	uint8_t status = 0;
	/* Program the user Flash area word by word
    (area defined by FLASH_USER_START_ADDR and FLASH_USER_END_ADDR) ***********/
	uint32_t page_start_addr = FLASH_BASE_ADDR + page_number*FLASH_PAGE_SIZE;
	//if (FLASH_BANK_1 == GetCurrentBank()) {
	page_start_addr += FLASH_BANK_SIZE;  // write to bank 2 page
	//}
	uint32_t Address = page_start_addr;
	//	uint64_t DATA_64 = 0x1122334455667788;
	uint64_t u64_data = 0;
	HAL_Delay(100);

	HAL_FLASH_Unlock();
	while (Address < page_start_addr+buf_len)
	{
		HAL_Delay(1);
		memcpy(&u64_data, pbuf, sizeof u64_data);
		//		u64_data += pbuf;
		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, Address, u64_data) == HAL_OK)
		{
			Address += sizeof u64_data;
			pbuf    += sizeof u64_data;
		}
		else
		{
			/* Error occurred while writing data in Flash memory.
         User can add here some code to deal with this error */
			status = 1;
			break;
			/*while (1)
			{
				BSP_LED_On(LED2);
				HAL_Delay(100);
				BSP_LED_Off(LED2);
				HAL_Delay(2000);
			}
			 */
		}
	}
	if (0==status)
	{
	}

	/* Lock the Flash to disable the flash control register access (recommended
     to protect the FLASH memory against possible unwanted operation) *********/
	HAL_FLASH_Lock();
	return status;
}

void flash_page_rewrite(uint8_t *pbuf, uint32_t buf_len, uint8_t page_num)
{
	other_bank_flash_page_erase(page_num);
	HAL_Delay(100);
	other_bank_flash_page_program(pbuf, buf_len, page_num);
}

void test_flash_program()
{
	_debug("Start FLASH PROGRAMMING\r\n");
	uint8_t global_buf[2049] = {0,};
	uint8_t page_num = 3;
	flash_page_rewrite(global_buf, 2048, page_num);
	_debug("End FLASH PROGRAMMING\r\n");
}


