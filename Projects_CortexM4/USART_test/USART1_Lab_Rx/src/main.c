/*
 * main.c
 *
 *  Created on: Aug 23, 2023
 *  Author: Gehad
 *
 *  Description: Turning a LED ON depending on the received data from another MCU
 *  Pin used:  A1 for red led
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
	MRCC_voidEnableClock(RCC_AHB1,0);

	HLED_VoidInit(GPIO_A,PIN1);

	/* Initialize USART */
	MUSART1_voidInit();
	MUSART1_voidEnable();

	u16 received_data = 0 ;

	while(1)
	{
		/* Receive data from first MC */
		 received_data = MUSART1_u8ReceiveData() - ZeroASCIICode;

		/* Check the received value */
		if (received_data == 1)
		{
			/* LED ON */
			MGPIO_VoidSetPinValue(GPIO_A,PIN1, HIGH);
		}
		else
		{
			/* LED OFF */
			MGPIO_VoidSetPinValue(GPIO_A, PIN1, LOW);
		}
	}
}
