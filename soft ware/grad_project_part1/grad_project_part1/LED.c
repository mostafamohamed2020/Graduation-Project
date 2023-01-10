/*
 * LED.c
 *
 *  Created: 11/2/2020 3:01:42 PM
 *  Author: mostafa gomaa
 */ 

#include "LED.h"

void LED_INIT(u_int8 port , u_int8 pin)
{
	switch (port)
	{
		case DIO_PORTA:
		DIO_SETPINDIR(DIO_PORTA , pin , DIO_PIN_OUTPUT);
		break;
		
		case DIO_PORTB:
		DIO_SETPINDIR(DIO_PORTB , pin , DIO_PIN_OUTPUT);
		break;
		
		case DIO_PORTC:
		DIO_SETPINDIR(DIO_PORTC , pin , DIO_PIN_OUTPUT);
		break;
		
		case DIO_PORTD:
		DIO_SETPINDIR(DIO_PORTD , pin , DIO_PIN_OUTPUT);
		break;
		
		default:
		break;
	}
	
}

/* LED_ON WITH POSITIVE LOGIC */
void LED_ON(u_int8 port , u_int8 pin)
{
	switch (port)
	{
		case DIO_PORTA:
		DIO_SETPINVAL(DIO_PORTA , pin , DIO_PIN_HIGH);
		break;
		
		case DIO_PORTB:
		DIO_SETPINVAL(DIO_PORTB , pin , DIO_PIN_HIGH);
		break;
		
		case DIO_PORTC:
		DIO_SETPINVAL(DIO_PORTC , pin , DIO_PIN_HIGH);
		break;
		
		case DIO_PORTD:
		DIO_SETPINVAL(DIO_PORTD, pin , DIO_PIN_HIGH);
		break;
		
		default:
		break;
	}
	
}

/* LED_OFF WITH POSITIVE LOGIC */
void LED_OFF(u_int8 port , u_int8 pin)
{
	switch (port)
	{
		case DIO_PORTA:
		DIO_SETPINVAL(DIO_PORTA , pin , DIO_PIN_LOW);
		break;
		
		case DIO_PORTB:
		DIO_SETPINVAL(DIO_PORTB , pin , DIO_PIN_LOW);
		break;
		
		case DIO_PORTC:
		DIO_SETPINVAL(DIO_PORTC , pin , DIO_PIN_LOW);
		break;
		
		case DIO_PORTD:
		DIO_SETPINVAL(DIO_PORTD, pin , DIO_PIN_LOW);
		break;
		
		default:
		break;
	}
	
}

/* LED TOGGLE WITH POSITIVE LOGIC */
void LED_TOGGLE(u_int8 port , u_int8 pin)
{
	switch (port)
	{
		case DIO_PORTA:
		DIO_PINTOGGLE(DIO_PORTA , pin );
		break;
		
		case DIO_PORTB:
		DIO_PINTOGGLE(DIO_PORTB , pin );
		break;
		
		case DIO_PORTC:
		DIO_PINTOGGLE(DIO_PORTC , pin );
		break;
		
		case DIO_PORTD:
		DIO_PINTOGGLE(DIO_PORTD, pin );
		break;
		
		default:
		break;
	}
}