/*
 * timerone.c
 *
 *  Created on: Sep 10, 2019
 *      Author: Cheng-Chiang (rocky)
 */
#include "timerone.h"

void *timer1Thread(void *arg0)
{
    Timer_Handle timer0;
    Timer_Params params;

    /* Call driver init functions */
    //GPIO_init();
    Timer_init();


    Timer_Params_init(&params);
    params.period =250000;//
    params.periodUnits = Timer_PERIOD_US;
    params.timerMode = Timer_CONTINUOUS_CALLBACK;
    params.timerCallback = timerQuarterCallback;

    timer0 = Timer_open(0, &params);

    if (timer0 == NULL) {
        /* Failed to initialized timer */
        while (1) {}
    }

    if (Timer_start(timer0) == Timer_STATUS_ERROR) {
        /* Failed to start timer */
        while (1) {}
    }

    return (NULL);
}

/*
 * This callback is called every 1,000,000 microseconds, or 1 second. Because
 * the LED is toggled each time this function is called, the LED will blink at
 * a rate of once every 2 seconds.
 * */
void timerQuarterCallback(Timer_Handle myHandle)
{
   //sendTimeMsgToQ1();
}
