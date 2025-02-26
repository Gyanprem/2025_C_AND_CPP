//#include <math.h>
#include <stdio.h>

int Min(int Num1, int Num2)
{
	if(Num1>= Num2)
		return Num2;
	else
		return Num1;
}

int LCM(int Num1, int Num2, int K)
{
//if either of the two number is 1, return their product 
	if(Num1 == 1 || Num2 == 1)
		return Num1 * Num2;
	//if noth the number are equal
	if(Num1 == Num2)
		return Num1;
	//if K is smaller than the minimum of two numbers
	if(K <= Min(Num1, Num2))  {

	//check if both number are divisible by K or not
	if(Num1 % K == 0 && Num2 % K == 0) {
		//recursively call LCM() function
		return K * LCM(Num1 / K, Num2 / K, 2);
	}
	else 
		return LCM(Num1, Num2, K+1);
	}
	//if K exceed minimum
	else
	 return Num1 * Num2;
}



int main()
{
	int N = 12, M = 9;
	int ans = LCM(N, M, 2);
	printf("%d",ans);
	return 0;
}

