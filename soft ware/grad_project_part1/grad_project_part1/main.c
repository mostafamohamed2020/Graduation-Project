/*
 * grad_project_part1.c
 *
 * Created: 1/4/2021 11:16:50 PM
 * Author : mostafa gomaa
 *
 * transmitter side
 * 
 */ 

#include "GPS.h"

#include "LCD.h"

//#include "SPI.h"

#define F_CPU 8000000UL

/*
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
*/

int main(void)
{
	//u_int8 RecLat[12] , RecLong[12];

	GPS_INIT();
	
	LCD_INIT();
	
	//SPI_INIT_MASTER();
	
	//SPI_MASTER_INIT_TRANSMIT();
	
	//u_int8 name = 0 ;
	
	
	u_int8 longtude[13];
	
	u_int8 latitude[12];
	
    while (1) 
    {
		
		
		
		GPS_extract_position_val(longtude , latitude);
		
		LCD_GOTO(0,0);
		LCD_WRITESTRING("lat : ");
		LCD_WRITESTRING(latitude);
		UART_SEND_STRING(latitude);
		UART_SEND_STRING("\r\t");
				
		LCD_GOTO(2,0);
		LCD_WRITESTRING("long : ");
		LCD_WRITESTRING(longtude);
		UART_SEND_STRING(longtude);
		UART_SEND_STRING("\r\t");
		RecLat  = SPI_TRANSCEIV_BYTE('A');
		RecLong = SPI_TRANSCEIV_BYTE('A');
		
	}
}

