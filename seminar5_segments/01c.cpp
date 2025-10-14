#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char **ptr_to_str = malloc(sizeof(char*));
    *ptr_to_str = malloc(15 * sizeof(char)); 
    strcpy(*ptr_to_str, "Cat and dogs");
    
    printf("c. Pointer to string: %s\n", *ptr_to_str);
    
    free(*ptr_to_str);
    free(ptr_to_str);
    
    return 0;
}
