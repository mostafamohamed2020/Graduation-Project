/*
 * LCD_CONFG.h
 *
 * Created: 11/2/2020 12:38:45 PM
 *  Author: mostafa gomaa
 */ 


#ifndef LCD_CONFG_H_
#define LCD_CONFG_H_

#include "ATMEGA32_REGISTERS.h"
#include "DIO.h"

#define LCD_8BIT_DATA_PORT   DIO_PORTA
#define LCD_8BIT_CMD_PORT    DIO_PORTC

#define LCD_4BIT_DATA_PORT   DIO_PORTA
#define LCD_4BIT_CMD_PORT    DIO_PORTB

#define LCD_RS_PIN           DIO_PIN1
#define LCD_RW_PIN           DIO_PIN2
#define LCD_E_PIN            DIO_PIN3

#define LCD_D0_PIN           DIO_PIN0
#define LCD_D1_PIN           DIO_PIN1
#define LCD_D2_PIN           DIO_PIN2
#define LCD_D3_PIN           DIO_PIN3
#define LCD_D4_PIN           DIO_PIN4
#define LCD_D5_PIN           DIO_PIN5
#define LCD_D6_PIN           DIO_PIN6
#define LCD_D7_PIN           DIO_PIN7


#endif /* LCD_CONFG_H_ */