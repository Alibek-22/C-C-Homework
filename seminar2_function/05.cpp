#include <stdio.h>

void print_binary(unsigned int x)
{
    int y=x%2;
    x/=2;
    if (x)
    {
        print_binary(x);
    }
    printf("%i", y);
}

int main()
{
    int y;
    scanf("%i", &y);

    print_binary(y);
    return 0;
}
