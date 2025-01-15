#include <stdio.h>
int main()
{
int num = 9361;
int rem = 0;
while(num != 0)
{
	rem = num %10;
	printf("%d\t",rem);
	num = num /10;
}
return 0;
}
