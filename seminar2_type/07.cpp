#include <stdio.h>
#include <string.h>

int main() {
    char type[10];
    scanf("%10[^\n]", type);

    if (strcmp(type, "char") == 0)
        printf("%zu", sizeof(char));
    else if (strcmp(type, "short") == 0)
        printf("%zu", sizeof(short));
    else if (strcmp(type, "int") == 0)
        printf("%zu", sizeof(int));
    else if (strcmp(type, "long") == 0)
        printf("%zu", sizeof(long));
    else if (strcmp(type, "long long") == 0)
        printf("%zu", sizeof(long long));
    else if (strcmp(type, "size_t") == 0)
        printf("%zu", sizeof(size_t));
    else if (strcmp(type, "int8_t") == 0)
        printf("%zu", sizeof(char));
    else if (strcmp(type, "int32_t") == 0)
        printf("%zu", sizeof(int));
    else if (strcmp(type, "uint32_t") == 0)
        printf("%zu", sizeof(unsigned int));
    else if (strcmp(type, "float") == 0)
        printf("%zu", sizeof(float));
    else if (strcmp(type, "double") == 0)
        printf("%zu", sizeof(double));
    else if (strcmp(type, "int[100]") == 0)
        printf("%zu", sizeof(int[100]));
    else if (strcmp(type, "char[100]") == 0)
        printf("%zu", sizeof(char[100]));
    else
        printf("Тип данных не указан в списке");
    
    return 0;
}
