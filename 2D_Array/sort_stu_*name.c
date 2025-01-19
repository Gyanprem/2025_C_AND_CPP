#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_STUDENTS 5
#define MAX_NAME_LENGTH 100

// Function prototypes
void acceptStudentNames(char *names);
void printStudentNames(char *names);
void sortStudentNames(char *names);

int main() {
    char *studentNames = (char *)malloc(NUM_STUDENTS * MAX_NAME_LENGTH * sizeof(char));
    if (studentNames == NULL) {
        printf("Memory allocation failed. Exiting.\n");
        return 1;
    }

    // Accept student names
    acceptStudentNames(studentNames);

    // Print student names before sorting
    printf("\nStudent Names Before Sorting:\n");
    printStudentNames(studentNames);

    // Sort student names
    sortStudentNames(studentNames);

    // Print student names after sorting
    printf("\nStudent Names After Sorting:\n");
    printStudentNames(studentNames);

    // Free allocated memory
    free(studentNames);

    return 0;
}

void acceptStudentNames(char *names) {
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Enter the name of student %d: ", i + 1);
        fgets(names + i * MAX_NAME_LENGTH, MAX_NAME_LENGTH, stdin);
        // Remove newline character if present
        size_t len = strlen(names + i * MAX_NAME_LENGTH);
        if (len > 0 && *(names + i * MAX_NAME_LENGTH + len - 1) == '\n') {
            *(names + i * MAX_NAME_LENGTH + len - 1) = '\0';
        }
    }
}

void printStudentNames(char *names) {
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("%s\n", names + i * MAX_NAME_LENGTH);
    }
}

void sortStudentNames(char *names) {
    char temp[MAX_NAME_LENGTH];
    for (int i = 0; i < NUM_STUDENTS - 1; i++) {
        for (int j = i + 1; j < NUM_STUDENTS; j++) {
            if (strcmp(names + i * MAX_NAME_LENGTH, names + j * MAX_NAME_LENGTH) > 0) {
                // Swap names[i] and names[j]
                strcpy(temp, names + i * MAX_NAME_LENGTH);
                strcpy(names + i * MAX_NAME_LENGTH, names + j * MAX_NAME_LENGTH);
                strcpy(names + j * MAX_NAME_LENGTH, temp);
            }
        }
    }
}

