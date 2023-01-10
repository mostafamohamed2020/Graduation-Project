/****************************************************************************/
/* AUTHOR   : MOSTAFA MUHAMED ABDOU                                         */
/* DATE     : 5 JAN 2021                                                    */
/* VERSION  : V01                                                           */
/****************************************************************************/

#ifndef GPS_H_
#define GPS_H_

#include "uart.h"

#include "LED.h"

#include "LCD.h"

void GPS_INIT(void);

void GPS_extract_position_val(u_int8 *long_value , u_int8 *lat_value);
/*

void GPS_extract_lat_position_val(u_int8 *lat_value);

void GPS_extract_long_position_val(u_int8 *long_value);
*/

#endif /* GPS_H_ */