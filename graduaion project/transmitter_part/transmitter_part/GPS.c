/****************************************************************************/
/* AUTHOR   : MOSTAFA MUHAMED ABDOU                                         */
/* DATE     : 5 JAN 2021                                                    */
/* VERSION  : V01                                                           */
/****************************************************************************/

#include "GPS.h"

#include <util/delay.h>
						
void GPS_INIT(void)
{
	UART_init();
}

void GPS_extract_position_val(u_int8 *long_value , u_int8 *lat_value)
{
	u_int8 rx_data = 0 ;
	
	/* ARRAY TO STORE DATA RECEIVED FROM GPS */
	u_int8 gps_str[66];
	
	/* STARTING OF COORDINATES STRING */
	u_int8 gpgga[6] = {'$' , 'G' , 'P' , 'G' , 'G' , 'A'};
	
	u_int8 gps_str_counter = 0 ;
	
    while(gps_str_counter < 70)
	{
		rx_data = UART_recieveByte();
		
		gps_str_counter++;
		
		gps_str[gps_str_counter -1] = rx_data;
		
		/* CHECK THE CORRECTNESS OF RECEIVED START */
		if(gps_str_counter < 7)
		{
			if (gps_str[gps_str_counter - 1] == gpgga[gps_str_counter - 1])
			{
	
			}
			else
			gps_str_counter = 0;
		}
		
		if(gps_str_counter == 70)
		{
			/* 
			 * RESTART FROM THE INITIAL VALUE TO 
			 * RECEIVE ANOTHER STRING
			 */
			
			gps_str_counter = 0; //COUNTER FOR THE RECEIVED STRING
			
			u_int8 j = 0 ; //COUNTER FOR THE LONGTUDE STRING
			
			 /* STORING THE LONGTUDE POSITION */
			for(j = 0 ; j <= 12 ; j++)
			{
				long_value[j] = gps_str[j+30];
			}
			long_value[13] = '\0'; // TERMINATE THE LONGTUDE STRING  
			
			u_int8 k = 0 ; //COUNTER FOR THE LATITUDE STRING
			/* STORING THE LATITUDE POSITION */
			for(k = 0 ; k <= 11 ; k++)
			{
				lat_value[k] = gps_str[k+17];
			}
			lat_value[12] = '\0'; // TERMINATE THE LATITUDE STRING 
			
			/* END THE FUNCTION LOOP */
			break;
		}
	}
}



