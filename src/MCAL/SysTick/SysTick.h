/**************************************************************************************
* FILE DESCRIPTION
* -------------------------------------------------------------------------------------
*					File: SYSTICK.H
*       Module: SYSTICK
*		
*	 Description: Header file for all SYSTICK related registers and APIs
*
*
***************************************************************************************/


#ifndef SYSTICK_H
#define SYSTICK_H


/*- INCLUDES
***************************************************************************************/
#include "types.h"
#include "BIT_MATH.h"
#include "stdio.h"


/*- SYSTICK PORTS' ADDRESSES
***************************************************************************************/
#define PER_BASE_ADDRESS						0xE000E000
#define STCTRL											(*((volatile uint32_t*)(PER_BASE_ADDRESS + (0x010)))) 
#define STRELOAD										(*((volatile uint32_t*)(PER_BASE_ADDRESS + (0x014)))) 
#define STCURRENT										(*((volatile uint32_t*)(PER_BASE_ADDRESS + (0x018)))) 


/*- SYSTICK REGISTERS' PINS
***************************************************************************************/
#define SYSTICK_ENABLE_PIN										0
#define SYSTICK_INTEN_PIN											1
#define SYSTICK_CLK_SRC_PIN										2
#define SYSTICK_USE_PIOSC_OSC_VAL							0
#define SYSTICK_USE_SYS_CLK_SRC_VAL						1
#define SYSTICK_COUNT_PIN											16


/*- CALLBACK FUNCTION
***************************************************************************************/

typedef void(*SysTick_cb_type)(void);
void SysTick_cb(SysTick_cb_type ptr);



/*- APIs
***************************************************************************************/
void SysTick_Init();

#endif /* SYSTICK.H */