#include <stdio.h>
int main(void)
{
int num = 0x11223344;
char *ptr = (char *)&num;
if(*ptr == 0x44)
	printf("little endian\n");
else
	printf("big endianess\n");
return 0;
}
