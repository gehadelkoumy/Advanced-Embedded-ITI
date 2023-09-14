/*********************************************************************************/
/* Author    : Gehad Elkoumy                                                     */
/* Version   : V01                                                               */
/* Date      : 13 AUG 2023                                                       */
/*********************************************************************************/

#include "../../01-LIB/01-STD_TYPES/STD_TYPES.h"
#include "../../01-LIB/02-BIT_MATH/BIT_MATH.h"

#include "GPIO_private.h"
#include "GPIO_config.h"
#include "GPIO_interface.h"


void MGPIO_VoidSetPinMode(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Mode)
{
	switch(Copy_u8Port)
	{
	case GPIO_A:
		GPIOA -> MODER &= ~ ( ( 0b11 )    << ( Copy_u8Pin * 2 ));  	/*Reset or clear pin mode (2bits)*/
		GPIOA -> MODER |= ( Copy_u8Mode ) << ( Copy_u8Pin * 2 );   	/*apply mode on pin (interface file)*/
		break;

	case GPIO_B:
		/*Reset pin then overwrite*/
		GPIOB -> MODER &= ~ ( ( 0b11 )    << ( Copy_u8Pin * 2 ) );    
		GPIOB -> MODER |= ( Copy_u8Mode ) << ( Copy_u8Pin * 2 )  ;    
		break;
		
	case GPIO_C:
		GPIOC-> MODER &= ~ ( ( 0b11 )    << ( Copy_u8Pin * 2 ) );
		GPIOC-> MODER |= ( Copy_u8Mode ) << ( Copy_u8Pin * 2 )  ;
		break;
	}
}


void MGPIO_VoidSetPinOutputType(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8OutputType)
{
	switch(Copy_u8Port)
	{
	case GPIO_A:
		GPIOA -> OTYPER |= ( Copy_u8OutputType ) << ( Copy_u8Pin );  
		break;

	case GPIO_B:
		GPIOB -> OTYPER |= ( Copy_u8OutputType ) << ( Copy_u8Pin );    
		break;
		
	case GPIO_C:
		GPIOC -> OTYPER |= ( Copy_u8OutputType ) << ( Copy_u8Pin );
		break;
	}
}


void MGPIO_VoidSetPinOutputSpeed(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8OutputSpeed)
{
	switch(Copy_u8Port)
	{
	case GPIO_A:
		GPIOA -> OSPEEDR |= ( Copy_u8OutputSpeed ) << ( Copy_u8Pin * 2 );  
		break;

	case GPIO_B:
		GPIOB -> OSPEEDR |= ( Copy_u8OutputSpeed ) << ( Copy_u8Pin * 2 );    
		break;
		
	case GPIO_C:
		GPIOC -> OSPEEDR |= ( Copy_u8OutputSpeed ) << ( Copy_u8Pin * 2 );
		break;
	}
}


void MGPIO_VoidSetPullType(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8PullType)
{
	switch(Copy_u8Port)
	{
	case GPIO_A:
		GPIOA -> PUPDR |= ( Copy_u8PullType ) << ( Copy_u8Pin * 2 );  
		break;

	case GPIO_B:
		GPIOB -> PUPDR |= ( Copy_u8PullType ) << ( Copy_u8Pin * 2 );    
		break;
		
	case GPIO_C:
		GPIOC -> PUPDR |= ( Copy_u8PullType ) << ( Copy_u8Pin * 2 );
		break;
	}
}


void MGPIO_VoidSetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value)
{
	switch(Copy_u8Port)
	{
	/* output data high or low for each pin */
	case GPIO_A:
		if( Copy_u8Value == HIGH )
		{
			SET_BIT( GPIOA->ODR , Copy_u8Pin );
		}
		else if( Copy_u8Value == LOW )
		{
			CLR_BIT( GPIOA->ODR , Copy_u8Pin );
		}
		break;
		
	case GPIO_B:
		if( Copy_u8Value == HIGH )
		{
			SET_BIT( GPIOB->ODR  , Copy_u8Pin );
		}
		else if( Copy_u8Value == LOW )
		{
			CLR_BIT( GPIOB->ODR  , Copy_u8Pin );
		}
		break;
		
	case GPIO_C:
		if( Copy_u8Value == HIGH )
		{
			SET_BIT( GPIOC->ODR , Copy_u8Pin );
		}
		else if( Copy_u8Value == LOW )
		{
			CLR_BIT( GPIOC->ODR , Copy_u8Pin );
		}
		break;

	}
}


