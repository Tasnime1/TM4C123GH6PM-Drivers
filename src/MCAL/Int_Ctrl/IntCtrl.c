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

void IntCtrl_SetPriorityGrouping(EN_IntCtrl_GroupSubGroupType_t PriorityGroupSubGroup)
{
	APINT = (APINT_VECTKEY<<APINT_VECTKEY_POS);
	uint8_t PriorityGroupSubGroup_temp = ( (uint8_t)PriorityGroupSubGroup &(7U) );
	APINT |= (PriorityGroupSubGroup_temp<<APINT_PRIGROUP_POS);
}

void IntCtrl_SetPriority(EN_IntCtrl_PortsIntNum_t IntNum, uint8_t IntPriority)
{
	uint8_t InterruptPriority_temp = ((IntPriority & (0x07) ) << 5);
	uint8_t IntPriorityStartBit = ( (IntNum%4) * (8) );
	PRIx(IntNum) |= (InterruptPriority_temp << IntPriorityStartBit);
}

void IntCtrl_EnableInterrupt(EN_IntCtrl_PortsIntNum_t IntNum)
{
	SET_BIT(ENx(IntNum), IntNum%32);
}

void IntCtrl_DisableInterrupt(EN_IntCtrl_PortsIntNum_t IntNum)
{
	SET_BIT(DISx(IntNum), IntNum%32);
}

/*- APIS' DECLARATION
*****************************************************************************************/

void IntCtrl_Init(const ST_IntCtrl_ConfigType_t* IntCtrlConfigPtr)
{
	uint8_t u8_InterruptsCounter = 0;
	for(u8_InterruptsCounter =0 ; u8_InterruptsCounter < INTS_NUM ; u8_InterruptsCounter++)
	{
		EN_IntCtrl_PortsIntNum_t IntNum = IntCtrlConfigPtr[u8_InterruptsCounter].IntNum;
		EN_GPIO_PortNum_t PortNum = IntCtrlConfigPtr[u8_InterruptsCounter].PortNum;
		EN_GPIO_ChannelNum_t PinNum = IntCtrlConfigPtr[u8_InterruptsCounter].PinNum;
		
		if(u8_InterruptsCounter == 0)
		{
			IntCtrl_SetPriorityGrouping(IntCtrlConfigPtr[u8_InterruptsCounter].GroupSubGroupPriority);
		}
		IntCtrl_SetPriority(IntNum, IntCtrlConfigPtr[u8_InterruptsCounter].IntPriority);
		
		switch(IntCtrlConfigPtr[u8_InterruptsCounter].IntCtrlSense)
		{
			case INTCTRL_LEVEL_TRIGGERED:
				SET_BIT(GPIOIS(PortNum), PinNum);
				break;
			
			case INTCTRL_EDGE_TRIGGERED:
				CLR_BIT(GPIOIS(PortNum), PinNum);
				break;
			
			default:
				#warning "WRONG INTERRUPT SENSE ENTERED"
				break;
		}
		
		
		switch(IntCtrlConfigPtr[u8_InterruptsCounter].IntChangeType)
		{
			case INTCTRL_FALLING:
				CLR_BIT(GPIOIBE(PortNum), PinNum);
				SET_BIT(GPIOIEV(PortNum), PinNum);
				break;
			
			case INTCTRL_RISING:
				CLR_BIT(GPIOIBE(PortNum), PinNum);
				CLR_BIT(GPIOIEV(PortNum), PinNum);
				break;
			case INTCTRL_BOTH_EDGES:
				SET_BIT(GPIOIBE(PortNum), PinNum);
				break;
			
			default:
				#warning "WRONG INTERRUPT CHANGE TRIGGER ENTERED"
				break;
		}
		
		SET_BIT(GPIOICR(PortNum), PinNum);
		SET_BIT(GPIOIM(PortNum), PinNum);
		
		IntCtrl_EnableInterrupt(IntNum);
	}
}