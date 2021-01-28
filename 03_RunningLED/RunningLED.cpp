#include "Define.h"

void Led_on_individually(int row, int col);
int main()
{
    TIMER_MODE=0;   //chose timer as mode
    BIT_MODE=0;     // 16bit timer
    PRESCALER=10;   //16Mhz divided by a^10= ftime (i.e numbers of ticks per second)->1 sec there are 15625 ticks
    CC_1=15625;     //write 15625 to the compare/capture register 1; Event_COMPARE_1 will turn 1 when the counter reach CC1 value
    TASK_START=1;   //start the timer
    
    DIRSET=(1<<4)+(1<<5)+(1<<6)+(1<<7)+(1<<8)+(1<<9)+(1<<10)+(1<<11)+(1<<12)+(1<<13)+(1<<14)+(1<<15); //set all GPIO pins which connect to LEDs as output pins
    OUTSET=(1<<4)+(1<<5)+(1<<6)+(1<<7)+(1<<8)+(1<<9)+(1<<10)+(1<<11)+(1<<12);                         //set the collums high so all LEDs should be off
    
    while (1)
    {
        for (int i=1; i<=5; i++)
        {
            for (int j=1;j<=5;j++)
            {
                while (EVENT_COMPARE_1==0)  //keep looping when EVEN_COMPARE_1 register is 0
                {}                          // i.e when Timer has not reached the value in CC1 register
            
            Led_on_individually( i, j);
            EVENT_COMPARE_1=0;              //clear EVENT_COMPARE_1 (the flag)
            TASK_CLEAR=1;                   // clear Timer
            }
        }
    }
    
}

