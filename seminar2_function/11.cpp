#include <iostream>
#define MAX 100

void multiply(float a[MAX][MAX], float b[MAX][MAX], float c[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = 0; 
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main()
{
    int n;
    std::cin >> n;
    float a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            std::cin >> a[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            std::cin >> b[i][j];

    multiply(a, b, c, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            std::cout << c[i][j] << ' ';
        std::cout << std::endl;
    }

    return 0;
}
