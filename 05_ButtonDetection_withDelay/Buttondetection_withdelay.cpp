#include "Define.h"
void Delay(int milisec);
void Led_on_individually(int row, int col);
void Debounce(int button);
int main()
{
     
    BUTTON_B=0;                //set BUTTON_B register to 0x0 which enable input buffet and set it as an input pin
                                
    DIRSET=(1<<4)+(1<<5)+(1<<6)+(1<<7)+(1<<8)+(1<<9)+(1<<10)+(1<<11)+(1<<12)+(1<<13)+(1<<14)+(1<<15); //set as output
    OUTSET=(1<<4)+(1<<5)+(1<<6)+(1<<7)+(1<<8)+(1<<9)+(1<<10)+(1<<11)+(1<<12);   // set LED collumns to high
    OUTCLR=(1<<13)+(1<<14)+(1<<15);                                             //Set LED rows to low           
   
    
    while (1)
    {
      for (int i=1;i<=5;i++)
        for (int j=1;j<=5;j++){
            while ((IN&(1<<26))!=0) //keep looping until BUTTON_B is pressed (showing low)
                {}
                Delay(100);      //Delay for 100 milisec to debounce the button, comment this line out to see how it react without debounce
                Led_on_individually(i,j);
                }
    
    }
}