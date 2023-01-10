/*
 * LCD.c
 *
 * Created: 11/2/2020 12:39:34 PM
 *  Author: mostafa gomaa
 */ 
#include "LCD.h"

void LCD_INIT(void)
{
	#if LCD_MODE  == 8
	
    DIO_SETPINDIR(LCD_8BIT_CMD_PORT , LCD_RS_PIN , DIO_PIN_OUTPUT);	
	DIO_SETPINDIR(LCD_8BIT_CMD_PORT , LCD_RW_PIN , DIO_PIN_OUTPUT);	
	DIO_SETPINDIR(LCD_8BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_OUTPUT);
	
	DIO_SETPORTDIR(LCD_8BIT_DATA_PORT , DIO_PORT_OUTPUT);
	
	_delay_ms(100);	
	
	LCD_SENDCMD(LCD_8BIT_MODE);
	LCD_SENDCMD(LCD_CURSOR_OFF);
	LCD_SENDCMD(LCD_CURSOR_INC);
	LCD_SENDCMD(LCD_RETURN_HOME);
	LCD_SENDCMD(LCD_CLEAR);
	
	#elif LCD_MODE == 4
	
	DIO_SETPINDIR(LCD_4BIT_CMD_PORT , LCD_RS_PIN , DIO_PIN_OUTPUT);
	DIO_SETPINDIR(LCD_4BIT_CMD_PORT , LCD_RW_PIN , DIO_PIN_OUTPUT);
	DIO_SETPINDIR(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_OUTPUT);
	
	DIO_SETPINDIR(LCD_4BIT_DATA_PORT , LCD_D4_PIN , DIO_PIN_OUTPUT);
	DIO_SETPINDIR(LCD_4BIT_DATA_PORT , LCD_D5_PIN , DIO_PIN_OUTPUT);
	DIO_SETPINDIR(LCD_4BIT_DATA_PORT , LCD_D6_PIN , DIO_PIN_OUTPUT);
	DIO_SETPINDIR(LCD_4BIT_DATA_PORT , LCD_D7_PIN , DIO_PIN_OUTPUT);
	
	 _delay_ms(100);
	 
	 LCD_SENDCMD(LCD_4BIT_MODE_CMD1);
	 LCD_SENDCMD(LCD_4BIT_MODE_CMD2);
	 LCD_SENDCMD(LCD_4BIT_MODE_CMD3);
	 LCD_SENDCMD(LCD_CURSOR_OFF);
	 LCD_SENDCMD(LCD_CURSOR_INC);
	 LCD_SENDCMD(LCD_RETURN_HOME);
	 LCD_SENDCMD(LCD_CLEAR);
	
	#endif 
}

void LCD_SENDCMD(u_int8 cmd)
{
	#if LCD_MODE  == 8
	
	DIO_SETPINVAL(LCD_8BIT_CMD_PORT , LCD_RS_PIN , DIO_PIN_LOW);  //COMMAND MODE
	DIO_SETPINVAL(LCD_8BIT_CMD_PORT , LCD_RW_PIN , DIO_PIN_LOW);  //WRITE TO LCD MODE
	DIO_SETPINVAL(LCD_8BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);  //PREPARE FOR LATCH 
	
	DIO_SETPORTVAL(PORTA , cmd);  //SEND THE COMMAND
	
	DIO_SETPINVAL(LCD_8BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_HIGH);  //LATCH
	_delay_ms(1);
    DIO_SETPINVAL(LCD_8BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);  //LATCH
	_delay_ms(5);
	
	#elif LCD_MODE == 4
	
	DIO_SETPINVAL(LCD_4BIT_CMD_PORT , LCD_RS_PIN , DIO_PIN_LOW);  //COMMAND MODE
	DIO_SETPINVAL(LCD_4BIT_CMD_PORT , LCD_RW_PIN , DIO_PIN_LOW);  //WRITE TO LCD MODE
	DIO_SETPINVAL(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);  //PREPARE FOR LATCH
	
	PORTA = ((cmd & 0xF0) | (PORTA & 0x0F)); //SEND THE MSB(HIGH NIBBLE)
	
	DIO_SETPINVAL(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_HIGH); //LATCH
	_delay_ms(1);
	DIO_SETPINVAL(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);  //LATCH
	
	PORTA = ((cmd << 4) | (PORTA & 0x0F)); //SEND THE LSB(LOW NIBBLE)
	
	DIO_SETPINVAL(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_HIGH); //LATCH
	_delay_ms(1);
	DIO_SETPINVAL(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);  //LATCH
	
	_delay_ms(5); //5 ms BEFORE SENDING THE NEXT COMMAND
	
	#endif
}

