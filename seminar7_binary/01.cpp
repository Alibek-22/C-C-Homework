#include <stdio.h>
#include <string.h>

int main()
{
    unsigned char a[16] = {0x00, 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70,
                           0x80, 0x90, 0xA0, 0xB0, 0xC0, 0xD0, 0xE0, 0xF0};

    // 1. Печать всех байт в шестнадцатеричной системе
    printf("Hex: ");
    for (int i = 0; i < 16; i++) {
        printf("0x%02X ", a[i]);
    }
    printf("\n");

    // 2. Печать всех байт в десятичной системе
    printf("Dec: ");
    for (int i = 0; i < 16; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    // 3. Печать в формате Index: Hex: ASCII:
    for (int i = 0; i < 16; i++) {
        printf("Index: %02d Hex: 0x%02X ASCII: ", i, a[i]);
        if (a[i] >= 32 && a[i] <= 126) { // печатаемые символы ASCII
            printf("%c", a[i]);
        } else {
            printf(".");
        }
        printf("\n");
    }

    // 4. Присвоить байту с индексом 5 значение 0xE5
    a[5] = 0xE5;
    printf("\nAfter a[5] = 0xE5:\n");
    printf("Hex: ");
    for (int i = 0; i < 16; i++) {
        printf("0x%02X ", a[i]);
    }
    printf("\n");

    // 5. Копирование первых семи байт на три байта правее (memmove)
    memmove(a + 3, a, 7);
    printf("\nAfter memmove(a+3, a, 7):\n");
    printf("Hex: ");
    for (int i = 0; i < 16; i++) {
        printf("0x%02X ", a[i]);
    }
    printf("\n");

    // 6. Копирование последних пяти байт в начало массива (memcpy)
    memcpy(a, a + 11, 5);
    printf("\nAfter memcpy(a, a+11, 5):\n");
    printf("Hex: ");
    for (int i = 0; i < 16; i++) {
        printf("0x%02X ", a[i]);
    }
    printf("\n");

    // 7. Занулить байты с индексами от 5 до 10 (memset)
    memset(a + 5, 0, 6); // 6 байт: индексы 5,6,7,8,9,10
    printf("\nAfter memset(a+5, 0, 6):\n");
    printf("Hex: ");
    for (int i = 0; i < 16; i++) {
        printf("0x%02X ", a[i]);
    }
    printf("\n");

    return 0;
}
