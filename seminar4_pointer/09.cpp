#include <stdio.h>
#include <string.h>
#include <ctype.h>

void used_chars(const char* str, char* used) {
    int letters[26] = {0}; 

    while (*str) {
        if (isalpha((unsigned char)*str)) { 
            char lower = tolower((unsigned char)*str);
            letters[lower - 'a'] = 1; 
        }
        str++;
    }

    char* p = used;
    for (int i = 0; i < 26; i++) {
        if (letters[i]) {
            *p = 'a' + i; 
            p++;
        }
    }
    *p = '\0'; 
}

int main() {
    char s[50] = "Sapere Aude";
    char u[30];

    used_chars(s, u);
    printf("%s\n", u); 

    strcpy(s, "123!$@");
    used_chars(s, u);
    printf("%s\n", u); 

    strcpy(s, "The Quick Brown Fox Jumps Over The Lazy Dog!");
    used_chars(s, u);
    printf("%s\n", u); 

    return 0;
}
