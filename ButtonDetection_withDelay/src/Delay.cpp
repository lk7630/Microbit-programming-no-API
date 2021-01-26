#include "Define.h"

void Delay(int milisec)
{
    TIMER_MODE=0;   //chose timer as mode
    BIT_MODE=0;     // 16bit timer
    PRESCALER=9;    // 16MHz/2^9=31250 ticks per second
    CC_1=milisec * 0.001 * 31250;   //1 sec= 0.001 milisec
    TASK_START=1;
    while (EVENT_COMPARE_1==0) // keep looping until the Timer counter reaches the value in CC_1 register
    {}
    EVENT_COMPARE_1=0;
    TASK_STOP=1;        //stop the timer
    TASK_CLEAR=1;       //clear the timer
}