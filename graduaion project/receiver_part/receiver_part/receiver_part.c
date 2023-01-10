/*********************************************************************/
/* AUTHOR  : MOSTAFA MOHAMED ABDO                                    */
/* DATE    : 1st APRIL 2021                                          */
/* VERSION : V01                                                     */
/* RECEIVER SIDE                                                     */
/*********************************************************************/

//#include "GPS.h"

#include "LCD.h"

#include "SPI.h"

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
	//GPS_INIT();
	
	LCD_INIT();
	
	SPI_INIT_SLAVE();

	
	//UART_INIT();
	
	u_int8 name = 0 , t = 0 ;
	
	
	//u_int8 longtude[13];
	
	//u_int8 latitude[12];
	
	name = SPI_TRANSCEIV_BYTE('B');
	
	LCD_WRITECHAR(name);

    while (1) 
    {
		
		
		
		//UART_SEND_STRING(name);
		
		/*
		SPI_RECEIVE_STRING(longtude);
		
		LCD_GOTO(0,1);
		
		LCD_WRITESTRING(longtude);
		*/
	    /*
		GPS_extract_position_val(longtude , latitude);
		
		LCD_GOTO(0,0);
		LCD_WRITESTRING("lat : ");
		LCD_WRITESTRING(latitude);
		SPI_SEND_STRING(latitude);
		UART_SEND_STRING("\r\t");
				
		LCD_GOTO(2,0);
		LCD_WRITESTRING("long : ");
		LCD_WRITESTRING(longtude);
		SPI_SEND_STRING(longtude);
		UART_SEND_STRING("\r\t");
        */
	}
	
}

