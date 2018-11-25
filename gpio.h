#ifndef __GPIO_H
#define __GPIO_H

/************************Header files*********************/
#include <stdio.h>
#include "C:\ti\TivaWare_C_Series-2.1.4.178\inc\tm4c123gh6pm.h"
#include <stdint.h>

/***************************Macros************************/
#define GPIO_LOCK_KEY           0x4C4F434B  // Unlocks the GPIO_CR register
#define RED   0X02
#define BLUE  0X04
#define GREEN 0X08
#define SW1   0X10
#define SW2   0X01
#define SW1AND2 0X00


/*************Functions' prototypes**********************/
/*
 * This function is used to initialize PORTF pins for 2 switches and 3 leds of the launchpad
 *
 * @param void
 *
 * @return void
 */
void PORTF_init(void);
/********************************************************************************************/
/*
 * This function reads the state of pf0 and pf4 pins (sw0 and sw1) in the launchpad and return them
 *
 *@param void
 *
 *@return uint32_t value of the portf data register of pf0 and pf4 
 */
uint32_t read_PORTF(void);
/*********************************************************************************************/
/*
 *This function writes to pf1, pf2, and pf3 bits of PORTF to control 3-color LED 
 *
 *@param data: which is the value we want to write in the data register to control the 3-color LED
 *
 *@return void
 */
void write_PORTF(uint32_t data);
/*********************************************************************************************/
#endif /*__GPIO_H*/
