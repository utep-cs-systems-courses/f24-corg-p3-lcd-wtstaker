#ifndef stateMachine_included
#define stateMachine_included

#define STATE_LCD 0
#define STATE_LED 1
#define STATE_BUZZER 2
#define NUM_STATES 3

void advance_state(); //Advance to the next state
void execute_state(); //Execute the current state

void update_lcd();    // Update the LCD screen
void update_led();    // Update the LEDs
void update_buzzer(); // Update the buzzer tone

void draw_smiley_face(); // Draw a smiley face on the LCD

#endif
