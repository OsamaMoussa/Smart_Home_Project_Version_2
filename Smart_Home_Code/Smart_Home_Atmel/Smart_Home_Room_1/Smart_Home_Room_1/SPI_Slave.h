/*
 * SPI_Slave.h
 *
 * Created: 2/18/2021 2:06:55 AM
 *  Author: Osama Moussa
 */ 


#ifndef SPI_SLAVE_H_
#define SPI_SLAVE_H_

#include "SPI.h"

#define SPI_IS_Slave_Enabled() (DIO_Channel_Read(SS)==STD_Low)

void SPI_Slave_Init(void);
void SPI_Slave_Send_Data(Uint8 Data);
Uint8 SPI_Slave_Recieve_Data(void);


#endif /* SPI_SLAVE_H_ */