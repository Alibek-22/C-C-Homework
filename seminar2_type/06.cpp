#include <stdio.h>
#include <math.h>
#include <stdbool.h>

const double step = 1e-2;
const double eps = 1e-10;

double gamma(double x)
{
    double integral = 0.0;
    double t = 0.0;
    double prev_value = 0.0;
    
    while (true)
    {
        double current_value = pow(t, x - 1) * exp(-t);
        double area = (prev_value + current_value) * step / 2.0;
        
        integral += area;
        
        if (t > 20.0 && area < eps)
        {
            break;
        }
        
        prev_value = current_value;
        t += step;
    }
    
    return integral;
}

int main()
{
    double x;
    scanf("%lf", &x);
    
    if (x <= 1.0)
    {
        return 1;
    }
    
    double result;
    
    if (x == (int)x)
    {
        int n = (int)x;
        result = 1.0;
        for (int i = 1; i < n; i++)
        {
            result *= i;
        }
    }
    else
    {
        result = gamma(x);
    }
    
    if (result > 1e10 || result < 1e-10)
    {
        printf("%.5e", result);
    }
    else
    {
        printf("%.6f", result);
    }
    
    return 0;
}
