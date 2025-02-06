#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "students.dat"

typedef struct {
    int roll;
    char name[50];
    float marks;
} Student;

typedef enum {
    ADD = 1,
    DISPLAY,
    SEARCH_ROLL,
    SEARCH_NAME,
    MODIFY,
    REMOVE,
    EXIT
} Menu;

void write_student() {
    FILE *file = fopen(FILE_NAME, "ab");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }
    Student s;
    printf("Enter Roll Number: ");
    scanf("%d", &s.roll);
    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);
    fwrite(&s, sizeof(Student), 1, file);
    fclose(file);
    printf("Student record added successfully!\n");
}

void read_students() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        printf("No records found!\n");
        return;
    }
    Student s;
    while (fread(&s, sizeof(Student), 1, file)) {
        printf("Roll: %d, Name: %s, Marks: %.2f\n", s.roll, s.name, s.marks);
    }
    fclose(file);
}

void search_student_by_roll(int roll) {
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        printf("No records found!\n");
        return;
    }
    Student s;
    while (fread(&s, sizeof(Student), 1, file)) {
        if (s.roll == roll) {
            printf("Record Found: Roll: %d, Name: %s, Marks: %.2f\n", s.roll, s.name, s.marks);
            fclose(file);
            return;
        }
    }
    printf("Record not found!\n");
    fclose(file);
}

void search_student_by_name(char *name) {
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        printf("No records found!\n");
        return;
    }
    Student s;
    int found = 0;
    while (fread(&s, sizeof(Student), 1, file)) {
        if (strcmp(s.name, name) == 0) {
            printf("Record Found: Roll: %d, Name: %s, Marks: %.2f\n", s.roll, s.name, s.marks);
            found = 1;
        }
    }
    if (!found) printf("Record not found!\n");
    fclose(file);
}

void modify_student(int roll) {
    FILE *file = fopen(FILE_NAME, "rb+");
    if (!file) {
        printf("No records found!\n");
        return;
    }
    Student s;
    while (fread(&s, sizeof(Student), 1, file)) {
        if (s.roll == roll) {
            printf("Enter New Name: ");
            scanf(" %[^\n]", s.name);
            printf("Enter New Marks: ");
            scanf("%f", &s.marks);
            fseek(file, -sizeof(Student), SEEK_CUR);
            fwrite(&s, sizeof(Student), 1, file);
            fclose(file);
            printf("Record updated successfully!\n");
            return;
        }
    }
    printf("Record not found!\n");
    fclose(file);
}

void remove_student(int roll) {
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        printf("No records found!\n");
        return;
    }
    FILE *temp = fopen("temp.dat", "wb");
    Student s;
    int found = 0;
    while (fread(&s, sizeof(Student), 1, file)) {
        if (s.roll == roll) {
            found = 1;
        } else {
            fwrite(&s, sizeof(Student), 1, temp);
        }
    }
    fclose(file);
    fclose(temp);
    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);
    if (found)
        printf("Record removed successfully!\n");
    else
        printf("Record not found!\n");
}

int main() {
    int choice, roll;
    char name[50];
    while (1) {
        printf("\nStudent Database Menu\n");
        printf("1. Add Student\n2. Display Students\n3. Search by Roll Number\n4. Search by Name\n5. Modify Student\n6. Remove Student\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case ADD:
                write_student();
                break;
            case DISPLAY:
                read_students();
                break;
            case SEARCH_ROLL:
                printf("Enter Roll Number to search: ");
                scanf("%d", &roll);
                search_student_by_roll(roll);
                break;
            case SEARCH_NAME:
                printf("Enter Name to search: ");
                scanf(" %[^\n]", name);
                search_student_by_name(name);
                break;
            case MODIFY:
                printf("Enter Roll Number to modify: ");
                scanf("%d", &roll);
                modify_student(roll);
                break;
            case REMOVE:
                printf("Enter Roll Number to remove: ");
                scanf("%d", &roll);
                remove_student(roll);
                break;
            case EXIT:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice, try again!\n");
        }
    }
    return 0;
}
