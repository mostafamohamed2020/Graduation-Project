/*
 * ESP8266.h
 *
 * Created: 7/8/2021 7:28:19 PM
 *  Author: click
 */ 

#ifndef ESP8266_H_
#define ESP8266_H_

#include "uart.h"

#include <avr/delay.h>

/* INITIALIZE THE ESP MODULE */
void ESP8266_INIT( void );

/* CONNECT TO THE LOCAL NETWORK (ROUTER) */
void ESP8266_ConnectToWiFi( u_int8 * SSID , u_int8 * Password );

/* CONNECT TO THE SERVER */
void ESP8266_ConnectToSrvTcp( u_int8 * Domain , u_int8 * Port );

/* SEND REQUEST FOR DATA */
void ESP8266_SendHttpReq( u_int8 * Key , u_int8 * Data , u_int8 * Length );

/* RECEIVE DATA FROM THE SERVER */
u_int8   ESP8266_ReceiveHttpReq( u_int8 * ChannelID , u_int8 * Length );

/* CLEAR MODULE BUFFER */
void ESP8266_ClearBuffer( void );


#endif /* ESP8266_H_ */