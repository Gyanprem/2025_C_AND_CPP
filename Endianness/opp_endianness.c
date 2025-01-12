#include <stdio.h>
#include <string.h>
#include <stdint.h>

const char* opposite_endianness(const char* endianness) {
	return (strcmp(endianness, "big") == 0) ? "little" :
		(strcmp(endianness, "little") == 0) ? "big" : NULL;
	}
uint32_t reverse_bytes(uint32_t num) {
	return ((num & 0xFF000000) >> 24) | ((num & 0x00FF0000) >> 8) | ((num & 0x0000FF00) << 8) | ((num & 0x000000FF) << 24);
	}
int main() {
	const char* result;
	result = opposite_endianness("big");
	printf("opposite of big : %s\n", result ? result : "Invalid input");

	result = opposite_endianness("little");
    printf("Opposite of little: %s\n", result ? result : "Invalid input");

    result = opposite_endianness("unknown");
    printf("Opposite of unknown: %s\n", result ? result : "Invalid input");

    uint32_t num = 0x11223344;
    uint32_t reversed = reverse_bytes(num);
    printf("Original: 0x%X, Reversed: 0x%X\n", num, reversed);

    return 0;
}






















