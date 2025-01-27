#include <stdio.h>
#include <string.h>

// Define the student structure
struct Student {
    int rollNumber;
    char name[100];
};

// Function to display the students
void displayStudents(struct Student students[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Roll No: %d, Name: %s\n", students[i].rollNumber, students[i].name);
    }
}

// Function to sort students by roll number
void sortByRollNumber(struct Student students[], int size) {
    struct Student temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (students[j].rollNumber > students[j + 1].rollNumber) {
                // Swap the students
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

// Function to sort students by name
void sortByName(struct Student students[], int size) {
    struct Student temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (strcmp(students[j].name, students[j + 1].name) > 0) {
                // Swap the students
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    // Initialize the array of students
    struct Student students[] = {
        {102, "John"},
        {101, "Alice"},
        {103, "Bob"}
    };
    
    // Calculate the number of students
    int size = sizeof(students) / sizeof(students[0]);

    // Display original student data
    printf("Original List:\n");
    displayStudents(students, size);
    
    // Sort by roll number
    sortByRollNumber(students, size);
    printf("\nSorted by Roll Number:\n");
    displayStudents(students, size);
    
    // Sort by name
    sortByName(students, size);
    printf("\nSorted by Name:\n");
    displayStudents(students, size);
    
    return 0;
}

