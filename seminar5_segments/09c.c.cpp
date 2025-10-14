#include <stdio.h>

#define SIZE 1000000  

int main()
{
    getchar();
    printf("1. Before stack allocation\n");
    
    getchar();
    printf("2. Allocating array on stack\n");
    char data[SIZE];
    
    getchar();
    printf("3. Setting first char to 'A'\n");
    data[0] = 'A';
    
    getchar();
    printf("4. Setting last char to 'B'\n");
    data[SIZE - 1] = 'B';
    
    getchar();
    printf("5. Printing first char = %c\n", data[0]);
    
    getchar();
    printf("6. Printing last char = %c\n", data[SIZE - 1]);
    
    getchar();
    return 0;
}
