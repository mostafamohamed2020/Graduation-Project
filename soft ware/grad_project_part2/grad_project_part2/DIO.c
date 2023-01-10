/* 
 * DIO .c
 * author : mostafa gomaa
 */

#include "DIO.h"
#include "common_macros.h"

void DIO_SETPINDIR(u_int8 port , u_int8 pin , u_int8 dir)
{
	switch(dir)
	{
		case DIO_PIN_INPUT:  //in case of input 
		switch(port)
		{
			case DIO_PORTA:
			clear_bit(DDRA , pin);
			break;
			case DIO_PORTB:
			clear_bit(DDRB , pin);
			break;
			case DIO_PORTC:
			clear_bit(DDRC , pin);
			break;
			case DIO_PORTD:
			clear_bit(DDRD , pin);
			break;
			default:
			break;
		} //end of switch(port)
		break;
		
		case DIO_PIN_OUTPUT:  //in case of output
		switch(port)
		{
			case DIO_PORTA:
			set_bit(DDRA , pin);
			break;
			case DIO_PORTB:
			set_bit(DDRB , pin);
			break;
			case DIO_PORTC:
			set_bit(DDRC , pin);
			break;
			case DIO_PORTD:
			set_bit(DDRD , pin);
			break;
			default:
			break;
		} //end of switch(port)
		break;
		 
	} //end of swich(dir)
} //end of function

void DIO_SETPORTDIR(u_int8 port , u_int8 dir)
{
	switch(port)
	{
		case DIO_PORTA:
		DDRA = dir;
		break;
	    case DIO_PORTB:
		DDRB = dir;
		break;
		case DIO_PORTC:
		DDRC = dir;
		break;
		case DIO_PORTD:
		DDRD = dir;
		break;
		default:
		break;
	} //end of switch(port)
} //end of the function

void DIO_SETPINVAL(u_int8 port , u_int8 pin , u_int8 val)
{
	switch(val)
	{
		case DIO_PIN_LOW:
		switch(port)
		{
			case DIO_PORTA:
			clear_bit(PORTA , pin);
			break;
			case DIO_PORTB:
			clear_bit(PORTB , pin);
			break;
			case DIO_PORTC:
			clear_bit(PORTC , pin);
			break;
			case DIO_PORTD:
			clear_bit(PORTD , pin);
			break;
			default:
			break;
		} //end of switch(port)
		break;
		
		case DIO_PIN_HIGH:
		switch(port)
		{
			case DIO_PORTA:
			set_bit(PORTA , pin);
			break;
			case DIO_PORTB:
			set_bit(PORTB , pin);
			break;
			case DIO_PORTC:
			set_bit(PORTC , pin);
			break;
			case DIO_PORTD:
			set_bit(PORTD , pin);
			break;
			default:
			break;
		} //end of switch(port)
		break;
	} //end of switch(val)
} //end of the function

void DIO_SETPORTVAL(u_int8 port , u_int8 val)
{
	switch(port)
	{
		case DIO_PORTA:
		PORTA = val;
		break;
		case DIO_PORTB:
		PORTB = val;
		break;
		case DIO_PORTC:
		PORTC = val;
		break;
		case DIO_PORTD:
		PORTD = val;
		break;
		default:
		break;
	} //end of switch(port)
} //end of the function

void DIO_READPIN(u_int8 port , u_int8 pin , u_int8* val)
{
	switch(port)
	{
		case DIO_PORTA:
		*val = get_bit(PINA , pin);
		break;
		case DIO_PORTB:
		*val = get_bit(PINB , pin);
		break;
		case DIO_PORTC:
		*val = get_bit(PINC , pin);
		break;
		case DIO_PORTD:
		*val = get_bit(PIND , pin);
		break;
		default:
		break;
	} //end of switch(port)
}//end of the function
 
void DIO_READPORT(u_int8 port , u_int8* val)
{
	switch(port)
	{
		case DIO_PORTA:
		*val = PINA;
		break;
		case DIO_PORTB:
		*val = PINB;
		break;
		case DIO_PORTC:
		*val = PINC;
		break;
		case DIO_PORTD:
		*val = PIND;
		break;
		default:
		break;
	} //end of switch(port)
} //end of the function

void DIO_PINTOGGLE(u_int8 port , u_int8 pin)
{
	switch(port)
	{
		case DIO_PORTA:
		toggle_bit(PORTA , pin);
		break;
		case DIO_PORTB:
		toggle_bit(PORTB , pin);
		break;
		case DIO_PORTC:
		toggle_bit(PORTC , pin);
		break;
		case DIO_PORTD:
		toggle_bit(PORTD , pin);
		break;
		default:
		break;
	} //end of switch(port)
} //end of the function

void DIO_SETPULLUPS(u_int8 port , u_int8 pin)
{
	switch (port)
	{
		case DIO_PORTA:
		set_bit(PORTA , pin);
		break;
		
		case DIO_PORTB:
		set_bit(PORTB , pin);
		break;
		
		case DIO_PORTC:
		set_bit(PORTC , pin);
		break;
		
		case DIO_PORTD:
		set_bit(PORTD , pin);
		break;
		
		default:
		break;
	}
}
