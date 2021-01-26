/*
    2 modes:
    - Mode 0:
        +Press BUTTON_A to run LED from right to leff
        +Press BUTTON_A to run LED from left to right
    - Mode 1:
        +Press BUTTON_A to run LED from bottom to top
        +Press BUTTON_B to run LED from top to bottm
    Change mode by pressing and holding A+B. All LEDs flash and then the 1st LED on 
     
*/


#include "Define.h"
void delay(int milisec);
void Led_on_individually(int row, int col);
void Debounce(int button,char type, int samples, int time);
int main()
{
     
    
    BUTTON_B=0;              
    BUTTON_A=0;
    DIRSET=(1<<4)+(1<<5)+(1<<6)+(1<<7)+(1<<8)+(1<<9)+(1<<10)+(1<<11)+(1<<12)+(1<<13)+(1<<14)+(1<<15);
    OUTSET=(1<<4)+(1<<5)+(1<<6)+(1<<7)+(1<<8)+(1<<9)+(1<<10)+(1<<11)+(1<<12);  
    int row=(1<<13)+(1<<14)+(1<<15);
    OUTCLR=row;     //Set all row to low
    int col=(1<<4)+(1<<5)+(1<<6)+(1<<7)+(1<<8)+(1<<9)+(1<<10)+(1<<11)+(1<<12);
    OUTSET=col; //Set all columns to high

    int i=1;
    int j=1;
    Led_on_individually(i,j);
    int mode=0;
    while (1)
    {
        if (((IN&(1<<26))==0)&&((IN&(1<<17))!=0))
        {
            Debounce(BUTTON_B,'B',4,30);
            //delay(100);
            if ((i==5)&&(j==5))
                {i=1;
                j=1;}
            else if (j==5)
                {j=1;
                i++;}
            else
            {
                j++;
                }
                if (mode==0)
            Led_on_individually(i,j);
            else Led_on_individually(j,i);      
        }
         if (((IN&(1<<26))!=0)&&((IN&(1<<17))==0))
        {
            Debounce(BUTTON_A,'A',4,30);
            //delay(100);
            if ((i==1)&&(j==1))
                {i=5;
                j=5;}
            else if (j==1)
                {j=5;
                i--;}
            else
            {
                j--;
                }
            if (mode==0)
            Led_on_individually(i,j);
            else Led_on_individually(j,i);     
        }
        if (((IN&(1<<26))==0)&&((IN&(1<<17))==0))
        {
            delay(1000); // Instead of using debounce, a simple delay works better since it's impossible to press both buttons at the same time
            if (((IN&(1<<26))==0)&&((IN&(1<<17))==0))
            {
            if (mode==0)
            mode=1;
            else mode=0;
            OUTSET=row;
            OUTCLR=col;
            delay(400);
            i=j=1;
            Led_on_individually(i,j);
            }
            while (((IN&(1<<26))==0)&&((IN&(1<<17))==0))
            {}
            delay(100);
        }

    }
}