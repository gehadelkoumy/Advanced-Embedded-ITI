/*
 * MUARt-Prog.c
 *
 *  Created on: Aug 22, 2023
 *      Author: Menna
 */

#include "../../01-LIB/01-STD_TYPES/STD_TYPES.h"
#include "../../01-LIB/02-BIT_MATH/BIT_MATH.h"

#include "MUSART_Config.h"
#include "MUSART_Interface.h"
#include "MUSART_Private.h"

void MUSART_voidInit(void){

	// Word length
	#if USART1_WORD_LENGTH == 8
		CLR_BIT(USART1 -> CR1, CR1_M);

	#elif USART1_WORD_LENGTH == 9
		SET_BIT(USART1 -> CR1, CR1_M);
	#endif

	// Stop bits
	#if USART1_STOP_BITS == 1
		CLR_BIT(USART1 -> CR2, CR2_STOP0);
		CLR_BIT(USART1 -> CR2, CR2_STOP1);
	// ADD OTHER OPTIONS LATER
	#endif

	// BAUD RATE
	// USART1 -> BRR = 0x0000008B;
	USART1 -> BRR = 0x410b0000;

	#if USART1_INTERRUPT_ENABLE == 1
		SET_BIT(USART1 -> CR1, CR1_RXNEIE);
	#endif

	SET_BIT(USART1 -> CR1, CR1_TE);
	SET_BIT(USART1 -> CR1, CR1_RE);

	SET_BIT(USART1 -> CR1, CR1_UE);     // Enable UART
}


void MUSART_voidDisable(void){

	CLR_BIT(USART1 -> CR1, CR1_TE);
	CLR_BIT(USART1 -> CR1, CR1_RE);
}


void MUSART_voidSendData(u8 copy_u8Data){

	USART1 -> DR = copy_u8Data;
	while(!GET_BIT(USART1 -> SR, SR_TC));
}


u8 MUSART_u8Receive(void){

	if(GET_BIT(USART1 -> SR, SR_RXNE)){
		return USART1 -> DR;
	}
}


/* Set Callback */
static void(*USART_GPFun)(void) = {0};

void MUSART_voidSetCallBack(void (*ptr)){

	USART_GPFun = ptr;
}


void USART1_IRQHandler(void){
	if(USART_GPFun){
		USART_GPFun();
	}
}
