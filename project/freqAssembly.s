// Set initial buzzer frequency
buzzer_set_frequency:
    PUSH    R4                    ; Save registers
    MOV     #1000, R4             ; Load initial frequency into R4
    CALL    #adjust_buzzer_frequency ; Call the adjustment function
    MOV     R4, &buzzer_frequency ; Store adjusted frequency in global variable
    POP     R4                    ; Restore registers
    RET                           ; Return to the C program
//Adjust the frequency  
adjust_buzzer_frequency:
    PUSH    R4                    ; Save registers
    ADD     #100, R4              ; Increment frequency by 100
    POP     R4                    ; Restore registers
    RET                           ; Return to buzzer_set_frequency
