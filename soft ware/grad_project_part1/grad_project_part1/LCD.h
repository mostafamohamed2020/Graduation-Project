/*
 * LCD.h
 *
 * Created: 11/2/2020 12:39:09 PM
 *  Author: mostafa gomaa
 */ 

#ifndef LCD_H_
#define LCD_H_

#include "LCD_CONFG.h"
#include "standard_types.h"
#define F_CPU 8000000
#include <util/delay.h>

#define LCD_CURSOR_OFF       0x0C
#define LCD_RETURN_HOME      0x02
#define LCD_CURSOR_INC       0x06
#define LCD_CLEAR            0x01

#define LCD_8BIT_MODE        0x38   
#define LCD_4BIT_MODE_CMD1   0x33
#define LCD_4BIT_MODE_CMD2   0x32
#define LCD_4BIT_MODE_CMD3   0x28

#define    LCD_MODE     4


void LCD_INIT(void);

void LCD_SENDCMD(u_int8 cmd);

void LCD_WRITECHAR(u_int8 chr);

void LCD_WRITESTRING(u_int8* str);

void LCD_GOTO(u_int8 row , u_int8 column);

void LCD_CLear(void);

void LCD_WRITEINT(s_int32 num);







#endif /* LCD_H_ */