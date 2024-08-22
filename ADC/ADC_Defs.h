/**
 * @file ADC_Defs.h
 * @author Kunal Salvi (kunalsalviusu@gmail.com)
 * @brief  The variables used to configure the ADC are declared in this file.
 *         Use these configurations only.
 *         
 * @version 0.1
 * @date 2024-08-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef ADC_DEFS_H_
#define ADC_DEFS_H_

#include "main.h"
#include "ADC.h"

/**
 * @brief 
 * 
 * This sturct is used in _ADC_Channel_ struct. 
 * Used to enable or disable a particular Channel of the ADC.
 * 
 * @see _ADC_Channel_
 * 
 * @param Enable 
 * @param Disable
 * 
 */
typedef struct _ADC_Channel_Enable_Disable_{
	bool Enable;
	bool Disable;
}_ADC_Channel_Enable_Disable_;

/**
 * @brief 
 * 
 * This sturct is used in _ADC_Channel_ struct. 
 * Used to enable or disable a particular Channel of the ADC.
 * 
 * @see _ADC_Channel_
 * 
 *  @param Sequence_1;
	@param Sequence_2;
	@param Sequence_3;
	@param Sequence_4;
	@param Sequence_5;
	@param Sequence_6;
	@param Sequence_7;
	@param Sequence_8;
	@param Sequence_9;
	@param Sequence_10;
	@param Sequence_11;
	@param Sequence_12;
	@param Sequence_13;
	@param Sequence_14;
	@param Sequence_15;
	@param Sequence_16;
 * 
 */
typedef struct _ADC_Channel_Sequence_Number_{

	uint8_t Sequence_1;
	uint8_t Sequence_2;
	uint8_t Sequence_3;
	uint8_t Sequence_4;
	uint8_t Sequence_5;
	uint8_t Sequence_6;
	uint8_t Sequence_7;
	uint8_t Sequence_8;
	uint8_t Sequence_9;
	uint8_t Sequence_10;
	uint8_t Sequence_11;
	uint8_t Sequence_12;
	uint8_t Sequence_13;
	uint8_t Sequence_14;
	uint8_t Sequence_15;
	uint8_t Sequence_16;
}_ADC_Channel_Sequence_Number_;

/**
 * @brief 
 * 
 * This struct provides an easy way for the user to set the sample time 
 * of a channel. All the options when selected will have an additional
 * 12 cycles added to them in the hardware. 
 * So _3_Cycles is selected by the user, then total cycles taken to complete
 * one conversion of that channel will be 3+12 = 15 cycles.
 * Is used in _ADC_Channel_ struct. 
 * 
 * @see _ADC_Channel_
 * 
 *  @param  _3_Cycles
	@param _15_Cycles
	@param _28_Cycles
	@param _56_Cycles
	@param _84_Cycles
	@param _112_Cycles
	@param _144_Cycles
	@param _480_Cycles
 * 
 */

typedef struct _ADC_Channel_Sample_Time_{
	uint8_t _3_Cycles;
	uint8_t _15_Cycles;
	uint8_t _28_Cycles;
	uint8_t _56_Cycles;
	uint8_t _84_Cycles;
	uint8_t _112_Cycles;
	uint8_t _144_Cycles;
	uint8_t _480_Cycles;
}_ADC_Channel_Sample_Time_;

/**
 * @brief 
 * This sturct is used in ADC_Configuration struct. 
 * Encapsulates all the necessary configurations needed for any 
 * ADC channel. 
 * 
 * @param Enable
 * @param Sequence_Number
 * @param Sample_Time
 * 
 * @see _ADC_Channel_Enable_Disable_
 * @see _ADC_Channel_Sequence_Number_
 * @see _ADC_Channel_Sample_Time_
 * 
 */
typedef struct _ADC_Channel_{

	_ADC_Channel_Enable_Disable_ Enable;
	_ADC_Channel_Sequence_Number_ Sequence_Number;
	_ADC_Channel_Sample_Time_ Sample_Time;
}_ADC_Channel_;


/**
 * @brief 
 * This struct helps select the mode in which the conversions will happen.
 * 
 * @attention When an external trigger is used i.e. Regular_External_Trigger_Enable or 
 * Injected_External_Trigger_Enable is configured to be Enable, make sure to 
 * select "Single" instead of Continuous.
 * 
 * @snippet Conversion_Mode.Single
 * 
 * @see ADC_Configuration 
 */
typedef struct ADC_Mode
{
	uint8_t Single;
	uint8_t Continuous;

}ADC_Mode;

typedef struct 	ADC_Channel_Type{
	uint8_t Regular;
	uint8_t Injected;
}ADC_Channel_Type;

