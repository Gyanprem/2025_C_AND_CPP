#include <stdio.h>
void removeCharacter(char *str, char charToRemove) {
	int i,j = 0;
	for(i =0; str[i] != '\0'; i++) {
		if(str[i] !=charToRemove) {
		str[j] = str[i];
		j++;
		}
	}
	str[j] = '\0';
}
int main() {
	char str[] = "hello world";
	char charToRemove = 'o';
	removeCharacter(str, charToRemove);
	printf("Result : %s\n",str);
	return 0;
}
