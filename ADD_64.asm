    AREA ADD64, CODE, READONLY
    ENTRY
    EXPORT MAIN         ; Export the main symbol to make it the program entry point

MAIN
    LDR R0, =NUM1       ; Load the address of NUM1 into R0
    LDR R1, [R0]        ; Load the first word of NUM1 into R1
    LDR R2, [R0, #4]    ; Load the second word of NUM1 into R2
    LDR R0, =NUM2       ; Load the address of NUM2 into R0
    LDR R3, [R0]        ; Load the first word of NUM2 into R3
    LDR R4, [R0, #4]    ; Load the second word of NUM2 into R4
    ADDS R5, R1, R3     ; Add R1 and R3, store result in R5, update flags
    ADC R6, R2, R4      ; Add R2 and R4 with carry, store result in R6
    LDR R0, =RESULT     ; Load the address of RESULT into R0
    STR R5, [R0]        ; Store the lower 32-bit result in RESULT
    STR R6, [R0, #4]    ; Store the upper 32-bit result in RESULT + 4

STOP B STOP              ; Infinite loop to stop execution

NUM1 DCD 0x22222222, 0x33333333   ; Define NUM1 with two 32-bit values
NUM2 DCD 0x33333333, 0x22222222   ; Define NUM2 with two 32-bit values

    AREA RESULT, DATA, READWRITE   ; Define writable data area
Result DCD 0x0              ; Define RESULT with two 32-bit values initialized to 0

    END                            ; End of the program
