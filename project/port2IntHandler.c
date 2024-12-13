#include <msp430.h>
#include "switches.h"

void __interrupt_vec(PORT2_VECTOR) Port_2() {
    if (P2IFG & SWITCHES) {        // Check if any switch caused the interrupt
        P2IFG &= ~SWITCHES;        // Clear flags for the switches
        switch_interrupt_handler(); // Handle the switch press
    }
}
