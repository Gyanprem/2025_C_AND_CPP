#include <stdio.h>

int main() {
    unsigned int x = 0x1234; // Original value
    unsigned int swapped;

    // Extract the first two digits (0x12) and the last two digits (0x34)
    unsigned int firstTwo = (x & 0xFF00); // Get the first two digits
    unsigned int lastTwo = (x & 0x00FF);   // Get the last two digits

    // Swap the first two digits with the last two digits
    swapped = (lastTwo << 8) | (firstTwo >> 8); // Shift last two to the front and keep first two

    printf("Original: 0x%X\n", x);
    printf("Swapped: 0x%X\n", swapped);

    return 0;
}
