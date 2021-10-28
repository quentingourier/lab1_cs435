/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <stdio.h>

DigitalIn b1(PA_10);
DigitalIn b2(PB_3);
DigitalIn b3(PB_5);
DigitalIn b4(PB_4);

DigitalOut ledR(PB_10);
DigitalOut ledV(PA_8);
DigitalOut ledB(PA_9);

BusIn laibouton(PA_10, PB_3, PB_5, PB_4);
BusOut lailaid(PB_10, PA_8, PA_9);

void ControlLED_DigitalIO ()
{
    ledR = (!b4 && (!b3)) || (!b4 && b2) || (b3 && b2 && b1);
    ledV = (!b4 && b3) || (b4 && (!b3)) || (b3 && b2 && b1);
    ledB = b4;
}

void ControlLED_BusIO ()
{
    switch(laibouton)
    {
        case 12 ... 15:
            lailaid = 0b001;
            break;
        case 10 ... 11:
            lailaid = 0b010;
            break;
        case 8 ... 9:
            lailaid = 0b011;
            break;
        case 4 ... 7:
            lailaid = 0b110;
            break;
        case 1 ... 3:
            lailaid = 0b100;
            break;
        case 0:
            lailaid = 0b111;
            break;
    }
}

int main()
{
    while(true)
    {
        //ControlLED_DigitalIO ();   
        ControlLED_BusIO ();    
    }
}

