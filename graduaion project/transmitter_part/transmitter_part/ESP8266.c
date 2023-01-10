/****************************************************************************/
/* AUTHOR   : MOSTAFA MUHAMED ABDOU                                         */
/* DATE     : 8 JUL 2021                                                    */
/* VERSION  : V01                                                           */
/****************************************************************************/

#include "ESP8266.h"

u_int8 volatile Iterator = 0  ;

/* GLOBAL ARRAY TO RECEIVE DATA */
u_int8 volatile DataCome[200] ;

/* INITIALIZE THE ESP MODULE */
void ESP8266_INIT( void )
{

	/* Sending AT Command To Check ESP8266 Is Working Or Not  */
	UART_sendString( (u_int8 *)"AT\r\n" );

	_delay_ms( 3000 );

	/* Clear ESP8266 Buffer */
	ESP8266_ClearBuffer();
    
	/* SET THE MODE OF ESP (STATION MODE) */
	UART_sendString( (u_int8 *)"AT+CWMODE=1\r\n" );
	_delay_ms( 3000 );
    
	/* Clear ESP8266 Buffer */
	ESP8266_ClearBuffer();
    
	
	UART_sendString( (u_int8 *)"AT+CIPMODE=0\r\n" );
	_delay_ms( 3000 );

}

/* CONNECT TO THE LOCAL NETWORK (ROUTER) */
void ESP8266_ConnectToWiFi( u_int8 * SSID , u_int8 * Password )
{
	/* CLEAR ESP8266 BUFFER */
	ESP8266_ClearBuffer();

	UART_sendString( (u_int8 *) "AT+CWJAP=\"" );
	UART_sendString( (u_int8 *) SSID );
	UART_sendString( (u_int8 *) "\",\"" );
	UART_sendString( (u_int8 *) Password);
	UART_sendString( (u_int8 *) "\"\r\n");
	_delay_ms( 8000 );

}

/* CONNECT TO THE SERVER */
void ESP8266_ConnectToSrvTcp( u_int8 * Domain , u_int8 * Port )
{
	/* CLEAR ESP8266 BUFFER */
	ESP8266_ClearBuffer();

	UART_sendString( (u_int8 *) "AT+CIPSTART=\"TCP\",\"" );
	UART_sendString( (u_int8 *) Domain );
	UART_sendString( (u_int8 *) "\"," );
	UART_sendString( (u_int8 *) Port );
	UART_sendString( (u_int8 *) "\r\n" );
	_delay_ms( 2000 );

}

/* SEND REQUEST FOR DATA */
void ESP8266_SendHttpReq( u_int8 * Key , u_int8 * Data , u_int8 * Length )
{
	ESP8266_ClearBuffer();

	UART_sendString( (u_int8 *) "AT+CIPSEND=" );
	UART_sendString( (u_int8 *) Length );
	UART_sendString( (u_int8 *) "\r\n" );
	_delay_ms( 4000 );

	ESP8266_ClearBuffer();

	UART_sendString( (u_int8 *) "GET /update?api_key=" );
	UART_sendString( (u_int8 *) Key );
	UART_sendString( (u_int8 *) "&field1=" );
	UART_sendString( (u_int8 *) Data );
	UART_sendString( (u_int8 *) "\r\n" );
	_delay_ms( 20000 );

}

/* RECEIVE DATA FROM THE SERVER */
u_int8   ESP8266_ReceiveHttpReq( u_int8 * ChannelID , u_int8 * Length )
{
	ESP8266_ClearBuffer();

	UART_sendString( (u_int8 *) "AT+CIPSEND=" );
	UART_sendString( (u_int8 *) Length );
	UART_sendString( (u_int8 *) "\r\n" );
	_delay_ms( 4000 );

	ESP8266_ClearBuffer();

	UART_sendString( (u_int8 *) "GET http://" );
	UART_sendString( (u_int8 *) ChannelID );
	UART_sendString( (u_int8 *) "/value.txt\r\n" );
	_delay_ms( 20000 );

	ESP8266_ConnectToSrvTcp( (u_int8 *)"162.253.155.226" , (u_int8 *)"80" );

	/*For yrabiot3.freevar.com ( Value Array Index )*/
	return  DataCome[82] ;

}

/* CLEAR MODULE BUFFER */
void ESP8266_ClearBuffer( void )
{
	u_int8 LOC_Iterator1 = 0 ;
	Iterator = 0 ;

	for( LOC_Iterator1 = 0 ; LOC_Iterator1 < 150 ; LOC_Iterator1++ ){

		DataCome[ LOC_Iterator1 ] = 0 ;

	}

}