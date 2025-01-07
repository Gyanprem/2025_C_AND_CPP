#include <stdio.h>
char *strrev(char *s);

int main(void)
{
	char str[] = "DeSd";
	printf("str before reverse :%s\n",str);
	strrev(str);
	printf("str after reverse : %s\n",str);
	return 0;
}
char *strrev(char *s)
{
	int i =0,j=0;
	for( ; s[j] !='\0'; j++);
	j--;
	for( ; i<j; i++, j--)
	{
		char temp= s[i];
		s[i] = s[j];
		s[j] = temp;
	}
	return s;
}

