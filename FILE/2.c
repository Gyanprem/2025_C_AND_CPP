#include <stdio.h>
#include <stdlib.h>

// Function to copy file contents character by character
void copyFile(FILE *source, FILE *destination) {
    char ch;
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }
}

int main() {
    char sourceFile[100], destinationFile[100], userInput[100];
    FILE *source, *destination;

    // Get source file name
    printf("Enter source file name: ");
    scanf("%s", sourceFile);
    
    // Open source file for reading
    source = fopen(sourceFile, "r");
    if (source == NULL) {
        printf("Error: Cannot open source file.\n");
        return 1;
    }
    
    // Get destination file name
    printf("Enter destination file name: ");
    scanf("%s", destinationFile);
    
    // Open destination file for writing
    destination = fopen(destinationFile, "w");
    if (destination == NULL) {
        printf("Error: Cannot open destination file.\n");
        fclose(source);
        return 1;
    }
    
    // Copy file contents
    copyFile(source, destination);
    
    // Close the files after copying
    fclose(source);
    fclose(destination);
    
    // Display the copied contents
    destination = fopen(destinationFile, "r");
    if (destination == NULL) {
        printf("Error: Cannot open destination file for reading.\n");
        return 1;
    }
    
    printf("\nContents of the copied file:\n");
    while ((fgets(userInput, sizeof(userInput), destination)) != NULL) {
        printf("%s", userInput);
    }
    fclose(destination);
    
    // Accept user input and write to destination file
    destination = fopen(destinationFile, "a"); // Open in append mode
    if (destination == NULL) {
        printf("Error: Cannot open destination file for appending.\n");
        return 1;
    }
    
    printf("\nEnter additional data to append: ");
    getchar(); // Clear the buffer
    fgets(userInput, sizeof(userInput), stdin);
    fprintf(destination, "%s", userInput);
    fclose(destination);
    
    printf("\nData appended successfully!\n");
    return 0;
}

