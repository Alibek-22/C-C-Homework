#include <stdio.h>
#include <math.h>

int solve_quadratic(double a, double b, double c, double* px1, double* px2) {
    const double eps = 1e-10;

    if (fabs(a) < eps) {
       
        if (fabs(b) < eps) return 0; 
        *px1 = -c / b;
        return 1; 
    }

    double d = b * b - 4 * a * c;

    if (d > eps) {
        double sqrt_d = sqrt(d);
        *px1 = (-b + sqrt_d) / (2 * a);
        *px2 = (-b - sqrt_d) / (2 * a);
        return 2;
    } else if (fabs(d) <= eps) {
        *px1 = -b / (2 * a);
        return 1;
    } else {
        return 0;
    }
}

int main() {
    double a, b, c, x1, x2;
    printf("A, B, C: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    int roots = solve_quadratic(a, b, c, &x1, &x2);

    if (roots == 0)
        printf("Нет корней\n");
    else if (roots == 1)
        printf("Один корень: %.10f\n", x1);
    else
        printf("Два корня: %.10f и %.10f\n", x1, x2);

    return 0;
}
