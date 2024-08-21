/*
 * ADC.c
 *
 *  Created on: Jul 31, 2024
 *      Author: kunal
 */


#include "ADC.h"

DMA_Config xADC;

int8_t pin_temp = 0;

//void ADC_IRQHandler(void)
//{
//	if(ADC1 -> SR & ADC_SR_OVR)
//	{
//		ADC1 -> SR &= ~(ADC_SR_OVR | ADC_SR_EOC);
//		ADC1 -> CR2 |= ADC_CR2_ADON ;
//		ADC1 -> CR2 |= ADC_CR2_SWSTART;
//		DMA_Set_Target(&xADC);
//		DMA_Set_Trigger(&xADC);
//	}
//}

static void ADC_Timer_External_Trigger_Init(ADC_Config *config)
{
	if(config->External_Trigger.Trigger_Event == ADC_Configuration.Regular_External_Trigger_Event.Timer_1_CC1)
	{
		RCC -> APB2ENR |= RCC_APB2ENR_TIM1EN;
		TIM1 -> CCR1 = 100/2 -1;
		TIM1->PSC = 16800;
		TIM1->ARR = 100-1;
		TIM1 -> CR2 |= TIM_CR2_MMS_1 | TIM_CR2_MMS_0;
		TIM1 -> CCER |= TIM_CCER_CC1E;
		TIM1->CR1 |= TIM_CR1_CEN ;
	}
	else if(config->External_Trigger.Trigger_Event == ADC_Configuration.Regular_External_Trigger_Event.Timer_1_CC2)
	{
		RCC -> APB2ENR |= RCC_APB2ENR_TIM1EN;
		TIM1 -> EGR |= TIM_EGR_CC2G;
		TIM1->DIER |=  TIM_DIER_CC2IE;
		//	NVIC_EnableIRQ(TIM1_CC_IRQn);
		//	NVIC_SetPriority(TIM1_CC_IRQn,1);
		TIM1->PSC = 10000-1;
		TIM1->ARR = 8400-1;
		TIM1->CR1 |= TIM_CR1_CEN;
	}
	else if(config->External_Trigger.Trigger_Event == ADC_Configuration.Regular_External_Trigger_Event.Timer_1_CC3)
	{
		RCC -> APB2ENR |= RCC_APB2ENR_TIM1EN;
		TIM1 -> EGR |= TIM_EGR_CC3G;
		TIM1->DIER |=  TIM_DIER_CC3IE;
		//	NVIC_EnableIRQ(TIM1_CC_IRQn);
		//	NVIC_SetPriority(TIM1_CC_IRQn,1);
		TIM1->PSC = 10000-1;
		TIM1->ARR = 8400-1;
		TIM1->CR1 |= TIM_CR1_CEN;
	}
	else if(config->External_Trigger.Trigger_Event == ADC_Configuration.Injected_External_Trigger_Event.Timer_1_CC4)
	{
		RCC -> APB2ENR |= RCC_APB2ENR_TIM1EN;
		TIM1 -> EGR |= TIM_EGR_CC4G;
		TIM1->DIER |=  TIM_DIER_CC4IE;
		//	NVIC_EnableIRQ(TIM1_CC_IRQn);
		//	NVIC_SetPriority(TIM1_CC_IRQn,1);
		TIM1->PSC = 10000-1;
		TIM1->ARR = 8400-1;
		TIM1->CR1 |= TIM_CR1_CEN;
	}
	/***************************************************************************************************************/
	else if(config->External_Trigger.Trigger_Event == ADC_Configuration.Injected_External_Trigger_Event.Timer_2_CC1)
	{
		RCC -> APB1ENR |= RCC_APB1ENR_TIM2EN;
		TIM2 -> EGR |= TIM_EGR_CC1G;
		TIM2->DIER |=  TIM_DIER_CC1IE;
		//	NVIC_EnableIRQ(TIM1_CC_IRQn);
		//	NVIC_SetPriority(TIM1_CC_IRQn,1);
		TIM2->PSC = 10000-1;
		TIM2->ARR = 8400-1;
		TIM2->CR1 |= TIM_CR1_CEN;
	}
	else if(config->External_Trigger.Trigger_Event == ADC_Configuration.Regular_External_Trigger_Event.Timer_2_CC2)
	{
		RCC -> APB1ENR |= RCC_APB1ENR_TIM2EN;
		TIM2 -> EGR |= TIM_EGR_CC2G | TIM_EGR_UG;
//		TIM2->DIER |=  TIM_DIER_CC2IE;
//		//	NVIC_EnableIRQ(TIM1_CC_IRQn);
//		//	NVIC_SetPriority(TIM1_CC_IRQn,1);
//		TIM2->PSC = 10000-1;
//		TIM2->ARR = 8400-1;
//		TIM2->CR1 |= TIM_CR1_CEN;

		TIM2 -> CCR1 = 10000/2 -1;
		TIM2->PSC = 16800;
		TIM2->ARR = 10000-1;
		TIM2 -> CR2 |=  TIM_CR2_MMS_1;
		TIM2 -> CCER |= TIM_CCER_CC2E;
		TIM2->CR1 |= TIM_CR1_CEN ;
	}
	else if(config->External_Trigger.Trigger_Event == ADC_Configuration.Regular_External_Trigger_Event.Timer_2_CC3)
	{
		RCC -> APB1ENR |= RCC_APB1ENR_TIM2EN;
		TIM2 -> EGR |= TIM_EGR_CC3G;
		TIM2->DIER |=  TIM_DIER_CC3IE;
		// NVIC_EnableIRQ(TIM1_CC_IRQn);
		//	NVIC_SetPriority(TIM1_CC_IRQn,1);
		TIM2->PSC = 10000-1;
		TIM2->ARR = 8400-1;
		TIM2->CR1 |= TIM_CR1_CEN;
	}
	else if(config->External_Trigger.Trigger_Event == ADC_Configuration.Regular_External_Trigger_Event.Timer_2_CC4)
	{
		RCC -> APB1ENR |= RCC_APB1ENR_TIM2EN;
		TIM2 -> EGR |= TIM_EGR_CC3G;
		TIM2->DIER |=  TIM_DIER_CC3IE;
		// NVIC_EnableIRQ(TIM1_CC_IRQn);
		//	NVIC_SetPriority(TIM1_CC_IRQn,1);
		TIM2->PSC = 10000-1;
		TIM2->ARR = 8400-1;
		TIM2->CR1 |= TIM_CR1_CEN;
	}
	else if(config->External_Trigger.Trigger_Event == ADC_Configuration.Regular_External_Trigger_Event.Timer_2_TRGO)
	{
		RCC -> APB1ENR |= RCC_APB1ENR_TIM2EN;

		TIM2->DIER |=  TIM_DIER_UIE;
		// NVIC_EnableIRQ(TIM1_CC_IRQn);
		//	NVIC_SetPriority(TIM1_CC_IRQn,1);
		TIM2 -> CR2 |=  TIM_CR2_MMS_1;
		TIM2->PSC = 10000-1;
		TIM2->ARR = 1680-1;
		TIM2->CR1 |= TIM_CR1_CEN;
		TIM2 -> EGR |= TIM_EGR_UG;
	}
	/***************************************************************************************************************/
	else if(config->External_Trigger.Trigger_Event == ADC_Configuration.Regular_External_Trigger_Event.Timer_3_CC1)
	{
		RCC -> APB1ENR |= RCC_APB1ENR_TIM2EN;
		TIM3 -> EGR |= TIM_EGR_CC1G;
		TIM3->DIER |=  TIM_DIER_CC1IE;
		//	NVIC_EnableIRQ(TIM1_CC_IRQn);
		//	NVIC_SetPriority(TIM1_CC_IRQn,1);
		TIM3->PSC = 10000-1;
		TIM3->ARR = 8400-1;
		TIM3->CR1 |= TIM_CR1_CEN;
	}
	else if(config->External_Trigger.Trigger_Event == ADC_Configuration.Injected_External_Trigger_Event.Timer_3_CC2)
	{
		RCC -> APB1ENR |= RCC_APB1ENR_TIM2EN;
		TIM3 -> EGR |= TIM_EGR_CC2G;
		TIM3->DIER |=  TIM_DIER_CC2IE;
		//	NVIC_EnableIRQ(TIM1_CC_IRQn);
		//	NVIC_SetPriority(TIM1_CC_IRQn,1);
		TIM3->PSC = 10000-1;
		TIM3->ARR = 8400-1;
		TIM3->CR1 |= TIM_CR1_CEN;
	}
	else if(config->External_Trigger.Trigger_Event == ADC_Configuration.Injected_External_Trigger_Event.Timer_3_CC4)
	{
		RCC -> APB1ENR |= RCC_APB1ENR_TIM2EN;
		TIM3 -> EGR |= TIM_EGR_CC3G;
		TIM3->DIER |=  TIM_DIER_CC3IE;
		// NVIC_EnableIRQ(TIM1_CC_IRQn);
		//	NVIC_SetPriority(TIM1_CC_IRQn,1);
		TIM3->PSC = 10000-1;
		TIM3->ARR = 8400-1;
		TIM3->CR1 |= TIM_CR1_CEN;
	}
	/***************************************************************************************************************/
}

