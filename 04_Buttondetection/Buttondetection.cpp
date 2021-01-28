#include "Define.h"

int main()
{
    BUTTON_B=0;             //set B as input and disable input buffer
    DIRSET=(1<<4)+(1<<13);  //set 2 GPIO pins as output
    OUTCLR=(1<<4);          //set collumn to low
    
    
    while (1)
    {
       if ((IN&(1<<26))!=0) //button bounce happens too fast for human to see
       {
        OUTSET=(1<<13);
        }
        else OUTCLR=(1<<13);
    
    }
}