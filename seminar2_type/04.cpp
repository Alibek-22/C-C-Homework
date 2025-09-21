#include <stdio.h>

double pi(int n)
{
    double k = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(i%2 == 0)
        {
            k -= (float)1/(2 * i - 1);
        }
        else
        {
            k += (float)1/(2 * i - 1);
        }
    }
    return k * 4;
}

int main()
{
    int n;
    scanf("%i", &n);
    printf("%lf", pi(n));

    return 0;
}