static int8_t ADC_Sampling_Config(ADC_Config *config)
{

	uint8_t conversion_Counter = 0;
	if(config->Channel_0.Enable == ENABLE)
	{

		config->Port->SMPR2 |= config->Channel_0.Sample_Time << ADC_SMPR2_SMP0_Pos;
		conversion_Counter += 1;
	}

	if(config->Channel_1.Enable == ENABLE)
	{
		config->Port->SMPR2 |= config->Channel_1.Sample_Time << ADC_SMPR2_SMP1_Pos;
		conversion_Counter += 1;
	}

	if(config->Channel_2.Enable == ENABLE)
	{
		config->Port->SMPR2 |= config->Channel_2.Sample_Time << ADC_SMPR2_SMP2_Pos;
		conversion_Counter += 1;
	}

	if(config->Channel_3.Enable == ENABLE)
	{
		config->Port->SMPR2 |= config->Channel_3.Sample_Time << ADC_SMPR2_SMP3_Pos;
		conversion_Counter += 1;
	}

	if(config->Channel_4.Enable == ENABLE)
	{
		config->Port->SMPR2 |= config->Channel_4.Sample_Time << ADC_SMPR2_SMP4_Pos;
		conversion_Counter += 1;
	}

	if(config->Channel_5.Enable == ENABLE)
	{
		config->Port->SMPR2 |= config->Channel_5.Sample_Time << ADC_SMPR2_SMP5_Pos;
		conversion_Counter += 1;
	}

	if(config->Channel_6.Enable == ENABLE)
	{
		config->Port->SMPR2 |= config->Channel_6.Sample_Time << ADC_SMPR2_SMP6_Pos;
		conversion_Counter += 1;
	}

	if(config->Channel_7.Enable == ENABLE)
	{
		config->Port->SMPR2 |= config->Channel_7.Sample_Time << ADC_SMPR2_SMP7_Pos;
		conversion_Counter += 1;
	}

	if(config->Channel_8.Enable == ENABLE)
	{
		config->Port->SMPR2 |= config->Channel_8.Sample_Time << ADC_SMPR2_SMP8_Pos;
		conversion_Counter += 1;
	}

	if(config->Channel_9.Enable == ENABLE)
	{
		config->Port->SMPR1 |= config->Channel_9.Sample_Time << ADC_SMPR2_SMP9_Pos;
		conversion_Counter += 1;
	}

	if(config->Channel_10.Enable == ENABLE)
	{
		config->Port->SMPR1 |= config->Channel_10.Sample_Time << ADC_SMPR1_SMP10_Pos;
		conversion_Counter += 1;
	}

	if(config->Channel_11.Enable == ENABLE)
	{
		config->Port->SMPR1 |= config->Channel_11.Sample_Time << ADC_SMPR1_SMP11_Pos;
		conversion_Counter += 1;
	}
	/**************************************************************************************************************/
	if(config->Channel_12.Enable == ENABLE)
	{
		config->Port->SMPR1 |= config->Channel_12.Sample_Time << ADC_SMPR1_SMP12_Pos;
		conversion_Counter += 1;
	}
	/**************************************************************************************************************/
	if(config->Channel_13.Enable == ENABLE)
	{
		config->Port->SMPR1 |= config->Channel_13.Sample_Time << ADC_SMPR1_SMP13_Pos;
		conversion_Counter += 1;
	}
	/**************************************************************************************************************/
	if(config->Channel_14.Enable == ENABLE)
	{
		config->Port->SMPR1 |= config->Channel_14.Sample_Time << ADC_SMPR1_SMP14_Pos;
		conversion_Counter += 1;
	}
	/**************************************************************************************************************/
	if(config->Channel_15.Enable == ENABLE)
	{
		config->Port->SMPR1 |= config->Channel_15.Sample_Time << ADC_SMPR1_SMP15_Pos;
		conversion_Counter += 1;
	}



	return conversion_Counter;

}

