/*
 * SPI.c
 *
 * Created: 12/14/2020 11:39:14 PM
 *  Author: mostafa gomaa
 */ 

#include "SPI.h"

void SPI_INIT_MASTER()
{
	/**************** MASTER SIDE **********************
	 *                                                 *
	 *          MOSI ->  OUPTPUT_PIN                   *
	 *          SS   ->  OUTPUT_PIN                    *
	 *          MISO ->  INPUT_PIN                     *
	 *          SCK  ->  OUTPUT_PIN                    *
	 *                                                 *
	 **************************************************/     
    
	DIO_SETPINDIR(DIO_PORTB , DIO_PIN4 , DIO_PIN_OUTPUT);
	DIO_SETPINDIR(DIO_PORTB , DIO_PIN5 , DIO_PIN_OUTPUT);
	DIO_SETPINDIR(DIO_PORTB , DIO_PIN6 , DIO_PIN_INPUT);
	DIO_SETPINDIR(DIO_PORTB , DIO_PIN7 , DIO_PIN_OUTPUT);
	
	/* CURRENT CONFIGURATION */
	SPCR = 0x53;
	
	/*
	#if SPI_INTERRUPT_MODE  == ENABLE_SPI_INTERRUPT
	
	set_bit(SPCR , 7);
	
	#elif SPI_INTERRUPT_MODE == DISABLE_SPI_INTERRUPT
	
	clear_bit(SPCR , 7);
	#endif
	*/
	/* ENABLE SPI MODULE */
	//set_bit(SPCR , 6);
	/*
	#if SPI_DATA_ORDER == SEND_LSB_FIRST
	
	set_bit(SPCR , 5);
	
	#elif SPI_DATA_ORDER == SEND_MSB_FIRST
	
	clear_bit(SPCR , 5);
	#endif
	*/
	/* MASTER MODE */
	//set_bit(SPCR , 4);
	/*
	#if SPI_CLOCK_POLARITY == IDLE_HIGH_POLARITY
	
	set_bit(SPCR , 3);
	
	#elif SPI_CLOCK_POLARITY == IDLE_LOW_POLARITY
	
	clear_bit(SPCR , 3);
	#endif
	
	#if SPI_CLOCK_PHASE == READ_WRITE_PHASE
	
	clear_bit(SPCR , 2);
	
	#elif SPI_CLOCK_PHASE == WRITE_READ_PHASE
	
	set_bit(SPCR , 2);
	#endif
	
	#if DOUBLE_SPEED_MODE == ENABLE_DOUBLE_SPEED_MODE
	
	set_bit(SPSR , 0);
	
	#elif DOUBLE_SPEED_MODE == DISABLE_DOUBLE_SPEED_MODE
	
	clear_bit(SPSR , 0);
	#endif
	
	#if SPI_PRESCALER_VALUE == PRESCALLER_4
	
	clear_bit(SPCR , 0);
	clear_bit(SPCR , 1);
	clear_bit(SPSR , 0);
	
	#elif SPI_PRESCALER_VALUE == PRESCALLER_16
	
	set_bit(SPCR , 0);
	clear_bit(SPCR , 1);
	clear_bit(SPSR , 0);
	
	#elif SPI_PRESCALER_VALUE == PRESCALLER_32
	
	clear_bit(SPCR , 0);
	set_bit(SPCR , 1);
	set_bit(SPSR , 0);
	
	#elif SPI_PRESCALER_VALUE == PRESCALLER_128
	
	set_bit(SPCR , 0);
	set_bit(SPCR , 1);
	clear_bit(SPSR , 0);
	
	#elif SPI_PRESCALER_VALUE == PRESCALLER_2
	
	clear_bit(SPCR , 0);
	clear_bit(SPCR , 1);
	set_bit(SPSR , 0);
	
	#elif SPI_PRESCALER_VALUE == PRESCALLER_8
	
	set_bit(SPCR , 0);
	clear_bit(SPCR , 1);
	set_bit(SPSR  , 0);
	#endif
	*/
}

