/**************************************************************************************
* FILE DESCRIPTION
* -------------------------------------------------------------------------------------
*					File: INTCTRL.C
*       Module: INTCTRL
*		
*	 Description: Source file for InterruptControl Functions/APIs Declaration
*
*
***************************************************************************************/


/*- INCLUDES
***************************************************************************************/

#include "IntCtrl.h"

/* FUNCTIONS' DECLARATION
****************************************************************************************/

void IntCtrl_SetPriorityGrouping(EN_GroupSubGroupType_t PriorityGroupSubGroup)
{
	APINT = (APINT_VECTKEY<<APINT_VECTKEY_POS);
	uint8_t PriorityGroupSubGroup_temp = ( (uint8_t)PriorityGroupSubGroup &(7U) );
	APINT |= (PriorityGroupSubGroup_temp<<APINT_PRIGROUP_POS);
}

void IntCtrl_SetPriority(InterruptNum_t IntNum, uint8_t IntPriority)
{
	uint8_t InterruptPriority_temp = ((IntPriority & (0x07) ) << 5);
	uint8_t IntPriorityStartBit = ( (IntNum%4) * (8) );
	PRIx(IntNum) |= (InterruptPriority_temp << IntPriorityStartBit);
}

void IntCtrl_EnableInterrupt(InterruptNum_t IntNum)
{
	ENx(IntNum);
}

void IntCtrl_DisableInterrupt(InterruptNum_t IntNum)
{
	DISx(IntNum);
}

/*- APIS' DECLARATION
*****************************************************************************************/

void IntCtrl_Init()
{
	
}