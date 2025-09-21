#include <stdio.h>

void alice(int n);
void bob(int n);

void alice(int n)
{
    n = n*3 + 1;
    printf("Alice:  %i\n", n);
    bob(n);
}

void bob(int n)
{
    if (n%2==0)
    {
        n/=2;
        printf("Bob:    %i\n", n);
        bob(n);
    }
    else if (n!=1)
    {
        alice(n);
    }
    return;
}

int main()
{
    int n;
    scanf("%i", &n);
    alice(n);

    return 0;
}
