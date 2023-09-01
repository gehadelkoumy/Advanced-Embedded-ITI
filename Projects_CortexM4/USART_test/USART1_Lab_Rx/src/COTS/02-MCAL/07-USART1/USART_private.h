/*****************************************/
/* Author  :  Gehad Elkoumy              */
/* Version :  V01                        */
/* Date    :  23 AUG 2023                */
/*****************************************/

#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

#define 	USART1_Base_Address		0x40011000

typedef struct{
	u32 SBK			:1	;
	u32 RWU			:1	;
	u32 RE			:1	;
	u32 TE			:1	;
	u32 IDLEIE		:1	;
	u32 RXNEIE		:1	;
	u32 TCIE		:1	;
	u32 TXEIE		:1	;
	u32 PEIE		:1	;
	u32 PS			:1	;
	u32 PCE			:1	;
	u32 WAKE		:1	;
	u32 M			:1	;
	u32 UE			:1	;
	u32 RESERVED	:1	;
	u32 OVER8		:1	;
	u32 RESERVED1	:16	;
}CR1_t;

typedef struct{
	volatile u32 	SR;
	volatile u32 	DR;
	volatile u32 	BRR;
	volatile CR1_t  CR1;
	volatile u32 	CR2;
	volatile u32 	CR3;
	volatile u32 	GTPR;
}USART_t;


#define 	USART1 		((USART_t *) USART1_Base_Address)

static void (*USART1_GlobalPtr) (void) = '\0' ;



#endif
