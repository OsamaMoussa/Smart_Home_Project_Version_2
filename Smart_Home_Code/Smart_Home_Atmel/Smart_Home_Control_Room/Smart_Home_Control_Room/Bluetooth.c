/*
 * Bluetooth.c
 *
 * Created: 2/17/2021 8:38:19 PM
 *  Author: Osama Moussa
 */ 

#include "Bluetooth.h"

void Bluetooth_Init(void)
{
  UART_Init_Type Bluetooth_UART_Init = {UART_Parity_Mode_Disabled , UART_Stop_Bit_1Bit , UART_Char_Size_8Bit };
  UART_Init(&Bluetooth_UART_Init);	
}

void Bluetooth_Send_To_Device_Char(Uint8 Char)
{
	UART_Tx_Char(Char);
}
void Bluetooth_Send_To_Device_String(Sint8* String)
{
	UART_Tx_String(String);
}
Uint16 Blutooth_Receive_From_Device_Char(void)
{
	return UART_Rx_Char();
}