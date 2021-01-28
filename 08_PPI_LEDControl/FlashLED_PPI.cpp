#include "Define.h"

int main()
{
    //BUTTON_B=0; //set BUTTON_B as input and enable input buffer
    DIRSET=(1<<4)+(1<<13); //set pin4 and 13 as output
    OUTCLR=(1<<4);
    //DIRCLR=(1<<26);

    CONFIG_0|=((1<<0)+(1<<1));          //Mode : task
    CONFIG_0|=((1<<11)+(1<<10)+(1<<8)); //PSEL : pin13 01101
    CONFIG_0|=((1<<17)+(1<<16));        //POLARITY : toggle hi->low or low->hi
    
    CONFIG_1|=(1<<0);          //Mode : event
    CONFIG_1|=((1<<12)+(1<<11)+(1<<9)); //PSEL : pin27 11011
    CONFIG_1|=(1<<17) + (1<<16);        //POLARITY : generate on rising edge
    
    
    CHENSET=1;      //enable channel 0 PPI
    CH0_EEP=(GPIOTE_BASE_ADDRESS + 0x104);   // attach IN[1] register of GPIOTE to EEP (Event)
    CH0_TEP=(GPIOTE_BASE_ADDRESS + 0x000);  // attach OUT[0] resister of GPIOTE to TEP (TASK)
    
    while(1){}  // infinite loop to see that PPI does not envolve the CPU
}