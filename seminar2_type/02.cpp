#include <stdio.h>
unsigned long long int razm(int n, int k) 
{
    unsigned long long int fn = 1;
    for (int i = n - k + 1; i <= n; ++i)
        fn *= i;

    return fn;
}

int main() 
{
    int n, k;
    scanf("%i %i", &n, &k);
    printf("%llu\n", razm(n, k));
}
