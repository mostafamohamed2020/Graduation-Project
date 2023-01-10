/*
 * SPI.h
 *
 * Created: 12/14/2020 11:38:57 PM
 *  Author: mostafa gomaa
 */ 

#include "DIO.h"
#include "SPI_CONFIG.h"
#include "standard_types.h"
#include "common_macros.h"


#ifndef SPI_H_
#define SPI_H_

#define F_CPU 8000000


#define ENABLE_SPI_INTERRUPT      0
#define DISABLE_SPI_INTERRUPT     1

#define SEND_LSB_FIRST            0
#define SEND_MSB_FIRST            1

#define IDLE_HIGH_POLARITY        0
#define IDLE_LOW_POLARITY         1

#define READ_WRITE_PHASE          0
#define WRITE_READ_PHASE          1

#define ENABLE_DOUBLE_SPEED_MODE  0
#define DISABLE_DOUBLE_SPEED_MODE 1

#define PRESCALLER_4              0
#define PRESCALLER_16             1
#define PRESCALLER_128            2
#define PRESCALLER_2              3
#define PRESCALLER_8              4
#define PRESCALLER_32             5

void SPI_INIT_MASTER();

void SPI_INIT_SLAVE();

void SPI_MASTER_INIT_TRANSMIT();

void SPI_MASTER_END_TRANSMIT();

void SPI_SEND_BYTE(u_int8 data);

u_int8 SPI_RECEIVE_BYTE();

u_int8 SPI_TRANSCEIV_BYTE(u_int8 DATA);

void SPI_SEND_STRING(const u_int8* str);

void SPI_RECEIVE_STRING(u_int8* str);





#endif /* SPI_H_ */