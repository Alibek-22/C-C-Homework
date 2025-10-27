#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    if (fseek(file, 0, SEEK_END) != 0) {
        perror("fseek failed");
        fclose(file);
        return 1;
    }

    long file_size = ftell(file);
    if (file_size == -1) {
        perror("ftell failed");
        fclose(file);
        return 1;
    }

    printf("File size: %ld bytes\n", file_size);

    fclose(file);
    return 0;
}
