#include <stdio.h>
#include <string.h>

void sort_names(char *names[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(names[i], names[j]) > 0) {
                char *temp = names[i];
                names[i] = names[j];
                names[j] = temp;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    // Check if any arguments are passed
    if (argc < 2) {
        printf("No names provided. Please pass names as command-line arguments.\n");
        return 1;
    }

    // Sort the names
    sort_names(argv + 1, argc - 1);

    // Display the sorted names
    printf("The provided names in sorted order are:\n");
    for (int i = 1; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

    return 0;
}

