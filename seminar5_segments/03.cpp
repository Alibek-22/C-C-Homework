#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat(const char* a, const char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    int total_len = len_a + len_b + 1; 
    
    char* result = malloc(total_len * sizeof(char));
    
    strcpy(result, a);
    strcat(result, b);
    
    return result;
}

int main() {
    const char* str1 = "Hello, ";
    const char* str2 = "World!";
    
    char* concatenated = concat(str1, str2);
    
    printf("Результат конкатенации: %s\n", concatenated);
    
    free(concatenated);
    
    const char* part1 = "Geometric ";
    const char* part2 = "progression";
    
    char* combined = concat(part1, part2);
    printf("Еще один пример: %s\n", combined);
    
    free(combined);
    
    return 0;
}
