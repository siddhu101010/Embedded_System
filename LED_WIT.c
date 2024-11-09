#include <lpc213x.h>

void lcd_cmd(unsigned int);
void lcd_data(unsigned int);
void lcd_print(char *);

int main(void) {
    char s[20] = {"WIT"};

    PINSEL0 = 0x0;    // Set PINSEL0 to GPIO mode
    PINSEL1 = 0x0;    // Set PINSEL1 to GPIO mode
    PINSEL2 = 0x0;    // Set PINSEL2 to GPIO mode

    IODIR1 = IODIR1 | (0xFF << 16); // Set P1.16-P1.23 as output for LCD data
    IODIR1 = IODIR1 | (1 << 25);    // Ensure P1.25 is output (assumed here for LCD control lines)

    IODIR0 = IODIR0 | 0x20000400;   // Clear P0.29 (assuming it’s used for LCD control)
    IOCLR0 = IOCLR0 | 0x20000000;   // Clear another control line as needed
    IOCLR0 = IOCLR0 | 0x00000400;

    lcd_cmd(0x38);   // LCD 8-bit mode
    lcd_cmd(0x0e);   // Display ON, cursor ON
    lcd_cmd(0x06);   // Entry mode set
    lcd_cmd(0x01);   // Clear display
    lcd_cmd(0x80);   // Force cursor to beginning of first line

    lcd_print(s);    // Print "Pravin" on the LCD
}

void lcd_cmd(unsigned int a) {
    int i;

    IOCLR1 = IOCLR1 | (0xFF << 16);
    IOCLR1 = IOCLR1 | 0x02000000;   // Enable pin high
    IOSET1 = IOSET1 | a << 16;      // Send command to data pins
    IOSET0 = IOSET0 | 0x20000000;
    for (i = 0; i < 5000; i++);     // Small delay
    IOCLR0 = IOCLR0 | 0x20000000;   // Enable pin low

    for (i = 0; i < 60000; i++);    // Delay for command processing
    return;
}

void lcd_data(unsigned int a) {
    int i;

    IOCLR1 = IOCLR1 | (0xFF << 16); // Clear data bits
    IOSET1 = IOSET1 | 0x02000000;   // Send data to data pins

    IOSET1 = IOSET1 | a << 16;      // Enable pin high
    IOSET0 = IOSET0 | 0x20000000;   // Enable pin low

    for (i = 0; i < 5000; i++);     // Delay for data processing
    IOCLR0 = IOCLR0 | 0x20000000;

    for (i = 0; i < 60000; i++);    // Additional delay for data processing
    return;
}

void lcd_print(char *s) {
    int i, j;
    for (i = 0; s[i] != '\0'; i++) {
        lcd_data(s[i]);             // Send each character to LCD
        for (j = 0; j < 6000; j++); // Small delay between characters
    }
}