void MGPIO_VoidSetPinValueFast(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value)
{
	switch(Copy_u8Port)
	{
	/* Set-Reset for pin state */
	case GPIO_A:
		if( Copy_u8Value == HIGH )
		{
			GPIOA -> BSRR = (1 << Copy_u8Pin);     /*speed up -- 0 has no effect*/
		}
		else if( Copy_u8Value == LOW )
		{
			GPIOA -> BSRR = (1 << (Copy_u8Pin + 16));
		}
		break;
		
	case GPIO_B:
		if( Copy_u8Value == HIGH )
		{
			GPIOB -> BSRR = (1 << Copy_u8Pin);
		}
		else if( Copy_u8Value == LOW )
		{
			GPIOB -> BSRR = (1 << (Copy_u8Pin + 16));
		}
		break;
		
	case GPIO_C:
		if( Copy_u8Value == HIGH )
		{
			GPIOC -> BSRR = (1 << Copy_u8Pin);
		}
		else if( Copy_u8Value == LOW )
		{
			GPIOC -> BSRR = (1 << (Copy_u8Pin + 16));
		}
		break;

	}
}


u8 MGPIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	u8 LOC_u8Result = 0 ;   //return value

	switch(Copy_u8Port)
	{
	/*get input data*/
	case GPIO_A:
		LOC_u8Result = GET_BIT( GPIOA->IDR , Copy_u8Pin );
		break;
		
	case GPIO_B:
		LOC_u8Result = GET_BIT( GPIOB->IDR , Copy_u8Pin );
		break;
		
	case GPIO_C:
		LOC_u8Result = GET_BIT( GPIOC->IDR , Copy_u8Pin );
		break;
	}
	
	return LOC_u8Result;
}


void MGPIO_VoidSetPinAlternativeFunction(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8AF)
{
	switch(Copy_u8Port)
	{
	case GPIO_A:
		/*AFRL controls form pin0 to pin7 (each pin has 4 bits)*/
		if(Copy_u8Pin <= 7 )
		{
			GPIOA->AFRL &= ~ ( ( 0b1111 )  << ( Copy_u8Pin * 4 ));  /*Reset or clear pin (4bits)*/
			GPIOA->AFRL |= ( Copy_u8AF ) << ( Copy_u8Pin * 4 );   /*apply mode on pin (interface file)*/
		}
		
		/*AFRH controls form pin8 to pin15 (each pin has 4 bits)*/
		else if(Copy_u8Pin <= 15 )
		{
			Copy_u8Pin = Copy_u8Pin - 8;
			GPIOA->AFRH &= ~ ( ( 0b1111 )  << ( Copy_u8Pin * 4 ) );
			GPIOA->AFRH |= ( Copy_u8AF ) << ( Copy_u8Pin * 4 );
		}

		break;

	case GPIO_B:
		if(Copy_u8Pin <= 7 )
		{
			/*Reset pin then overwrite*/
			GPIOB->AFRL &= ~ ( ( 0b1111 )  << ( Copy_u8Pin * 4 ) );    /*Reset or clear pin*/
			GPIOB->AFRL |= ( Copy_u8AF ) << ( Copy_u8Pin * 4 )  ;    /*apply mode on pin*/
		}
		
		else if(Copy_u8Pin <= 15 )
		{
			Copy_u8Pin = Copy_u8Pin - 8;
			GPIOB->AFRH &= ~ ( ( 0b1111 )  << ( Copy_u8Pin * 4 ) );
			GPIOB->AFRH |= ( Copy_u8AF ) << ( Copy_u8Pin * 4 )  ;
		}
		
		break;
		
	case GPIO_C:
		if(Copy_u8Pin <= 7 )
		{
			GPIOC->AFRL &= ~ ( ( 0b1111 )  << ( Copy_u8Pin * 4 ) );
			GPIOC->AFRL |= ( Copy_u8AF ) << ( Copy_u8Pin * 4 )  ;
		}
		
		else if(Copy_u8Pin <= 15 )
		{
			Copy_u8Pin = Copy_u8Pin - 8;
			GPIOC->AFRH &= ~ ( ( 0b1111 )  << ( Copy_u8Pin * 4 ) );
			GPIOC->AFRH |= ( Copy_u8AF ) << ( Copy_u8Pin * 4 )  ;
		}
		
		break;

	}
}

                    /*lock pin mode*/
