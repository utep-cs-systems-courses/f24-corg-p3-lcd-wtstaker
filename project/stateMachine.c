#include "stateMachine.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "led.h"
#include "buzzer.h"

static int currentState = 0;

// Goes to next state
void advance_state() {
    currentState = (currentState + 1) % NUM_STATES; // Loop through states
}

//Executes the current state
void execute_state() {
    switch (currentState) {
    case STATE_LCD:
        update_lcd(); // Update LCD content
        break;
    case STATE_LED:
        update_led(); // Toggle LEDs
        break;
    case STATE_BUZZER:
        update_buzzer(); // Play buzzer tone
        break;
    default:
        break;
    }
}

//LCD state: screen with text and a smiley face
void update_lcd() {
    clearScreen(COLOR_BLUE);
    drawString8x12(20, 20, "LCD State", COLOR_WHITE, COLOR_BLACK);
    draw_smiley_face();
}

// LED state: Toggles between the green and red LEDs 
void update_led() {
    static int toggle = 0;
    if (toggle) {
        turn_on_green_led();
    } else {
        turn_on_red_led();
    }
    toggle = !toggle; // Alternate LEDs
}

// Buzzer state: Plays a tone and then silences it 
void update_buzzer() {
    static int toggle = 0;
    if (toggle) {
        buzzer_set_period(1000); //Set a tone
    } else {
        buzzer_set_period(0);    //Turn off
    }
    toggle = !toggle; //alternate 
}

// Draws a smiley face on the screen
void draw_smiley_face() {
    int center_x = screenWidth / 2;
    int center_y = screenHeight / 2;
    int face_radius = 30;
    int eye_radius = 5;
    int mouth_width = 20;
    int mouth_height = 5;

    // Draw face
    fillCircle(center_x, center_y, face_radius, COLOR_YELLOW);

    // Draw left eye
    fillCircle(center_x - 10, center_y - 10, eye_radius, COLOR_BLACK);

    // Draw right eye
    fillCircle(center_x + 10, center_y - 10, eye_radius, COLOR_BLACK);

    // Draw mouth
    fillRectangle(center_x - mouth_width / 2, center_y + 10, mouth_width, mouth_height, COLOR_BLACK);
}
