/*********************************************************************************/
/* Author    : Gehad Elkoumy                                                     */
/* Version   : V01                                                               */
/* Date      : 13 AUG 2023                                                       */
/*********************************************************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

/*			Pin State				*/
#define 		HIGH    		1
#define 		LOW     		0

/* 			   Port Id 				*/
#define 		GPIO_A   		0
#define 		GPIO_B   		1
#define 		GPIO_C   		2

/* 			   Pin Id				*/
#define 		PIN0    		0
#define 		PIN1    		1
#define 		PIN2    		2
#define 		PIN3    		3
#define 		PIN4    		4
#define 		PIN5    		5
#define 		PIN6    		6
#define 		PIN7    		7
#define 		PIN8    		8
#define 		PIN9    		9
#define 		PIN10   		10
#define 		PIN11   		11
#define 		PIN12   		12
#define 		PIN13   		13
#define 		PIN14   		14
#define 		PIN15   		15


/* 				Macros for GPIO Modes 				*/
#define 		INPUT      	  	0b00
#define 		OUTPUT     	  	0b01
#define 		AF       	  	0b10			//Alternative Function
#define 		ANALOG     	  	0b11

/* 				Macros for Output Type 				*/
#define 		OUTPUT_PP    		0		    //push pull
#define 		OUTPUT_OD   		1           //open drain

/* 				Macros for Output speed 				*/
#define 		OUTPUT_SPEED_LOW       		0b00
#define 		OUTPUT_SPEED_MEDUIM    		0b01
#define 		OUTPUT_SPEED_HIGH      		0b10
#define 		OUTPUT_SPEED_VERY_HIGH 		0b11

/* 				Macros for pull 						*/
#define 		PULL_OFF              0b00
#define 		PULL_UP               0b01
#define 		PULL_DOWN             0b10

/* 				Macros for Alternative Function 		*/
#define 		AF0           0b0000
#define 		AF1           0b0001
#define 		AF2           0b0010
#define 		AF3           0b0011
#define 		AF4           0b0100
#define 		AF5           0b0101
#define 		AF6           0b0110
#define 		AF7           0b0111
#define 		AF8           0b1000
#define 		AF9           0b1001
#define 		AF10          0b1010
#define 		AF11          0b1011
#define 		AF12          0b1100
#define 		AF13          0b1101
#define 		AF14          0b1110
#define 		AF15          0b1111

/*               					Functions Prototypes								*/
void MGPIO_VoidSetPinMode(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Mode);
void MGPIO_VoidSetPinOutputType(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8OutputType);
void MGPIO_VoidSetPinOutputSpeed(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8OutputSpeed);
void MGPIO_VoidSetPullType(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8PullType);
void MGPIO_VoidSetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value);
void MGPIO_VoidSetPinValueFast(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value);
u8 MGPIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin);
void MGPIO_VoidSetPinAlternativeFunction(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8AF);
void MGPIO_VoidLockPin(u8 Copy_u8Port , u8 Copy_u8Pin);
void MGPIO_VoidSetLowerPinValue(u8 Copy_u8Port , u8 Copy_u8Value);


#endif
