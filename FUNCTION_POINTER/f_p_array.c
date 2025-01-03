#include <stdio.h>
void add(int a, int b)
{
	printf("addition is %d\n", a+b);
}
void sub(int  a, int b)
{
	printf("subtraction is %d\n", a-b);
}
void mul(int a, int b)
{
	printf("multiplication is %d\n", a*b);
}

int main()
{
	//fun_ptr_arr is an array of function pointers
	void (*fptrarr[])(int, int) = {add, sub, mul };
	unsigned int ch, a=15, b= 10;
	printf("enter choice: 0 for add,1for sub,2 for mul\n");
	scanf("%d", &ch);
	if(ch >2)
	return 0;
		(*fptrarr[ch])(a,b);
		return 0;
}
