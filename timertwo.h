/*
 * timertwo.h
 *
 *  Created on: Sep 10, 2019
 *      Author: Cheng-Chiang (rocky)
 */

#ifndef TIMERTWO_H_
#define TIMERTWO_H_



#include <stddef.h>

// Driver Header files
#include <ti/drivers/GPIO.h>
#include <ti/drivers/Timer.h>
#include <ti/drivers/ADC.h>

// Board Header file
#include "Board.h"


// Callback used for toggling the LED.
void timer55Callback(Timer_Handle myHandle);
void *timer2Thread(void *arg0);
void adc0Read(void);



#endif // TIMERTWO_H_

