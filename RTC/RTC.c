/*
 * RTC.c
 *
 *  Created on: Aug 31, 2024
 *      Author: kunal
 */

#include "RTC.h"

static uint8_t BCD_to_Decimal_Converter(uint8_t bcd)
{
	return ((bcd >> 4) * 10) + (bcd & 0x0F);
}

static uint8_t Decimal_to_BCD(uint8_t decimal) {
    return ((decimal / 10) << 4) | (decimal % 10);
}

static void Enter_Initalization_Mode(void)
{
    // Unlock the RTC registers
    RTC->WPR = 0xCA;
    RTC->WPR = 0x53;
}

static void Exit_Initalization_Mode(void)
{
    // Lock the RTC registers
    RTC->WPR = 0xFF;
}


void RTC_Init(RTC_Config *config)
{
    // Enable the power interface clock
    RCC->APB1ENR |= RCC_APB1ENR_PWREN;

    // Enable access to the backup domain
    PWR->CR |= PWR_CR_DBP;

    // Enable the LSE oscillator
    RCC->BDCR |= RCC_BDCR_LSEON;
    while (!(RCC->BDCR & RCC_BDCR_LSERDY)) {
        // Wait until LSE is ready
    }

    // Select the RTC clock source as LSE
    RCC->BDCR |= RCC_BDCR_RTCSEL_0;

    // Enable the RTC clock
    RCC->BDCR |= RCC_BDCR_RTCEN;

    Enter_Initalization_Mode();

    // Set initialization mode
    RTC->ISR |= RTC_ISR_INIT;
    while (!(RTC->ISR & RTC_ISR_INITF)) {
        // Wait until the RTC is in initialization mode
    }

    // Set prescaler values (example: 32767 for LSE 32.768 kHz clock)
    RTC->PRER = (0x7F << 16) | 0xFF;

    uint8_t hours_bcd = Decimal_to_BCD(config->Time_Setup.Hour);
    uint8_t minutes_bcd = Decimal_to_BCD(config->Time_Setup.Minute);
    uint8_t seconds_bcd = Decimal_to_BCD(config->Time_Setup.Second);

    // Set the time (example: 22:30:00 for 10:30 PM)
    RTC->TR = (hours_bcd << 16) | (minutes_bcd << 8) | (seconds_bcd);

    uint8_t year = Decimal_to_BCD(config->Time_Setup.Year);
    uint8_t month = Decimal_to_BCD(config->Time_Setup.Month);
    uint8_t day = Decimal_to_BCD(config->Time_Setup.Day);
    uint8_t weekday = Decimal_to_BCD(config->Time_Setup.Weekday);



    // Exit initialization mode
    RTC->ISR &= ~RTC_ISR_INIT;

    // Set prescaler values (example: 32767 for LSE 32.768 kHz clock)
    RTC->PRER = (0x7F << 16) | 0xFF;

    Exit_Initalization_Mode();
}

void RTC_Set_Alarm(RTC_Config *config)
{

	if(config->Alarm_1.Enable == ENABLE)
	{
		Enter_Initalization_Mode();

		Exit_Initalization_Mode();
//
	}
	if(config->Alarm_2.Enable == ENABLE)
	{
		Enter_Initalization_Mode();

		Exit_Initalization_Mode();
	}

}
