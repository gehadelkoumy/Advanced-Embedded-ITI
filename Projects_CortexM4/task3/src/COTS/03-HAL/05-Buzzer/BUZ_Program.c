/*****************************************/
/* Author  :  Gehad Elkoumy              */
/* Version :  V01                        */
/* Date    :  14 Sep 2023                */
/*****************************************/

#include "../../01-LIB/01-STD_TYPES/STD_TYPES.h"
#include "../../01-LIB/02-BIT_MATH/BIT_MATH.h"

#include "../../02-MCAL/02-GPIO/GPIO_interface.h"
#include "../../02-MCAL/06-STK/STK_interface.h"

#include "BUZ_Config.h"
#include "BUZ_Interface.h"

void HBUZZER_voidInit(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	MGPIO_VoidSetPinMode(Copy_u8Port, Copy_u8Pin, OUTPUT);
	MGPIO_VoidSetPinOutputType(Copy_u8Port, Copy_u8Pin, OUTPUT_PP);
}

void HBUZZER_voidBuzzerState(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8BuzzerState)
{
	MGPIO_VoidSetPinValue(Copy_u8Port, Copy_u8Pin, Copy_u8BuzzerState);
}
