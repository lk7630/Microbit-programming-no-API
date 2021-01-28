#include "Define.h"

/*


Led matrix (row.col):       (1.1) (2.4) (1.2) (2.5) (1.3)
                            (3.4) (3.5) (3.6) (3.7) (3.8)
                            (2.2) (1.9) (2.3) (3.9) (2.1)
                            (1.8) (1.7) (1.6) (1.5) (1.4)
                            (3.3) (2.7) (3.1) (2.6) (3.2)
LED to GPIO mapping:-----                            
row1:13     row2:14     row3:15
col1:4  col3:6  col5:8  col7:10    col9:12
col2:5  col4:7  col6:9  col8:11
        --------------------------
        
Individual LED is turned on by pulling the corresponding row high (1) and col low (0)          
*/
void Led_on_individually (int row, int col)
{
    OUTCLR=(1<<13)+(1<<14)+(1<<15);     //Set all row to low
    OUTSET=(1<<4)+(1<<5)+(1<<6)+(1<<7)+(1<<8)+(1<<9)+(1<<10)+(1<<11)+(1<<12);   //Set all cols to high
    switch (row){
    case 1:
        switch (col){
            case 1:
                OUTSET=(1<<13);
                OUTCLR=(1<<4);
                break;
            case 2:
                OUTSET=(1<<14);
                OUTCLR=(1<<7);
                break;
            case 3:
                OUTSET=(1<<13);
                OUTCLR=(1<<5);
                break;
            case 4:
                OUTSET=(1<<14);
                OUTCLR=(1<<8);
                break;
            case 5:
                OUTSET=(1<<13);
                OUTCLR=(1<<6);
                break;
            }
        break;
    case 2:
        switch (col){
            case 1:
                OUTSET=(1<<15);
                OUTCLR=(1<<7);
                break;
            case 2:
                OUTSET=(1<<15);
                OUTCLR=(1<<8);
                break;
            case 3:
                OUTSET=(1<<15);
                OUTCLR=(1<<9);
                break;
            case 4:
                OUTSET=(1<<15);
                OUTCLR=(1<<10);
                break;
            case 5:
                OUTSET=(1<<15);
                OUTCLR=(1<<11);
                break;
            }
        break;
    case 3:
        switch (col){
            case 1:
                OUTSET=(1<<14);
                OUTCLR=(1<<5);
                break;
            case 2:
                OUTSET=(1<<13);
                OUTCLR=(1<<12);
                break;
            case 3:
                OUTSET=(1<<14);
                OUTCLR=(1<<6);
                break;
            case 4:
                OUTSET=(1<<15);
                OUTCLR=(1<<12);
                break;
            case 5:
                OUTSET=(1<<14);
                OUTCLR=(1<<4);
                break;
            }
        break;
    case 4:
        switch (col){
            case 1:
                OUTSET=(1<<13);
                OUTCLR=(1<<11);
                break;
            case 2:
                OUTSET=(1<<13);
                OUTCLR=(1<<10);
                break;
            case 3:
                OUTSET=(1<<13);
                OUTCLR=(1<<9);
                break;
            case 4:
                OUTSET=(1<<13);
                OUTCLR=(1<<8);
                break;
            case 5:
                OUTSET=(1<<13);
                OUTCLR=(1<<7);
                break;
            }
        break;
    case 5:
        switch (col){
            case 1:
                OUTSET=(1<<15);
                OUTCLR=(1<<6);
                break;
            case 2:
                OUTSET=(1<<14);
                OUTCLR=(1<<10);
                break;
            case 3:
                OUTSET=(1<<15);
                OUTCLR=(1<<4);
                break;
            case 4:
                OUTSET=(1<<14);
                OUTCLR=(1<<9);
                break;
            case 5:
                OUTSET=(1<<15);
                OUTCLR=(1<<5);
                break;
            }
        break;
        }
}