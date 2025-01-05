#include <stdio.h>
void print_binary_rec(int num)
{
	if(num == 0)
	return 0;
	print_binary_rec(num/2);
	printf("%d",num%2);
}

int main(void)
{
	unsigned char num = 10;
	print_binary_rec(num);
	printf("\n");
	return 0;
}
