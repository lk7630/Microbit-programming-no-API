#include "Define.h"


int main()
{   
    DIRSET=(1<<4)+(1<<13); //set pin4 and 13 as output
    OUTCLR=(1<<4);       //set pin 04 (column 1) to 0
    OUTSET=(1<<13);
    
}