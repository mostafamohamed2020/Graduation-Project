/*
 * GPS.h
 *
 * Created: 1/5/2021 12:26:32 AM
 *  Author: mostafa gomaa
 */ 


#ifndef GPS_H_
#define GPS_H_

#include "UART.h"

void GPS_INIT(void);

void GPS_extract_position_val(u_int8 *long_value , u_int8 *lat_val);


#endif /* GPS_H_ */