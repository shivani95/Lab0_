/* 
 * File:   led.c
 * Author: shivani
 *
 * 
 */

#include <xc.h>
#include "led.h"
#define OUTPUT 0
#define  ON 1

void initLEDs(){
    
    TRISDbits.TRISD0 = OUTPUT;
    TRISDbits.TRISD1 = OUTPUT;
    TRISDbits.TRISD2 = OUTPUT;
    LATDbits.LATD0 = ON;
    LATDbits.LATD1 = ON;
    LATDbits.LATD2 = ON;
   
}

void turnOnLED(int led){
    
    //TODO: You may choose to write this function
    // as a matter of convenience
    //code is used from lecture 4 to turn on LEDs
    if(led == 1)
    {
      LATDbits.LATD0 = 1;
      LATDbits.LATD1 = 0;
      LATDbits.LATD2 = 0;
    }
    else if(led == 2)
    {
      LATDbits.LATD0 = 0;
      LATDbits.LATD1 = 1;
      LATDbits.LATD2 = 0;        
    }
    else if(led == 3)
    { 
      LATDbits.LATD0 = 0;
      LATDbits.LATD1 = 0;
      LATDbits.LATD2 = 1;
    }
    
}
