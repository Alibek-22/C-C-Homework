#include <stdio.h>

int main()
{
    int x1, x2, y1, y2, r1, r2;
    scanf("%i %i %i %i %i %i", &x1, &y1, &r1, &x2, &y2, &r2);

    if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) == (r1 + r2)*(r1 + r2))
    {
        printf("Touch");
    }
    else if((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) < (r1 + r2)*(r1 + r2))
    {
        printf("Intersect");
    }
    else
    {
        printf("Do not intersect");
    }

    return 0;
}
