/*
* SPI_HW.h
*
* Created: 2/17/2021 10:52:35 PM
*  Author: Osama Moussa
*/


#ifndef SPI_HW_H_
#define SPI_HW_H_

#include "STD_Types.h"

typedef struct{
	Uint8 SPR_Bits:2;
	Uint8 CPHA_Bit:1;
	Uint8 CPOL_Bit:1;
	Uint8 MSTR_Bit:1;
	Uint8 DORD_Bit:1;
	Uint8 SPE_Bit:1;
	Uint8 SPIE_Bit:1;
    }SPI_SPCR_Reg_Bits_Type;

typedef struct{
	Uint8 SPI2X_Bits:1;
	Uint8 Reserved_Bits:5;
	Uint8 WCOL_Bit:1;
	Uint8 SPIF_Bit:1;
    }SPI_SPSR_Reg_Bits_Type;

typedef union {
	 Uint8                  All_Reg;
	 SPI_SPCR_Reg_Bits_Type Bits;
	}SPI_SPCR_Reg_Type;

typedef union {
	Uint8                  All_Reg;
	SPI_SPSR_Reg_Bits_Type Bits;
    }SPI_SPSR_Reg_Type;

typedef struct{
	SPI_SPCR_Reg_Type SPCR_Reg;
	SPI_SPSR_Reg_Type SPSR_Reg;
	Uint8             SPDR_Reg;
	}SPI_Registers;
	
#define SPI ((volatile SPI_Registers *)0x2D)

#endif /* SPI_HW_H_ */