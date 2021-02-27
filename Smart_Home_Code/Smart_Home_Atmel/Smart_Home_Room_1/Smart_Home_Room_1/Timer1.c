/*
 * Timer1.c
 *
 * Created: 2/11/2021 6:17:14 PM
 *  Author: Osama Moussa
 */ 

#include "Timer1.h"

void Timer1_CS_Select(Timer1_CS_Type ClockSource)
{
	
	Timer1_TCCR1B_Reg->CS1_Bits = ClockSource ;
	Timer1_Presc = 1;
	switch(ClockSource)
	{
		case Timer1_CS_NoCS:
		case Timer1_CS_ExtCS_FallingEdge:
		case Timer1_CS_ExtCS_RisingEdge:
		case Timer1_CS_NoPresc:
		Timer1_Presc = 1;
		break;

		case Timer1_CS_8Presc:
		Timer1_Presc = 8;
		break;
		
		case Timer1_CS_64Presc:
		Timer1_Presc = 64;
		break;
		
		case Timer1_CS_256Presc:
		Timer1_Presc = 256;
		break;
		
		case Timer1_CS_1024Presc:
		Timer1_Presc = 1024;
		break;
	}
}

void Timer1_Mode_Select(Timer1_WG_Mode_Type WG_Mode ,Timer1_COM_Type COM_Type, Timer1_COM_Mode_Type COM_Mode)
{
	switch(WG_Mode)
	{
		case Timer1_WG_Normal_Mode:
		Timer1_TCCR1B_Reg->WGM13_Bit=STD_Low;
		Timer1_TCCR1B_Reg->WGM12_Bit=STD_Low;
		Timer1_TCCR1A_Reg->WGM11_Bit=STD_Low;
		Timer1_TCCR1A_Reg->WGM10_Bit=STD_Low;
		Timer1_Top =0xFFFF;
		break;
		
		case Timer1_WG_PWM_8Bit_Mode:
		Timer1_TCCR1B_Reg->WGM13_Bit=STD_Low;
		Timer1_TCCR1B_Reg->WGM12_Bit=STD_Low;
		Timer1_TCCR1A_Reg->WGM11_Bit=STD_Low;
		Timer1_TCCR1A_Reg->WGM10_Bit=STD_High;
		Timer1_Top =255;
		break;
		
		case Timer1_WG_PWM_9Bit_Mode:
		Timer1_TCCR1B_Reg->WGM13_Bit=STD_Low;
		Timer1_TCCR1B_Reg->WGM12_Bit=STD_Low;
		Timer1_TCCR1A_Reg->WGM11_Bit=STD_High;
		Timer1_TCCR1A_Reg->WGM10_Bit=STD_Low;
		Timer1_Top = 511;
		break;
		
		case Timer1_WG_PWM_10Bit_Mode:
		Timer1_TCCR1B_Reg->WGM13_Bit=STD_Low;
		Timer1_TCCR1B_Reg->WGM12_Bit=STD_Low;
		Timer1_TCCR1A_Reg->WGM11_Bit=STD_High;
		Timer1_TCCR1A_Reg->WGM10_Bit=STD_High;
		Timer1_Top = 1023;
		break;
		
		case Timer1_WG_CTC_OCR1A_Mode:
		Timer1_TCCR1B_Reg->WGM13_Bit=STD_Low;
		Timer1_TCCR1B_Reg->WGM12_Bit=STD_High;
		Timer1_TCCR1A_Reg->WGM11_Bit=STD_Low;
		Timer1_TCCR1A_Reg->WGM10_Bit=STD_Low;
		Timer1_Top = Timer1_OCR1A_Reg ;
		break;
		
		case Timer1_WG_FastPWM_8Bit_Mode:
		Timer1_TCCR1B_Reg->WGM13_Bit=STD_Low;
		Timer1_TCCR1B_Reg->WGM12_Bit=STD_High;
		Timer1_TCCR1A_Reg->WGM11_Bit=STD_Low;
		Timer1_TCCR1A_Reg->WGM10_Bit=STD_High;
		Timer1_Top = 255;
		break;
		
		case Timer1_WG_FastPWM_9Bit_Mode:
		Timer1_TCCR1B_Reg->WGM13_Bit=STD_Low;
		Timer1_TCCR1B_Reg->WGM12_Bit=STD_High;
		Timer1_TCCR1A_Reg->WGM11_Bit=STD_High;
		Timer1_TCCR1A_Reg->WGM10_Bit=STD_Low;
		Timer1_Top = 511;
		break;
		
		case Timer1_WG_FastPWM_10Bit_Mode:
		Timer1_TCCR1B_Reg->WGM13_Bit=STD_Low;
		Timer1_TCCR1B_Reg->WGM12_Bit=STD_High;
		Timer1_TCCR1A_Reg->WGM11_Bit=STD_High;
		Timer1_TCCR1A_Reg->WGM10_Bit=STD_High;
		Timer1_Top = 1023;
		break;
		
		case Timer1_WG_PWM_ICR1_B_Mode:
		Timer1_TCCR1B_Reg->WGM13_Bit=STD_High;
		Timer1_TCCR1B_Reg->WGM12_Bit=STD_Low;
		Timer1_TCCR1A_Reg->WGM11_Bit=STD_Low;
		Timer1_TCCR1A_Reg->WGM10_Bit=STD_Low;
		Timer1_Top = Timer1_ICR1_Reg;
		break;
		
		case Timer1_WG_PWM_OCR1A_B_Mode:
		Timer1_TCCR1B_Reg->WGM13_Bit=STD_High;
		Timer1_TCCR1B_Reg->WGM12_Bit=STD_Low;
		Timer1_TCCR1A_Reg->WGM11_Bit=STD_Low;
		Timer1_TCCR1A_Reg->WGM10_Bit=STD_High;
		Timer1_Top = Timer1_OCR1A_Reg;
		break;
		
		case Timer1_WG_PWM_ICR1_T_Mode:
		Timer1_TCCR1B_Reg->WGM13_Bit=STD_High;
		Timer1_TCCR1B_Reg->WGM12_Bit=STD_Low;
		Timer1_TCCR1A_Reg->WGM11_Bit=STD_High;
		Timer1_TCCR1A_Reg->WGM10_Bit=STD_Low;
		Timer1_Top = Timer1_ICR1_Reg ;
		break;
		
		case Timer1_WG_PWM_OCR1A_T_Mode:
		Timer1_TCCR1B_Reg->WGM13_Bit=STD_High;
		Timer1_TCCR1B_Reg->WGM12_Bit=STD_Low;
		Timer1_TCCR1A_Reg->WGM11_Bit=STD_High;
		Timer1_TCCR1A_Reg->WGM10_Bit=STD_High;
		Timer1_Top = Timer1_OCR1A_Reg ;
		break;
		
		case Timer1_WG_CTC_ICR1_Mode:
		Timer1_TCCR1B_Reg->WGM13_Bit=STD_High;
		Timer1_TCCR1B_Reg->WGM12_Bit=STD_High;
		Timer1_TCCR1A_Reg->WGM11_Bit=STD_Low;
		Timer1_TCCR1A_Reg->WGM10_Bit=STD_Low;
		Timer1_Top = Timer1_ICR1_Reg ;
		break;
		
		/*case Timer1_WG_Reserved_Mode:
		Timer1_TCCR1B_Reg->WGM13_Bit=STD_High;
		Timer1_TCCR1B_Reg->WGM12_Bit=STD_High;
		Timer1_TCCR1A_Reg->WGM11_Bit=STD_Low;
		Timer1_TCCR1A_Reg->WGM10_Bit=STD_High;
		Timer1_Top = 0;
		break;*/
		
		case Timer1_WG_FastPWM_ICR1_Mode:
		Timer1_TCCR1B_Reg->WGM13_Bit=STD_High;
		Timer1_TCCR1B_Reg->WGM12_Bit=STD_High;
		Timer1_TCCR1A_Reg->WGM11_Bit=STD_High;
		Timer1_TCCR1A_Reg->WGM10_Bit=STD_Low;
		Timer1_Top = Timer1_ICR1_Reg ;
		break;
		
		case Timer1_WG_FastPWM_OCR1A_Mode:
		Timer1_TCCR1B_Reg->WGM13_Bit=STD_High;
		Timer1_TCCR1B_Reg->WGM12_Bit=STD_High;
		Timer1_TCCR1A_Reg->WGM11_Bit=STD_High;
		Timer1_TCCR1A_Reg->WGM10_Bit=STD_High;
		Timer1_Top = Timer1_OCR1A_Reg ;
		break;
	}
	
	switch (COM_Type)
	{
		case Timer1_COM_A:
		Timer1_TCCR1A_Reg->COM1A_Bits = COM_Mode;
		break;
		
		case Timer1_COM_B:
		Timer1_TCCR1A_Reg->COM1B_Bits = COM_Mode;
		break;
	}
	
}

void Timer1_Init(Timer1_Init_Type* Timer1_Init_Instance)
{
	Timer1_Mode_Select(Timer1_Init_Instance->WG_Mode, Timer1_Init_Instance->COM_Num , Timer1_Init_Instance->COM_Mode);
	Timer1_CS_Select(Timer1_Init_Instance->CS);
}

void Timer1_NonInv_FPWM_Duty(Timer1_COM_Type COM_Num , Float32 Duty)
{
   
   Uint16 OCR1A_Value = (Uint16) ( (((Float32)Duty/100.0)*(Timer1_Top+1))-1 ) ;
   switch (COM_Num)
   {
	   case Timer1_COM_A:
	   Timer1_OCR1A_Reg = OCR1A_Value ;
	   break;
	   
	   case Timer1_COM_B:
	   Timer1_OCR1B_Reg = OCR1A_Value ;
	   break;
   }

}

