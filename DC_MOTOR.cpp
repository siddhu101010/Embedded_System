#include <LPC214x.h>

#define bit(x) (1 << x)
#define delay for (i = 0; i <= 60000; i++)

unsigned int i;

int main() {
    IODIR0 = 0xf;       // Set the direction of Port 0 pins 0-3 as output
    IOPIN0 = 0;          // Initialize Port 0 to 0
    VPBDIV = 0x01;       // Set the VPB divider to 1 (if needed)

    while (1) {
        IOSET0 = bit(0);     // Set bit 0 of Port 0q
        IOCLR0 = bit(1);     // Clear bit 1 of Port 0
        delay; delay;

        IOCLR0 = bit(0) | bit(1);  // Clear bits 0 and 1 of Port 0
        delay; delay;

        IOSET0 = bit(1);     // Set bit 1 of Port 0
        IOCLR0 = bit(0);     // Clear bit 0 of Port 0
        delay; delay;

        IOCLR0 = bit(0) | bit(1);  // Clear bits 0 and 1 of Port 0
        delay; delay;
    }
}
