#include <stdio.h>
#include <string.h>
char *my_strcpy(char *dest, const char *src);
int main(void)
{
	char str1[20];
	char str2[20];
	printf("Enter string : ");
	scanf("%[^\n]s",str1);
	printf("str1 = %s\n",str1);
	my_strcpy(str2,str1);
	printf("str2 = %s\n",str2);
	return 0;
}
char *my_strcpy(char *dest, const char *src)
{
	int i;
	for(i=0;src[i]!='\0';i++)
		dest[i] =src[i];
		dest[i] = '\0';
		return dest;
	}

