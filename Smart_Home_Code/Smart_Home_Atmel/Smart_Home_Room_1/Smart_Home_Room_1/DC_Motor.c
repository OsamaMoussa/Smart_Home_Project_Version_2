/*
* DC_Motor.c
*
* Created: 2/14/2021 5:35:15 PM
*  Author: Osama Moussa
*/
#include "DC_Motor.h"

void DC_Motor_Init(void)
{
	DIO_Channel_Mode(DC_Motor_IN1,Output);
	DIO_Channel_Mode(DC_Motor_IN2,Output);
	DIO_Channel_Mode(DC_Motor_E,Output);
	Timer2_Init_Type Timer2_DC_Motor_Init = {Timer2_WG_FastPWM_Mode,Timer2_COM_Clear_Mode, Timer2_CS_64Presc};
	Timer2_Init(&Timer2_DC_Motor_Init);
}

void DC_Motor_CW(DC_Motor_Speed_type Speed)
{
	DIO_Channel_Write(DC_Motor_IN2,STD_Low);
	DIO_Channel_Write(DC_Motor_IN1,STD_High);
	Timer2_NonInv_FPWM_Duty(Speed);
}

void DC_Motor_ACW(DC_Motor_Speed_type Speed)
{

	DIO_Channel_Write(DC_Motor_IN2,STD_High);
	DIO_Channel_Write(DC_Motor_IN1,STD_Low);
	Timer2_NonInv_FPWM_Duty(Speed);
}

void DC_Motor_Stop(void)
{
	DIO_Channel_Write(DC_Motor_IN2,STD_High);
	DIO_Channel_Write(DC_Motor_IN1,STD_High);
}
