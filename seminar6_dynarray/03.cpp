#include <stdio.h>

int main() 
{
#if defined(DOG)
    printf("Dog1\n");
#else
    printf("No dog1\n");
#endif

    return 0;
}
