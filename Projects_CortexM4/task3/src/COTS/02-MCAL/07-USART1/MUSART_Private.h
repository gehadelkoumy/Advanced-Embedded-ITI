/*
 * MUART_Private.h
 *
 *  Created on: Aug 22, 2023
 *      Author: Menna
 */

#ifndef MCAL_MUSART_MUSART_PRIVATE_H_
#define MCAL_MUSART_MUSART_PRIVATE_H_

#define USART1_BASE_ADD		0x40011000
#define USART2_BASE_ADD		0x40004400
#define USART6_BASE_ADD		0x40011400

typedef struct{

	u32 SR;
	u32 DR;
	u32 BRR;
	u32 CR1;
	u32 CR2;
	u32 CR3;
	u32 GTPR;

}UART_MemMap_t;

#define USART1   ((volatile UART_MemMap_t*) USART1_BASE_ADD)
#define USART2   ((volatile UART_MemMap_t*) USART2_BASE_ADD)
#define USART6   ((volatile UART_MemMap_t*) USART6_BASE_ADD)


/* CR1 bits */
#define CR1_UE		13
#define CR1_M 		12

#define CR1_PCE		10
#define CR1_PS		9
#define CR1_PEIE	8
#define CR1_TXEIE	7

#define CR1_RXNEIE	5

#define CR1_TE		3
#define CR1_RE		2

/* CR2 bits */
#define CR2_STOP0	12
#define CR2_STOP1	13

// SR bits
#define SR_TC		6
#define SR_RXNE		5


/* BRR */
// Baud rate

#endif /* MCAL_MUSART_MUSART_PRIVATE_H_ */
