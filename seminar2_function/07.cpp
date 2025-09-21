#include <stdio.h>

int count_even(int x[], int n)
{
    int k=0;
    for (int i=0; i!=n; ++i)
    {
        if (x[i]%2==0)
        {
            ++k;
        }
    }
    return k;
}

int main()
{
    int n, el;
    scanf("%i", &n);
    int x[n];

    for (int i=0; i!=n; ++i)
    {
        scanf("%i", &el);
        x[i] = el;
    }

    printf("%i", count_even(x, n));
    return 0;
}
