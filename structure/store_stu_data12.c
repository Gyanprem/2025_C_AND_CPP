#include <stdio.h>
#include <string.h>

#define MAX_NAME_LEN 50

// Define the structure to store student information
struct Student {
    char name[MAX_NAME_LEN];  // Student's name
    unsigned int age : 5;     // Age (5 bits, maximum age of 32 years)
    unsigned int gender : 1;  // Gender (1 bit, 0 for male, 1 for female)
    unsigned int standard : 4; // Standard (4 bits, maximum value of 12)
};

// Function to accept student information from the user
void acceptStudentInfo(struct Student* student) {
    getchar();  // To clear any leftover newline characters from previous inputs

    printf("Enter student's name: ");
    fgets(student->name, MAX_NAME_LEN, stdin);
    student->name[strcspn(student->name, "\n")] = '\0';  // Remove newline character
    
    printf("Enter student's age (max 32): ");
    unsigned int age;
    scanf("%u", &age);
    if (age <= 32) {
        student->age = age;  // Assign the valid age to the bit-field
    } else {
        printf("Invalid age. Please enter a value <= 32.\n");
    }
    
    printf("Enter student's gender (0 for Male, 1 for Female): ");
    unsigned int gender;
    scanf("%u", &gender);
    if (gender == 0 || gender == 1) {
        student->gender = gender;  // Assign valid gender to the bit-field
    } else {
        printf("Invalid gender. Please enter 0 for Male or 1 for Female.\n");
    }
    
    printf("Enter student's standard (1 to 12): ");
    unsigned int standard;
    scanf("%u", &standard);
    if (standard >= 1 && standard <= 12) {
        student->standard = standard;  // Assign valid standard to the bit-field
    } else {
        printf("Invalid standard. Please enter a value between 1 and 12.\n");
    }
}

// Function to display student information
void displayStudentInfo(struct Student student) {
    printf("\nStudent Name: %s\n", student.name);
    printf("Age: %u\n", student.age);
    printf("Gender: %s\n", student.gender == 0 ? "Male" : "Female");
    printf("Standard: %u\n", student.standard);
}

int main() {
    struct Student students[3]; // Array to store information of 3 students

    // Accept and display information for each student
    for (int i = 0; i < 3; i++) {
        printf("\nEnter information for student %d:\n", i + 1);
        acceptStudentInfo(&students[i]);
    }

    // Display the information of all students
    for (int i = 0; i < 3; i++) {
        printf("\nDisplaying information for student %d:\n", i + 1);
        displayStudentInfo(students[i]);
    }

    return 0;
}

