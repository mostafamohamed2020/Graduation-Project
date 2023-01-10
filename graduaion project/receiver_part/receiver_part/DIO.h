/*
 * DIO.h
 * author : mostafa gomaa
 */

#ifndef DIO
#define DIO

#include "ATMEGA32_REGISTERS.h"

#define DIO_PORTA         0
#define DIO_PORTB         1
#define DIO_PORTC         2
#define DIO_PORTD         3

#define DIO_PIN0          0
#define DIO_PIN1          1
#define DIO_PIN2          2
#define DIO_PIN3          3
#define DIO_PIN4          4
#define DIO_PIN5          5
#define DIO_PIN6          6
#define DIO_PIN7          7

#define DIO_PIN_OUTPUT    1
#define DIO_PIN_INPUT     0

#define DIO_PORT_OUTPUT   0xFF
#define DIO_PORT_INPUT    0x00

#define DIO_PIN_HIGH      1
#define DIO_PIN_LOW       0

#define DIO_PORT_HIGH     0xFF
#define DIO_PORT_LOW      0x00

void DIO_SETPINDIR(u_int8 port , u_int8 pin , u_int8 dir);
void DIO_SETPORTDIR(u_int8 port , u_int8 dir);

void DIO_SETPINVAL(u_int8 port , u_int8 pin , u_int8 val);
void DIO_SETPORTVAL(u_int8 port , u_int8 val);

void DIO_READPIN(u_int8 port , u_int8 pin , u_int8* val);
void DIO_READPORT(u_int8 port , u_int8* val);

void DIO_PINTOGGLE(u_int8 port , u_int8 pin);

void DIO_SETPULLUPS(u_int8 port , u_int8 pin);

#endif   /*end DIO */
