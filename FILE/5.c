#include <stdio.h>

// Define a structure to hold student information
typedef struct {
    int id;
    char name[50];
    float marks;
} Student;

// Function to write student record to a file
void writeStudentRecord(const char *filename, Student s) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }
    fprintf(file, "%d %s %.2f\n", s.id, s.name, s.marks);
    fclose(file);
    printf("Student record written successfully.\n");
}

// Function to read student record from a file
void readStudentRecord(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return;
    }
    Student s;
    if (fscanf(file, "%d %49s %f", &s.id, s.name, &s.marks) == 3) {
        printf("Student ID: %d\n", s.id);
        printf("Name: %s\n", s.name);
        printf("Marks: %.2f\n", s.marks);
    } else {
        printf("Error reading student record.\n");
    }
    fclose(file);
}

int main() {
    Student s1 = {101, "JohnDoe", 85.5};
    const char *filename = "student.txt";

    // Writing the student record to file
    writeStudentRecord(filename, s1);

    // Reading the student record from file
    readStudentRecord(filename);

    return 0;
}

