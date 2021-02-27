/*
 * Timer0.c
 *
 * Created: 2/18/2021 7:52:11 AM
 *  Author: osama yassin
 */ 

#include "Timer0.h"

Uint8 Timer0_CS_Select(Timer0_CS_Type ClockSource)
{
	Uint16 Prescaler = 0;
	Timer0_TCCR0_Reg->CS0_Bits = ClockSource ;
	switch(ClockSource)
	{
		case Timer0_CS_NoPresc:
		case Timer0_CS_NoCS:
		case Timer0_CS_ExtCS_FallingEdge:
		case Timer0_CS_ExtCS_RisingEdge:
		Prescaler = 0;
		break;
		case Timer0_CS_8Presc:
		Prescaler = 8;
		break;
		case Timer0_CS_64Presc:
		Prescaler = 64;
		break;
		case Timer0_CS_256Presc:
		Prescaler = 256;
		break;
		case Timer0_CS_1024Presc:
		Prescaler = 1024;
		break;
	}
	return Prescaler;
}

void Timer0_Mode_Select(Timer0_WG_Mode_Type WG_Mode , Timer0_COM_Mode_Type CMO_Mode)
{
	switch(WG_Mode)
	{
		case Timer0_WG_Normal_Mode:
		Timer0_TCCR0_Reg->WGM01_Bit=STD_Low;
		Timer0_TCCR0_Reg->WGM00_Bit=STD_Low;
		break;
		
		case Timer0_WG_PWM_Mode:
		Timer0_TCCR0_Reg->WGM01_Bit=STD_Low;
		Timer0_TCCR0_Reg->WGM00_Bit=STD_High;
		break;
		
		case Timer0_WG_CTC_Mode:
		Timer0_TCCR0_Reg->WGM01_Bit=STD_High;
		Timer0_TCCR0_Reg->WGM00_Bit=STD_Low;
		break;
		
		case Timer0_WG_FastPWM_Mode:
		Timer0_TCCR0_Reg->WGM01_Bit=STD_High;
		Timer0_TCCR0_Reg->WGM00_Bit=STD_High;
		break;
	}
	Timer0_TCCR0_Reg->COM0_Bits = CMO_Mode;
}

void  Timer0_Init(Timer0_Init_Type* Timer0_Init_Instance)
{
    Timer0_CS_Select(Timer0_Init_Instance->CS);
	Timer0_Mode_Select(Timer0_Init_Instance->WG_Mode , Timer0_Init_Instance->COM_Mode);	
}