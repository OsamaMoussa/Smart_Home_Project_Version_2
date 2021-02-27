/*
 * DIO_HW.h
 *
 * Created: 2/7/2021 5:29:35 PM
 *  Author: Osama Moussa
 */ 


#ifndef DIO_HW_H_
#define DIO_HW_H_

typedef struct{
	Uint8 Bit_0:1;
	Uint8 Bit_1:1;
	Uint8 Bit_2:1;
	Uint8 Bit_3:1;
	Uint8 Bit_4:1;
	Uint8 Bit_5:1;
	Uint8 Bit_6:1;
	Uint8 Bit_7:1;
    }DIO_Reg_Bits_Type;

typedef union{
	DIO_Reg_Bits_Type Bits ;
	Uint8             All_Reg;
    }DIO_Reg_Type;

typedef struct{

	DIO_Reg_Type  PIND_Reg;
	DIO_Reg_Type  DDRD_Reg;
	DIO_Reg_Type PORTD_Reg;
	
	DIO_Reg_Type  PINC_Reg;
	DIO_Reg_Type  DDRC_Reg;
	DIO_Reg_Type PORTC_Reg;
	
	DIO_Reg_Type  PINB_Reg;
	DIO_Reg_Type  DDRB_Reg;
	DIO_Reg_Type PORTB_Reg;
	
	DIO_Reg_Type  PINA_Reg;
	DIO_Reg_Type  DDRA_Reg;
	DIO_Reg_Type  PORTA_Reg;
    }DIO_Registers;
	
#define DIO ((volatile DIO_Registers *) 0x30)

#endif /* DIO_HW_H_ */