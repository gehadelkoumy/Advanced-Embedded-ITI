/*
 * main.c
 *
 *  Created on: Aug 28, 2023
 *  Author: Gehad
 *
 *  Description: In this RX script :
 *  			 - check if the car door is open or not by getting the state of a button.
 *  			 - Button ON means that car door is open (not safe if car is moving "if received 1 from
 *  			 	first micro-controller" so a buzzer is ON if that happened).
 *  			 - Button OFF: Car door is close (safe whether the car is moving or not).
 *
 *  Pin used:  	  B2 	--> Button
 *  		   	  B7 	--> Buzzer
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
	HSWITCH_VoidInit(GPIO_B,PIN2,PULL_DOWN);

	/* Buzzer */
	MGPIO_VoidSetPinMode(GPIO_B,PIN7,OUTPUT);
	MGPIO_VoidSetPinOutputType(GPIO_B,PIN7,OUTPUT_PP);

	/* Initialize USART */
	MUSART1_voidInit();
	MUSART1_voidEnable();

	volatile u8 ButtonState = 0;
	u8 ReceivedState = 0;

	while(1)
	{
		/* Get the state of the button */
		ButtonState = MGPIO_u8GetPinValue(GPIO_B,PIN2);

		/* if the button state and received data is 1 then a buzzer is ON */
		if (ButtonState == 1)
		{
			/* Receive Motor state from the 1st micro-controller */
			ReceivedState = MUSART1_u8ReceiveData() - ZeroASCIICode;

			if (ReceivedState == 1)
			{
				/* Buzzer turned ON (both buttons are ON) */
				MGPIO_VoidSetPinValue(GPIO_B,PIN7,HIGH);
			}
			/* handling case that ReceivedState = 0 */
			else
			{
				/* Buzzer turned OFF */
				MGPIO_VoidSetPinValue(GPIO_B,PIN7,LOW);
			}
		}
		/* handling case that buttonState = 0 */
		else
		{
			/* Buzzer turned OFF */
			MGPIO_VoidSetPinValue(GPIO_B,PIN7,LOW);
		}
	}
}
