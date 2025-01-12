#include <stdio.h>
#include <string.h>

// Helper function to check if a character is in a given string
int isCharacterInString(char *string, char ch) {
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == ch) {
            return 1; // Character found in string
        }
    }
    return 0; // Character not found
}

// Function to remove all characters from string1 in string2
void removeCharacters(char *string1, char *string2) {
    int i, j = 0;
    for (i = 0; string2[i] != '\0'; i++) {
        if (!isCharacterInString(string1, string2[i])) {
            string2[j] = string2[i];
            j++;
        }
    }
    string2[j] = '\0'; // Null-terminate the modified string2
}

int main() {
    char string1[] = "aeiou"; // Characters to remove (e.g. vowels)
    char string2[] = "hello world"; // The main string to process
    
    removeCharacters(string1, string2);
    printf("Result: %s\n", string2); // Output: "hll wrld"
    
    return 0;
}

