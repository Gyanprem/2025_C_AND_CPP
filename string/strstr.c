#include <stdio.h>
//strstr- locate a substring
int main(void)
{
	char str[64] = "I am student of Desd course";
	char substr[4] = "am";
	char *ptr = strstr(str, substr);
	printf("str = %u\n",str);
	printf("ptr = %u\n",ptr);
	printf("ptr = %s\n",ptr);
	return 0;
}
