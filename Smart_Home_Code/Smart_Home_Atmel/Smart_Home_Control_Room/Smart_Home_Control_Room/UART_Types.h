/*
 * UART_Types.h
 *
 * Created: 2/17/2021 6:15:24 PM
 *  Author: Osama Moussa
 */ 


#ifndef UART_TYPES_H_
#define UART_TYPES_H_

typedef enum {
	 UART_Parity_Mode_Disabled = 0b00,
	 UART_Parity_Mode_Reserved = 0b01,
	 UART_Parity_Mode_Even     = 0b10,
	 UART_Parity_Mode_Odd      = 0b11
	}UART_Parity_Mode_Type;

typedef enum {
	UART_Stop_Bit_1Bit = 0,
	UART_Stop_Bit_2Bit
    }UART_Stop_Bit_Type;

typedef enum {
	UART_Char_Size_5Bit = 0,
	UART_Char_Size_6Bit,
	UART_Char_Size_7Bit,
	UART_Char_Size_8Bit,
	UART_Char_Size_9Bit,      
    }UART_Char_Size_Type;

typedef struct {
	 UART_Parity_Mode_Type  UART_Parity_Mode;
	 UART_Stop_Bit_Type     UART_Stop_Bit;
	 UART_Char_Size_Type    UART_Char_Size;
	 }UART_Init_Type;
	 	
#endif /* UART_TYPES_H_ */