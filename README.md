# Microbit programming no API
 Basic Microbit programming using none or limited APIs

This repo is for the purpose of understanding the operation of Micro:bit at a lower level. If you are a beginner in microcontroller programming and want to understand how the codes interact with the registers without using pre-written APIs/libraries this may be a good starting point. I am using BBC micro:bit version 1.5.

Micro:bit v1.5 hardware : 
https://tech.microbit.org/hardware/1-5-revision/

Micro:bit v1.5 schematic
https://github.com/lk7630/Microbit-programming-no-API/blob/main/Resources/Schematic_BBC-Microbit_V1.5.PDF

Micro:bit v1.5 processor (nRF51822) documents:
 + Product Specification: https://github.com/lk7630/Microbit-programming-no-API/blob/main/Resources/nRF51822_ProductSpec_v3.3.pdf
 + Reference Manual (datasheet): https://github.com/lk7630/Microbit-programming-no-API/blob/main/Resources/nRF51_RM_v3.0.pdf

I suggest downloading the Product Spec and Reference manual and keep them handy.
I am using mbed.com to develop the programs (an online development flatform).
It is recommended to follow this order (which also is the order I went through when I learnt this dev board):
1. LightLED
2. BlinkingLED
3. RunningLED
4. Buttondetection
5. Buttondetection_SimpleDebounce
6. Buttondetection_withDebounce
