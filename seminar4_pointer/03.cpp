#include <stdio.h>

void cube(float* px)
{
    *px = (*px) * (*px) * (*px);
}

int main()
{
    float x;
    printf("x = ");
    scanf("%f", &x);
    
    cube(&x);
    
    printf("x = %.2f\n", x);
    
    return 0;
}
