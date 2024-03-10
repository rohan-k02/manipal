/* Q1. Write a C program to display the number “1234” serially in the seven segment
display. */

#include <LPC17xx.h>

// Lookup table for seven-segment display patterns
unsigned char tohex[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

// Initialize array to store digits (1234)
long int arr[4] = {4, 3, 2, 1};
unsigned int i,j;
int main() {
    SystemInit();
    SystemCoreClockUpdate();
    LPC_GPIO0->FIODIR |= 0xFF0;
    LPC_GPIO1->FIODIR |= 0xF << 23;

    while (1) {
        for (i = 0; i < 4; i++) {
            // Display each digit
            LPC_GPIO1->FIOPIN = i << 23;
            LPC_GPIO0->FIOPIN = tohex[arr[i]] << 4;
            for (j = 0; j < 1000; j++);
        }
        
        // Clear the display
        LPC_GPIO0->FIOCLR |= 0x00000FF0;
    }
}
