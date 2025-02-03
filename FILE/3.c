#include <stdio.h>
#include <stdlib.h>

void copy_file_line_by_line(const char *source_file, const char *destination_file) {
    FILE *src = fopen(source_file, "r");
    FILE *dest = fopen(destination_file, "w");

    // Check if the source file was opened successfully
    if (src == NULL) {
        perror("Error opening source file");
        return;
    }

    // Check if the destination file was opened successfully
    if (dest == NULL) {
        perror("Error opening destination file");
        fclose(src);
        return;
    }

    char buffer[1024]; // Buffer to hold each line

    // Read each line from the source file and write it to the destination file
    while (fgets(buffer, sizeof(buffer), src) != NULL) {
        fputs(buffer, dest);
    }

    printf("Contents copied successfully from %s to %s\n", source_file, destination_file);

    // Close files
    fclose(src);
    fclose(dest);
}

int main() {
    const char *source = "source.txt";
    const char *destination = "destination.txt";

    copy_file_line_by_line(source, destination);

    return 0;
}

