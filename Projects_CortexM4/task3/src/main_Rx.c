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
#include "COTS/02-MCAL/07-USART1/MUSART_Interface.h"


#include "COTS/03-HAL/01-LED/LED_interface.h"
#include "COTS/03-HAL/02-SWITCH/SWITCH_interface.h"
#include "COTS/03-HAL/03-LCD/LCD_interface.h"
#include "COTS/03-HAL/05-Buzzer/BUZ_interface.h"


#define BUZZ 	15

#define DOOR1 	5
#define DOOR2 	6
#define DOOR3 	7
#define DOOR4 	8

#define EXTI5_9 23
#define USART_INT 37

#define TX		9
#define RX		10

u8 motor_state = 0;
u8 door1_state = 0;
u8 door2_state = 0;
u8 door3_state = 0;
u8 door4_state = 0;

u8 any_door_state = 0;


void LCD_update()
{
	HLCD_voidGoToXY(0, 1);
	HLCD_voidString((u8*)"1:");
	if(!door1_state)
		HLCD_voidString((u8*)"CLOSE");
	else
		HLCD_voidString((u8*)"OPEN ");

	HLCD_voidGoToXY(9, 1);
	HLCD_voidString((u8*)"2:");
		if(!door2_state)
			HLCD_voidString((u8*)"CLOSE");
		else
			HLCD_voidString((u8*)"OPEN ");

	HLCD_voidGoToXY(0, 2);
	HLCD_voidString((u8*)"3:");
		if(!door3_state)
			HLCD_voidString((u8*)"CLOSE");
		else
			HLCD_voidString((u8*)"OPEN ");

	HLCD_voidGoToXY(9, 2);
	HLCD_voidString((u8*)"4:");
		if(!door4_state)
			HLCD_voidString((u8*)"CLOSE");
		else
			HLCD_voidString((u8*)"OPEN ");
}



void Door1Interrupt(){
	door1_state = HSWITCH_u8GetSwitchState(GPIO_B, DOOR1);
	any_door_state = door1_state || door2_state || door3_state || door4_state;

	if((!motor_state) & any_door_state){
		HBUZZER_voidBuzzerState(GPIO_B, BUZZ, HIGH);
	}
	else{
		HBUZZER_voidBuzzerState(GPIO_B, BUZZ, LOW);
	}
}


void Door2Interrupt(){
	door2_state = HSWITCH_u8GetSwitchState(GPIO_B, DOOR2);
	any_door_state = door1_state || door2_state || door3_state || door4_state;

	if((!motor_state) & any_door_state){
		HBUZZER_voidBuzzerState(GPIO_B, BUZZ, HIGH);
	}

	else{
		HBUZZER_voidBuzzerState(GPIO_B, BUZZ, LOW);
	}
}


void Door3Interrupt(){

	door3_state = HSWITCH_u8GetSwitchState(GPIO_B, DOOR3);
	any_door_state = door1_state || door2_state || door3_state || door4_state;

	if((!motor_state) & any_door_state){
		HBUZZER_voidBuzzerState(GPIO_B, BUZZ, HIGH);
	}

	else{
		HBUZZER_voidBuzzerState(GPIO_B, BUZZ, LOW);
	}
}


void Door4Interrupt(){
	door4_state = HSWITCH_u8GetSwitchState(GPIO_B, DOOR4);
	any_door_state = door1_state || door2_state || door3_state || door4_state;

	if((!motor_state) & any_door_state){
		HBUZZER_voidBuzzerState(GPIO_B, BUZZ, HIGH);
	}

	else{
		HBUZZER_voidBuzzerState(GPIO_B, BUZZ, LOW);
	}
}

void motorInterrupt(){
	motor_state = MUSART_u8Receive();

	if((!motor_state) & any_door_state){
		HBUZZER_voidBuzzerState(GPIO_B, BUZZ, HIGH);
	}

	else{
		HBUZZER_voidBuzzerState(GPIO_B, BUZZ, LOW);
	}
}



