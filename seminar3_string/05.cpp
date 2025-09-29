#include <stdio.h>
#include <ctype.h>

int main() {
    char digit;
    int sum = 0;
    
    while (scanf("%c", &digit) == 1) {
        if (isdigit(digit)) {
            sum += digit - '0';  
        } else {
            break;
        }
    }
    
    printf("%d\n", sum);
    return 0;
}
