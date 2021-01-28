/*
    The idea is to get a sample after a set amout of time. The number of X samples 
    and the duration between 2 samples can be defined. If X samples have the same
    value (either high or low) the loop stop. If a n+1 sample is different from the n
    sample we start over to get the samples 
*/

#include "Define.h"

void Delay (int mili);
void Debounce(int button,char ID, int samples, int time)
{
    int bit=0;
    switch(ID){
        case 'A':
        case 'a':
            bit=17; //GPIO pin# 17
            break;
        case 'B':
        case 'b':
            bit=26; //GPIO pin# 18
            break;
        }
    int current_state=(IN&(1<<bit));    //current_state= state of
                                        // BUTTON_A if bit=17 or BUTTON_B if bit=26
    int count=0;
    while(1)
    {
        Delay(time);
        if (((IN&(1<<bit))==current_state))
        {
        count++;
        }
        else {
            count=0;
            current_state=(IN&(1<<bit));
            }
        if (count>(samples-1))
        break;
    }

}