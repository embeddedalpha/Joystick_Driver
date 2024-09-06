/*
 * Joystick_HAL.c
 *
 *  Created on: Aug 27, 2024
 *      Author: kunal
 */


#include "Joystick_HAL.h"

ADC_Config Joystick;

#define Joystick_Buffer_Size 2*MAX_JOYSTICK_INSTANCES

uint16_t Joystick_Data_Buffer[Joystick_Buffer_Size];

void Joystick_HAL_Init(Joystick_HAL_Typedef *instance)
{
	if(instance ->number_of_Joystick_Instances == 1)
	{
		Joystick.Channel_0.Enable = ADC_Configuration.Channel.Enable.Enable;
		Joystick.Channel_0.Sample_Time = ADC_Configuration.Channel.Sample_Time._3_Cycles;
		Joystick.Channel_0.Sequence_Number = ADC_Configuration.Channel.Sequence_Number.Sequence_1;

		Joystick.Channel_1.Enable = ADC_Configuration.Channel.Enable.Enable;
		Joystick.Channel_1.Sample_Time = ADC_Configuration.Channel.Sample_Time._3_Cycles;
		Joystick.Channel_1.Sequence_Number = ADC_Configuration.Channel.Sequence_Number.Sequence_2;
	}
	else if(instance ->number_of_Joystick_Instances == 2)
	{
		Joystick.Channel_0.Enable = ADC_Configuration.Channel.Enable.Enable;
		Joystick.Channel_0.Sample_Time = ADC_Configuration.Channel.Sample_Time._3_Cycles;
		Joystick.Channel_0.Sequence_Number = ADC_Configuration.Channel.Sequence_Number.Sequence_1;

		Joystick.Channel_1.Enable = ADC_Configuration.Channel.Enable.Enable;
		Joystick.Channel_1.Sample_Time = ADC_Configuration.Channel.Sample_Time._3_Cycles;
		Joystick.Channel_1.Sequence_Number = ADC_Configuration.Channel.Sequence_Number.Sequence_2;

		Joystick.Channel_2.Enable = ADC_Configuration.Channel.Enable.Enable;
		Joystick.Channel_2.Sample_Time = ADC_Configuration.Channel.Sample_Time._3_Cycles;
		Joystick.Channel_2.Sequence_Number = ADC_Configuration.Channel.Sequence_Number.Sequence_3;

		Joystick.Channel_3.Enable = ADC_Configuration.Channel.Enable.Enable;
		Joystick.Channel_3.Sample_Time = ADC_Configuration.Channel.Sample_Time._3_Cycles;
		Joystick.Channel_3.Sequence_Number = ADC_Configuration.Channel.Sequence_Number.Sequence_4;
	}
	else if(instance ->number_of_Joystick_Instances == 3)
	{
		Joystick.Channel_0.Enable = ADC_Configuration.Channel.Enable.Enable;
		Joystick.Channel_0.Sample_Time = ADC_Configuration.Channel.Sample_Time._3_Cycles;
		Joystick.Channel_0.Sequence_Number = ADC_Configuration.Channel.Sequence_Number.Sequence_1;

		Joystick.Channel_1.Enable = ADC_Configuration.Channel.Enable.Enable;
		Joystick.Channel_1.Sample_Time = ADC_Configuration.Channel.Sample_Time._3_Cycles;
		Joystick.Channel_1.Sequence_Number = ADC_Configuration.Channel.Sequence_Number.Sequence_2;

		Joystick.Channel_2.Enable = ADC_Configuration.Channel.Enable.Enable;
		Joystick.Channel_2.Sample_Time = ADC_Configuration.Channel.Sample_Time._3_Cycles;
		Joystick.Channel_2.Sequence_Number = ADC_Configuration.Channel.Sequence_Number.Sequence_3;

		Joystick.Channel_3.Enable = ADC_Configuration.Channel.Enable.Enable;
		Joystick.Channel_3.Sample_Time = ADC_Configuration.Channel.Sample_Time._3_Cycles;
		Joystick.Channel_3.Sequence_Number = ADC_Configuration.Channel.Sequence_Number.Sequence_4;

		Joystick.Channel_4.Enable = ADC_Configuration.Channel.Enable.Enable;
		Joystick.Channel_4.Sample_Time = ADC_Configuration.Channel.Sample_Time._3_Cycles;
		Joystick.Channel_4.Sequence_Number = ADC_Configuration.Channel.Sequence_Number.Sequence_5;

		Joystick.Channel_5.Enable = ADC_Configuration.Channel.Enable.Enable;
		Joystick.Channel_5.Sample_Time = ADC_Configuration.Channel.Sample_Time._3_Cycles;
		Joystick.Channel_5.Sequence_Number = ADC_Configuration.Channel.Sequence_Number.Sequence_6;
	}
	else if(instance ->number_of_Joystick_Instances == MAX_JOYSTICK_INSTANCES)
	{
		Joystick.Channel_0.Enable = ADC_Configuration.Channel.Enable.Enable;
		Joystick.Channel_0.Sample_Time = ADC_Configuration.Channel.Sample_Time._3_Cycles;
		Joystick.Channel_0.Sequence_Number = ADC_Configuration.Channel.Sequence_Number.Sequence_1;

		Joystick.Channel_1.Enable = ADC_Configuration.Channel.Enable.Enable;
		Joystick.Channel_1.Sample_Time = ADC_Configuration.Channel.Sample_Time._3_Cycles;
		Joystick.Channel_1.Sequence_Number = ADC_Configuration.Channel.Sequence_Number.Sequence_2;

		Joystick.Channel_2.Enable = ADC_Configuration.Channel.Enable.Enable;
		Joystick.Channel_2.Sample_Time = ADC_Configuration.Channel.Sample_Time._3_Cycles;
		Joystick.Channel_2.Sequence_Number = ADC_Configuration.Channel.Sequence_Number.Sequence_3;

		Joystick.Channel_3.Enable = ADC_Configuration.Channel.Enable.Enable;
		Joystick.Channel_3.Sample_Time = ADC_Configuration.Channel.Sample_Time._3_Cycles;
		Joystick.Channel_3.Sequence_Number = ADC_Configuration.Channel.Sequence_Number.Sequence_4;

		Joystick.Channel_4.Enable = ADC_Configuration.Channel.Enable.Enable;
		Joystick.Channel_4.Sample_Time = ADC_Configuration.Channel.Sample_Time._3_Cycles;
		Joystick.Channel_4.Sequence_Number = ADC_Configuration.Channel.Sequence_Number.Sequence_5;

		Joystick.Channel_5.Enable = ADC_Configuration.Channel.Enable.Enable;
		Joystick.Channel_5.Sample_Time = ADC_Configuration.Channel.Sample_Time._3_Cycles;
		Joystick.Channel_5.Sequence_Number = ADC_Configuration.Channel.Sequence_Number.Sequence_6;

		Joystick.Channel_6.Enable = ADC_Configuration.Channel.Enable.Enable;
		Joystick.Channel_6.Sample_Time = ADC_Configuration.Channel.Sample_Time._3_Cycles;
		Joystick.Channel_6.Sequence_Number = ADC_Configuration.Channel.Sequence_Number.Sequence_7;

		Joystick.Channel_7.Enable = ADC_Configuration.Channel.Enable.Enable;
		Joystick.Channel_7.Sample_Time = ADC_Configuration.Channel.Sample_Time._3_Cycles;
		Joystick.Channel_7.Sequence_Number = ADC_Configuration.Channel.Sequence_Number.Sequence_8;
	}

	Joystick.Channel_Type = ADC_Configuration.Channel_Type.Regular;
	Joystick.Conversion_Mode = ADC_Configuration.Conversion_Mode.Single;
	Joystick.Data_Alignment = ADC_Configuration.Data_Alignment.Right_Justified;
	Joystick.Port = ADC_Configuration.Port._ADC1_;
	Joystick.Resolution = ADC_Configuration.Resolution.Bit_12;
	Joystick.External_Trigger.Enable = ENABLE;
//	Joystick.External_Trigger.Trigger_Event = ADC_Configuration.Regular_External_Trigger_Event.Timer_2_TRGO;
	Joystick.External_Trigger.Trigger_Event = ADC_Configuration.Regular_External_Trigger_Event.Timer_2_CC2;
	ADC_Init(&Joystick);
	ADC_Start_Capture(&Joystick, Joystick_Data_Buffer);
}

uint16_t Joystick_HAL_Read_X(uint8_t joystickIndex)
{
	if(joystickIndex == 1)
	{
		return Joystick_Data_Buffer[0];
	}
	else if(joystickIndex == 1)
	{
		return Joystick_Data_Buffer[2];
	}

	return 0;
}

uint16_t Joystick_HAL_Read_Y(uint8_t joystickIndex)
{
	if(joystickIndex == 1)
	{
		return Joystick_Data_Buffer[1];
	}
	else if(joystickIndex == 1)
	{
		return Joystick_Data_Buffer[3];
	}

	return 0;
}
