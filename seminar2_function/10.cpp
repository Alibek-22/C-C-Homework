#include <stdio.h>
#define MAX 100

void assign(float A[MAX][MAX], float B[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = B[i][j];
}

int main()
{
    int n;
    float A[MAX][MAX], B[MAX][MAX];
    
    printf("n: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%f", &B[i][j]);
    
    assign(A, B, n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%.1f ", A[i][j]);
        printf("\n");
    }
    
    return 0;
}
