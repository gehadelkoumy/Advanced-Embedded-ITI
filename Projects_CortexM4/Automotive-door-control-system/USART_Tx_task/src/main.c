/*
 * main.c
 *
 *  Created on: Aug 28, 2023
 *  Author: Gehad
 *
 *  Description: - Depending on the state of a button, a motor is turned on or off.
 *  			 - When the button is pressed, Motor ON (the car is moving), if not, then the motor is OFF
 *  			   (the car has stopped).
 *  			 - The state of the motor is always sent to another microcontroller to check if the car door
 *  			    is open or not for car safety.
 *  			 - If the door is opened, a buzzer will be turned on...
 *  			   (that will be handled in the RX script).
 *
 *  Pin used:     A5 	--> Button
 *  		   	  B6    --> Motor
 *  		   A9 & A10 --> USART
 */

#include "COTS/01-LIB/01-STD_TYPES/STD_TYPES.h"
#include "COTS/01-LIB/02-BIT_MATH/BIT_MATH.h"

#include "COTS/02-MCAL/01-RCC/RCC_interface.h"
#include "COTS/02-MCAL/02-GPIO/GPIO_interface.h"
#include "COTS/02-MCAL/03-NVIC/NVIC_interface.h"
#include "COTS/02-MCAL/04-EXTI/EXTI_interface.h"
#include "COTS/02-MCAL/05-SYSCFG/SYSCFG_interface.h"
#include "COTS/02-MCAL/06-STK/STK_interface.h"
#include "COTS/02-MCAL/07-USART1/USART_interface.h"

#include "COTS/04-SERVICES/OS_interface.h"

#include "COTS/03-HAL/01-LED/LED_interface.h"
#include "COTS/03-HAL/02-SWITCH/SWITCH_interface.h"


void main()
{
	/*initialize clocks*/
	MRCC_voidInitSysClock();

	/*Enable GPIOA clock */
	MRCC_voidEnableClock(RCC_AHB1,GPIOA_EN);
	MRCC_voidEnableClock(RCC_AHB1,GPIOB_EN);

	/* switch */
	HSWITCH_VoidInit(GPIO_A,PIN5,PULL_DOWN);

	/* DC Motor */
	MGPIO_VoidSetPinMode(GPIO_B,PIN6,OUTPUT);
	MGPIO_VoidSetPinOutputType(GPIO_B,PIN6,OUTPUT_PP);

	/* Initialize USART */
	MUSART1_voidInit();
	MUSART1_voidEnable();

	volatile u8 ButtonState = 0;

	while(1)
	{
		/* Get the state of the button */
		ButtonState = MGPIO_u8GetPinValue(GPIO_A,PIN5);

		/* Motor is ON or OFF depending on button state */
		MGPIO_VoidSetPinValue(GPIO_B,PIN6,ButtonState);

		/* Send Motor state to another micro-controller */
		MUSART1_voidSendNumbers(ButtonState);
	}
}
