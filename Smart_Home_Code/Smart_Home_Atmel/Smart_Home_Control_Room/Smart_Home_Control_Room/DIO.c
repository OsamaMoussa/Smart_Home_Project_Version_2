/*
* DIO.c
*
* Created: 2/7/2021 7:00:01 PM
*  Author: Osama Moussa
*/

#include "DIO.h"

void  DIO_Channel_Mode(DIO_Channel_Type Channel , DIO_Direction_Type Direction)
{
	DIO_Port_Type Port = Channel/STD_Reg_Bits_Number;
	DIO_Bit_Type  Bit  = Channel%STD_Reg_Bits_Number;
	volatile DIO_Reg_Type * Reg = 0x00 ;
	
	switch(Port)
	{
		case DIO_PortA :
		Reg = &(DIO->DDRA_Reg);
		break;
		
		case DIO_PortB :
		Reg = &(DIO->DDRB_Reg);
		break;
		
		case DIO_PortC :
		Reg = &(DIO->DDRC_Reg);
		break;
		
		case DIO_PortD :
		Reg = &(DIO->DDRD_Reg);
		break;
	}
	
	switch(Bit)
	{
		case DIO_Bit_0 :
		Reg->Bits.Bit_0 = Direction;
		break;
		
		case DIO_Bit_1 :
		Reg->Bits.Bit_1 = Direction;
		break;
		
		case DIO_Bit_2 :
		Reg->Bits.Bit_2 = Direction;
		break;
		
		case DIO_Bit_3 :
		Reg->Bits.Bit_3 = Direction;
		break;
		
		case DIO_Bit_4 :
		Reg->Bits.Bit_4 = Direction;
		break;
		
		case DIO_Bit_5 :
		Reg->Bits.Bit_5 = Direction;
		break;
		
		case DIO_Bit_6 :
		Reg->Bits.Bit_6 = Direction;
		break;
		
		case DIO_Bit_7 :
		Reg->Bits.Bit_7 = Direction;
		break;
	}
}

void  DIO_Channel_Write(DIO_Channel_Type Channel , STD_Level_Type Level)
{
	DIO_Port_Type Port = Channel/STD_Reg_Bits_Number;
	DIO_Bit_Type  Bit  = Channel%STD_Reg_Bits_Number;
	volatile DIO_Reg_Type * Reg = 0x00 ;

	switch(Port)
	{
		case DIO_PortA :
		Reg = &(DIO->PORTA_Reg);
		break;
		
		case DIO_PortB :
		Reg = &(DIO->PORTB_Reg);
		break;
		
		case DIO_PortC :
		Reg = &(DIO->PORTC_Reg);
		break;
		
		case DIO_PortD :
		Reg = &(DIO->PORTD_Reg);
		break;
	}
	
	switch(Bit)
	{
		case DIO_Bit_0 :
		Reg->Bits.Bit_0 = Level;
		break;
		
		case DIO_Bit_1 :
		Reg->Bits.Bit_1 = Level;
		break;
		
		case DIO_Bit_2 :
		Reg->Bits.Bit_2 = Level;
		break;
		
		case DIO_Bit_3 :
		Reg->Bits.Bit_3 = Level;
		break;
		
		case DIO_Bit_4 :
		Reg->Bits.Bit_4 = Level;
		break;
		
		case DIO_Bit_5 :
		Reg->Bits.Bit_5 = Level;
		break;
		
		case DIO_Bit_6 :
		Reg->Bits.Bit_6 = Level;
		break;
		
		case DIO_Bit_7 :
		Reg->Bits.Bit_7 = Level;
		break;
	}
}

