/*
 * SPI.h
 *
 * Created: 2/17/2021 11:50:27 PM
 *  Author: Osama Moussa
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "DIO.h"
#include "SPI_HW.h"
#include "SPI_Types.h"

#define SS   DIO_Channel_B4
#define MOSI DIO_Channel_B5
#define MISO DIO_Channel_B6
#define SCK  DIO_Channel_B7

#define SPI_Data_Reg SPI->SPDR_Reg
 
#define SPI_Enable()                       (SPI->SPCR_Reg.Bits.SPE_Bit=STD_High) 
#define SPI_Disable()                      (SPI->SPCR_Reg.Bits.SPE_Bit=STD_Low)
#define SPI_Data_Order_Select(DataOrder)   (SPI->SPCR_Reg.Bits.DORD_Bit=DataOrder)
#define SPI_State_Select(State)            (SPI->SPCR_Reg.Bits.MSTR_Bit=State)
#define SPI_Presc_Select(Presc)            (SPI->SPCR_Reg.Bits.SPR_Bits=Presc)
#define SPI_IS_Transfer_Complete()         (SPI->SPSR_Reg.Bits.SPIF_Bit == STD_High)

void  SPI_Init(SPI_Init_Type * SPI_Init_Instace);
void  SPI_Send_Data(Uint8 Data);
Uint8 SPI_Recieve_Data(void);
Uint8 SPI_TxRx(Uint8 Data);
 
#endif /* SPI_H_ */