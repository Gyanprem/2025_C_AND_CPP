#include <stdio.h>

int main() {
    // Input in hexadecimal
    unsigned int X = 0x1234;

    // Extract digits using bitwise operations
    int d1 = (X >> 12) & 0xF; // Thousands place (most significant digit)
    int d2 = (X >> 8) & 0xF;  // Hundreds place
    int d3 = (X >> 4) & 0xF;  // Tens place
    int d4 = X & 0xF;         // Units place

    // Convert each hexadecimal digit to decimal (if needed)
    // Rearrange to 2134
    int Y = d2 * 1000 + d1 * 100 + d3 * 10 + d4;

    // Print results
    printf("Input X in hexadecimal: 0x%X\n", X);
    printf("Rearranged output Y: %d\n", Y);

    return 0;
}

