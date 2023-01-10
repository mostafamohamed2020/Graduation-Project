/*
 * UART.c
 *
 * Created: 11/29/2020 2:52:56 AM
 *  Author: mostafa gomaa
 */ 

#include "UART.h"

void UART_INIT(void)
{
	/* directions of TX and RX pins */
	DIO_SETPINDIR(DIO_PORTD , DIO_PIN1 , DIO_PIN_OUTPUT);
	DIO_SETPINDIR(DIO_PORTD , DIO_PIN0 , DIO_PIN_INPUT);
	
	/* enable transmission and receiving */
	set_bit(UCSRB , 3);
	set_bit(UCSRB , 4);
	
	/* read UCSRC */
	set_bit(UCSRC , 7);
	
	
	#if UART_MODE == ASYNCRONOUS_MODE
	
	 clear_bit(UCSRC , 6);
	 
	#elif UART_MODE == SYNCRONOUS_MODE
	
	set_bit(UCSRC , 6);
	#endif
	
	#if DOUBLE_SPEED_MODE == ENABLE_DOUBLE_SPEED_MODE
	 
	 set_bit(UCSRA , 1);
	 
	#elif DOUBLE_SPEED_MODE == DISABLE_DOUBLE_SPEED_MODE
	
	 clear_bit(UCSRA , 1);
	#endif
	
	#if MULTI_PROCESSOR_MODE == ENABLE_MULTIPROCESSOR_MODE
	 
	 set_bit(UCSRA , 0);
	 
	#elif MULTI_PROCESSOR_MODE == DISABLE_MULTIPROCESSOR_MODE
	
	 clear_bit(UCSRA , 0);
	#endif
	
	#if RECEIVING_INTERRUPT == ENABLE_RECEIVING_INTERRUPT
	 
	 set_bit(UCSRB , 7);
	 
	#elif RECEIVING_INTERRUPT == DISABLE_RECEIVING_INTERRUPT
	
	clear_bit(UCSRB , 7);
	#endif
	
	#if TRANSMITTING_INTERRUPT == ENABLE_TRANSMITTING_INTERRUPT
	
	 set_bit(UCSRB , 6);
	 
	#elif TRANSMITTING_INTERRUPT == DISABLE_TRANSMITTING_INTERRUPT
	
	 clear_bit(UCSRB , 6);
	#endif
	
	#if UDR_INTERRUPT == ENABLE_UDR_INTERRUPT
	
	 set_bit(UCSRB , 5);
	 
	#elif UDR_INTERRUPT == DISABLE_UDR_INTERRUPT
	
	  clear_bit(UCSRB , 5);
	#endif
	
	#if CHARACTER_SIZE == CHAR_SIZE_5BIT
	
	 clear_bit(UCSRC , 1);
	 clear_bit(UCSRC , 2);
	 clear_bit(UCSRB , 2);
	 
	#elif CHARACTER_SIZE == CHAR_SIZE_6BIT
	
	  set_bit(UCSRC , 1);
	  clear_bit(UCSRC , 2);
	  clear_bit(UCSRB , 2);
	  
	#elif CHARACTER_SIZE == CHAR_SIZE_7BIT
	
	  clear_bit(UCSRC , 1);
	  set_bit(UCSRC , 2);
	  clear_bit(UCSRB , 2);
	  
	#elif CHARACTER_SIZE == CHAR_SIZE_8BIT
	
	  set_bit(UCSRC , 1);
	  set_bit(UCSRC , 2);
	  clear_bit(UCSRB , 2);
	  
	#elif CHARACTER_SIZE == CHAR_SIZE_9BIT
	
	  set_bit(UCSRC , 1);
	  set_bit(UCSRC , 2);
	  set_bit(UCSRB , 2);
	#endif
	
	#if PARITY_BIT_MODE == DISABLE_PARITY_BIT
	 
	 clear_bit(UCSRC , 4);
	 clear_bit(UCSRC , 5);
	 
	#elif PARITY_BIT_MODE == EVEN_PARITY_BIT
	
	clear_bit(UCSRC , 4);
	set_bit(UCSRC , 5);
	
	#elif PARITY_BIT_MODE == ODD_PARITY_BIT
	
	 set_bit(UCSRC , 4);
	 set_bit(UCSRC , 5);
	#endif
	
	#if STOP_BITS == ONE_STOP_BIT
	 
	 clear_bit(UCSRC , 3);
	 
	#elif STOP_BITS == TWO_STOP_BITS
	
	set_bit(UCSRC , 3);
	#endif
	
	#if BAUDRATE_VALUE == BAUDRATE_9600 
	 
	u_int32 BR_VALUE = 0;
	BR_VALUE = ((80000) / (16 * 96)) - 1;
	UBRRL = BR_VALUE;
	 
	#elif BAUDRATE_VALUE == BAUDRATE_4800
	
	u_int32 BR_VALUE = 0;
	BR_VALUE = ((80000) / (16 * 48)) - 1;
	UBRRL = BR_VALUE;
	
	#elif BAUDRATE_VALUE == BAUDRATE_2400
	 
	 u_int32 BR_VALUE = 0;
	 BR_VALUE = ((80000) / (16 * 24)) - 1;
	 UBRRL = BR_VALUE;
	 
	#elif BAUDRATE_VALUE == BAUDRATE_115200
	
	u_int32 BR_VALUE = 0;
	BR_VALUE = ((80000) / (16 * 1152)) - 1;
	UBRRL = BR_VALUE;
	
	#endif
	
	
}

void UART_SEND_BYTE(u_int8 data)
{
	UDR = data;
	
	while(get_bit(UCSRA , 5) == 0);
}

void UART_SEND_STRING(u_int8* str)
{
	u_int8 counter = 0;
	
	while (str[counter] != '\0')
	{
		UART_SEND_BYTE(str[counter]);
		counter++;
	}
}

u_int8 UART_RECEIVE_BYTE(void)
{
	while(get_bit(UCSRA , 7) == 0);
	
	return UDR;
}

void UART_RECEIVE_STRING(u_int8* str)
{
	u_int8 counter = 0;
	
	str[counter] == UART_RECEIVE_BYTE();
	
	while (str[counter] != '\0')
	{
		str[counter] == UART_RECEIVE_BYTE();
	}
	str[counter] = '\0';
}

void UART_SEND_INT(s_int32 num)
{
	u_int8 i = 0, k ;
	
	u_int8 number[10];
	
	/* In case of negative numbers */
	if(num < 0)
	{
		num *= -1;
		while(num > 0)
		{
			number[i] = (num % 10) + 48;  //Equivalent ASCII of number
			num /= 10;
			i++;
		}
		number[i] = '-'; // storing the negative sign
		
		for(k = i+1 ; k > 0 ; k--)
		{
			UART_SEND_BYTE(number[k - 1]); //Display each number
		}
	}
	/* Zero case */
	else if(num == 0)
	{
		UART_SEND_BYTE('0');
	}
	
	/* In case of positive numbers */
	else if(num > 0)
	{
		while(num > 0)
		{
			number[i] = (num % 10) + 48; //Equivalent ASCII of number
			num /= 10;
			i++;
		}
		
		for(k = i ; k > 0 ; k--)
		{
			UART_SEND_BYTE(number[k-1]); //Display each number
		}
	}
}
