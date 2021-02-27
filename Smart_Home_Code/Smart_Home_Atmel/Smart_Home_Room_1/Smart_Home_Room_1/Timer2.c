/*
 * Timer2.c
 *
 * Created: 2/26/2021 3:54:56 PM
 *  Author: Osama Moussa
 */ 

#include "Timer2.h"

Uint8 Timer2_CS_Select(Timer2_CS_Type ClockSource)
{
	Uint16 Prescaler = 0;
	Timer2_TCCR2_Reg->CS2_Bits = ClockSource ;
	switch(ClockSource)
	{
		case Timer2_CS_NoPresc:
		case Timer2_CS_NoCS:
		case Timer2_CS_ExtCS_FallingEdge:
		case Timer2_CS_ExtCS_RisingEdge:
		Prescaler = 0;
		break;
		case Timer2_CS_8Presc:
		Prescaler = 8;
		break;
		case Timer2_CS_64Presc:
		Prescaler = 64;
		break;
		case Timer2_CS_256Presc:
		Prescaler = 256;
		break;
		case Timer2_CS_1024Presc:
		Prescaler = 1024;
		break;
	}
	return Prescaler;
}

void Timer2_Mode_Select(Timer2_WG_Mode_Type WG_Mode , Timer2_COM_Mode_Type CMO_Mode)
{
	switch(WG_Mode)
	{
		case Timer2_WG_Normal_Mode:
		Timer2_TCCR2_Reg->WGM21_Bit=STD_Low;
		Timer2_TCCR2_Reg->WGM20_Bit=STD_Low;
		break;
		
		case Timer2_WG_PWM_Mode:
		Timer2_TCCR2_Reg->WGM21_Bit=STD_Low;
		Timer2_TCCR2_Reg->WGM20_Bit=STD_High;
		break;
		
		case Timer2_WG_CTC_Mode:
		Timer2_TCCR2_Reg->WGM21_Bit=STD_High;
		Timer2_TCCR2_Reg->WGM20_Bit=STD_Low;
		break;
		
		case Timer2_WG_FastPWM_Mode:
		Timer2_TCCR2_Reg->WGM21_Bit=STD_High;
		Timer2_TCCR2_Reg->WGM20_Bit=STD_High;
		break;
	}
	Timer2_TCCR2_Reg->COM2_Bits = CMO_Mode;
}

void  Timer2_Init(Timer2_Init_Type* Timer2_Init_Instance)
{
	Timer2_CS_Select(Timer2_Init_Instance->CS);
	Timer2_Mode_Select(Timer2_Init_Instance->WG_Mode , Timer2_Init_Instance->COM_Mode);
}

void Timer2_NonInv_FPWM_Duty(Float32 Duty)
{
	Uint16 OCR2_Value = (Uint8) ( (((Float32)Duty/100.0)*(Timer2_Top+1))-1 ) ;
	Timer2_OCR2_Reg = OCR2_Value ;
}
