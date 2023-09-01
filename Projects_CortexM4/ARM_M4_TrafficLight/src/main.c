/*
 * main.c
 *
 *  Created on: Aug 16, 2023
 *  Author: Gehad
 *
 *  Description: Traffic light project using a switch
 *  Pin used: A0 for switch -- A1, A2 and A3 for leds
 */

#include "COTS/01-LIB/01-STD_TYPES/STD_TYPES.h"
#include "COTS/01-LIB/02-BIT_MATH/BIT_MATH.h"

#include "COTS/02-MCAL/01-RCC/RCC_interface.h"
#include "COTS/02-MCAL/02-GPIO/GPIO_interface.h"
#include "COTS/02-MCAL/03-NVIC/NVIC_interface.h"
#include "COTS/02-MCAL/04-EXTI/EXTI_interface.h"
#include "COTS/02-MCAL/05-SYSCFG/SYSCFG_interface.h"
#include "COTS/02-MCAL/06-STK/STK_interface.h"

#include "COTS/03-HAL/01-LED/LED_interface.h"
#include "COTS/03-HAL/02-SWITCH/SWITCH_interface.h"


/* ISR for EXTI0 */
void TakeAction0(void)
{
	HLED_VoidLedBlink(GPIO_A,PIN1);
	HLED_VoidLedBlink(GPIO_A,PIN2);
	HLED_VoidLedBlink(GPIO_A,PIN3);
}


void main()
{
	/*initialize clocks*/
	MRCC_voidInitSysClock();

	/*Enable GPIOA,B,C clock */
	MRCC_voidEnableClock(RCC_AHB1,0);
	MRCC_voidEnableClock(RCC_AHB1,1);
	MRCC_voidEnableClock(RCC_AHB1,2);

	/*Enable SYSCFG clock */
	MRCC_voidEnableClock(RCC_APB2,14);

	/* switch */
	HSWITCH_VoidInit(GPIO_A,PIN0,PULL_UP);

	/* three leds */
	HLED_VoidInit(GPIO_A,PIN1);
	HLED_VoidInit(GPIO_A,PIN2);
	HLED_VoidInit(GPIO_A,PIN3);

	/* SYSFG for portA */
	MSYSCFG_voidSetEXTIConfiguration(LINE0,SYSCFG_A);

	/* Init EXTI */
	MEXTI_voidInit();
	MEXTI_voidSetSignalLatch(LINE0 , FALLING);
	EXTI_voidSetCallBack(TakeAction0 , LINE0);

	/* Init systick */
	MSTK_voidInit();

	/*Enable EXTI0 interrupt from NVIC*/
	MNVIC_voidEnableInterrupt(6);


	while(1)
	{

	}
}
