/*
 *  File Name :DIO_Enums.h
 *  Des: File include Enums
 *  Created on: Aug 31, 2023
 *  Author: ABDELRAHMAN MAGDY
 */

#ifndef GPIO_ENUMS_func_H_
#define GPIO_ENUMS_func_H_

#include "typedef.h"
// enum to select port name
typedef enum
{
	PORT_A  =0,
	PORT_B  =1,
	PORT_C  =2,
	PORT_D  =3,
} DIO_port_name;

// enum to select pin name
typedef enum
{
	PIN_0 =0,
	PIN_1 =1,
	PIN_2 =2,
	PIN_3 =3,
	PIN_4 =4,
	PIN_5 =5,
	PIN_6 =6,
	PIN_7 =7,
}DIO_pin_name;

// enum to select pin direction
typedef enum
{
	INPUT =0,
	OUTPUT =1,
}DIO_pin_direction;

// enum to select port direction
typedef enum
{
	INPUT_PORT =0,
	OUTPUT_PORT =1,
}DIO_port_direction;

//TO Choose Type Of outputvalue of pin
typedef enum
{
	HIGH =1,
	LOW  =0,
}DIO_pin_output_value;

//TO Choose Type Of outputvalue of port
typedef enum
{
	HIGH_PORT =1,
	LOW_PORT  =0,
}DIO_port_output_value;



/*
 *  File Name :DIO_funcs.h
 *  Des: File include functions
 *  Created on: Aug 31, 2023
 *  Author: ABDELRAHMAN MAGDY
 */


void GPIO_setpindirection ( DIO_port_name port, DIO_pin_name pin, DIO_pin_direction direction);   //function to Set The Direction to pin
void GPIO_writepin (DIO_port_name port, DIO_pin_name pin, DIO_pin_output_value value);            //function to write the output value to pin
uint_8 GPIO_readpin (DIO_port_name port, DIO_pin_name pin);                                       //function to Read the input value to pin

void GPIO_setportdirection ( DIO_port_name port, DIO_port_direction direction);                   //function to Set The Direction to port
void GPIO_writeport (DIO_port_name port, DIO_port_output_value value);                            //function to write the output value to port
uint_8 GPIO_readport (DIO_port_name port);                                                        //function to Read the input value to port

#endif /* MCAL_INCLUDE_DIO_FUNC_H_ */


