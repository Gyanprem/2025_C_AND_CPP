#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

// Structure to hold student information
typedef struct {
    int roll_number;
    char name[50];
} Student;

// Function to search student by roll number
Student* search_by_roll_number(Student students[], int count, int roll_number) {
    for (int i = 0; i < count; i++) {
        if (students[i].roll_number == roll_number) {
            return &students[i];
        }
    }
    return NULL;
}

// Function to search student by name
Student* search_by_name(Student students[], int count, const char* name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].name, name) == 0) {
            return &students[i];
        }
    }
    return NULL;
}

int main() {
    Student students[MAX_STUDENTS] = {
        {101, "Alice"},
        {102, "Bob"},
        {103, "Charlie"}
    };
    int student_count = 3;

    // Search by roll number
    int roll_number_to_search = 102;
    Student* result_by_roll = search_by_roll_number(students, student_count, roll_number_to_search);
    if (result_by_roll != NULL) {
        printf("Student found: Roll Number: %d, Name: %s\n", result_by_roll->roll_number, result_by_roll->name);
    } else {
        printf("Student not found by roll number.\n");
    }

    // Search by name
    char name_to_search[50] = "Alice";
    Student* result_by_name = search_by_name(students, student_count, name_to_search);
    if (result_by_name != NULL) {
        printf("Student found: Roll Number: %d, Name: %s\n", result_by_name->roll_number, result_by_name->name);
    } else {
        printf("Student not found by name.\n");
    }

    return 0;
}

