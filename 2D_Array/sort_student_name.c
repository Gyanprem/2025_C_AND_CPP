#include <stdio.h>
#include <string.h>

#define NUM_STUDENTS 5
#define MAX_NAME_LEN 100
void accept_student_names(char students[NUM_STUDENTS][MAX_NAME_LEN]) {
printf("enter names of %d students :\n",NUM_STUDENTS);
for(int i = 0; i< NUM_STUDENTS;i++){
	printf("enter name for students %d : ", i+1);
	fgets(students[i], MAX_NAME_LEN, stdin);
	students[i][strcspn(students[i], "\n")] = '\0';
	}
}
void print_student_names(char students[NUM_STUDENTS][MAX_NAME_LEN]){
printf("\n list of student names :\n");
for(int i = 0;i<NUM_STUDENTS; i++) {
	printf("students %d  : %s\n", i+1, students[i]);
	}
}

void sort_student_names(char students[NUM_STUDENTS][MAX_NAME_LEN]) {
char temp[MAX_NAME_LEN];
for(int i=0;i<NUM_STUDENTS - 1; i++) {
	for(int j = i+1; j <NUM_STUDENTS; j++) {
		if(strcmp(students[i], students[j]) > 0 ) {
		strcpy(temp, students[i]);
		strcpy(students[i], students[j]);
		strcpy(students[j], temp);
		}
	}
}
}

int main() {
	char students[NUM_STUDENTS][MAX_NAME_LEN];
	accept_student_names(students);
	print_student_names(students);
	sort_student_names(students);
	printf("\n sorted list of student names :\n");
	print_student_names(students);
	return 0;
}



















