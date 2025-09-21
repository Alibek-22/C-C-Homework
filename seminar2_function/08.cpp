#include <stdio.h>

void reverse(int a[], int n)
{
    for (int i = 0; i < n / 2; ++i)
    {
        int temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = temp;
    }
}

int main()
{
    int n;
    scanf("%i", &n);
    int a[n];
    
    for (int i = 0; i < n; ++i)
        scanf("%i", &a[i]);
    
    reverse(a, n);
    
    for (int i = 0; i < n; ++i)
        printf("%i ", a[i]);
    
    return 0;
}
