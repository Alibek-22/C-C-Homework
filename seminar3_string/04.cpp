#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    scanf("%s %s", str1, str2);
    
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int max_len = (len1 > len2) ? len1 : len2;
    
    for (int i = 0; i < max_len; i++) {
        if (i < len1) {
            printf("%c", str1[i]);
        }
        if (i < len2) {
            printf("%c", str2[i]);
        }
    }
    
    printf("\n");
    return 0;
}
