/* 
 * File:   main.c
 * Author: shivani
 * Description: lab 0.
 * 
 */

#include <xc.h>
#include <sys/attribs.h>
#include "timer.h"
#include "led.h"
#include "interrupt.h"
#include "config.h"

#define OUTPUT 0
#define INPUT 1

//TODO: Define states of the state machine
typedef enum stateTypeEnum{ LED1, LED2, LED3} stateType;

//TODO: Use volatile variables that change within interrupts
volatile stateType state = LED1;
//unsigned int dummyVariable = 0;

int main() {
    SYSTEMConfigPerformance(10000000);    //Configures low-level system parameters for 10 MHz clock
    enableInterrupts();                   //This function is necessary to use interrupts.
    //TODO: Write each initialization function
    initLEDs();
    initTimer1();
    
    
    while(1){
        //TODO: Implement a state machine to create the desired functionality
        switch(state){
            case LED1:
                LATDbits.LATD0 = 1;
                LATDbits.LATD1 = 0;
                LATDbits.LATD2 = 0;
      
                break;
            case LED2:
                LATDbits.LATD0 = 0;
                LATDbits.LATD1 = 1;
                LATDbits.LATD2 = 0;
                
                break;
            case LED3:
                LATDbits.LATD0 = 0;
                LATDbits.LATD1 = 0;
                LATDbits.LATD2 = 1;
                
                break;
        }
    } 
   return 0;
}

//TODO: Add interrupt service routines that manage the change of states
//for particular events as needed


void __ISR(_TIMER_1_VECTOR, IPL7SRS) _T1Interrupt() {
    IFS0bits.T1IF = 0; //flag down 
    LATDbits.LATD0 = !LATDbits.LATD0;
    if(state == LED1) state = LED2;
    else if(state == LED2) state = LED3;
    else if(state == LED3) state = LED1;
}
