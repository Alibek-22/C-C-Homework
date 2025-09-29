#include <stdio.h>
#include <ctype.h>

void encrypt(char* str, int k) {
    k = k % 26;
    if (k < 0) k += 26;  
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (isupper(str[i])) {
           str[i] = 'A' + (str[i] - 'A' + k) % 26;
        } else if (islower(str[i])) {
            str[i] = 'a' + (str[i] - 'a' + k) % 26;
        }
    }
}

int main() {
    int k;
    char str[1000];
    while (scanf("%d ", &k) == 1) {
        fgets(str, sizeof(str), stdin);
        
        int len = 0;
        while (str[len] != '\0' && str[len] != '\n') {
            len++;
        }
        str[len] = '\0';
        
        encrypt(str, k);
        printf("%s\n", str);
    }
    
    return 0;
}
