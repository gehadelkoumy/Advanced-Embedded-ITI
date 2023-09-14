/*
 * MUART_Interface.h
 *
 *  Created on: Aug 22, 2023
 *      Author: Menna
 */

#ifndef MCAL_MUSART_MUSART_INTERFACE_H_
#define MCAL_MUSART_MUSART_INTERFACE_H_

void MUSART_voidInit(void);
void MUSART_voidDisable(void);

void MUSART_voidSendData(u8 copy_u8Data);
u8 MUSART_u8Receive(void);

void MUSART_voidSetCallBack(void (*ptr));


#endif /* MCAL_MUSART_MUSART_INTERFACE_H_ */
