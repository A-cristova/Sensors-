/*
 *  File Name :PWM_0.h
 *  Created on: Sep 18, 2023
 *  Author: ABDELRAHMAN MAGDY
*/
#include "typedef.h"

#ifndef _PWM_0_H_
#define _PWM_0_H_

//Definitions of Prescaler of PWM_0
#define Np_No_clock          0
#define Np_0                 1
#define Np_8                 2
#define Np_64                3
#define Np_256               4
#define Np_1024              5
#define Np_Ex_clk_falling    6
#define Np_Ex_clk_raising    7

//********************************************************************************************************************************************
void PWM0_init();
void set_dutycycle( uint_8 d_cycle);
void set_prescaler( uint_8 N);
//********************************************************************************************************************************************



#endif /* PWM__PWM_0_PWM_0_H_ */
