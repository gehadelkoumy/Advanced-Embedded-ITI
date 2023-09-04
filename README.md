> ### ***Interfacing with STM32F401CC micro-controller***  
> `Guidance for testing drivers`  

This is documentation for handling drivers implemented in the COTS_CortexM4 folder. ***Layered architecture*** is used, which divides the software into some layers:

- **`APP`** *(Application Layer)* is the layer where the main.c file exists.
- **`HAL`** *(Hardware Abstraction Layer)* is a software program for external hardware components like sensors and actuators.
- **`MCAL`** *(Microcontroller Abstraction Layer)* is a software program for any peripheral inside the microcontroller.
<br>

The figure below includes all implemented drivers in the layered architecture:

<br>

   ![LayeredArch](https://github.com/gehadelkoumy/readme-formatting/assets/68203785/ece3b6d4-6e95-46df-b0b8-979f0bc69177)
    
<br>

### 1. Handling GPIO peripheral
- Enable the clock on used ports `PORTA, PORTB, or PORTC` using RCC driver.
- Specify the mode of the pin as `INPUT` or `OUTPUT`.
    - If `OUTPUT`, choose the output type and the speed of the pin.
    - If `INPUT`, specify the pull type as UP or DOWN or NO PULL - used for triggering pulses out of sensor or for a switch.
      <br>
      
*NOTES*: 
- If we want to get the state of a specific PIN use the function `MGPIO_u8GetPinValue`.
- On some STM32 GPIO pins, the user has the possibility to select alternate function inputs/outputs, this can be provided using
the function `MGPIO_VoidSetPinAlternativeFunction`.

<br>

### 2. Handling EXTI peripheral
- Enable the clock on used ports `PORTA, PORTB, or PORTC` using RCC driver.
- Set the pin Mode as `INPUT` and choose the suitable pull type.
- Select the port you want using SYSCFG driver.
- Enable interrupt line *(used pin)* and interrupt mode as `Rising` or `Falling` or `On change` 
- Enable interrupt using NVIC core peripheral *(position number in the vector table from DataSheet)*.
- Use `EXTI_voidSetCallBack` function to be able to jump to ISR when the interrupt flag is raised.
  <br>

*NOTES*: 
- SYSCFG peripheral must be enabled using RCC driver.
- External interrupt can be enabled without EXTI peripheral by setting the pending flag of the used line using `MNVIC_voidSetPendingFlag` function in the NVIC driver.

<br>

### 3. Handling USART (Transimission)
- Enable the USART clock from RCC driver.
- Enable the USART by setting the *UE* bit in the *USART_CR1* register.
- Select the desired baud rate using the *USART_BRR* register.
- Set the *TE* bit in *USART_CR1* to send an idle frame as the first transmission.
- Write the data to send in the *USART_DR* register by using `MUSART1_voidSendData` function. 
<br>

*NOTES*: 
- If sending a string, use this function `MUSART1_voidSendString`.
- If sending a number that has more than one digit, use this function `MUSART1_voidSendNumbers`.

<br>

### 4. Handling USART (Reception)
- Enable the USART clock from RCC driver.
- Enable the USART by setting the *UE* bit in the *USART_CR1* register.
- Select the desired baud rate using the *USART_BRR* register.
- Set the *RE* bit of the *USART_CR1* register, this will enable the receiver to search for a start bit.
- Use `MUSART1_u8ReceiveData` function to receive data.
<br>

*NOTES*: 
- `MUSART1_u8ReceiveData` function will recieve only one character in ASCII.
- If receiving more than one character, use `MUSART1_voidSendNumbers` function. It will return the number of received characters
each one stored as an element of an array.

