#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char filename[100], ch;
    
    // Get the filename from the user
    printf("Enter the filename: ");
    scanf("%s", filename);
    
    // Open the file in read mode
    file = fopen(filename, "r");
    
    // Check if the file exists
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }
    
    // Read the file character by character and display on the screen
    printf("\nContents of the file:\n");
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    
    // Close the file
    fclose(file);
    return 0;
}

