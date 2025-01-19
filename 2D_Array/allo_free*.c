#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int *allocateMatrix(int rows, int cols);
void freeMatrix(int *matrix);

int main() {
    int rows, cols;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Allocate memory for the matrix
    int *matrix = allocateMatrix(rows, cols);
    if (matrix == NULL) {
        printf("Memory allocation failed. Exiting.\n");
        return 1;
    }

    // Example: Initialize the matrix with values
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *(matrix + i * cols + j) = i * cols + j;
        }
    }

    // Print the matrix
    printf("\nMatrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(matrix + i * cols + j));
        }
        printf("\n");
    }

    // Free the allocated memory
    freeMatrix(matrix);

    return 0;
}

int *allocateMatrix(int rows, int cols) {
    int *matrix = (int *)malloc(rows * cols * sizeof(int));
    if (matrix == NULL) {
        return NULL;
    }
    return matrix;
}

void freeMatrix(int *matrix) {
    free(matrix);
}

