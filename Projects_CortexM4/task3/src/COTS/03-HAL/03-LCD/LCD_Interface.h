/*****************************************/
/* Author  :  Gehad Elkoumy              */
/* Version :  V01                        */
/* Date    :  13 Sep 2023                */
/*****************************************/

#ifndef _LCD_INTERFACE_H            //header file guard
#define _LCD_INTERFACE_H

#define FunctionSet        (0b00111000)
#define Display_ON_OFF     (0b00001100)
#define CLR_Display        (0b00000001)

#define DDRAM_Address      (0x80)
#define LineOne            (0x40)

#define ZeroASCIICode       48


                        /*Functions Prototypes*/
void HLCD_voidInitialize(void);
void HLCD_voidWriteCommand(u8 Copy_u8Command);
void HLCD_voidWriteData(u8 Copy_u8Data);
void HLCD_voidGoToXY(u8 Copy_u8Digits , u8 Copy_u8Line);
void HLCD_voidString(u8 * Copy_u8Data);
void HLCD_voidNumbers(u32 Copy_u32Number);
void HLCD_voidWriteSpecialCharacter(u8 *pattern , u8 Copy_u8Character , u8 Col , u8 Row);
void HLCD_voidClear(void);


#endif
