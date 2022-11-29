 /******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.h
 *
 * Description: Header file for the ATmega16 PWM driver
 *
 * Author: Shimaa Gamal
 *
 *******************************************************************************/

#ifndef PWM_H_
#define PWM_H_

#include "std_types.h"

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description : Function responsible for initialize the Timer0 PWM
 *
 */

void PWM_Timer0_Init(uint8 duty_cycle);

#endif /* PWM_H_ */
