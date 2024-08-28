#include <stdint.h>
#include "main.h"
#include "ADC.h"
#include "GPIO.h"





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




	for(;;)
	{


		GPIO_Pin_High(GPIOD, 12);
		Delay_milli(1000);
		GPIO_Pin_Low(GPIOD, 12);
		Delay_milli(1000);
	}
}
