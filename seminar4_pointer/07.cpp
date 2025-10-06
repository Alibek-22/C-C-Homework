#include <stdio.h>

int* max(int* pa, int* pb) {
    if (*pa > *pb)
        return pa;  
    else
        return pb;
}

int main() {
    int a = 10;
    int b = 30;
    int c = 20;

    *max(&a, &b) += 1;   
    printf("%i %i %i\n", a, b, c);  

    return 0;
}
