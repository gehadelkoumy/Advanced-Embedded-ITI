/*
 * main.c
 *
 *  Created on: Aug 23, 2023
 *  Author: Gehad
 *
 *  Description: Sending 1 from MCU to another one if a button is pressed
 *  Pin used:  A0 --> button
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

void ButtonPressed (void);

void main()
{
	/*initialize clocks*/
	MRCC_voidInitSysClock();

	/*Enable GPIOA clock */
	MRCC_voidEnableClock(RCC_AHB1,0);

	/*Enable SYSCFG clock */
	MRCC_voidEnableClock(RCC_APB2,14);

	/* switch */
	HSWITCH_VoidInit(GPIO_A,PIN0,PULL_UP);

	/* SYSFG for portA */
	MSYSCFG_voidSetEXTIConfiguration(LINE0,SYSCFG_A);

	/* Init EXTI */
	MEXTI_voidInit();
	MEXTI_voidSetSignalLatch(LINE0 , FALLING);
	EXTI_voidSetCallBack(ButtonPressed , LINE0);

	MNVIC_voidEnableInterrupt(6);

	/* Initialize USART */
	MUSART1_voidInit();
	MUSART1_voidEnable();


	while(1)
	{

	}
}

/* ISR of EXTI0 */
void ButtonPressed (void)
{
	MUSART1_voidSendNumbers(1);
}
