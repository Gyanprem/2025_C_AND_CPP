#include <stdio.h>
#include <stdlib.h>

int global_var = 10; // Stored in .data section
static int static_var; // Stored in .bss section

void example_function() {
 int local_var = 20;  // Stored in stack
 static int static_local_var = 30; // Stored in .data/.bss
 int *heap_var = (int*)malloc(sizeof(int)); // Stored in heap
}

int main() {
 example_function();
 return 0;
}

