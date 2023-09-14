/**********************************************************/
/* Author    : Gehad Ekoumy                               */
/* Version   : V01                           		     */
/* Date      : 16 AUG 2023                                */
/**********************************************************/

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

void HLED_VoidInit(u8 Copy_u8Port,u8 Copy_u8Pin);
void HLED_VoidLedState(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8LedState);
void HLED_VoidLedBlink(u8 Copy_u8Port,u8 Copy_u8Pin);

/* Led state */
#define		LED_ON		1
#define 	LED_OFF		0


#endif
