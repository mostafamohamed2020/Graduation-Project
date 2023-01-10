/****************************************************************************/
/* AUTHOR   : MOSTAFA MUHAMED ABDOU                                         */
/* DATE     : 11 FEB 2021                                                    */
/* VERSION  : V01                                                           */
/****************************************************************************/



#ifndef LED_H_
#define LED_H_

#include "common_macros.h"
#include "standard_types.h"
#include "ATMEGA32_REGISTERS.h"
#include "DIO.h"

void LED_INIT(u_int8 port , u_int8 pin);

void LED_ON(u_int8 port , u_int8 pin);

void LED_OFF(u_int8 port , u_int8 pin);

void LED_TOGGLE(u_int8 port , u_int8 pin);






#endif /* LED_H_ */