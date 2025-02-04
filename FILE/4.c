#include <stdio.h>
#include <stdlib.h>

void copy_file_line_by_line(const char *source_file, const char *destination_file) {
    FILE *src = fopen(source_file, "r");
    FILE *dest = fopen(destination_file, "w");

    if (src == NULL) {
        perror("Error opening source file");
        return;
    }

    if (dest == NULL) {
        perror("Error opening destination file");
        fclose(src);
        return;
    }

    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), src) != NULL) {
        fputs(buffer, dest);
    }

    printf("Contents copied successfully from %s to %s\n", source_file, destination_file);

    fclose(src);
    fclose(dest);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    copy_file_line_by_line(argv[1], argv[2]);

    return 0;
}

