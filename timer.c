/* 
 * File:   timer.c
 * Author: gvanhoy
 *
 * Created on August 27, 2015, 3:26 PM
 */

#include <xc.h>
#define PRESCALAR_256 3

void initTimer1(){
    //TODO: Initialize Timer 1 to have a period of
    // 1 second. Enable its interrupt
    PR1 = 39061; // the period register set at 1 second
    T1CONbits.TCKPS = PRESCALAR_256;  
    T1CONbits.ON = 1; //turns on the timer 
    TMR1 = 0; //timer keeps count
    IEC0bits.T1IE = 1; //enables the interrupt 
    IPC1bits.T1IP = 7;  //timer priority 
    IFS0bits.T1IF = 0;
    
}
