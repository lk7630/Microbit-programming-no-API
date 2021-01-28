#include "Define.h"

int main()
{
    
    TIMER_MODE=0;   //chose timer as mode
    BIT_MODE=0;     // 16bit timer
    PRESCALER=9;   //16Mhz divided by 10= ftime (i.e numbers of ticks per second)
    CC_1=31250;     //write 15625 to the compare/capture register 1; Event_COMPARE_1 will turn 1 when the counter reach CC1 value
    DIRSET=(1<<4)+(1<<13)+(1<<14); //set pin4 and 13 as output
    OUTCLR=(1<<4); 
    OUTSET=(1<<13);

    SHORTS_1|=(1<<1); //shortcut from capre_event

    CONFIG_0|=((1<<0)+(1<<1));          //Mode
    CONFIG_0|=((1<<11)+(1<<10)+(1<<8)); //PSEL
    CONFIG_0|=((1<<17)+(1<<16));        //POLARITY
    
    
    CHENSET=1;      //enable channel 0 PPI
    CH0_EEP=(BASE_TIMER_ADDRESS + 0x144);   // attach Compare_event[1] to EEP (EVENT port)
    CH0_TEP=(GPIOTE_BASE_ADDRESS + 0x000);  // attach CONFIG[0] resister of GPIOTE to TEP (TASK port)
    
    TASK_START=1;
    while(1){}  // infinite loop to see that PPI does not envolve the CPU
}