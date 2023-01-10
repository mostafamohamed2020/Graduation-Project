/*
 * UART.h
 *
 * Created: 11/29/2020 2:52:39 AM
 *  Author: mostafa gomaa
 */ 


#ifndef UART_H_
#define UART_H_

#include "DIO.h"
#include "standard_types.h"
#include "common_macros.h"
#include "UART_CONFIG.h"

#define F_CPU 8000000

#define SYNCRONOUS_MODE   0
#define ASYNCRONOUS_MODE  1

#define ONE_STOP_BIT      0
#define TWO_STOP_BITS     1

#define DISABLE_PARITY_BIT 0
#define EVEN_PARITY_BIT   1
#define ODD_PARITY_BIT    2

#define CHAR_SIZE_5BIT    0
#define CHAR_SIZE_6BIT    1
#define CHAR_SIZE_7BIT    2
#define CHAR_SIZE_8BIT    3
#define CHAR_SIZE_9BIT    4

#define BAUDRATE_9600     0
#define BAUDRATE_115200   1
#define BAUDRATE_4800     2
#define BAUDRATE_2400     3

#define ENABLE_MULTIPROCESSOR_MODE  0
#define DISABLE_MULTIPROCESSOR_MODE 1

#define ENABLE_DOUBLE_SPEED_MODE  0
#define DISABLE_DOUBLE_SPEED_MODE  1

#define ENABLE_TRANSMITTING_INTERRUPT 0
#define DISABLE_TRANSMITTING_INTERRUPT 1

#define ENABLE_RECEIVING_INTERRUPT 0
#define DISABLE_RECEIVING_INTERRUPT 1

#define ENABLE_UDR_INTERRUPT 0
#define DISABLE_UDR_INTERRUPT 1

void UART_INIT(void);

void UART_SEND_BYTE(u_int8 data);

void UART_SEND_STRING(u_int8* str);

u_int8 UART_RECEIVE_BYTE(void);

void UART_RECEIVE_STRING(u_int8* str);

void UART_SEND_INT(s_int32 num);

void UART_RECEIVE_INT();



#endif /* UART_H_ */