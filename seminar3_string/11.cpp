#include <stdio.h>
#include <stddef.h> // Для size_t

void safe_strcpy(char dest[], size_t dest_size, const char src[]) {
    if (dest_size == 0) return; 

    size_t i = 0;
    while (i < dest_size - 1 && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';
}

int main() {
    char a[10] = "Mouse";
    char b[50] = "LargeElephant";

    safe_strcpy(a, sizeof(a), b);  // OK

    printf("a = \"%s\"\n", a);     

    return 0;
}
