#include <msp430.h>
#include "switches.h"
#include "stateMachine.h"
#include "lcdutils.h"
#include "lcddraw.h"


void switchInit(){
  P2REN |= SWITCHES;  
  P2IE |= SWITCHES;   
  P2OUT |= SWITCHES;  
  P2DIR &= ~SWITCHES; 
  
}
void switch_interrupt_handler() {
    char p2val = P2IN;             // current state of Port 2
    //update state machine or variables
    if (!(p2val & SW1)) {          // switch 1: advance state
        advance_state();
    }
    if (!(p2val & SW2)) {          // switch 2: display message
        clearScreen(COLOR_BLUE);                      // Clear the screen
        drawString8x12(20, 20, "Switch 2 Pressed!",   // Display a message
                   COLOR_WHITE, COLOR_BLACK);
    }
}
    
