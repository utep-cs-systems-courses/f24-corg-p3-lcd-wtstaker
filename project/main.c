#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "handler.h"

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
void start_screen(){
  drawString8x12(20, 1,"test", COLOR_RED, COLOR_BLACK);
  drawString8x12(1, 32, "SW1: LEFT", COLOR_WHITE, COLOR_BLACK);
  drawString8x12(1, 44, "SW2: RIGHT", COLOR_WHITE, COLOR_BLACK);
  drawString8x12(1, 56, "SW3: UP", COLOR_WHITE, COLOR_BLACK);
  drawString8x12(1, 68, "SW4: DOWN", COLOR_WHITE, COLOR_BLACK);
  drawString8x12(1, 92, "PRESS ANYTHING", COLOR_WHITE, COLOR_BLACK);
  drawString8x12(1, 104, "TO BEGIN", COLOR_WHITE, COLOR_BLACK);
}
