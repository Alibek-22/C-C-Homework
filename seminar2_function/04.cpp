#include <stdio.h>

int sum_of_digits(int x)
{
    int k=0;
    while (x!=0)
    {
        k+=(x%10);
        x/=10;
    }
    return k;
}

int main()
{
    int x;
    scanf("%i", &x);

    printf("%i", sum_of_digits(x));
    return 0;
}
