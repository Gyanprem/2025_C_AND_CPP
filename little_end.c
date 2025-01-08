#include <stdio.h>
int main()
{
int num =0x11223344;
char *ptr = (char *)&num;
if(*ptr == 0x44)
	printf("little endian \n");
else
	printf("big endian \n");
return 0;
}