void main()
{
	/*initialize clocks*/
	MRCC_voidInitSysClock();

	/*Enable GPIOB clock */
	MRCC_voidEnableClock(RCC_AHB1,GPIOB_EN);

	/*Enable GPIOA clock */
	MRCC_voidEnableClock(RCC_AHB1,GPIOA_EN);

	/*Enable USART clock */
	MRCC_voidEnableClock(RCC_APB2,USART1_EN);

	/*Enable SYSCNF clock*/
	MRCC_voidEnableClock(RCC_APB2,SYSCFG_EN);

	/* Initialize USART */
	MGPIO_VoidSetPinMode(GPIO_A, TX, AF);
	MGPIO_VoidSetPinMode(GPIO_A, RX, AF);

	MGPIO_VoidSetPinAlternativeFunction(GPIO_A, TX, AF7);
	MGPIO_VoidSetPinAlternativeFunction(GPIO_A, RX, AF7);

	MUSART_voidInit();

	/* switch */
	HSWITCH_VoidInit(GPIO_B,DOOR1,PULL_UP);
	HSWITCH_VoidInit(GPIO_B,DOOR2,PULL_UP);
	HSWITCH_VoidInit(GPIO_B,DOOR3,PULL_UP);
	HSWITCH_VoidInit(GPIO_B,DOOR4,PULL_UP);

	/* Buzzer */
	HBUZZER_voidInit(GPIO_B, BUZZ);

	/*NVIC Enable*/
	MNVIC_voidEnableInterrupt(EXTI5_9);

	/*Set Interrupt to port B*/
	MSYSCFG_voidSetEXTIConfiguration(DOOR1,SYSCFG_B);
	MSYSCFG_voidSetEXTIConfiguration(DOOR2,SYSCFG_B);
	MSYSCFG_voidSetEXTIConfiguration(DOOR3,SYSCFG_B);
	MSYSCFG_voidSetEXTIConfiguration(DOOR4,SYSCFG_B);

	/*Enable Interrupts*/
	MEXTI_voidEnableEXTI(DOOR1);
	MEXTI_voidEnableEXTI(DOOR2);
	MEXTI_voidEnableEXTI(DOOR3);
	MEXTI_voidEnableEXTI(DOOR4);

	/*Select signal latch*/
	MEXTI_voidSetSignalLatch(DOOR1 , ON_CHANGE);
	MEXTI_voidSetSignalLatch(DOOR2 , ON_CHANGE);
	MEXTI_voidSetSignalLatch(DOOR3 , ON_CHANGE);
	MEXTI_voidSetSignalLatch(DOOR4 , ON_CHANGE);

	/*Set EXTI callback*/
	MEXTI_voidSetCallBack(Door1Interrupt,DOOR1);
	MEXTI_voidSetCallBack(Door2Interrupt,DOOR2);
	MEXTI_voidSetCallBack(Door3Interrupt,DOOR3);
	MEXTI_voidSetCallBack(Door4Interrupt,DOOR4);


	/*USART Interrupt*/
	MNVIC_voidEnableInterrupt(USART_INT);
	MUSART_voidSetCallBack(motorInterrupt);

	/* Initialize states*/
	door1_state = HSWITCH_u8GetSwitchState(GPIO_B, DOOR1);
	door2_state = HSWITCH_u8GetSwitchState(GPIO_B, DOOR2);
	door3_state = HSWITCH_u8GetSwitchState(GPIO_B, DOOR3);
	door4_state = HSWITCH_u8GetSwitchState(GPIO_B, DOOR4);
	any_door_state = door1_state || door2_state || door3_state || door4_state;

	/* LCD */
	MSTK_voidInit();
	HLCD_voidInitialize();

	LCD_update();

	MSTK_voidSetIntervalPeriodic(10000000, LCD_update);

//	MEXTI_voidSoftwareTrigger(5);

	while(1)
	{

	}

}

