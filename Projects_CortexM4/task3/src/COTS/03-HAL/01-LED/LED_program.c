/**********************************************************/
/* Author    : Gehad Ekoumy                               */
/* Version   : V01                           		     */
/* Date      : 16 AUG 2023                                */
/**********************************************************/

#include "../../01-LIB/01-STD_TYPES/STD_TYPES.h"
#include "../../01-LIB/02-BIT_MATH/BIT_MATH.h"

#include "../../02-MCAL/02-GPIO/GPIO_interface.h"
#include "../../02-MCAL/06-STK/STK_interface.h"

#include "LED_private.h"
#include "LED_interface.h"
#include "LED_config.h"

void HLED_VoidInit(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	MGPIO_VoidSetPinMode(Copy_u8Port , Copy_u8Pin , OUTPUT);
	MGPIO_VoidSetPinOutputSpeed(Copy_u8Port , Copy_u8Pin , OUTPUT_SPEED_LOW);
	MGPIO_VoidSetPinOutputType(Copy_u8Port , Copy_u8Pin , OUTPUT_PP);
}


void HLED_VoidLedState(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8LedState)
{
	MGPIO_VoidSetPinValue(Copy_u8Port , Copy_u8Pin , Copy_u8LedState);
}


void HLED_VoidLedBlink(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	MGPIO_VoidSetPinValue(Copy_u8Port , Copy_u8Pin , LED_ON);
	MSTK_voidSetBusyWait(10000000);
	MGPIO_VoidSetPinValue(Copy_u8Port , Copy_u8Pin , LED_OFF);
	MSTK_voidSetBusyWait(10000000);
}
