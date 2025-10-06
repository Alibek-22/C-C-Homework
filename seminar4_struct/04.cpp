#include <stdio.h>
#include <stddef.h>
#include <stdalign.h>

struct cat {
    char x;
    size_t y;
};

struct dog {
    size_t y;
    char x;
};

struct mouse {
    char x;
    char y;
    size_t z;
};

struct rat {
    char x;
    size_t z;
    char y;
};

struct fox {
    char x;
    struct mouse y;
};

int main(void) {
    printf("char: size=%zu align=%zu\n", sizeof(char), alignof(char));
    printf("int: size=%zu align=%zu\n", sizeof(int), alignof(int));
    printf("size_t: size=%zu align=%zu\n", sizeof(size_t), alignof(size_t));
    printf("int[10]: size=%zu align=%zu\n", sizeof(int[10]), alignof(int[10]));
    printf("int*: size=%zu align=%zu\n", sizeof(int*), alignof(int*));

    printf("struct cat: size=%zu align=%zu\n", sizeof(struct cat), alignof(struct cat));
    printf("struct dog: size=%zu align=%zu\n", sizeof(struct dog), alignof(struct dog));
    printf("struct mouse: size=%zu align=%zu\n", sizeof(struct mouse), alignof(struct mouse));
    printf("struct rat: size=%zu align=%zu\n", sizeof(struct rat), alignof(struct rat));
    printf("struct fox: size=%zu align=%zu\n", sizeof(struct fox), alignof(struct fox));

    return 0;
}
