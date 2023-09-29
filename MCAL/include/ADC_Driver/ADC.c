/*
 *  File Name : ADC.c
 *  Created on: Sep 24, 2023
 *  Author: ABDELRAHMAN MAGDY
*/
#include <avr/io.h>
#include <avr/interrupt.h>
#include "typedef.h"
#include "common_macros.h"
#include "adc.h"

/*
 * Function to init ADC
 * set REF_Voltage
 * set Prescaler
*/
void ADC_init(const ADC_str *config)
{
	ADMUX = ((config->REF_Voltage &0x03)<<6);
	ADCSRA = (config->N &0x07);
	SET_BIT(ADCSRA,ADEN);
}

//********************************************************************************************************
//********************************************************************************************************

/*
 * Function to READCHANNEL OF  ADC
*/
uint_16 ADC_Read_Channel(uint_8 ch_num)
{
	ch_num &= 0x07;
	ADMUX &= 0xE0;
	ADMUX = ADMUX | ch_num ;
	SET_BIT(ADCSRA,ADSC);

    while IF_BIT_CLEAR(ADCSRA,ADIF))
    {
	SET_BIT(ADCSRA,ADIF);
    }

	return ADC ;
}

//********************************************************************************************************
//********************************************************************************************************

//enable interrupt of ADC
static volatile void (*g_func)()= NULL;           //CALLBACK_func to call it in ISR
void ADC_Enable_interrupt()
{
	SET_BIT(SREG,7);
	SET_BIT(ADCSRA,ADIE);
}
void ADC_callback_func (void(*function)(void))
{
	g_func = (volatile void (*)())function;
}
ISR(ADC_vect)                                      //ISR of ADC
{
	g_func();
}
