/*
 * timerone.h
 *
 *  Created on: Sep 10, 2019
 *      Author: Cheng-Chiang (rocky)
 */

#ifndef TIMERONE_H_
#define TIMERONE_H_

#include <stddef.h>

/* Driver Header files */
#include <ti/drivers/GPIO.h>
#include <ti/drivers/Timer.h>

/* Board Header file */
#include "Board.h"


/* Callback used for toggling the LED. */
void *timer1Thread(void *arg0);
void timerQuarterCallback(Timer_Handle myHandle);


#endif /* TIMERONE_H_ */
