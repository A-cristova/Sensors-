/*
 * main.c
 *
 *  Created on: Sep 25, 2023
 *      Author: Abdo Cris
 */

#include <avr/io.h>
#include <util/delay.h>
#include "typedef.h"
#include "common_macros.h"
#include "adc.h"
#include "lcd.h"
#include "pwm_0.h"


int main ()
{
	PWM0_init();
    set_prescaler(Np_0);

	ADC_str  conf = {AVCC,N_64};

	uint_16 intensity ;
	uint_32 in_seg ;
	uint_32 temp ;

	ADC_init(&conf);
	LCD_init();
	_delay_ms(200);

	LCD_displayString("TEMP IS = ");
	LCD_displayStringRowColumn (1,0,"intensity = ");
	while (1)
	{
		_delay_ms(200);

		in_seg = ADC_Read_Channel(0);
		temp = ((uint_32)(in_seg*100*5))/(1024);
		LCD_moveCursor (0,11);
		if (temp >=100)
		{
			LCD_integerToString(temp);
		}
		else if (temp <100)
		{
			LCD_integerToString(temp);
			LCD_displayCharacter(' ');
		}
		else{}
//****************************************************************
		_delay_ms(200);

		intensity = ADC_Read_Channel(7);
		set_dutycycle(intensity /9.85);
		LCD_moveCursor (1,13);
		if (intensity >=100)
		{
			LCD_integerToString(intensity);
		}
		else if (intensity <100)
		{
			LCD_integerToString(intensity);
			LCD_displayCharacter(' ');
        }
		else{}
	}

}


