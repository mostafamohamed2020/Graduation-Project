/****************************************************************************/
/* AUTHOR   : MOSTAFA MUHAMED ABDOU                                         */
/* DATE     : 11 FEB 2020                                                   */
/* VERSION  : V01                                                           */
/****************************************************************************/


#ifndef UART_H_
#define UART_H_

#include "standard_types.h"
#include "common_macros.h"
#include "DIO.h"
#include <avr/io.h>

void UART_init(void);

void UART_sendByte(const u_int8 data);

u_int8 UART_recieveByte(void);

void UART_sendString(const u_int8 *Str);

void UART_receiveString(u_int8 *Str); // Receive until #

#endif /* UART_H_ */