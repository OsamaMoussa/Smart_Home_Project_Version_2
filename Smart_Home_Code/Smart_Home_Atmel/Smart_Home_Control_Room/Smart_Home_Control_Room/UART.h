/*
 * UART.h
 *
 * Created: 2/17/2021 6:26:09 PM
 *  Author: Osama Moussa
 */ 


#ifndef UART_H_
#define UART_H_

#include "STD_Types.h"
#include "UART_HW.h"
#include "UART_Types.h"

#define F_CPU             16000000UL
#define UART_Baud_Rate    9600
#define UART_Double_Speed 0

#if (UART_Double_Speed==0)
  #define UART_UBRR_Value      ((F_CPU/(16UL* UART_Baud_Rate))-1)
#else
  #define UART_UBRR_Value      ((F_CPU/(8UL* UART_Baud_Rate))-1)
#endif

#define UART_Data_Reg              (UART_UDR_Reg)
#define UART_Receiver_Enable()     (UART_UCSRB_Reg->Bits.RXEN_Bit=STD_High)
#define UART_Transmitter_Enable()  (UART_UCSRB_Reg->Bits.TXEN_Bit=STD_High)
#define UART_IS_Data_Reg_Empty()   (UART_UCSRA_Reg->Bits.UDRE_Bit == STD_High)
#define UART_IS_Receive_Complete() (UART_UCSRA_Reg->Bits.RXC_Bit == STD_High)

void UART_Parity_Mode_Select(UART_Parity_Mode_Type Parity_Mode);                     
void UART_Stop_Bit_Select(UART_Stop_Bit_Type Stop_Bit);        
void UART_Char_Size_Select(UART_Char_Size_Type UART_Char_Size);
void UART_Baud_Rate_Init(void);

void   UART_Init(UART_Init_Type* UART_Init);
void   UART_Tx_Char(Uint8 Char);
void   UART_Tx_String(Sint8* String);
Uint16 UART_Rx_Char(void);

#endif /* UART_H_ */