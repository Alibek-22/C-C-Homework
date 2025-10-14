#include <stdio.h>
#include <stdlib.h>

int main() {
  
    size_t *p = malloc(sizeof(size_t));
    *p = 123;
    printf("a. Number in heap: %zu\n", *p);
    free(p);
    
    return 0;
}
