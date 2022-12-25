#ifndef GPT_H
#define GPT_H

/**************************************************************************************
* FILE DESCRIPTION
* -------------------------------------------------------------------------------------
*					File: GPT.H
*       Module: GPT
*		
*	 Description: header file for all GPT related registers and APIs
*
*
***************************************************************************************/


/*- INCLUDES
***************************************************************************************/
#include "types.h"
#include "BIT_MATH.h"
#include "GPT_cfg.h"
#include "stdio.h"
#include "GPIO.h"

/*- GPIO PORTS' ADDRESSES
***************************************************************************************/

#define TIMER
//#define WIDE_TIMER

#if defined(TIMER)
#define TIMERx(x)               	    ((0x40030000)+((x)*0x1000))
#define TIMER_0_ADDRESS																0X40030000
#define TIMER_1_ADDRESS																0X40031000
#define TIMER_2_ADDRESS																0X40032000
#define TIMER_3_ADDRESS																0X40033000
#define TIMER_4_ADDRESS																0X40034000
#define TIMER_5_ADDRESS																0X40035000


#elif defined(WIDE_TIMER)
#define TIMERx(x)                     (x<2?((0x40036000)+((x)*0x1000)):((0x4004C000)+((x-2)*0x1000)))
#define TIMER_0_ADDRESS													0X40036000
#define TIMER_1_ADDRESS													0X40037000
#define TIMER_2_ADDRESS													0X4004C000
#define TIMER_3_ADDRESS								  				0X4004D000
#define TIMER_4_ADDRESS													0X4004E000
#define TIMER_5_ADDRESS													0X4004F000

#else
#error "Please choose WIDE or NORMAL Timer Mode"
#endif




/*- GPIO REGISTERS AND BIT FUNCTIONALITIES
***************************************************************************************/

#define RCGCTIMER				                      (*((volatile uint32_t*)(SystemControl + (0x604))))    
#define RCGCWTIMER				                    (*((volatile uint32_t*)(SystemControl + (0x65C))))    
	
#define GPTMCFG(x)						                (*((volatile uint32_t*)(TIMERx(x) + (0x000))))    
#define GPTMTAMR(x)						                (*((volatile uint32_t*)(TIMERx(x) + (0x004))))    
#define GPTMTBMR(x)						                (*((volatile uint32_t*)(TIMERx(x) + (0x008))))    
#define GPTMCTL(x)						                (*((volatile uint32_t*)(TIMERx(x) + (0x00C))))    
#define GPTMSYNC(x)						                (*((volatile uint32_t*)(TIMERx(x) + (0x010))))    
#define GPTMIMR(x)						                (*((volatile uint32_t*)(TIMERx(x) + (0x018))))    
#define GPTMRIS(x)						                (*((volatile uint32_t*)(TIMERx(x) + (0x01C))))    
#define GPTMMIS(x)						                (*((volatile uint32_t*)(TIMERx(x) + (0x020))))    
#define GPTMICR(x)						                (*((volatile uint32_t*)(TIMERx(x) + (0x024))))    
#define GPTMTAILR(x)						              (*((volatile uint32_t*)(TIMERx(x) + (0x028))))    
#define GPTMTBILR(x)						              (*((volatile uint32_t*)(TIMERx(x) + (0x02C))))    
#define GPTMTAMATCHR(x)						            (*((volatile uint32_t*)(TIMERx(x) + (0x030))))    
#define GPTMTBMATCHR(x)						            (*((volatile uint32_t*)(TIMERx(x) + (0x034))))    
#define GPTMTAPR(x)						                (*((volatile uint32_t*)(TIMERx(x) + (0x038))))    
#define GPTMTBPR(x)						                (*((volatile uint32_t*)(TIMERx(x) + (0x03C))))    
#define GPTMTAPMR(x)						              (*((volatile uint32_t*)(TIMERx(x) + (0x040))))    
#define GPTMTBPMR(x)						              (*((volatile uint32_t*)(TIMERx(x) + (0x044))))    
#define GPTMTAR(x)						                (*((volatile uint32_t*)(TIMERx(x) + (0x048))))    
#define GPTMTBR(x)						                (*((volatile uint32_t*)(TIMERx(x) + (0x04C))))    
#define GPTMTAV(x)						                (*((volatile uint32_t*)(TIMERx(x) + (0x050))))    
#define GPTMTBV(x)						                (*((volatile uint32_t*)(TIMERx(x) + (0x054))))    
#define GPTMRTCPD(x)						              (*((volatile uint32_t*)(TIMERx(x) + (0x058))))    
#define GPTMTAPS(x)						                (*((volatile uint32_t*)(TIMERx(x) + (0x05C))))    
#define GPTMTBPS(x)						                (*((volatile uint32_t*)(TIMERx(x) + (0x060))))    
#define GPTMTAPV(x)						                (*((volatile uint32_t*)(TIMERx(x) + (0x064))))    
#define GPTMTBPV(x)						                (*((volatile uint32_t*)(TIMERx(x) + (0x068))))    
#define GPTMPP(x)						                	(*((volatile uint32_t*)(TIMERx(x) + (0xFC0))))    



