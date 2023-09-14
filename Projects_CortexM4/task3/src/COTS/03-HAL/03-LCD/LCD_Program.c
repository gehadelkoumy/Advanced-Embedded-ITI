/*****************************************/
/* Author  :  Gehad Elkoumy              */
/* Version :  V01                        */
/* Date    :  13 Sep 2023                */
/*****************************************/

#include "../../01-LIB/01-STD_TYPES/STD_TYPES.h"
#include "../../01-LIB/02-BIT_MATH/BIT_MATH.h"

#include "../../02-MCAL/02-GPIO/GPIO_interface.h"
#include "../../02-MCAL/06-STK/STK_interface.h"

#include "LCD_Config.h"
#include "LCD_Interface.h"

//___________________________________________initialize LCD____________________________________
void HLCD_voidInitialize(void)
{
	 /*set pin direction (called only one time)*/
	MGPIO_VoidSetPinMode(RS_Write_EN_port , RS , OUTPUT);     //RS
	MGPIO_VoidSetPinMode(RS_Write_EN_port , Write , OUTPUT);     //R/W
	MGPIO_VoidSetPinMode(RS_Write_EN_port , EN , OUTPUT);     //Enable
	          /*set port direction*/
	MGPIO_VoidSetPinMode(LCD_port , PIN0, OUTPUT);
	MGPIO_VoidSetPinMode(LCD_port , PIN1, OUTPUT);
	MGPIO_VoidSetPinMode(LCD_port , PIN2, OUTPUT);
	MGPIO_VoidSetPinMode(LCD_port , PIN3, OUTPUT);
	MGPIO_VoidSetPinMode(LCD_port , PIN4, OUTPUT);
	MGPIO_VoidSetPinMode(LCD_port , PIN5, OUTPUT);
	MGPIO_VoidSetPinMode(LCD_port , PIN6, OUTPUT);
	MGPIO_VoidSetPinMode(LCD_port , PIN7, OUTPUT);
	
	MSTK_voidSetBusyWait(30000);
	//_delay_ms(30);
    HLCD_voidWriteCommand(FunctionSet);     //send command function set
	//_delay_ms(2);
    MSTK_voidSetBusyWait(2000);
	HLCD_voidWriteCommand(Display_ON_OFF);     //send command display on/off
	//_delay_ms(2);
	MSTK_voidSetBusyWait(2000);
	HLCD_voidWriteCommand(CLR_Display);     //send command clear display
	MSTK_voidSetBusyWait(2000);
}
//___________________________________________write command____________________________________-
void HLCD_voidWriteCommand(u8 Copy_u8Command)
{
	/*RS = 0*/
	MGPIO_VoidSetPinValue(RS_Write_EN_port , RS , LOW);
	/*R/W = 0*/
	MGPIO_VoidSetPinValue(RS_Write_EN_port , Write , LOW);
	/*send command*/
	MGPIO_VoidSetLowerPinValue(LCD_port , Copy_u8Command);
	/*Enable pulse*/
	MGPIO_VoidSetPinValue(RS_Write_EN_port , EN , HIGH);
	//_delay_ms(2);
	MSTK_voidSetBusyWait(20000);
	MGPIO_VoidSetPinValue(RS_Write_EN_port , EN , LOW);
}

//____________________________________________write data______________________________________
void HLCD_voidWriteData(u8 Copy_u8Data)
{
	/*RS = 1*/
	MGPIO_VoidSetPinValue(RS_Write_EN_port , RS , HIGH);
	/*R/W = 0*/
	MGPIO_VoidSetPinValue(RS_Write_EN_port , Write , LOW);
	/*send data*/
	MGPIO_VoidSetLowerPinValue(LCD_port , Copy_u8Data);
	/*Enable pulse*/
	MGPIO_VoidSetPinValue(RS_Write_EN_port , EN , HIGH);
	//_delay_ms(2);
	MSTK_voidSetBusyWait(2000);
	MGPIO_VoidSetPinValue(RS_Write_EN_port , EN , LOW);
}
//__________________________________________specify position___________________________________
void HLCD_voidGoToXY(u8 Copy_u8Digits , u8 Copy_u8Line)
{
	if (Copy_u8Line == 1)
	{
		HLCD_voidWriteCommand( DDRAM_Address + Copy_u8Digits );
	}

	else if(Copy_u8Line == 2)
	{
		HLCD_voidWriteCommand( DDRAM_Address + LineOne + Copy_u8Digits );
	}
}
//____________________________________________display string____________________________________
void HLCD_voidString(u8 * Copy_u8Data)
{
	while( (*Copy_u8Data) != '\0' )
	{
		HLCD_voidWriteData(*Copy_u8Data);
		Copy_u8Data++;
	}
}
//____________________________________________display numbers_________________________________
void HLCD_voidNumbers(u32 Copy_u32Number)
{
		u8 arr[15];
		u8 digits = 0;
		while(Copy_u32Number != 0)
		{
			arr[digits] = (Copy_u32Number % 10) + ZeroASCIICode ;
			Copy_u32Number /= 10 ;
			digits++;
		}
		for(s8 j=digits-1 ; j>=0 ; j--)
		{
			HLCD_voidWriteData(arr[j]);
		}
}
//_____________________________________________write special character_________________________
void HLCD_voidWriteSpecialCharacter(u8 *pattern , u8 Copy_u8Character , u8 Col , u8 Row)
{
	HLCD_voidWriteCommand(64 + (Copy_u8Character*8));     //CGRAM_Address
	for(u8 i=0 ; i<8 ; i++)
	{
		HLCD_voidWriteData(pattern[i]);
	}
	HLCD_voidGoToXY(Col , Row);
	HLCD_voidWriteData(Copy_u8Character);
}

//_______________________________________________Clear LCD_____________________________________
void HLCD_voidClear(void)
{
	HLCD_voidWriteCommand(CLR_Display);
}

