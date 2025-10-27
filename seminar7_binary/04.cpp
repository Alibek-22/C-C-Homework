#include <stdio.h>

int is_little_endian() {
    int x = 1;
    char *p = (char*)&x;
    return *p == 1;
}

int main() {
    if (is_little_endian()) {
        printf("Little Endian\n");
    } else {
        printf("Big Endian\n");
    }
    return 0;
}
