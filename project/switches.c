#include <msp430.h>
#include "switches.h"

void switchInit(){
  P2REN |= SWITCHES;  
  P2IE |= SWITCHES;   
  P2OUT |= SWITCHES;  
  P2DIR &= ~SWITCHES; 
  
}
void switch_interrupt_handler() {
    char p2val = P2IN;             // current state of Port 2
    //update state machine or variables
    if (!(p2val & SW1)) {          // switch 1: clear screen
        clearScreen();
    }
    if (!(p2val & SW2)) {          // switch 2:
        
    }
    
