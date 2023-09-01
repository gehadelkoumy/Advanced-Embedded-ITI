/*****************************************/
/* Author  :  Gehad Elkoumy              */
/* Version :  V01                        */
/* Date    :  23 AUG 2023                */
/*****************************************/

#include "../../01-LIB/01-STD_TYPES/STD_TYPES.h"
#include "../../01-LIB/02-BIT_MATH/BIT_MATH.h"

#include "../01-RCC/RCC_interface.h"
#include "../02-GPIO/GPIO_interface.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void MUSART1_voidInit(void)
{
	/*Enable clock of SYSCFG, GPIOA , USART1*/
	MRCC_voidEnableClock(RCC_APB2,SYSCFG_EN);
	MRCC_voidEnableClock(RCC_AHB1,GPIOA_EN);
	MRCC_voidEnableClock(RCC_APB2,USART1_EN);

	/*pin mode*/
	MGPIO_VoidSetPinMode(GPIO_A,PIN9,AF);   // TX
	MGPIO_VoidSetPinMode(GPIO_A,PIN10,AF);   // RX
	
	MGPIO_VoidSetPinAlternativeFunction(GPIO_A,PIN9,AF7);
	MGPIO_VoidSetPinAlternativeFunction(GPIO_A,PIN10,AF7);

	/*	baud rate	*/
	USART1 -> BRR = BaudRate;

	USART1 -> CR1.TE = 1;				/* Enabling Transmitter */
	USART1 -> CR1.RE = 1;				/* Enabling Receiver */
	
	USART1 -> SR = 0;					/* Clearing status register */
}


void MUSART1_voidEnable(void)
{
	USART1 -> CR1.UE = 1;
}

void MUSART1_voidDisable(void)
{
	USART1 -> CR1.UE = 0;
}


void MUSART1_voidSendData(u8 Copy_u16Data)
{
	USART1 -> DR = Copy_u16Data;
	while((GET_BIT((USART1 -> SR), 6)) == 0);
	CLR_BIT(USART1->SR,6);

}

void MUSART1_voidSendString(u8 *Copy_u8String)
{
	while( (*Copy_u8String) != '\0' )
		{
			MUSART1_voidSendData(*Copy_u8String);
			Copy_u8String++;
		}
}

void MUSART1_voidSendNumbers(s32 Copy_s32Number)
{
	char arr[15];
	/* convert number to string */
	//	gcvt(Copy_s32Number, 8,arr);
	itoa(Copy_s32Number , arr , 10);
	u8* string = (u8*)arr;

	MUSART1_voidSendString(string);
}

u8 MUSART1_u8ReceiveData(void)
{
	u8 Loc_u8ReceivedData = 0;
	/* wait until receive complete*/
	while((GET_BIT((USART1 -> SR), 5)) == 0);
	Loc_u8ReceivedData = USART1 -> DR;
	return (Loc_u8ReceivedData);
}

u8 MUSART1_u8ReceiveDataBlock(u8* Copy_u8DataArr)
{
	u8 Loc_u8Data = 0;
	u8 Loc_u8Index = 0;

	Loc_u8Data = MUSART1_u8ReceiveData();

	while(Loc_u8Data != '\0')
	{
		Copy_u8DataArr[Loc_u8Index] = Loc_u8Data;
		Loc_u8Index++;
		Loc_u8Data = MUSART1_u8ReceiveData();
	}

	return Loc_u8Index;
}


void MUSART1_VoidSetCallBack(void (*ptr) (void))
{
	USART1_GlobalPtr = ptr;
}

void USART1_IRQHandler(void)
{
	USART1_GlobalPtr();
}





















