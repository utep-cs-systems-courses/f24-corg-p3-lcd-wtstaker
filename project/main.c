#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include <stdio.h>



void screen_on();
int main(void) {
  configureClocks(); 
  ledInit();
  buzzerInit();
  switchInit();
  enableWDTInterrupts();

  screen_on();
  or_sr(0x18);
 
  
}
void screen_on(){
  drawString8x12(20, 1,"test", COLOR_RED, COLOR_BLACK);
 
}
