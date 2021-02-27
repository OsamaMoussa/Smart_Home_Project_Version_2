/*
* Servo_Motor.c
*
* Created: 2/15/2021 8:05:19 PM
*  Author: Osama Moussa
*/

#include "Servo_Motor.h"

void Servo_Motor_Init(void)
{
	Uint16 ICR1_Value = 0;
	
	DIO_Channel_Mode(Servo_Motor_Channel , Output);
	
	Timer1_CS_Select(Timer1_CS_64Presc);
	ICR1_Value = (Uint16) ( ( F_CPU/(Timer1_Presc*F_W) )-1);
	Timer1_ICR1_Reg =  ICR1_Value ;
	Timer1_Init_Type Timer1_Servo_Motor_Init={Timer1_WG_FastPWM_ICR1_Mode,  Servo_Motor_COM , Timer1_COM_Clear_Mode , Timer1_CS_64Presc};
	Timer1_Init(&Timer1_Servo_Motor_Init);
}

void Servo_Motor_Angle(Float32 Angle)
{
	Float32 T_Duty =0.0;
	Float32 Duty   =0.0;

	T_Duty = T_Duty_max - (((Angle_max-Angle)/(Angle_max-Angle_min))*(T_Duty_min));
	Duty   = (((T_Duty *F_CPU) / ((Float32)Timer1_Presc*(Timer1_Top+1) ) )*100);

	Timer1_NonInv_FPWM_Duty(Servo_Motor_COM,Duty);
}