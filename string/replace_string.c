#include <stdio.h>
#include <stdlib.h>

void findAndReplace(char *str, const char *find, const char *replace) {
    char result[1000]; // Temporary result array
    int i = 0, j = 0, k, findLen = 0, replaceLen = 0;

    // Calculate lengths of find and replace strings
    while (find[findLen] != '\0') findLen++;
    while (replace[replaceLen] != '\0') replaceLen++;

    while (str[i] != '\0') {
        int match = 1;
        
        // Check if find string matches at current position
        for (k = 0; k < findLen; k++) {
            if (str[i + k] != find[k]) {
                match = 0;
                break;
            }
        }

        if (match) {
            // Copy replace string to result
            for (k = 0; k < replaceLen; k++) {
                result[j++] = replace[k];
            }
            i += findLen; // Skip the matched substring
        } else {
            result[j++] = str[i++];
        }
    }

    result[j] = '\0'; // Null-terminate the result string

    // Copy result back into original string
    for (i = 0; result[i] != '\0'; i++) {
        str[i] = result[i];
    }
    str[i] = '\0';
}

int main() {
    char text[100] = "hello world, hello!";
    findAndReplace(text, "hello", "hi");
    printf("Replaced text: %s\n", text);

    return 0;
}

