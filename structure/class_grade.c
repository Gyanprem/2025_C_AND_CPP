#include <stdio.h>

// Define the structure to store student information
struct Student {
    char name[50];
    int standard;
    union {
        char grade;      // For grades A/B/C (only till 4th standard)
        float percentage; // For percentage (from 5th standard onwards)
    } result;
};

// Function to accept and display student information
void inputStudentInfo(struct Student *s) {
    printf("Enter student's name: ");
    scanf(" %[^\n]%*c", s->name);  // To accept multi-word name
    printf("Enter standard: ");
    scanf("%d", &s->standard);

    // Input result based on standard
    if (s->standard <= 4) {
        printf("Enter grade (A/B/C): ");
        scanf(" %c", &s->result.grade);
    } else {
        printf("Enter percentage: ");
        scanf("%f", &s->result.percentage);
    }
}

void displayStudentInfo(struct Student s) {
    printf("\nStudent Name: %s\n", s.name);
    printf("Standard: %d\n", s.standard);

    // Display result based on standard
    if (s.standard <= 4) {
        printf("Grade: %c\n", s.result.grade);
    } else {
        printf("Percentage: %.2f%%\n", s.result.percentage);
    }
}

int main() {
    struct Student students[3];  // Array to hold 3 students

    // Accept and display information for 3 students
    for (int i = 0; i < 3; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);
        inputStudentInfo(&students[i]);
    }

    // Display information of the 3 students
    printf("\nStudent Information:\n");
    for (int i = 0; i < 3; i++) {
        displayStudentInfo(students[i]);
    }

    return 0;
}

