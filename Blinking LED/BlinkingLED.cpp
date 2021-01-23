#include "Define.h"
/*
	Led blinking using Timer
*/

int main()
{
    TIMER_MODE=0;   //chose timer as mode
    BIT_MODE=0;     // 16bit timer
    PRESCALER=9;   //16Mhz divided by 10= ftime (i.e numbers of ticks per second)
    CC_1=31250;     //write 15625 to the compare/capture register 1; Event_COMPARE_1 will turn 1 when the counter reach CC1 value
    TASK_START=1;   //start the timer
    
    DIRSET=(1<<4)+(1<<13)+(1<<14); //set pin4 and 13 as output
    OUTCLR=(1<<4);         //set pin 04 (column 1) to 0
    
    while (1)
    {
        while (EVENT_COMPARE_1)     //when EVEN_COMPARE_1 is set (i.e when timer reaches CC_1 value)
        {
            TASK_STOP=1;            //stop Timer
            TASK_CLEAR=1;           //Clear timer (reset timer)
            TASK_START=1;           //Start timer again
            EVENT_COMPARE_1=0;
            if (OUT&(1<<13))        //check if pin 13 is high (1), clear if true and set if false
            {
                OUTSET=(1<<14);
                OUTCLR=(1<<13);
                break;
            }
            else
            {
                OUTCLR=(1<<14);
                OUTSET=(1<<13);
                break;
            }
        }
    }
    
}