#include <stdio.h>

bool is_even(int a)
{
    if (a%2==0)
    {
        return true;
    }
    return false;
}

int main()
{
    printf("%i\n", is_even(90));
    printf("%i\n", is_even(91));
}
