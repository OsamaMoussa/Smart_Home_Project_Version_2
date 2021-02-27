/*
 * Timer1_Types.h
 *
 * Created: 2/11/2021 5:25:19 PM
 *  Author: Osama Moussa
 */ 


#ifndef TIMER1_TYPES_H_
#define TIMER1_TYPES_H_

typedef enum{
	Timer1_WG_Normal_Mode=0,
	
	Timer1_WG_PWM_8Bit_Mode,
	Timer1_WG_PWM_9Bit_Mode,
	Timer1_WG_PWM_10Bit_Mode,
	
	Timer1_WG_CTC_OCR1A_Mode,
	
	Timer1_WG_FastPWM_8Bit_Mode,
	Timer1_WG_FastPWM_9Bit_Mode,
	Timer1_WG_FastPWM_10Bit_Mode,
	
	Timer1_WG_PWM_ICR1_B_Mode,
	Timer1_WG_PWM_OCR1A_B_Mode,
	Timer1_WG_PWM_ICR1_T_Mode,
	Timer1_WG_PWM_OCR1A_T_Mode,
	
	Timer1_WG_CTC_ICR1_Mode,
	
	//Timer1_WG_Reserved_Mode,
	
	Timer1_WG_FastPWM_ICR1_Mode,
	Timer1_WG_FastPWM_OCR1A_Mode
    }Timer1_WG_Mode_Type; //WaveForm Generation Mode types
	
typedef enum{
	Timer1_COM_A,
	Timer1_COM_B
	}Timer1_COM_Type;
	
typedef enum{
	Timer1_COM_Normal_Mode   =0b00,
	Timer1_COM_Toggle_Mode   =0b01,
	Timer1_COM_Reserved_Mode =0b01,
	Timer1_COM_Clear_Mode    =0b10,
	Timer1_COM_Set_Mode      =0b11
    }Timer1_COM_Mode_Type; //Compare Match Output Mode types

typedef enum{
	Timer1_CS_NoCS              =0b000,
	Timer1_CS_NoPresc           =0b001,
	Timer1_CS_8Presc            =0b010,
	Timer1_CS_64Presc           =0b011,
	Timer1_CS_256Presc          =0b100,
	Timer1_CS_1024Presc         =0b101,
	Timer1_CS_ExtCS_FallingEdge =0b110,
	Timer1_CS_ExtCS_RisingEdge  =0b111
    }Timer1_CS_Type;  //Clock Source types
	
	
typedef struct  {
	Timer1_WG_Mode_Type     WG_Mode;
	Timer1_COM_Type         COM_Num;
	Timer1_COM_Mode_Type    COM_Mode;
	Timer1_CS_Type          CS;
    }Timer1_Init_Type;
	
#endif /* TIMER1_TYPES_H_ */