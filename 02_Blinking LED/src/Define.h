
#define BASE_IO_ADDRESS 0x50000000
#define OUT (*(volatile unsigned long int *)(BASE_IO_ADDRESS + 0x504))
#define IN (*(volatile unsigned long int *)(BASE_IO_ADDRESS + 0x510))
#define OUTSET (*(volatile unsigned long int *)(BASE_IO_ADDRESS + 0x508))
#define OUTCLR (*(volatile unsigned long int *)(BASE_IO_ADDRESS + 0x50C))
#define DIRSET (*(volatile unsigned long int *)(BASE_IO_ADDRESS + 0x518))
#define DIRCLR (*(volatile unsigned long int *)(BASE_IO_ADDRESS + 0x51C))
#define BUTTON_A (*(volatile unsigned long int *)(BASE_IO_ADDRESS + 0x744))
#define BUTTON_B (*(volatile unsigned long int *)(BASE_IO_ADDRESS + 0x768))
#define BASE_TIMER_ADDRESS 0x40009000   //using timer1
                                        //timer0 8/16/24/32 bits
                                        //timer1 and timer 2: 8/16bit
#define TIMER_MODE (*(volatile unsigned long int*)(BASE_TIMER_ADDRESS + 0x504))
#define TASK_START (*(volatile unsigned long int*)(BASE_TIMER_ADDRESS + 0x000))
#define TASK_STOP (*(volatile unsigned long int*)(BASE_TIMER_ADDRESS + 0x004))
#define TASK_CLEAR (*(volatile unsigned long int*)(BASE_TIMER_ADDRESS + 0x00C))
#define BIT_MODE (*(volatile unsigned long int*)(BASE_TIMER_ADDRESS + 0x508))
#define EVENT_COMPARE_1 (*(volatile unsigned long int*)(BASE_TIMER_ADDRESS + 0x144))
#define CC_1 (*(volatile unsigned long int*)(BASE_TIMER_ADDRESS + 0x544))
#define PRESCALER (*(volatile unsigned long int*)(BASE_TIMER_ADDRESS + 0x510))