/********************************************************************************************************************/
static int8_t ADC_Pin_Init(ADC_Config *config)
{
	if(config->Channel_0.Enable == ENABLE)
	{
		GPIO_Pin_Init(GPIOA, 0, GPIO_Configuration.Mode.Analog, GPIO_Configuration.Output_Type.None, GPIO_Configuration.Speed.None, GPIO_Configuration.Pull.None, GPIO_Configuration.Alternate_Functions.Analog);
	}

	if(config->Channel_1.Enable == ENABLE)
	{
		GPIO_Pin_Init(GPIOA, 1, GPIO_Configuration.Mode.Analog, GPIO_Configuration.Output_Type.None, GPIO_Configuration.Speed.None, GPIO_Configuration.Pull.None, GPIO_Configuration.Alternate_Functions.Analog);
	}

	if(config->Channel_2.Enable == ENABLE)
	{
		GPIO_Pin_Init(GPIOA, 2, GPIO_Configuration.Mode.Analog, GPIO_Configuration.Output_Type.None, GPIO_Configuration.Speed.None, GPIO_Configuration.Pull.None, GPIO_Configuration.Alternate_Functions.Analog);
	}

	if(config->Channel_3.Enable == ENABLE)
	{
		GPIO_Pin_Init(GPIOA, 3, GPIO_Configuration.Mode.Analog, GPIO_Configuration.Output_Type.None, GPIO_Configuration.Speed.None, GPIO_Configuration.Pull.None, GPIO_Configuration.Alternate_Functions.Analog);
	}

	if(config->Channel_4.Enable == ENABLE)
	{
		GPIO_Pin_Init(GPIOA, 4, GPIO_Configuration.Mode.Analog, GPIO_Configuration.Output_Type.None, GPIO_Configuration.Speed.None, GPIO_Configuration.Pull.None, GPIO_Configuration.Alternate_Functions.Analog);
	}

	if(config->Channel_5.Enable == ENABLE)
	{
		GPIO_Pin_Init(GPIOA, 5, GPIO_Configuration.Mode.Analog, GPIO_Configuration.Output_Type.None, GPIO_Configuration.Speed.None, GPIO_Configuration.Pull.None, GPIO_Configuration.Alternate_Functions.Analog);
	}

	if(config->Channel_6.Enable == ENABLE)
	{
		GPIO_Pin_Init(GPIOA, 6, GPIO_Configuration.Mode.Analog, GPIO_Configuration.Output_Type.None, GPIO_Configuration.Speed.None, GPIO_Configuration.Pull.None, GPIO_Configuration.Alternate_Functions.Analog);
	}

	if(config->Channel_7.Enable == ENABLE)
	{
		GPIO_Pin_Init(GPIOA, 7, GPIO_Configuration.Mode.Analog, GPIO_Configuration.Output_Type.None, GPIO_Configuration.Speed.None, GPIO_Configuration.Pull.None, GPIO_Configuration.Alternate_Functions.Analog);
	}

	if(config->Channel_8.Enable == ENABLE)
	{
		GPIO_Pin_Init(GPIOB, 0, GPIO_Configuration.Mode.Analog, GPIO_Configuration.Output_Type.None, GPIO_Configuration.Speed.None, GPIO_Configuration.Pull.None, GPIO_Configuration.Alternate_Functions.Analog);
	}

	if(config->Channel_9.Enable == ENABLE)
	{
		GPIO_Pin_Init(GPIOB, 1, GPIO_Configuration.Mode.Analog, GPIO_Configuration.Output_Type.None, GPIO_Configuration.Speed.None, GPIO_Configuration.Pull.None, GPIO_Configuration.Alternate_Functions.Analog);
	}

	if(config->Channel_10.Enable == ENABLE)
	{
		GPIO_Pin_Init(GPIOC, 0, GPIO_Configuration.Mode.Analog, GPIO_Configuration.Output_Type.None, GPIO_Configuration.Speed.None, GPIO_Configuration.Pull.None, GPIO_Configuration.Alternate_Functions.Analog);
	}

	if(config->Channel_11.Enable == ENABLE)
	{
		GPIO_Pin_Init(GPIOC, 1, GPIO_Configuration.Mode.Analog, GPIO_Configuration.Output_Type.None, GPIO_Configuration.Speed.None, GPIO_Configuration.Pull.None, GPIO_Configuration.Alternate_Functions.Analog);
	}
	/**************************************************************************************************************/
	if(config->Channel_12.Enable == ENABLE)
	{
		GPIO_Pin_Init(GPIOC, 2, GPIO_Configuration.Mode.Analog, GPIO_Configuration.Output_Type.None, GPIO_Configuration.Speed.None, GPIO_Configuration.Pull.None, GPIO_Configuration.Alternate_Functions.Analog);
	}
	/**************************************************************************************************************/
	if(config->Channel_13.Enable == ENABLE)
	{
		GPIO_Pin_Init(GPIOC, 3, GPIO_Configuration.Mode.Analog, GPIO_Configuration.Output_Type.None, GPIO_Configuration.Speed.None, GPIO_Configuration.Pull.None, GPIO_Configuration.Alternate_Functions.Analog);
	}
	/**************************************************************************************************************/
	if(config->Channel_14.Enable == ENABLE)
	{
		GPIO_Pin_Init(GPIOC, 4, GPIO_Configuration.Mode.Analog, GPIO_Configuration.Output_Type.None, GPIO_Configuration.Speed.None, GPIO_Configuration.Pull.None, GPIO_Configuration.Alternate_Functions.Analog);
	}
	/**************************************************************************************************************/
	if(config->Channel_15.Enable == ENABLE)
	{
		GPIO_Pin_Init(GPIOC, 5, GPIO_Configuration.Mode.Analog, GPIO_Configuration.Output_Type.None, GPIO_Configuration.Speed.None, GPIO_Configuration.Pull.None, GPIO_Configuration.Alternate_Functions.Analog);
	}

	return 1;
}