/*- Timers order inside RCGCTIMER/RCGCWTIMER Registers
*******************************************************/


/*- Port Mux Control start bits in GPIOCTL register
****************************************************/
#define PMC0            0
#define PMC1            4
#define PMC2            8
#define PMC3           12
#define PMC4           16
#define PMC5           20
#define PMC6           24
#define PMC7           28

/*- Timer Length Configurations
********************************************/
#define GPTMCFG_START_BIT       			0
#define GPT_NORMAL_32_VALUE   				0X0
#define GPT_WIDE_64_VALUE   					0X0
#define GPT_NORMAL_32_RTC_VALUE   		0X1
#define GPT_WIDE_64_RTC_VALUE 			  0X1
#define GPT_NORMAL_16_VALUE   				0X4
#define GPT_WIDE_32_VALUE			 			  0X4

/*- GPTMTAMR Bits and Modes
********************************************/
#define TAMR_START_BIT  		 					0
#define ONE_SHOT_TIMER_MODE						0X1
#define PERIODIC_TIMER_MODE						0X2
#define CAPTURE_MODE									0X3

#define TACMR								   				2
#define TAAMS								   				3
#define TACDIR								   			4
#define TAMIE								   				5
#define TAWOT								   				6
#define TASNAPS								   			7
#define TAILD								   				8
#define TAPWMIE								   			9
#define TAMRSU								   			10
#define TAPLO								   				11

/*- GPTMTBMR Bits and Modes
********************************************/
#define TBMR_START_BIT  	 						0

#define TBCMR								   				2
#define TBAMS								   				3
#define TBCDIR								   			4
#define TBMIE								   				5
#define TBWOT								   				6
#define TBSNAPS								   			7
#define TBILD								   				8
#define TBPWMIE								   			9
#define TBMRSU								   			10
#define TBPLO								   				11

/*- GPIOCTL BITS
**********************************************/
#define TAEN 													0
#define TBEN 													8

/*- GPTMRIS Bits
*******************/
#define TATORIS         0
#define CAMRIS          1
#define CAERIS          2
#define RTCRIS          3
#define TAMRIS          4
#define TBTORIS         8
#define CBMRIS          9
#define CBERIS          10
#define TBMRIS          11
#define WUERIS					16

/*- GPTMIMR Bits
*****************************/
#define TATOIM         0
#define CAMIM          1
#define CAEIM          2
#define RTCIM          3
#define TAMIM          4
#define TBTOIM         8
#define CBMIM          9
#define CBEIM          10
#define TBMIM          11
#define WUEIM					 16

/*- GPTMICR Bits
*****************************/
#define TATOCINT         0
#define CAMCINT          1
#define CAECINT          2
#define RTCCINT          3
#define TAMCINT          4
#define TBTOCINT         8
#define CBMCINT          9
#define CBECINT          10
#define TBMCINT          11
#define WUECINT					 16


/*- GPTMMIS Bits
*****************************/
#define TATOMIS         0
#define CAMMIS          1
#define CAEMIS          2
#define RTCMIS          3
#define TAMMIS          4
#define TBTOMIS         8
#define CBMMIS          9
#define CBEMIS          10
#define TBMMIS          11
#define WUEMIS					16

/*- API TYPES
***************************************************************************************/
typedef enum
{
	GPT_NORMAL_16, GPT_NORMAL_32, GPT_WIDE_32, GPT_WIDE_64, GPT_WIDE_32_RTC, GPT_WIDE_64_RTC
}GPT_TimerLength;

typedef enum
{
	GPT_ONE_SHOT_MODE, GPT_PERIODIC_MODE, GPT_CAPTURE_MODE
}GPT_Mode;

typedef enum
{
	GPT_16MHz, GPT_100KHz
}GPT_ChannelFreq;

typedef enum
{
	TIMER_CHANNEL_0=0, TIMER_CHANNEL_1, TIMER_CHANNEL_2, TIMER_CHANNEL_3, TIMER_CHANNEL_4, TIMER_CHANNEL_5,
	TIMER_CHANNEL_6, TIMER_CHANNEL_7, TIMER_CHANNEL_8, TIMER_CHANNEL_9, TIMER_CHANNEL_10, TIMER_CHANNEL_11 
}GPT_Channel_Number;

typedef uint32_t delayTimeSeconds_t;

typedef struct
{
	GPT_Channel_Number      ChannelId;
	GPT_Mode								ChannelMode;
	GPT_TimerLength					ChannelLength;
	
}GPT_ConfigType;

/*- APIs
***************************************************************************************/
void Gpt_Init (const GPT_ConfigType* ConfigPtr);
void Gpt_StartTimer (GPT_Channel_Number ChannelId, delayTimeSeconds_t seconds);
void Gpt_StopTimer (GPT_Channel_Number ChannelId);


#endif /* GPT.H */
