#include <stdio.h>

unsigned long long int trib(int n)
{
    if (n==1 or n==2)
    {
        return 0;
    }
    if (n==3)
    {
        return 1;
    }
    long long int a=0, b=0, c=1, d;
    for (int k=0; k!=(n-2); ++k)
    {
        d=a+b+c;
        a=b;
        b=c;
        c=d;
    }
    return c;
}

int main()
{
    int n;
    scanf("%k", &n);

    printf("%llu", trib(n));
    return 0;
}
