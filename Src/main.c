#include <stdint.h>
#include "main.h"
#include "ADC.h"
#include "GPIO.h"

ADC_Config Joystick;

#define Joystick_Buffer_Size 4

uint16_t Joystick_Data_Buffer[Joystick_Buffer_Size];

bool Joystick_1_UP = 0;
bool Joystick_1_Down = 0;
bool Joystick_1_Left = 0;
bool Joystick_1_Right = 0;

bool Joystick_2_UP = 0;
bool Joystick_2_Down = 0;
bool Joystick_2_Left = 0;
bool Joystick_2_Right = 0;



int main(void)
{
	MCU_Clock_Setup();
	Delay_Config();

	GPIO_Pin_Init(GPIOD, 12,
			GPIO_Configuration.Mode.General_Purpose_Output,
			GPIO_Configuration.Output_Type.Push_Pull,
			GPIO_Configuration.Speed.Very_High_Speed,
			GPIO_Configuration.Pull.No_Pull_Up_Down,
			GPIO_Configuration.Alternate_Functions.None);

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

	Joystick.Channel_Type = ADC_Configuration.Channel_Type.Regular;
	Joystick.Conversion_Mode = ADC_Configuration.Conversion_Mode.Single;
	Joystick.Data_Alignment = ADC_Configuration.Data_Alignment.Right_Justified;
	Joystick.Port = ADC_Configuration.Port._ADC1_;
	Joystick.Resolution = ADC_Configuration.Resolution.Bit_12;
	Joystick.External_Trigger.Enable = ENABLE;
	Joystick.External_Trigger.Trigger_Event = ADC_Configuration.Regular_External_Trigger_Event.Timer_2_TRGO;

	ADC_Init(&Joystick);
	ADC_Start_Capture(&Joystick, Joystick_Data_Buffer);


	for(;;)
	{


		GPIO_Pin_High(GPIOD, 12);
		Delay_milli(1000);
		GPIO_Pin_Low(GPIOD, 12);
		Delay_milli(1000);
	}
}
