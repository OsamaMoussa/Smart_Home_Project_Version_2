/*
 * Bluetooth.h
 *
 * Created: 2/17/2021 8:38:34 PM
 *  Author: Osama Moussa
 */ 


#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_

#include "UART.h"
		
void   Bluetooth_Init(void);
void   Bluetooth_Send_To_Device_Char(Uint8 Char);
void   Bluetooth_Send_To_Device_String(Sint8* String);
Uint16 Blutooth_Receive_From_Device_Char(void);

#endif /* BLUETOOTH_H_ */