/*
* UART.c
*
* Created: 2/17/2021 6:26:21 PM
*  Author: Osama Moussa
*/

#include "UART.h"

void UART_Parity_Mode_Select(UART_Parity_Mode_Type Parity_Mode)
{
	UART_UCSRC_Reg->Bits.URSEL_Bit = STD_High;
	UART_UCSRC_Reg->Bits.UPM_Bits  = Parity_Mode;
}

void UART_Stop_Bit_Select(UART_Stop_Bit_Type Stop_Bit)
{
	UART_UCSRC_Reg->Bits.URSEL_Bit = STD_High;
	UART_UCSRC_Reg->Bits.USBS_Bit  = Stop_Bit;
}

void UART_Char_Size_Select(UART_Char_Size_Type UART_Char_Size)
{
	UART_UCSRC_Reg->Bits.URSEL_Bit=STD_High;
	switch (UART_Char_Size)
	{
		case UART_Char_Size_5Bit:
		UART_UCSRB_Reg->Bits.UCSZ2_Bit = STD_Low;
		UART_UCSRC_Reg->Bits.UCSZ1_Bit = STD_Low;
		UART_UCSRC_Reg->Bits.UCSZ0_Bit = STD_Low;
		break;
		
		case UART_Char_Size_6Bit:
		UART_UCSRB_Reg->Bits.UCSZ2_Bit = STD_Low;
		UART_UCSRC_Reg->Bits.UCSZ1_Bit = STD_Low;
		UART_UCSRC_Reg->Bits.UCSZ0_Bit = STD_High;
		break;
		
		case UART_Char_Size_7Bit:
		UART_UCSRB_Reg->Bits.UCSZ2_Bit = STD_Low;
		UART_UCSRC_Reg->Bits.UCSZ1_Bit = STD_High;
		UART_UCSRC_Reg->Bits.UCSZ0_Bit = STD_Low;
		break;
		
		case UART_Char_Size_8Bit:
		UART_UCSRB_Reg->Bits.UCSZ2_Bit = STD_Low;
		UART_UCSRC_Reg->Bits.UCSZ1_Bit = STD_High;
		UART_UCSRC_Reg->Bits.UCSZ0_Bit = STD_High;
		break;
		
		case UART_Char_Size_9Bit:
		UART_UCSRB_Reg->Bits.UCSZ2_Bit = STD_High;
		UART_UCSRC_Reg->Bits.UCSZ1_Bit = STD_High;
		UART_UCSRC_Reg->Bits.UCSZ0_Bit = STD_High;
		break;
	}
}

void UART_Baud_Rate_Init(void)
{
	UART_UBRRL_Reg = (Uint8) UART_UBRR_Value;
	UART_UCSRC_Reg->Bits.URSEL_Bit=STD_Low;
	UART_UBRRH_Reg = (Uint8) (UART_UBRR_Value>>STD_Reg_Bits_Number);
}

void UART_Init(UART_Init_Type* UART_Init)
{	
	UART_Receiver_Enable();
	UART_Transmitter_Enable();
	UART_Parity_Mode_Select(UART_Init->UART_Parity_Mode);
	UART_Stop_Bit_Select(UART_Init->UART_Stop_Bit);
	UART_Char_Size_Select(UART_Init->UART_Char_Size);
	UART_Baud_Rate_Init();
}

void UART_Tx_Char(Uint8 Char)
{
	while(UART_IS_Data_Reg_Empty()==STD_Low);
	UART_Data_Reg = Char;
}

void UART_Tx_String(Sint8* String)
{
	Uint8 i =0;
	while (String[i]!='\0')
	{
		UART_Tx_Char(String[i]);
		i++;
	}
}

Uint16 UART_Rx_Char(void)
{
	Uint16 Data = 0;
	while(UART_IS_Receive_Complete() == STD_Low);
	Data = UART_Data_Reg | (UART_UCSRB_Reg->Bits.RXB8_Bit<<STD_Reg_Bits_Number);
	return Data;
}