#ifndef INTCTRL_H
#define INTCTRL_H

/**************************************************************************************
* FILE DESCRIPTION
* -------------------------------------------------------------------------------------
*					File: INTCTRL.H
*       Module: INTCTRL
*		
*	 Description: header file for all Interrupt Control related registers and APIs
*
*
***************************************************************************************/


/*- INCLUDES
***************************************************************************************/
#include "types.h"
#include "BIT_MATH.h"
#include "IntCtrl_Config.h"
#include "stdio.h"
#include "GPIO.h"



/*- INT_CTRL PORTS' ADDRESSES
***************************************************************************************/

#define CORE_PER_BASE_ADD															0xE000E000
#define APINT																(*((volatile uint32_t*)(CORE_PER_BASE_ADD + (0xD0C))))  	
#define SWTRIG															(*((volatile uint32_t*)(CORE_PER_BASE_ADD + (0xF00))))	

#define PRIx(x)  														(*((volatile uint32_t*)(CORE_PER_BASE_ADD+((0x0400+((x/4)*4))))))
#define ENx(x)  														(*((volatile uint32_t*)(CORE_PER_BASE_ADD+((0x0100+((x/32)*32))))))
#define DISx(x)  														(*((volatile uint32_t*)(CORE_PER_BASE_ADD+((0x0180+((x/32)*32))))))

/*- INT_CTRL REGISTERS
***************************************************************************************/


/*- CONSTANTS
***************************************************************************************/

/*- APINT-related
*******************/
#define APINT_VECTKEY_POS															16
#define APINT_VECTKEY                                 0x05FA
#define APINT_PRIGROUP_POS														8 

/*- API TYPES
***************************************************************************************/
typedef enum
{
	USE_8_GROUPS_0_SUBGROUPS = 4, USE_4_GROUPS_2_SUBGROUPS, USE_2_GROUPS_4_SUBGROUPS, USE_0_GROUPS_8_SUBGROUPS
}EN_IntCtrl_GroupSubGroupType_t;

typedef enum
{
	INTCTRL_PORTA_INT_NUM=0, INTCTRL_PORTB_INT_NUM, INTCTRL_PORTC_INT_NUM, 
	INTCTRL_PORTD_INT_NUM, INTCTRL_PORTE_INT_NUM, INTCTRL_PORTF_INT_NUM=30
}EN_IntCtrl_PortsIntNum_t;

typedef enum
{
	INTCTRL_LEVEL_TRIGGERED, INTCTRL_EDGE_TRIGGERED
}En_IntCtrl_InterruptSense;

typedef enum
{
	INTCTRL_FALLING, INTCTRL_RISING, INTCTRL_BOTH_EDGES
}En_IntCtrl_InterruptChangeType;


typedef uint8_t InterruptPriority_t;

typedef struct
{
	EN_IntCtrl_PortsIntNum_t 							IntNum;
	InterruptPriority_t 									IntPriority;
	EN_IntCtrl_GroupSubGroupType_t 				GroupSubGroupPriority;
	En_IntCtrl_InterruptSense      				IntCtrlSense;
	En_IntCtrl_InterruptChangeType				IntChangeType;
	EN_GPIO_PortNum_t											PortNum;
	EN_GPIO_ChannelNum_t									PinNum;
}ST_IntCtrl_ConfigType_t;



/*- FUNCTIONS' PROTOTYPES
***************************************************************************************/
void IntCtrl_SetPriorityGrouping(EN_IntCtrl_GroupSubGroupType_t PriorityGroupSubGroup);
void IntCtrl_SetPriority(EN_IntCtrl_PortsIntNum_t IntNum, uint8_t IntPriority);
void IntCtrl_EnableInterrupt(EN_IntCtrl_PortsIntNum_t IntNum);
void IntCtrl_DisableInterrupt(EN_IntCtrl_PortsIntNum_t IntNum);

/* APIs
****************************************************************************************/
void IntCtrl_Init(const ST_IntCtrl_ConfigType_t* IntCtrlConfigPtr);

#endif /* INTCTRL.H */