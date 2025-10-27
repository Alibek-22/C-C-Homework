#include <stdio.h>
union int_to_str {
    int int_arr[4];
    char str[16];
};

int main()
{
    union int_to_str u = {{1819043144, 1461726319, 1684828783, 2593}};
    printf("(b) %s", u.str);
}
