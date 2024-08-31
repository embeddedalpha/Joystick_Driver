#include <stdint.h>
#include "main.h"
#include "Console.h"
#include "GPIO.h"


int j1x = 32768;
int j1y = -32768;
int j2x = 32768;
int j2y = -32768;

uint32_t tick = 0;
int32_t button1 = 0;

void TIM6_DAC_IRQHandler(void)
{
	TIM6 -> SR &= ~TIM_SR_UIF;
	tick += 1;

	button1 = GPIOA->IDR & GPIO_IDR_ID0_Msk;

	printConsole("%d,\r\n",button1);
}

void General_Timer_Update_Init(void)
{
	RCC -> APB1ENR |= RCC_APB1ENR_TIM6EN;
	TIM6->PSC = 84-1;
	TIM6->ARR = 4000-1;
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
	BSP_Init();

	GPIO_Pin_Init(GPIOA, 0,
			GPIO_Configuration.Mode.Input,
			GPIO_Configuration.Output_Type.None,
			GPIO_Configuration.Speed.None,
			GPIO_Configuration.Pull.None,
			GPIO_Configuration.Alternate_Functions.None);


	for(;;)
	{

		if(tick % 2 == 0)
		{
			GPIO_Pin_High(GPIOD, 12);
			GPIO_Pin_Low(GPIOD, 13);
			GPIO_Pin_High(GPIOD, 14);
			GPIO_Pin_Low(GPIOD, 15);
		}
		if(tick % 2 == 1)
		{
			GPIO_Pin_High(GPIOD, 13);
			GPIO_Pin_High(GPIOD, 15);
			GPIO_Pin_Low(GPIOD, 12);
			GPIO_Pin_Low(GPIOD, 14);
		}

	}
}
