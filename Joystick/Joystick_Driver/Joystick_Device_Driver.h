/*
 * Joystick_Device_Driver.h
 *
 *  Created on: Aug 27, 2024
 *      Author: kunal
 */

#ifndef JOYSTICK_DEVICE_DRIVER_H_
#define JOYSTICK_DEVICE_DRIVER_H_

#include "Joystick_HAL/Joystick_HAL.h"


typedef struct {
    int16_t x;
    int16_t y;
    bool button;
} JoystickPosition_t;

void Joystick_Init(uint8_t joystick_instances, float updaterate);
JoystickPosition_t Joystick_Read(uint8_t joystickIndex);

#endif /* JOYSTICK_DEVICE_DRIVER_H_ */
