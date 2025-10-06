#include <stdio.h>

int exchange(int* pa, int b) {
    int y = *pa; 
    *pa = b;       
    return y;    
}

int main() {
    int a = 10;
    printf("%i\n", exchange(&a, 20)); 
    printf("%i\n", a);                
    return 0
}
