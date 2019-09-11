/*
 * timertwo.c
 *
 *  Created on: Sep 10, 2019
 *      Author: Cheng-Chiang (rocky)
 */


#include "timertwo.h"


void *timer2Thread(void *arg0)
{
    Timer_Handle timer0;
    Timer_Params params;

    // Call driver init functions
    //GPIO_init();
    Timer_init();

    // Setting up the timer in continuous callback mode that calls the callback
     // function every 1,000,000 microseconds, or 1 second.

    Timer_Params_init(&params);
    params.period =55000;
    params.periodUnits = Timer_PERIOD_US;
    params.timerMode = Timer_CONTINUOUS_CALLBACK;
    params.timerCallback = timer55Callback;

    timer0 = Timer_open(0, &params);

    if (timer0 == NULL) {
        // Failed to initialized timer
        while (1) {}
    }

    if (Timer_start(timer0) == Timer_STATUS_ERROR) {
        // Failed to start timer
        while (1) {}
    }

    return (NULL);
}



void timer55Callback(Timer_Handle myHandle)
{
        adc0Read();
}

void adc0Read(void)
{
    ADC_init();
    ADC_Handle   adc;
    ADC_Params   params;
    int_fast16_t res;
    // ADC conversion result variables
    uint16_t adcValue0;
    uint32_t adcValue0MicroVolt;
    uint32_t calculated;

    ADC_Params_init(&params);
    adc = ADC_open(0, &params);

    if (adc == NULL) {
       // Display_printf(display, 0, 0, "Error initializing ADC0\n");
        while (1);
    }

    // Blocking mode conversion
    res = ADC_convert(adc, &adcValue0);

    if (res == ADC_STATUS_SUCCESS) {

        adcValue0MicroVolt = ADC_convertRawToMicroVolts(adc, adcValue0);
        calculated = (6762/(adcValue0MicroVolt*.0002048-9))-4;
    }
    else {

    }

    ADC_close(adc);

  //  return (NULL);
}

