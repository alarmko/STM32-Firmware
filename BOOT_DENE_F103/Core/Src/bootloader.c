/*
 * bootloader.c
 *
 *  Created on: Oct 16, 2020
 *      Author: Viktor Vano
 */

#include "bootloader.h"

void jumpToApp(const uint32_t address) // DIGER PROGRAMA ATLANIYOR
{
	const JumpStruct* vector_p = (JumpStruct*)address;
	deinitEverything();
    asm("msr msp, %0; bx %1;" : : "r"(vector_p->stack_addr), "r"(vector_p->func_p));
}

void deinitEverything()  //DEINIT ISLEMI YAPILIYOR,INIT YAPILANLAR TERS SIRADA DEINIT YAPILACAK
{
	//-- reset peripherals to guarantee flawless start of user application
	HAL_GPIO_DeInit(LED_GPIO_Port, LED_Pin);
//	HAL_GPIO_DeInit(USB_ENABLE_GPIO_Port, USB_ENABLE_Pin);
//	USBD_DeInit(&hUsbDeviceFS);
	  __HAL_RCC_GPIOC_CLK_DISABLE();
	  __HAL_RCC_GPIOD_CLK_DISABLE();
	  __HAL_RCC_GPIOB_CLK_DISABLE();
	  __HAL_RCC_GPIOA_CLK_DISABLE();
	HAL_RCC_DeInit();
	HAL_DeInit();
	SysTick->CTRL = 0;
	SysTick->LOAD = 0;
	SysTick->VAL = 0;
}