void LCD_WRITECHAR(u_int8 chr)
{
	#if LCD_MODE  == 8
	
	DIO_SETPINVAL(LCD_8BIT_CMD_PORT , LCD_RS_PIN , DIO_PIN_HIGH);  //DATA MODE
	DIO_SETPINVAL(LCD_8BIT_CMD_PORT , LCD_RW_PIN , DIO_PIN_LOW);  //WRITE TO LCD MODE
	DIO_SETPINVAL(LCD_8BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);  //DATA MODE
	
	PORTA = chr;  //SEND THE CHARACTER
	
	DIO_SETPINVAL(LCD_8BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_HIGH); //LATCH
	_delay_ms(1);
	DIO_SETPINVAL(LCD_8BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW); //LATCH
	
	_delay_ms(5); //5 ms BEFORE SENDING THE NEXT CHARACTER
	
	#elif LCD_MODE == 4
	
	DIO_SETPINVAL(LCD_4BIT_CMD_PORT , LCD_RS_PIN , DIO_PIN_HIGH);  //DATA MODE
	DIO_SETPINVAL(LCD_4BIT_CMD_PORT , LCD_RW_PIN , DIO_PIN_LOW);  //WRITE TO LCD MODE
	DIO_SETPINVAL(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);  //DATA MODE
	
	PORTA = ((chr & 0xF0) | (PORTA & 0x0F)); //SEND THE MSB(HIGH NIBBLE)
	
	DIO_SETPINVAL(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_HIGH); //LATCH
	_delay_ms(1);
	DIO_SETPINVAL(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW); //LATCH
	
	PORTA = ((chr << 4) | (PORTA & 0x0F)); //SEND THE LSB(LOW NIBBLE)
	
	DIO_SETPINVAL(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_HIGH); //LATCH
	_delay_ms(1);
	DIO_SETPINVAL(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW); //LATCH
	
	_delay_ms(5); //5 ms BEFORE SENDING THE NEXT CHARACTER
	
	#endif
}

void LCD_WRITESTRING(u_int8* str)
{
	u_int8 i = 0 ;
	
	while (str[i] != '\0')
	{
		LCD_WRITECHAR(str[i]);
		i++;
	}
}

void LCD_GOTO(u_int8 row , u_int8 column)
{
	u_int8 positions[4] = {0x80 , 0xC0 , 0x94 , 0xD4}; //POSITIONS OF 1st cell of each row 
		LCD_SENDCMD(positions[row] + column);
}

void LCD_CLear(void)
{
	LCD_SENDCMD(LCD_CLEAR);
}

void LCD_WRITEINT(s_int32 num)
{
	u_int8 i = 0, k ;
	u_int8 number[10];
	
	/* In case of negative numbers */
	if(num < 0)
	{
		num *= -1;
		while(num > 0)
		{
			number[i] = (num % 10) + 48;  //Equivalent ASCII of number
			num /= 10;
			i++;
		}
		number[i] = '-'; // storing the negative sign
		
		for(k = i+1 ; k > 0 ; k--)
		{
			LCD_WRITECHAR(number[k - 1]); //Display each number
		}
	}
	/* Zero case */
	else if(num == 0)
	{
		LCD_WRITECHAR('0');
	}
	
	/* In case of positive numbers */
	else if(num > 0)
	{
		while(num > 0)
		{
			number[i] = (num % 10) + 48; //Equivalent ASCII of number
			num /= 10;
			i++;
		}
		
		for(k = i ; k > 0 ; k--)
		{
			LCD_WRITECHAR(number[k-1]); //Display each number
		}
	}
}

