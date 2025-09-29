#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_palindrom(const char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    char str[1000];
    
    while (scanf("%s", str) == 1) {
        if (is_palindrom(str)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    
    return 0;
}
