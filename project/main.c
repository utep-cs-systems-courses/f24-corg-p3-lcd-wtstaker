#include <msp430.h>
#include <stdio.h>
#include "libTimer.h"
#include "led.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "stateMachine.h"

extern short buzzer_frequency; // global variable
void buzzer_set_frequency();   // assembly function
void screen_on();
void draw_smiley_face();
void play_tone();
void toggle_leds();

static int toggle = 0;

int main(void) {
    configureClocks(); 
    ledInit();
    buzzerInit();
    buzzer_set_frequency();    // Call the assembly function to set frequency
    buzzer_set_period(buzzer_frequency); // Set the buzzer period using updated frequency
    switchInit();
    enableWDTInterrupts();

    screen_on(); // Activate the LCD and draw the screen content
    or_sr(0x18); // CPU off with interrupts enabled
}

void screen_on() {
    clearScreen(COLOR_BLUE); // Clear the screen with blue background
    drawString8x12(20, 1, "Smiley + Sound", COLOR_RED, COLOR_BLACK); // Display title
    draw_smiley_face(); // Draw the smiley face
}

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

// Function to play tone using the buzzer 
void play_tone() {
    if (toggle) {
        buzzer_set_period(1000); // Set tone frequency 
    } else {
        buzzer_set_period(0);    // Turn off the buzzer
    }
    toggle = !toggle; // Toggle for next call
}

// Function to toggle LEDs
void toggle_leds() {
    if (toggle) {
        turn_on_green_led(); // Turn on the green LED
    } else {
        turn_on_red_led();   // Turn on the red LED
    }
    toggle = !toggle; // Toggle for next call
}

// state machine
void __interrupt_vec(WDT_VECTOR) WDT() {
    static int count = 0;
    count++;

    if (count == 125) { 
        advance_state(); 
        execute_state(); 
        count = 0;       
    }
}
