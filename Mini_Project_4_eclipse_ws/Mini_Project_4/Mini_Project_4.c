/******************************************************************************
 *
 * Module: Mini_Project4
 *
 * File Name: Mini_Project4.c
 *
 * Description: source file for Mini_Project4
 *
 * Author: Sohail Talaat
 *
 *******************************************************************************/
#include"ultra_sonic.h"/*to use ultrasonic driver*/
#include"lcd.h"/*to display the distance on lcd*/
#include<avr/io.h>/*to use avr register*/
#include<util/delay.h> /*to make a delay*/

int main()
{
	SREG |= (1<<7);/*enable global interrupt*/
	uint16 distance = 0;/*a varaiable to receive the distance*/

	LCD_init();/*initiate the lcd*/
	Ultrasonic_init();/*initiate the ultrasonic*/
	LCD_displayString("Distance = ");
	while(1)
	{
		distance = Ultrasonic_readDistance();/*get the distance*/
		LCD_moveCursor(0, 11);
		/*display the distance*/
		if(distance >= 100)
		{
		LCD_intgerToString(distance);
		}
		else
		{
			LCD_intgerToString(distance);
			LCD_displayCharacter(' ');
		}
		LCD_displayString("cm");
		_delay_ms(200);
	}

}

