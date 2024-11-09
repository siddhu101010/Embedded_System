#include <LPC21xx.h>

void my_delay(int a) {
    volatile int x, y;
    for (x = 0; x < a; x++)
        for (y = 0; y < a; y++);
}

int main() {
    PINSEL0 = 0x00;     // Set PINSEL0 to GPIO mode
    IODIR0 = 0xFF;      // Set all pins of Port 0 as output

    while (1) {
        IOSET0 = 0xAA;  // Set pattern 0xAA on Port 0
        my_delay(100); // Delay

        IOCLR0 = 0xAA;  // Clear pattern 0xAA on Port 0
        IOSET0 = 0x55;  // Set pattern 0x55 on Port 0
        my_delay(100); // Delay

        IOCLR0 = 0x55;  // Clear pattern 0x55 on Port 0
    }
}
