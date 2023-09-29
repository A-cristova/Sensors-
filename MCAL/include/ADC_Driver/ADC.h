/*
 *  File Name : ADC.h
 *  Created on: Sep 24, 2023
 *  Author: ABDELRAHMAN MAGDY
*/
#include "typedef.h"


#define ADC_Max_Value          1023
#define ADC_Ref_Volt_Value     2.56

#define  AREF              0
#define  AVCC              1
#define  Reserved          2
#define  Internal_V        3

#define  N_2       0
#define  N_4       2
#define  N_8       3
#define  N_16      4
#define  N_32      5
#define  N_64      6
#define  N_128     7

typedef struct
{
	uint_8 REF_Voltage;
	uint_8 N;
}ADC_str;


#ifndef ADC_H_
#define ADC_H_

void ADC_init(const ADC_str *config);
uint_16 ADC_Read_Channel(uint_8 ch_num);
void ADC_Enable_interrupt();
void ADC_callback_func();
#endif /* ADC_DRIVER_ADC_H_ */
