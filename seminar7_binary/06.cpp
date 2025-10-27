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

    int bytes_to_read = (file_size < 3) ? file_size : 3;

    if (bytes_to_read > 0) {
        if (fseek(file, -bytes_to_read, SEEK_END) != 0) {
            perror("fseek failed");
            fclose(file);
            return 1;
        }

        unsigned char buffer[3];
        size_t read_count = fread(buffer, 1, bytes_to_read, file);
        
        if (read_count != bytes_to_read) {
            perror("fread failed");
            fclose(file);
            return 1;
        }

        printf("Last %d byte(s): ", bytes_to_read);
        for (int i = 0; i < bytes_to_read; i++) {
            printf("%02X ", buffer[i]);
        }
        printf("\n");
    } else {
        printf("File is empty\n");
    }

    fclose(file);
    return 0;
}
