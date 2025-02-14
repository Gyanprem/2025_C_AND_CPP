//10. Write a program to Find all the roots of a quadratic equation in C.
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void find_roots(int a, int b, int c)
{
	//if a is 0 then eqation is not quadrant but linear
	if(a ==0) {
	printf("Invalid");
	return;
	}

	int d = (b * b) - (4*a*c);
	double sqrt_val = sqrt(abs(d));

	if(d > 0) {
		printf("roots are real and different\n");
		printf("%f\n%f", (double)(-b + sqrt_val)/ (2*a),(double)(-b - sqrt_val)/(2*a));
	}

	else if (d == 0) {
		printf("roots are real and same \n");
		printf("%f", -(double)b / (2*a));
	}
	else
	{
		printf("roots are complex \n");
		printf("%f + i%f\n%f - i%f", -(double)b / (2*a), sqrt_val / (2 *a), -(double)b / (2*a),sqrt_val /(2*a));
		}
	}

int main()
{
	int a =1, b = -16, c = 1;
	find_roots(a,b,c);
	return 0;
}

