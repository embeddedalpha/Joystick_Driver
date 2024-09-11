#include <stdint.h>
#include "main.h"
#include "Console/Console.h"
#include "Joystick_Driver/Joystick_Device_Driver.h"



uint32_t tick = 0;
int32_t button1 = 0;

JoystickPosition_t Right_Joystick;

void TIM6_DAC_IRQHandler(void)
{
	TIM6 -> SR &= ~TIM_SR_UIF;
	Right_Joystick = Joystick_Read(1);
	printConsole("%d,%d,%d,\r\n",Right_Joystick.x,Right_Joystick.y,tick);
}

void General_Timer_Update_Init(void)
{
	RCC -> APB1ENR |= RCC_APB1ENR_TIM6EN;
	TIM6->PSC = 8400-1;
	TIM6->ARR = 100-1;
	TIM6 -> EGR |= TIM_EGR_UG;
	TIM6->CR1 |= TIM_CR1_URS;
	TIM6->DIER |=  TIM_DIER_UIE;
	TIM6->CR1 |= TIM_CR1_CEN;
	NVIC_SetPriority(TIM6_DAC_IRQn,1);
	NVIC_EnableIRQ(TIM6_DAC_IRQn);
}

int main(void)
{
	MCU_Clock_Setup();
	Delay_Config();
	Console_Init(9600); //921600
	General_Timer_Update_Init();

	Joystick_Init(1, 900);



	for(;;)
	{



	}
}