/*Each lock bit freezes the corresponding bits of a specific Pin*/
void MGPIO_VoidLockPin(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	switch(Copy_u8Port)
	{
	case GPIO_A:

		/*locked pin*/
		CLR_BIT(GPIOA->LCKR , LCKK);
		SET_BIT(GPIOA->LCKR , Copy_u8Pin);

		/*activate the lock key*/
		SET_BIT(GPIOA->LCKR , LCKK);

		/*writing sequence*/
		//SET_BIT(GPIOA->LCKR , LCKK);
		//CLR_BIT(GPIOA->LCKR , LCKK);
		//SET_BIT(GPIOA->LCKR , LCKK);

		//CLR_BIT(GPIOA->LCKR , LCKK);
		//GET_BIT(GPIOA->LCKR , LCKK);

		/* wait untill Lock key deactivated */
		//while(!(GET_BIT(GPIOA->LCKR , LCKK)));

		break;


	case GPIO_B:
		/*locked pin*/
		CLR_BIT(GPIOB->LCKR , LCKK);
		SET_BIT(GPIOB->LCKR , Copy_u8Pin);

		/*activate the lock key*/
		SET_BIT(GPIOB->LCKR , LCKK);

		/*writing sequence*/
		//SET_BIT(GPIOB->LCKR , LCKK);
		//CLR_BIT(GPIOB->LCKR , LCKK);
		//SET_BIT(GPIOB->LCKR , LCKK);

		//CLR_BIT(GPIOB->LCKR , LCKK);
		//GET_BIT(GPIOB->LCKR , LCKK);

		/* wait untill Lock key deactivated */
		//while(!(GET_BIT(GPIOB->LCKR , LCKK)));

		break;


	case GPIO_C:
		/*locked pin*/
		CLR_BIT(GPIOC->LCKR , LCKK);
		SET_BIT(GPIOC->LCKR , Copy_u8Pin);

		/*activate the lock key*/
		SET_BIT(GPIOC->LCKR , LCKK);

		/*writing sequence*/
		//SET_BIT(GPIOC->LCKR , LCKK);
		//CLR_BIT(GPIOC->LCKR , LCKK);
		//SET_BIT(GPIOC->LCKR , LCKK);

		//CLR_BIT(GPIOC->LCKR , LCKK);
		//GET_BIT(GPIOC->LCKR , LCKK);

		/* wait untill Lock key deactivated */
		//while(!(GET_BIT(GPIOC->LCKR , LCKK)));

		break;
	}

}


void MGPIO_VoidSetLowerPinValue(u8 Copy_u8Port , u8 Copy_u8Value)
{
	switch(Copy_u8Port)
	{
	/* output data high or low for lower pins(0:7)
	 * clear last 8 pins then OR
	 */
	case GPIO_A:
		//GPIOA->ODR &= 0b0000;
		GPIOA->ODR = Copy_u8Value;
		break;

	case GPIO_B:
		GPIOB->ODR &= 0b0000;
		GPIOB->ODR |= Copy_u8Value;
		break;

	case GPIO_C:
		GPIOC->ODR &= 0b0000;
		GPIOC->ODR |= Copy_u8Value;
		break;

	}
}
