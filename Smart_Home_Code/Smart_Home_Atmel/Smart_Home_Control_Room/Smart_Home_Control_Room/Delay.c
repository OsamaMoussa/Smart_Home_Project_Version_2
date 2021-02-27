/*
 * Delay.c
 *
 * Created: 2/18/2021 7:50:04 AM
 *  Author: osama yassin
 */ 

#include "Delay.h"

void Delay_Init(void)
{
	Timer0_Init_Type Timer0_Init_Delay = {Timer0_WG_Normal_Mode,Timer0_COM_Normal_Mode,Timer0_CS_64Presc};
	Timer0_Init(&Timer0_Init_Delay);	
	Enable_OVF_Interrupt();
	Enable_OCR_Interrupt();
	Enable_General_Interrupt();
}

void Delay_us(Uint32 Delay_Time_us)
{
	Uint16  Prescaler   =0;
	Uint32  F_OS        =0;
	Float32 Delay_Calcs =0;
	Timer0_OVFs         =0;
	Timer0_OVF_Count    =0;
	Timer0_OCR_Flag     =0;
	
	Delay_Time_us   = (Float32)Delay_Time_us;
	Prescaler       = (Float32)Timer0_CS_Select(Timer0_CS_64Presc);
	F_OS            = (Float32)(F_CPU/1000000);
	Delay_Calcs     = (Float32)((Delay_Time_us*F_OS) / (256*Prescaler));
	Timer0_OVFs     = ( (Uint32)( Delay_Calcs) );
	Timer0_OCR0_Reg = (Uint8)( (Delay_Calcs - Timer0_OVFs)*256 - 1 );

	while(!(Timer0_OVF_Count == Timer0_OVFs));
	while(Timer0_OCR_Flag == 0);
}

void Delay_ms(Uint32 Delay_Time_ms)
{
	Uint16  Prescaler   =0;
	Uint32  F_OS        =0;
	Float32 Delay_Calcs =0;
	Timer0_OVFs         =0;
	Timer0_OVF_Count    =0;
	Timer0_OCR_Flag     =0;
	
	Prescaler       = (Float32)Timer0_CS_Select(Timer0_CS_64Presc);
	Delay_Time_ms   = (Float32)Delay_Time_ms;
	F_OS            = (Float32)(F_CPU/1000);
	Delay_Calcs     = (Float32)((Delay_Time_ms*F_OS) / (256*Prescaler));
	Timer0_OVFs     = ((Uint32)(Delay_Calcs));
	Timer0_OCR0_Reg = (Uint8)( (Delay_Calcs - Timer0_OVFs)*256 - 1 );
	
	while(!(Timer0_OVF_Count == Timer0_OVFs));
	while(Timer0_OCR_Flag == 0);
}

ISR(TIMER0_OVF_vect)
{
	Timer0_OVF_Count++;
}

ISR(TIMER0_COMP_vect)
{
	if(Timer0_OVF_Count == Timer0_OVFs)
	{
		Timer0_OVF_Count=0;
		Timer0_OCR_Flag =1;
	}
}