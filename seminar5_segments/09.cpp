#include <stdio.h>

int adder(int num) {
    static int total_sum = 0;  
    total_sum += num;
    return total_sum;
}

int main()
{
    printf("%i\n", adder(10)); // Должен напечатать 10
    printf("%i\n", adder(15)); // Должен напечатать 25
    printf("%i\n", adder(70)); // Должен напечатать 95
    
    return 0;
}
