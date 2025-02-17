//using recursion
#include <stdio.h>
void Reverse(char *str)
{
	if(*str)
	{
		Reverse(str+1);
		printf("%c",*str);
	}
}
int main()
{
	char str[]="string";
	Reverse(str);
	return 0;
}
