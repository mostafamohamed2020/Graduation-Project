/****************************************************************************/
/* AUTHOR   : MOSTAFA MUHAMED ABDOU                                         */
/* DATE     : 1st APRIL 2021                                                */
/* VERSION  : V01                                                           */
/* TRANSMITTER SIDE                                                         */
/****************************************************************************/
#define F_CPU 16000000UL

#include "GPS.h"

#include "LCD.h"

//#include "LED.h"

//#include "SPI.h"

#include <avr/delay.h>


u_int8 longtude[14] ;
	
u_int8 latitude[13] ; 
		

u_int32 s_to_i(u_int8 *str , u_int8 digits)
{
	u_int8 counter = 0;
	u_int32 number = 0 , result = 0;
	switch (digits)
	{
		case 1:
		number = 1;
		break;
		
		case 2:
		number = 10;
		break;
		
		case 3:
		number = 100;
		break;
		
		case 4:
		number = 1000;
		break;
		
		case 5:
		number = 10000;
		break;
		
		default:
		break;
		
	}
	
	while (str[counter] != '\0')
	{
		// evaluating a number from character 
		result += ((str[counter] - 48) * number);
		number = (number / 10);
		counter++;
	}
	
	return result ;
}


int main(void)
{
	u_int32 X = 0 ; 
	
	GPS_INIT();

	LCD_INIT();
	
	//SPI_INIT_MASTER();
	
	//SPI_MASTER_INIT_TRANSMIT();
	
	while (1) 
    {GPS_extract_position_val(longtude , latitude);
	
	LCD_GOTO(0,0);
	//LCD_WRITESTRING("long:");
	LCD_WRITESTRING(longtude);
	
	/*
	UART_sendString("long : ");
	UART_sendString(longtude);
	UART_sendString("\t");
	*/
	
	LCD_GOTO(1,0);
	//LCD_WRITESTRING("lat :");
	LCD_WRITESTRING(latitude);
	
	/*
	UART_sendString("latitude : ");
	UART_sendString(latitude);
	UART_sendString("\t");
	*/
	
	
		
	    //X = UART_recieveByte();
		//LCD_WRITECHAR(X);
		//_delay_ms(500);
		//SPI_MASTER_END_TRANSMIT();
		
	}
}

