/*
 *  File Name :Common_Macros.h
 *  Des: File include Common Macro
 *  Created on: Aug 31, 2023
 *  Author: ABDELRAHMAN MAGDY
 */

#ifndef COMMON_MCROS_H_
#define COMMON_MCROS_H_

#define  SET_BIT(REG,BIT)         (REG) |=(1<<(BIT))     //set bit in register
#define  CLEAR_BIT(REG,BIT)       (REG) &=~(1<<(BIT))    //clear bit in register
#define  TOGLLE_BIT(REG,BIT)      (REG) ^=(1<<(BIT))     //toggle bit in register
#define  IF_BIT_CLEAR(REG,BIT)    (!(REG)&(1<<(BIT))     //check if bit in register is clear
#define  IF_BIT_SET(REG,BIT)      ((REG)&(1<<(BIT))      //check if bit in register is set
#define  GET_BIT(REG,BIT)         ((REG)>>(BIT)&1)       //Get bit in register


#endif /* LIBRARY_INCLUDE_COMMON_MCROS_H_ */
