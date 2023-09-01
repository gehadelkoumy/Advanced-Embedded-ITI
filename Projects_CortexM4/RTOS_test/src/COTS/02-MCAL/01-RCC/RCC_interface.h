/*********************************************************************************/
/* Author    : Gehad Elkoumy                                                     */
/* Version   : V01                                                               */
/* Data      : 11 AUG 2023                                                       */
/*********************************************************************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H


/*Bus Id*/
#define RCC_AHB1      0 
#define RCC_AHB2      1 
#define RCC_APB1      2
#define RCC_APB2      3


void MRCC_voidInitSysClock(void);
void MRCC_voidEnableClock(u8 Copy_u8BusId , u8 Copy_u8PeripheralId);
void MRCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PeripheralId);


#endif