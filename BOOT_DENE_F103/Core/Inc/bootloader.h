/*
 * bootloader.h
 *
 *  Created on: Oct 16, 2020
 *      Author: vikto
 */

#ifndef INC_BOOTLOADER_H_
#define INC_BOOTLOADER_H_
//#define START_ADRES (0x08002000)			//Origin + Bootloader size (20kB)
#include "main.h"
typedef void (application_t)(void);
typedef struct
{
    uint32_t		stack_addr;     // Stack Pointer
    application_t*	func_p;        // Program Counter
} JumpStruct;
uint32_t Flashed_offset;
void jumpToApp();
void deinitEverything();
#endif /* INC_BOOTLOADER_H_ */