static const struct ADC_Configuration{

	struct Port{
		ADC_TypeDef *_ADC1_;
		ADC_TypeDef *_ADC2_;
		ADC_TypeDef *_ADC3_;
	}Port;



	struct Data_Alignment{

		uint8_t Left_Justified;
		uint8_t Right_Justified;
	}Data_Alignment;


	_ADC_Channel_ Channel;

	struct Conversion_Mode{
		uint8_t Single;
		uint8_t Continuous;
	}Conversion_Mode;

	ADC_Channel_Type Channel_Type;


	struct Resolution{
		uint8_t Bit_12;
		uint8_t Bit_10;
		uint8_t Bit_8;
		uint8_t Bit_6;
	}Resolution;

	struct Regular_External_Trigger_Enable{
		uint8_t Trigger_Disable;
		uint8_t Trigger_On_Rising_Edge;
		uint8_t Trigger_On_Falling_Edge;
		uint8_t Trigger_On_Both_Edges;
	}Regular_External_Trigger_Enable;


	struct Regular_External_Trigger_Event{
		uint8_t Timer_1_CC1;
		uint8_t Timer_1_CC2;
		uint8_t Timer_1_CC3;
		uint8_t Timer_2_CC2;
		uint8_t Timer_2_CC3;
		uint8_t Timer_2_CC4;
		uint8_t Timer_2_TRGO;
		uint8_t Timer_3_CC1;
		uint8_t Timer_3_TRGO;
		uint8_t Timer_4_CC4;
		uint8_t Timer_5_CC1;
		uint8_t Timer_5_CC2;
		uint8_t Timer_5_CC3;
		uint8_t Timer_8_CC1;
		uint8_t Timer_8_TRGO;
		uint8_t EXTI_11;
	}Regular_External_Trigger_Event;

	struct Injected_External_Trigger_Event{
		uint8_t Timer_1_CC4;
		uint8_t Timer_1_TRGO;
		uint8_t Timer_2_CC1;
		uint8_t Timer_2_TRGO;
		uint8_t Timer_3_CC2;
		uint8_t Timer_3_CC4;
		uint8_t Timer_4_CC1;
		uint8_t Timer_4_CC2;
		uint8_t Timer_4_CC3;
		uint8_t Timer_4_TRGO;
		uint8_t Timer_5_CC4;
		uint8_t Timer_5_TRGO;
		uint8_t Timer_8_CC2;
		uint8_t Timer_8_CC3;
		uint8_t Timer_8_CC4;
		uint8_t EXTI_15;
	}Injected_External_Trigger_Event;



	struct _Watchdog_Analog_{

		ADC_Channel_Type Channel_Type;

		bool Enable;
		bool Disable;

		struct Channel_Scan
		{
			bool All_Channels;
			bool Single_Channel;
		}Channel_Scan;





	}_Watchdog_Analog_;







}ADC_Configuration = {

		.Channel_Type = {
				.Regular = 0,
				.Injected = 1,
		},

		.Data_Alignment = {
			.Left_Justified = 1,
			.Right_Justified = 0,
		},


		.Port = {
			._ADC1_ = ADC1,
			._ADC2_ = ADC2,
			._ADC3_ = ADC3,
		},



		.Conversion_Mode = {
				.Single = 1,
				.Continuous = 2,
		},



		.Regular_External_Trigger_Enable = {
				.Trigger_Disable = 0,
				.Trigger_On_Rising_Edge = 1,
				.Trigger_On_Falling_Edge = 2,
				.Trigger_On_Both_Edges = 3,
		},

		.Regular_External_Trigger_Event =
		{
					.Timer_1_CC1 = 0,
					.Timer_1_CC2 = 1,
					.Timer_1_CC3 = 2,
					.Timer_2_CC2 = 3,
					.Timer_2_CC3 = 4,
					.Timer_2_CC4 = 5,
					.Timer_2_TRGO = 6,
					.Timer_3_CC1 = 7,
					.Timer_3_TRGO = 8,
					.Timer_4_CC4 = 9,
					.Timer_5_CC1 = 10,
					.Timer_5_CC2 = 11,
					.Timer_5_CC3 = 12,
					.Timer_8_CC1 = 13,
					.Timer_8_TRGO = 14,
					.EXTI_11 = 15,
		},

		.Channel = {
				.Enable = {
						.Enable = 1,
						.Disable = 0,
				},

				.Sequence_Number = {

						.Sequence_1 = 0,
						.Sequence_2 = 1,
						.Sequence_3 = 2,
						.Sequence_4 = 3,
						.Sequence_5 = 4,
						.Sequence_6 = 5,
						.Sequence_7 = 6,
						.Sequence_8 = 7,
						.Sequence_9 = 8,
						.Sequence_10 = 9,
						.Sequence_11 = 10,
						.Sequence_12 = 11,
						.Sequence_13 = 12,
						.Sequence_14 = 13,
						.Sequence_15 = 14,
						.Sequence_16 = 15,
				},
				.Sample_Time = {
						._3_Cycles = 0,
						._15_Cycles = 1,
						._28_Cycles = 2,
						._56_Cycles = 3,
						._84_Cycles = 4,
						._112_Cycles = 5,
						._144_Cycles = 6,
						._480_Cycles = 7,
				},
		},


};



#endif /* ADC_DEFS_H_ */
