#include <stdio.h>
#include <string.h>
int main()
{
	char src[40];
	char dest[20];
	memset(dest,'\0', sizeof(dest));
	strcpy(src, "Sunbeam DESD");
	strncpy(dest, src, 5);
	printf("final copied string : %s\n",dest);
	return 0;
}

