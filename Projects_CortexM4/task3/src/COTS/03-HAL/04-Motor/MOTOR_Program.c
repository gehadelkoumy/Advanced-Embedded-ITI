/*****************************************/
/* Author  :  Gehad Elkoumy              */
/* Version :  V01                        */
/* Date    :  14 Sep 2023                */
/*****************************************/

#include "../../01-LIB/01-STD_TYPES/STD_TYPES.h"
#include "../../01-LIB/02-BIT_MATH/BIT_MATH.h"

#include "../../02-MCAL/02-GPIO/GPIO_interface.h"
#include "../../02-MCAL/06-STK/STK_interface.h"

#include "MOTOR_Config.h"
#include "MOTOR_Interface.h"


void HMOTOR_voidInit(u8 Copy_u8EN, u8 Copy_u8IN1, u8 Copy_u8IN2)
{
	MGPIO_VoidSetPinMode(MOTOR_port, Copy_u8EN, OUTPUT);
	MGPIO_VoidSetPinOutputType(MOTOR_port, Copy_u8EN, OUTPUT_PP);

	MGPIO_VoidSetPinMode(MOTOR_port, Copy_u8IN1, OUTPUT);
	MGPIO_VoidSetPinOutputType(MOTOR_port, Copy_u8IN1, OUTPUT_PP);

	MGPIO_VoidSetPinMode(MOTOR_port, Copy_u8IN2, OUTPUT);
	MGPIO_VoidSetPinOutputType(MOTOR_port, Copy_u8IN2, OUTPUT_PP);

}

void HMOTOR_voidRotation(u8 Copy_u8EN, u8 Copy_u8IN1, u8 Copy_u8IN2, u8 Copy_u8Direction)
{
	switch(Copy_u8Direction)
	{
	case stop:
		MGPIO_VoidSetPinValue(MOTOR_port, Copy_u8EN, LOW);
		break;

	case CW:
		MGPIO_VoidSetPinValue(MOTOR_port, Copy_u8IN1, HIGH);
		MGPIO_VoidSetPinValue(MOTOR_port, Copy_u8IN2, LOW);
		MGPIO_VoidSetPinValue(MOTOR_port, Copy_u8EN, HIGH);
		break;

	case CCW:
		MGPIO_VoidSetPinValue(MOTOR_port, Copy_u8IN1, LOW);
		MGPIO_VoidSetPinValue(MOTOR_port, Copy_u8IN2, HIGH);
		MGPIO_VoidSetPinValue(MOTOR_port, Copy_u8EN, HIGH);
		break;
	}

}
