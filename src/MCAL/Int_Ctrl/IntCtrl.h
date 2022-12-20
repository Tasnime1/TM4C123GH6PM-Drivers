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
}EN_GroupSubGroupType_t;

typedef uint8_t InterruptNum_t;
typedef uint8_t InterruptPriority_t;

typedef struct
{
	InterruptNum_t IntNum;
	InterruptPriority_t IntPriority;
	EN_GroupSubGroupType_t GroupSubGroupNum;
}ST_IntCtrl_ConfigType_t;



/*- FUNCTIONS' PROTOTYPES
***************************************************************************************/
void IntCtrl_SetPriorityGrouping(EN_GroupSubGroupType_t PriorityGroupSubGroup);
void IntCtrl_SetPriority(InterruptNum_t IntNum, uint8_t IntPriority);
void IntCtrl_EnableInterrupt(InterruptNum_t IntNum);
void IntCtrl_DisableInterrupt(InterruptNum_t IntNum);

/* APIs
****************************************************************************************/
void IntCtrl_Init();

#endif /* INTCTRL.H */