/*
 * Timer2_Types.h
 *
 * Created: 2/26/2021 3:54:22 PM
 *  Author: Osama Moussa
 */ 


#ifndef TIMER2_TYPES_H_
#define TIMER2_TYPES_H_

typedef enum{
	Timer2_WG_Normal_Mode=0,
	Timer2_WG_PWM_Mode,
	Timer2_WG_CTC_Mode,
	Timer2_WG_FastPWM_Mode
    }Timer2_WG_Mode_Type; //WaveForm Generation Mode types

typedef enum{
	Timer2_COM_Normal_Mode   =0b00,
	Timer2_COM_Toggle_Mode   =0b01,
	Timer2_COM_Reserved_Mode =0b01,
	Timer2_COM_Clear_Mode    =0b10,
	Timer2_COM_Set_Mode      =0b11
    }Timer2_COM_Mode_Type; //Compare Match Output Mode types

typedef enum{
	Timer2_CS_NoCS              =0b000,
	Timer2_CS_NoPresc           =0b001,
	Timer2_CS_8Presc            =0b010,
	Timer2_CS_64Presc           =0b011,
	Timer2_CS_256Presc          =0b100,
	Timer2_CS_1024Presc         =0b101,
	Timer2_CS_ExtCS_FallingEdge =0b110,
	Timer2_CS_ExtCS_RisingEdge  =0b111
    }Timer2_CS_Type;  //Clock Source types

typedef struct  {
	Timer2_WG_Mode_Type   WG_Mode;
	Timer2_COM_Mode_Type  COM_Mode;
	Timer2_CS_Type        CS;
    }Timer2_Init_Type;



#endif /* TIMER2_TYPES_H_ */