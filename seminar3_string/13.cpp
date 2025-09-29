#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Error: Wrong number of arguments!\nUsage: %s <number> <operator> <number>\n", argv[0]);
        return 1;
    }
    
    long a = atol(argv[1]), b = atol(argv[3]);
    char op = argv[2][0];
    
    if (op == '/' && b == 0) { printf("Error: Division by zero!\n"); return 1; }
    if (op == '%' && b == 0) { printf("Error: Division by zero!\n"); return 1; }
    
    printf("%ld\n", op == '+' ? a + b : op == '-' ? a - b : op == '*' ? a * b : op == '/' ? a / b : a % b);
    return 0;
}
