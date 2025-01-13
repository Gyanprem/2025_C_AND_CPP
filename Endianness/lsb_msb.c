#include <stdio.h>
#include <string.h>
#include <stdint.h>
uint32_t lsb_to_msb_and_msb_to_lsb(uint32_t num) {
//lsb_to_msb
uint32_t lsb = (num & 1);
uint32_t msb = (num & 0x80000000) >>31;
//clear original LSB and MSB  then set them to their new position
num &= ~0x800000000;
num |= (lsb << 31) | msb;
return num;
}
 int main() {
  uint32_t num = 0x11223344;
  uint32_t swapped = lsb_to_msb_and_msb_to_lsb(num);
    printf("Original: 0x%X, LSB to MSB swapped: 0x%X\n", num, swapped);

    return 0;
}