static int8_t ADC_Sequence_Config(ADC_Config *config)
{
	if(config->Channel_0.Enable == ENABLE)
	{
		config -> Port -> SQR3 |= config->Channel_0.Sequence_Number << ADC_SQR3_SQ1_Pos;
	}

	if(config->Channel_1.Enable == ENABLE)
	{
		config -> Port -> SQR3 |= config->Channel_1.Sequence_Number << ADC_SQR3_SQ2_Pos;
	}

	if(config->Channel_2.Enable == ENABLE)
	{
		config -> Port -> SQR3 |= config->Channel_2.Sequence_Number << ADC_SQR3_SQ3_Pos;
	}

	if(config->Channel_3.Enable == ENABLE)
	{
		config -> Port -> SQR3 |= config->Channel_3.Sequence_Number << ADC_SQR3_SQ4_Pos;
	}

	if(config->Channel_4.Enable == ENABLE)
	{
		config -> Port -> SQR3 |= config->Channel_4.Sequence_Number << ADC_SQR3_SQ5_Pos;
	}

	if(config->Channel_5.Enable == ENABLE)
	{
		config -> Port -> SQR3 |= config->Channel_5.Sequence_Number << ADC_SQR3_SQ6_Pos;
	}

	if(config->Channel_6.Enable == ENABLE)
	{
		config -> Port -> SQR2 |= config->Channel_6.Sequence_Number << ADC_SQR2_SQ7_Pos;
	}

	if(config->Channel_7.Enable == ENABLE)
	{
		config -> Port -> SQR2 |= config->Channel_7.Sequence_Number << ADC_SQR2_SQ8_Pos;
	}

	if(config->Channel_8.Enable == ENABLE)
	{
		config -> Port -> SQR2 |= config->Channel_8.Sequence_Number << ADC_SQR2_SQ9_Pos;
	}

	if(config->Channel_9.Enable == ENABLE)
	{
		config -> Port -> SQR2 |= config->Channel_9.Sequence_Number << ADC_SQR2_SQ10_Pos;
	}

	if(config->Channel_10.Enable == ENABLE)
	{
		config -> Port -> SQR2 |= config->Channel_10.Sequence_Number << ADC_SQR2_SQ11_Pos;
	}

	if(config->Channel_11.Enable == ENABLE)
	{
		config -> Port -> SQR2 |= config->Channel_11.Sequence_Number << ADC_SQR2_SQ12_Pos;
	}
	/**************************************************************************************************************/
	if(config->Channel_12.Enable == ENABLE)
	{
		config -> Port -> SQR1 |= config->Channel_12.Sequence_Number << ADC_SQR1_SQ13_Pos;
	}
	/**************************************************************************************************************/
	if(config->Channel_13.Enable == ENABLE)
	{
		config -> Port -> SQR1 |= config->Channel_13.Sequence_Number << ADC_SQR1_SQ14_Pos;
	}
	/**************************************************************************************************************/
	if(config->Channel_14.Enable == ENABLE)
	{
		config -> Port -> SQR1 |= config->Channel_14.Sequence_Number << ADC_SQR1_SQ15_Pos;
	}
	/**************************************************************************************************************/
	if(config->Channel_15.Enable == ENABLE)
	{
		config -> Port -> SQR1 |= config->Channel_15.Sequence_Number << ADC_SQR1_SQ16_Pos;
	}

	return 1;
}