void  DIO_Channel_Toggle(DIO_Channel_Type Channel)
{
	DIO_Port_Type Port = Channel/STD_Reg_Bits_Number;
	DIO_Bit_Type  Bit  = Channel%STD_Reg_Bits_Number;
	volatile DIO_Reg_Type * Reg = 0x00  ;
	
	switch(Port)
	{
		case DIO_PortA :
		Reg = &(DIO->PORTA_Reg);
		break;
		
		case DIO_PortB :
		Reg = &(DIO->PORTB_Reg);
		break;
		
		case DIO_PortC :
		Reg =&(DIO->PORTC_Reg);
		break;
		
		case DIO_PortD :
		Reg = &(DIO->PORTD_Reg);
		break;
	}
	
	switch(Bit)
	{
		case DIO_Bit_0 :
		Reg->Bits.Bit_0 = !(Reg->Bits.Bit_0) ;
		break;
		
		case DIO_Bit_1 :
		Reg->Bits.Bit_1 = !(Reg->Bits.Bit_1);
		break;
		
		case DIO_Bit_2 :
		Reg->Bits.Bit_2 = !(Reg->Bits.Bit_2);
		break;
		
		case DIO_Bit_3 :
		Reg->Bits.Bit_3 = !(Reg->Bits.Bit_3);
		break;
		
		case DIO_Bit_4 :
		Reg->Bits.Bit_0 = !(Reg->Bits.Bit_4);
		break;
		
		case DIO_Bit_5 :
		Reg->Bits.Bit_5 = !(Reg->Bits.Bit_5);
		break;
		
		case DIO_Bit_6 :
		Reg->Bits.Bit_6 = !(Reg->Bits.Bit_6);
		break;
		
		case DIO_Bit_7 :
		Reg->Bits.Bit_7 = !(Reg->Bits.Bit_7);
		break;
	}
}

STD_Level_Type DIO_Channel_Read(DIO_Channel_Type Channel)
{
	DIO_Port_Type  Port = Channel/STD_Reg_Bits_Number;
	DIO_Bit_Type   Bit  = Channel%STD_Reg_Bits_Number;
	volatile DIO_Reg_Type * Reg = 0x00  ;
	STD_Level_Type level = STD_Low;
	
	switch(Port)
	{
		case DIO_PortA :
		Reg = &(DIO->PINA_Reg);
		break;
		
		case DIO_PortB :
		Reg = &(DIO->PINB_Reg);
		break;
		
		case DIO_PortC :
		Reg = &(DIO->PINC_Reg);
		break;
		
		case DIO_PortD :
		Reg = &(DIO->PIND_Reg);
		break;
	}
	
	switch(Bit)
	{
		case DIO_Bit_0 :
		level =Reg->Bits.Bit_0 ;
		break;
		
		case DIO_Bit_1 :
		level = Reg->Bits.Bit_1 ;
		break;
		
		case DIO_Bit_2 :
		level = Reg->Bits.Bit_2 ;
		break;
		
		case DIO_Bit_3 :
		level = Reg->Bits.Bit_3 ;
		break;
		
		case DIO_Bit_4 :
		level = Reg->Bits.Bit_4 ;
		break;
		
		case DIO_Bit_5 :
		level = Reg->Bits.Bit_5;
		break;
		
		case DIO_Bit_6 :
		level = Reg->Bits.Bit_6 ;
		break;
		
		case DIO_Bit_7 :
		level = Reg->Bits.Bit_7 ;
		break;
	}
	return level;
}

void  DIO_Port_Write(DIO_Port_Type Port, Uint8 Data)
{
	switch(Port)
	{
		case DIO_PortA:
		DIO->PORTA_Reg.All_Reg = Data;
		break;
		
		case DIO_PortB:
		DIO->PORTB_Reg.All_Reg = Data;
		break;
		
		case DIO_PortC:
		DIO->PORTC_Reg.All_Reg = Data;
		break;
		
		case DIO_PortD:
		DIO->PORTD_Reg.All_Reg = Data;
		break;
	}
}

Uint8 DIO_Port_Read(DIO_Port_Type Port)
{
	Uint8 Data =0;
		switch(Port)
		{
			case DIO_PortA:
			Data = DIO->PINA_Reg.All_Reg  ;
			break;
			
			case DIO_PortB:
			Data = DIO->PINB_Reg.All_Reg ;
			break;
			
			case DIO_PortC:
			Data = DIO->PINC_Reg.All_Reg ;
			break;
			
			case DIO_PortD:
			Data = DIO->PIND_Reg.All_Reg ;
			break;
		}
		return Data;	
}