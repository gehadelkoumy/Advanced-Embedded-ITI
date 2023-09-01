/*****************************************/
/* Author  :  Gehad Elkoumy              */
/* Version :  V01                        */
/* Date    :  23 AUG 2023                */
/*****************************************/

#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

/* Defining Macros */

#define 	BIT_WORD_8					0
#define 	BIT_WORD_9					1
	
#define 	PARITY_DISABLED				0
#define 	PARITY_ENABLED				1
	
#define 	EVEN_PARITY					0
#define 	ODD_PARITY					1
	
#define 	PE_DISABLED					0
#define 	PE_ENABLED					1


#define		Baud_9600				0x683
#define 	Baud_112500				0x410b0000

#define ZeroASCIICode       48

/*******************/

void MUSART1_voidInit(void);
void MUSART1_voidEnable(void);
void MUSART1_voidDisable(void);
void MUSART1_voidSendData(u8 Copy_u16Data);
void MUSART1_voidSendString(u8 *Copy_u8String);
void MUSART1_voidSendNumbers(s32 Copy_s32Number);
u8 MUSART1_u8ReceiveData(void);
u8 MUSART1_u8ReceiveDataBlock(u8* Copy_u8DataArr);
void MUSART1_VoidSetCallBack(void (*ptr) (void));


#endif






