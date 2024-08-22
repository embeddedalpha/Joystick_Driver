/**
 * @file ADC.h
 * @author Kunal Salvi (kunalsalvius@gmail.com)
 * @brief  This is the driver file to be added the the application code.
 *         Functions in this driver are implemented in @ref ADC.c
 *         
 * @version 0.1
 * @date 2024-08-21
 * 
 * @copyright Copyright (c) 2024
 * 
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


/** @struct ADC_Config
 *  @brief  This is the configuration structure to be used to make an instance of ADC.
 */

typedef struct ADC_Config{

/**
 * @brief 	Sets up the ADC hardware block to be used. 
 *        	STM32F407VGT6 has 3 ADC blocks and can be set using
 * 			@ref ADC_Configuration.Port
 * 
 */
	ADC_TypeDef *Port; 


/**
 * @brief 	Used to setup Data Alignment of the converted data. 
 *        	Data can be converted into Right or Left Alignment 
 * 			@ref ADC_Configuration.Data_Alignment
 * 
 */
	uint8_t Data_Alignment;

/**
 * @brief 	Used to setup Conversion Mode of the ADC. 
 *        	ADC conversions can Single or Continuous.
 * 			When External Trigger is enabled, make sure conversion mode
 * 			is set to Single  
 *          @ref ADC_Configuration.Conversion_Mode
 * 
 */
	uint8_t Conversion_Mode;


/**
 * @brief Used to setup Channel Type of the ADC.
 * 
 */
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
