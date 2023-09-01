/*
 * main.c
 *
 *  Created on: Aug 16, 2023
 *  Author: Gehad
 *
 *  Description: Traffic light project using RTOS
 *  Pin used:  A1, A2 and A3 for leds
 */

#include "COTS/01-LIB/01-STD_TYPES/STD_TYPES.h"
#include "COTS/01-LIB/02-BIT_MATH/BIT_MATH.h"

#include "COTS/02-MCAL/01-RCC/RCC_interface.h"
#include "COTS/02-MCAL/02-GPIO/GPIO_interface.h"
#include "COTS/02-MCAL/03-NVIC/NVIC_interface.h"
#include "COTS/02-MCAL/04-EXTI/EXTI_interface.h"
#include "COTS/02-MCAL/05-SYSCFG/SYSCFG_interface.h"
#include "COTS/02-MCAL/06-STK/STK_interface.h"

#include "COTS/04-SERVICES/OS_interface.h"

#include "COTS/03-HAL/01-LED/LED_interface.h"
#include "COTS/03-HAL/02-SWITCH/SWITCH_interface.h"

void RedLED(void)
{
	static u8 local_u8Pin1 = 0;
	TOG_BIT(local_u8Pin1 , 0);
	MGPIO_VoidSetPinValue(GPIO_A ,PIN1 ,local_u8Pin1);
}

void YellowLED(void)
{
	static u8 local_u8Pin2 = 0;
	TOG_BIT(local_u8Pin2 , 0);
	MGPIO_VoidSetPinValue(GPIO_A ,PIN2 ,local_u8Pin2);
}

void GreenLED(void)
{
	static u8 local_u8Pin3 = 0;
	TOG_BIT(local_u8Pin3 , 0);
	MGPIO_VoidSetPinValue(GPIO_A ,PIN3 ,local_u8Pin3);
}


void main()
{
	/*initialize clocks*/
	MRCC_voidInitSysClock();

	/*Enable GPIOA,B,C clock */
	MRCC_voidEnableClock(RCC_AHB1,0);
//	MRCC_voidEnableClock(RCC_AHB1,1);
//	MRCC_voidEnableClock(RCC_AHB1,2);

	/* three leds */
	HLED_VoidInit(GPIO_A,PIN1);
	HLED_VoidInit(GPIO_A,PIN2);
	HLED_VoidInit(GPIO_A,PIN3);

	/* Create Tasks */
	SOS_voidCreateTask(0,5000,RedLED,0);
	SOS_voidCreateTask(1,6000,YellowLED,1);
	SOS_voidCreateTask(2,7000,GreenLED,2);

	SOS_voidStart();


	while(1)
	{

	}
}
