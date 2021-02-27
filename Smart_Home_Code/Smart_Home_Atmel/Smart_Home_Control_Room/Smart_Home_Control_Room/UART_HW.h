/*
* UART_HW.h
*
* Created: 2/17/2021 5:28:10 PM
*  Author: Osama Moussa
*/


#ifndef UART_HW_H_
#define UART_HW_H_

#include "STD_Types.h"

typedef struct {
	Uint8 TXB8_Bit:1;
	Uint8 RXB8_Bit:1;
	Uint8 UCSZ2_Bit:1;
	Uint8 TXEN_Bit:1;
	Uint8 RXEN_Bit:1;
	Uint8 UDRIE_Bit:1;
	Uint8 TXCIE_Bit:1;
	Uint8 RXCIE_Bit:1;
    }UART_UCSRB_Reg_Bits_Type;

typedef struct {
	Uint8 MPCM_Bit:1;
	Uint8 U2X_Bit:1;
	Uint8 PE_Bit:1;
	Uint8 DOR_Bit:1;
	Uint8 FE_Bit:1;
	Uint8 UDRE_Bit:1;
	Uint8 TXC_Bit:1;
	Uint8 RXC_Bit:1;
    }UART_UCSRA_Reg_Bits_Type;

typedef struct {
	Uint8 UCPOL_Bit:1;
	Uint8 UCSZ0_Bit:1;
	Uint8 UCSZ1_Bit:1;
	Uint8 USBS_Bit:1;
	Uint8 UPM_Bits:2;
	Uint8 UMSEL_Bit:1;
	Uint8 URSEL_Bit:1;
    }UART_UCSRC_Reg_Bits_Type;

typedef union {
	Uint8                    All_Reg;
	UART_UCSRB_Reg_Bits_Type Bits;
    }UART_UCSRB_Reg_Type;

typedef union {
	Uint8                    All_Reg;
	UART_UCSRA_Reg_Bits_Type Bits;
    }UART_UCSRA_Reg_Type;

typedef union {
	Uint8                    All_Reg;
	UART_UCSRC_Reg_Bits_Type Bits;
    }UART_UCSRC_Reg_Type;


#define UART_UBRRL_Reg    *( (volatile Uint8 *) 0x29)
#define UART_UBRRH_Reg    *( (volatile Uint8 *) 0x40)
#define UART_UDR_Reg      *( (volatile Uint8 *) 0x2C)

#define UART_UCSRB_Reg     ( (volatile UART_UCSRB_Reg_Type *) 0x2A)
#define UART_UCSRA_Reg     ( (volatile UART_UCSRA_Reg_Type *) 0x2B)
#define UART_UCSRC_Reg     ( (volatile UART_UCSRC_Reg_Type *) 0x40)

#endif /* UART_HW_H_ */