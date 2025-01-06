#include <stdio.h>
#include <string.h>
size_t my_strlen(const char *s);
int main(void)
{
	char str[20];
	size_t len;
	printf("Enter string: ");
	scanf("%s[^\n]s",str);
	printf("str= %s\n",str);
	len = my_strlen(str);
	printf("length= %d\n",len);
	return 0;
}

size_t my_strlen(const char *s)
{
	size_t length = 0;
	for(int i = 0;s[i]!='\0';i++)

	length++;
	return length;
}
