/*
 * ADC.h
 *
 *  Created on: Jul 31, 2024
 *      Author: kunal
 */

#ifndef ADC_H_
#define ADC_H_

#include "main.h"
#include "GPIO.h"
#include "DMA.h"
#include "ADC_Defs.h"


typedef struct ADC_Pin{
	bool Enable;
	uint8_t Sequence_Number;
	uint8_t Sample_Time;
}ADC_Pin;

typedef struct ADC_Config{

	ADC_TypeDef *Port;

	uint8_t Data_Alignment;

	uint8_t Conversion_Mode;

	uint8_t Channel_Type;

	struct External_Trigger
	{
		bool Enable;
		uint8_t Trigger_Event;
		uint8_t Sampling_Frequency;
	}External_Trigger;

	ADC_Pin Channel_0;
	ADC_Pin Channel_1;
	ADC_Pin Channel_2;
	ADC_Pin Channel_3;
	ADC_Pin Channel_4;
	ADC_Pin Channel_5;
	ADC_Pin Channel_6;
	ADC_Pin Channel_7;
	ADC_Pin Channel_8;
	ADC_Pin Channel_9;
	ADC_Pin Channel_10;
	ADC_Pin Channel_11;
	ADC_Pin Channel_12;
	ADC_Pin Channel_13;
	ADC_Pin Channel_14;
	ADC_Pin Channel_15;

	uint8_t Resolution;

	struct Watchdog_Analog
	{
		bool Enable;
		uint8_t Channel_Type;
		bool Channel_Scan;
		uint8_t Channel;
		uint16_t Higher_Threshold;
		uint16_t Lower_Threshold;
	}Watchdog_Analog;



}ADC_Config;

int8_t ADC_Init(ADC_Config *config);
int8_t ADC_Enable(ADC_Config *config);
int8_t ADC_Start(ADC_Config *config);
int8_t ADC_Start_Capture(ADC_Config *config, uint16_t *buffer);

#endif /* ADC_H_ */
