#include <stdio.h>

unsigned int swap_lsb_msb(unsigned int num, int bit_length) {
    /*
    Swap the least significant bit (LSB) with the most significant bit (MSB) in a given number.

    Parameters:
        num: The input number.
        bit_length: The bit length to consider for the number.

    Returns:
        The number with the LSB and MSB swapped.
    */

    // Extract the LSB and MSB
    unsigned int lsb = num & 1;
    unsigned int msb = (num >> (bit_length - 1)) & 1;

    // If LSB and MSB are the same, no need to swap
    if (lsb == msb) {
        return num;
    }

    // Toggle the bits in the respective positions
    num ^= (1 << (bit_length - 1)); // Toggle MSB
    num ^= 1; // Toggle LSB

    return num;
}

int main() {
    unsigned int number = 75; // Example number (binary: 1001011)
    int bit_length = 7; // Bit length of the number

    unsigned int result = swap_lsb_msb(number, bit_length);

    printf("Original number: %u (binary: ", number);
    for (int i = bit_length - 1; i >= 0; i--) {
        printf("%u", (number >> i) & 1);
    }
    printf(")\n");

    printf("Modified number: %u (binary: ", result);
    for (int i = bit_length - 1; i >= 0; i--) {
        printf("%u", (result >> i) & 1);
    }
    printf(")\n");

    return 0;
}
