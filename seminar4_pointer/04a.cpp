#include <stdio.h>

void mult2(int* p, size_t n) {
    for (size_t i = 0; i < n; i++) {
        *(p + i) *= 2;
    }
}

int main() {
    size_t n;
    printf("A: ");
    scanf("%zu", &n);

    int arr[n];
    printf("B:\n");
    for (size_t i = 0; i < n; i++) {
        scanf("%d", (arr + i));
    }

    mult2(arr, n);

    printf("C:\n");
    for (size_t i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }

    return 0;
}
