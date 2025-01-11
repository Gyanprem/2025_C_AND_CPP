#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[64] = "I am student of DESD course";
	char *ptr;
	ptr = strtok(str, " ");
	printf("ptr = %s\n",ptr);
	while(ptr != NULL)
	{
		ptr = strtok(NULL, " ");
		printf("ptr = %s\n", ptr);
	}
	return 0;
}
