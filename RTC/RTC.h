/*
 * RTC.h
 *
 *  Created on: Aug 31, 2024
 *      Author: kunal
 */

#ifndef RTC_H_
#define RTC_H_

#include "main.h"

volatile uint8_t Hour;
volatile uint8_t Minute;
volatile uint8_t Second;
volatile uint8_t Day;
volatile uint8_t Month;
volatile uint8_t Year;
volatile uint8_t Day_of_Week;


typedef struct RTC_Config
{
	uint8_t Format;

	struct Time_Setup
	{

		uint8_t Second;
		uint8_t Minute;
		uint8_t Hour;


		uint16_t Year;
		uint8_t Month;
		uint8_t Day;
		uint8_t Weekday;
	}Time_Setup;

	struct RTC_Interrupts{
		bool Time_Stamp_Enable;
		bool Wake_up_Timer_Enable;
		bool Alarm_A_Enable;
		bool Alarm_B_Enable;
	}RTC_Interrupts;

	struct Alarm_1
	{
		bool Enable;
		uint8_t Day;
		uint8_t Second;
		uint8_t Minute;
		uint8_t Hour;
		bool Output_Pulse_Enable;
	}Alarm_1;

	struct Alarm_2
	{
		bool Enable;
		uint8_t Day;
		uint8_t Second;
		uint8_t Minute;
		uint8_t Hour;
		bool Output_Pulse_Enable;
	}Alarm_2;

}RTC_Config;



#endif /* RTC_H_ */
