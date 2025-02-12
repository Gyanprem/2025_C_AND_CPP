#include <stdio.h>
#include<math.h>

int main()
{
	double principal = 2500;
	double rate =7;
	double time = 30;
	double amount = principal * ((pow((1 + rate /100), time)));
	double ci = amount - principal;
	printf("compound interest is : %lf", ci);
	return 0;
}
