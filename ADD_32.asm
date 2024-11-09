    AREA Add32, CODE, READONLY
    ENTRY
MAIN
    LDR R0, =VALUE1       ; Load address of VALUE1
    LDR R1, [R0]          ; Load VALUE1 value into R1
    LDR R0, =VALUE2       ; Load address of VALUE2
    LDR R2, [R0]          ; Load VALUE2 value into R2
    LDR R0, =RES          ; Load address of RESULT (corrected to RES)
    ADD R3, R1, R2        ; Add R1 and R2, store result in R3
    STR R3, [R0]          ; Store the result in RES

STOP B STOP               ; Endless loop

VALUE1 DCD 0x22222222     ; Define VALUE1 with initial value
VALUE2 DCD 0x00002222     ; Define VALUE2 with initial value

    AREA DATA, DATA, READWRITE
RES DCD 0x0               ; Define RES (RESULT) with initial value 0
    END
