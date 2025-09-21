#include <stdio.h>
unsigned long long int fact(int n) 
{
    unsigned long long int result = 1;
    for (int i = 1; i <= n; ++i)
        result *= i;
    return result;
}

int main() 
{
    int k;
    scanf("%i", &k);
    printf("%llu\n", fact(k));
}
