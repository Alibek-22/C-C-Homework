#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* ptr;
};

typedef struct node Node;

int main(void) {
    Node *n1 = malloc(sizeof(Node));
    Node *n2 = malloc(sizeof(Node));
    Node *n3 = malloc(sizeof(Node));

    n1->value = 100;
    n2->value = 200;
    n3->value = 300;

    n1->ptr = n2;
    n2->ptr = n3;
    n3->ptr = n1;

    Node *current = n1;
    while (1) {
        printf("%d\n", current->value);
        current = current->ptr;
    }

    return 0;
}
