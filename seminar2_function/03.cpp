#include <stdio.h>

void print_even(int a, int b)
{
    a=(a+1)/2*2;
    b=b/2*2;
    for (int k=a;  k<=b; k+=2)
    {
        printf("%k ", k);
    }
}

int main()
{
    int a, b;
    scanf("%k %k", &a, &b);

    print_even(a, b);
    return 0;
}
