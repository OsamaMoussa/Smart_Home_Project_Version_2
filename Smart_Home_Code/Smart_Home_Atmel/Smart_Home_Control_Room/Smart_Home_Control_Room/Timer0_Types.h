/*
 * Timer0_Types.h
 *
 * Created: 2/11/2021 12:12:18 AM
 *  Author: Osama Moussa
 */ 

#ifndef TIMER0_TYPES_H_
#define TIMER0_TYPES_H_

typedef enum{
	Timer0_WG_Normal_Mode=0,
	Timer0_WG_PWM_Mode,
	Timer0_WG_CTC_Mode,
	Timer0_WG_FastPWM_Mode
	}Timer0_WG_Mode_Type; //WaveForm Generation Mode types
	
typedef enum{
	Timer0_COM_Normal_Mode   =0b00,
	Timer0_COM_Toggle_Mode   =0b01,
	Timer0_COM_Reserved_Mode =0b01,
	Timer0_COM_Clear_Mode    =0b10,
	Timer0_COM_Set_Mode      =0b11
    }Timer0_COM_Mode_Type; //Compare Match Output Mode types

typedef enum{
	Timer0_CS_NoCS              =0b000,
	Timer0_CS_NoPresc           =0b001,
	Timer0_CS_8Presc            =0b010,
	Timer0_CS_64Presc           =0b011,
	Timer0_CS_256Presc          =0b100,
	Timer0_CS_1024Presc         =0b101,
	Timer0_CS_ExtCS_FallingEdge =0b110,
	Timer0_CS_ExtCS_RisingEdge  =0b111
	}Timer0_CS_Type;  //Clock Source types

typedef struct  {
	Timer0_WG_Mode_Type   WG_Mode; 
	Timer0_COM_Mode_Type  COM_Mode;
	Timer0_CS_Type        CS;
    }Timer0_Init_Type;
		
#endif /* TIMER0_TYPES_H_ */