/********************************************************************************************************************/
int8_t ADC_Init(ADC_Config *config)
{
	if(config->Port == ADC_Configuration.Port._ADC1_) RCC -> APB2ENR |= RCC_APB2ENR_ADC1EN;
	else if(config->Port == ADC_Configuration.Port._ADC2_) RCC -> APB2ENR |= RCC_APB2ENR_ADC2EN;
	else if(config->Port == ADC_Configuration.Port._ADC3_)RCC -> APB2ENR |= RCC_APB2ENR_ADC3EN;
	else return -1;

	config -> Port -> CR1 |= ADC_CR1_SCAN ;

	if(config->Resolution == ADC_Configuration.Resolution.Bit_12) config -> Port -> CR1 &= ~ADC_CR1_RES;
	else if(config->Resolution == ADC_Configuration.Resolution.Bit_10) config -> Port -> CR1 |=  1 << ADC_CR1_RES_Pos;
	else if(config->Resolution == ADC_Configuration.Resolution.Bit_8)  config -> Port -> CR1 |=  2 << ADC_CR1_RES_Pos;
	else if(config->Resolution == ADC_Configuration.Resolution.Bit_6)  config -> Port -> CR1 |=  3 << ADC_CR1_RES_Pos;
	else return -1;


	if(config -> Conversion_Mode == ADC_Configuration.Conversion_Mode.Single){
		config -> Port -> CR2  &= ~ADC_CR2_CONT;
	}
	else if(config -> Conversion_Mode == ADC_Configuration.Conversion_Mode.Continuous){
		config -> Port -> CR2  |= ADC_CR2_CONT;
	}
	else {return -1;}


	config -> Port -> CR2 |= ADC_CR2_EOCS ;

	// Data Alignment
	if(config -> Data_Alignment == ADC_Configuration.Data_Alignment.Right_Justified)
	{
		config -> Port -> CR2 &= ~ADC_CR2_ALIGN;
	}
	else if(config -> Data_Alignment == ADC_Configuration.Data_Alignment.Left_Justified)
	{
		config -> Port -> CR2 |= ADC_CR2_ALIGN;
	}
	else {return -1;}

	pin_temp = ADC_Sampling_Config(config);

	config -> Port -> SQR1 |= (pin_temp-1) << ADC_SQR1_L_Pos;

	ADC_Pin_Init(config);



	if(config->Channel_Type == ADC_Configuration.Channel_Type.Regular)
	{
		config -> Port -> CR2 &= ~ADC_CR2_EXTSEL;

		if(config -> External_Trigger.Enable == ENABLE)
		{
//			config -> Port -> CR2 |= config -> External_Trigger.Trigger_Event << ADC_CR2_EXTSEL_Pos;
			config -> Port -> CR2 |= ADC_CR2_EXTSEL_2 | ADC_CR2_EXTSEL_1;
			config -> Port -> CR2 |= ADC_CR2_EXTEN_0;
			ADC_Timer_External_Trigger_Init(config);
		}
	}
	else if(config->Channel_Type == ADC_Configuration.Channel_Type.Injected)
	{
		config -> Port -> CR2 &= ~ADC_CR2_JEXTSEL;
		config -> Port -> CR2 |= config -> External_Trigger.Enable << ADC_CR2_JEXTEN_Pos;
		config -> Port -> CR2 |= config -> External_Trigger.Trigger_Event << ADC_CR2_JEXTSEL_Pos;
		ADC_Timer_External_Trigger_Init(config);

	}
	else return -1;


	config -> Port -> CR2 |= ADC_CR2_DMA;
	config -> Port -> CR2 |= ADC_CR2_DDS;

	ADC_Sequence_Config(config);

	ADC_Enable(config);

	xADC.Request = DMA_Configuration.Request._ADC1;
	xADC.transfer_direction = DMA_Configuration.Transfer_Direction.Peripheral_to_memory;
	xADC.circular_mode = DMA_Configuration.Circular_Mode.Enable;
	xADC.flow_control = DMA_Configuration.Flow_Control.DMA_Control;
	xADC.memory_data_size = DMA_Configuration.Memory_Data_Size.half_word;
	xADC.peripheral_data_size = DMA_Configuration.Peripheral_Data_Size.half_word;
	xADC.memory_pointer_increment = DMA_Configuration.Memory_Pointer_Increment.Enable;
	xADC.peripheral_pointer_increment = DMA_Configuration.Peripheral_Pointer_Increment.Disable;
	DMA_Init(&xADC);


	return 1;
}
/********************************************************************************************************************/

