#include "GPT.h"

void Gpt_Init (const GPT_ConfigType* ConfigPtr)
{
	uint8_t u8_TimerCounter = 0;
	for(u8_TimerCounter = 0; u8_TimerCounter<TIMERS_NUM; u8_TimerCounter++)
	{
		GPT_Channel_Number ChannelId = ConfigPtr[u8_TimerCounter].ChannelId;
		
		SET_BIT(RCGCTIMER, ChannelId);
		CLR_BIT(GPTMCTL(ChannelId), TAEN);
		
		
		switch(ConfigPtr[u8_TimerCounter].ChannelLength)
		{
			case GPT_NORMAL_16:
				GPTMCFG(ChannelId) = GPT_NORMAL_16_VALUE;
				break;
			
			case GPT_NORMAL_32:
				GPTMCFG(ChannelId) = GPT_NORMAL_32_VALUE;
				break;
			
			case GPT_WIDE_32:
				GPTMCFG(ChannelId) = GPT_WIDE_32_VALUE;
				break;
			
			case GPT_WIDE_64:
				GPTMCFG(ChannelId) = GPT_WIDE_64_VALUE;
				break;
			
			default:
				#warning "other configurations aren't supported yet"
				break;
		}
		
		
		switch(ConfigPtr[u8_TimerCounter].ChannelMode)
		{
			case GPT_ONE_SHOT_MODE:
				GPTMTAMR(ChannelId) |= (ONE_SHOT_TIMER_MODE<<TAMR_START_BIT);
				break;
			
			case GPT_PERIODIC_MODE:
				GPTMTAMR(ChannelId) |= (PERIODIC_TIMER_MODE<<TAMR_START_BIT);
				break;
			
			default:
				#warning "other configurations aren't supported yet"
				break;
		}
		
		GPTMTAPR(ChannelId) = 250-1;
		GPTMTAILR(ChannelId) = 64000-1;
		SET_BIT(GPTMICR(ChannelId), TATOCINT);
		SET_BIT(GPTMIMR(ChannelId) ,TATOIM);
		
		SET_BIT(GPTMCTL(ChannelId), TAEN);
	}
}

void Gpt_StartTimer (EN_GPIO_ChannelNum_t ChannelId, maxTickValue_t MaxTickValue)
{
	SET_BIT(GPTMCTL(ChannelId), TAEN);
}

void Gpt_StopTimer (EN_GPIO_ChannelNum_t ChannelId)
{
	CLR_BIT(GPTMCTL(ChannelId), TAEN);
}