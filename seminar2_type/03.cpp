#include <stdio.h>

float yearfrac(int year, int day)
{
    if (year % 4 == 0)
    {
        return (float)day / 366;
    }
    return (float)day / 365;
}

int main()
{
    int year, day;
    scanf("%i %i", &year, &day);
    printf("%.5f", yearfrac(year, day));

    return 0;
}