int8_t ADC_Enable(ADC_Config *config)
{
	config -> Port -> CR2 |= ADC_CR2_ADON;
	Delay_milli(1000);
//	uint32_t delay = 10000;
//	while (delay--);
	return 1;
}

int8_t ADC_Start(ADC_Config *config)
{
	config -> Port -> SR = 0;
	if(config->Channel_Type == ADC_Configuration.Channel_Type.Regular) {
		config -> Port -> CR2 |= ADC_CR2_SWSTART;
	}
	else if(config->Channel_Type == ADC_Configuration.Channel_Type.Injected){
		config -> Port -> CR2 |= ADC_CR2_JSWSTART;
	}
	else return -1;
	return 1;
}

int8_t ADC_Start_Capture(ADC_Config *config, uint16_t *buffer)
{
	if ((config->Port->SR) &(ADC_SR_OVR))
	{
		config->Port->CR2 &= ~ADC_CR2_ADON;
		config->Port->CR2 |= ADC_CR2_ADON;
	}

	xADC.buffer_length = pin_temp;
	xADC.peripheral_address = (uint32_t)&(config->Port->DR);
	xADC.memory_address = (uint32_t)buffer;

	DMA_Set_Target(&xADC);
	DMA_Set_Trigger(&xADC);
	config -> Port -> SR = 0;
	ADC_Start(config);
	return 1;
}