void SPI_INIT_SLAVE()
{
	
	/**************** SLAVE SIDE **********************
	 *                                                *
	 *          MOSI ->  INPUT_PIN                    *
	 *          SS   ->  INPUT_PIN                    *
	 *          MISO ->  OUTPUT_PIN                   *
	 *          SCK  ->  INPUT_PIN                    *
	 *                                                *
	 **************************************************/ 
	
	DIO_SETPINDIR(DIO_PORTB , DIO_PIN4 , DIO_PIN_INPUT);
	DIO_SETPINDIR(DIO_PORTB , DIO_PIN5 , DIO_PIN_INPUT);
	DIO_SETPINDIR(DIO_PORTB , DIO_PIN6 , DIO_PIN_OUTPUT);
	DIO_SETPINDIR(DIO_PORTB , DIO_PIN7 , DIO_PIN_INPUT);
	
	/* CHOOSE SLAVE MODE */
	clear_bit(SPCR , 4);
	
	/* ENABLE SPI MODULE */
	set_bit(SPCR , 6);
	
	/*
	 * CLOCK POLARITY AND CLOCK PHASE ARE  
	 * THE SAME IN MASTER SIDE AND SLAVE SIDE
	 */
	
	#if SPI_CLOCK_POLARITY == IDLE_HIGH_POLARITY
	
	set_bit(SPCR , 3);
	
	#elif SPI_CLOCK_POLARITY == IDLE_LOW_POLARITY
	
	clear_bit(SPCR , 3);
	#endif
	
	#if SPI_CLOCK_PHASE == READ_WRITE_PHASE
	
	clear_bit(SPCR , 2);
	
	#elif SPI_CLOCK_PHASE == WRITE_READ_PHASE
	
	set_bit(SPCR , 2);
	#endif
	
}

void SPI_MASTER_INIT_TRANSMIT()
{
	/* DRIVE THE SS PIN LOW */
	DIO_SETPINVAL(DIO_PORTB , DIO_PIN4 , DIO_PIN_LOW);

}

void SPI_MASTER_END_TRANSMIT()
{
	/* MAKE THE SS PIN HIGH */
	DIO_SETPINVAL(DIO_PORTB , DIO_PIN4 , DIO_PIN_HIGH);
}

u_int8 SPI_TRANSCEIV_BYTE(u_int8 DATA)
{
	/* 
     * THIS FUNCTION SEND DATA AND RETURN THE 
     * RECEIVED DATA FROM SLAVE
     */
	
	u_int8 REC_DATA = 0;
	
	SPDR = DATA ;  /* TRANSMITTED DATA */
	
	while(get_bit(SPSR , 7) == 0); /* DO NOT MOVE UNTILL DATA RECEIVED */
	
	REC_DATA = SPDR ; /* RECEIVED DATA */
	
	return REC_DATA;
}

void SPI_SEND_BYTE(u_int8 data)
{
	SPDR = data ;
	
	while(get_bit(SPSR , 7) == 0);
}

u_int8 SPI_RECEIVE_BYTE()
{
	u_int8 REC_DATA;
	
	while(get_bit(SPSR , 7) == 0);
	
	REC_DATA = SPDR ; 
	
	return REC_DATA;
}

void SPI_SEND_STRING(const u_int8* str)
{
	u_int8 counter = 0;
	
	while (str[counter] != '\0')
	{
		SPI_SEND_BYTE(str[counter]);
		
		counter++; /* MOVE TO THE SECOND LETTER */
	}
}

void SPI_RECEIVE_STRING(u_int8* str)
{
	u_int8 counter = 0 ;
	
	str[counter] = SPI_RECEIVE_BYTE();
	
	while (str[counter] != '#')
	{
		counter++;
		
		str[counter] = SPI_RECEIVE_BYTE();
	}
	
	str[counter] = '\0' ; /* TERMINATOR OF STRING */
}

