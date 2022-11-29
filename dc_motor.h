/******************************************************************************
 *
 * Module: DC motor
 *
 * File Name: dc_motor.h
 *
 * Description: header file for the DC motor driver
 *
 * Author: Shimaa Gamal
 *
 *******************************************************************************/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define DC_MOTOR_IN1_PORT_ID            PORTB_ID
#define DC_MOTOR_IN2_PORT_ID            PORTB_ID
#define DC_MOTOR_IN1_PIN_ID             PIN0_ID
#define DC_MOTOR_IN2_PIN_ID             PIN1_ID


/*******************************************************************************
 *                                Types Declarations                           *
 *******************************************************************************/

typedef enum{
	Stop , A_CW , CW

}DcMotor_State;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/* Description
 * The function responsible for setup the direction of the two motor pins
 * and Stop the DC motor at the beginning through the GPIO driver
 * */

void DcMotor_Init(void);

/* Description
 * The function responsible for rotate the DC Motor CW/ or A-CW or
 * stop the motor based on the state input state value
 * Send the required duty cycle to the PWM driver based on the required speed value.
 * */

void DcMotor_Rotate(DcMotor_State state , uint8 speed);


#endif /* DC_MOTOR_H_ */
