/*
 * Joystick_HAL.h
 *
 *  Created on: Aug 27, 2024
 *      Author: kunal
 */

#ifndef JOYSTICK_HAL_H_
#define JOYSTICK_HAL_H_

#include "main.h"
#include "ADC/ADC.h"
#include "GPIO/GPIO.h"

#define MAX_JOYSTICK_INSTANCES 4

typedef struct Joystick_HAL_Typedef{
	uint8_t number_of_Joystick_Instances;
	float update_rate;
}Joystick_HAL_Typedef;


void Joystick_HAL_Init(Joystick_HAL_Typedef *instance);
uint16_t Joystick_HAL_Read_X(uint8_t joystickIndex);
uint16_t Joystick_HAL_Read_Y(uint8_t joystickIndex);

#endif /* JOYSTICK_HAL_H_ */
