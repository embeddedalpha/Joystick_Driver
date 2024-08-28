/*
 * Joystick_Device_Driver.c
 *
 *  Created on: Aug 27, 2024
 *      Author: kunal
 */


#include "Joystick_Device_Driver.h"

Joystick_HAL_Typedef joystick_driver_instance;

void Joystick_Init(uint8_t joystick_instances, float updaterate)
{
	joystick_driver_instance.number_of_Joystick_Instances = joystick_instances;
	joystick_driver_instance.update_rate = updaterate;
	Joystick_HAL_Init(&joystick_driver_instance);
}


JoystickPosition_t Joystick_Read(uint8_t joystickIndex)
{
	JoystickPosition_t position;

    uint16_t rawX = Joystick_HAL_Read_X(joystickIndex);
    uint16_t rawY = Joystick_HAL_Read_Y(joystickIndex);

    // Normalize to signed 16-bit range (-32768 to 32767)
    position.x = (int16_t)(((int32_t)rawX - 2048) * 16);
    position.y = (int16_t)(((int32_t)rawY - 2048) * 16);

    return position;
}
