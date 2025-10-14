#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float* get_geometric_progression(float a, float r, int n) {
    float* progression = malloc(n * sizeof(float));
    
    for (int i = 0; i < n; i++) {
        progression[i] = a * powf(r, i);
    }
    
    return progression;
}

int main() {
    float a = 2.0f;   
    float r = 3.0f;     
    int n = 10;       
    
    float* geom_prog = get_geometric_progression(a, r, n);
    
    printf("Геометрическая прогрессия: a = %.2f, r = %.2f\n", a, r);
    for (int i = 0; i < n; i++) {
        printf("a%d = %.2f\n", i, geom_prog[i]);
    }
    
    free(geom_prog);
    
    return 0;
}
