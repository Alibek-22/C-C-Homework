#include <stdio.h>
#include "list.h"

int main()
{
    List a = init(0);

    for (int i = 0; i < 5; ++i)
        push_back(&a, 10 * (i + 1));
    for (int i = 0; i < 5; ++i)
        push_front(&a, 100 * (i + 1));

    print(&a); // 500 400 300 200 100 10 20 30 40 50

    printf("%i\n", pop_front(&a)); // 500
    printf("%i\n", pop_back(&a));  // 50
    print(&a); // 400 300 200 100 10 20 30 40

    Node* p = a.head;
    advance(&p, 3);
    p = erase(&a, p);
    print(&a); // 400 300 200 10 20 30 40

    List b = init(0);
    for (int i = 0; i < 3; ++i)
        push_back(&b, 1000 * (i + 1));
    splice(&a, p, &b);
    print(&a); // 400 300 200 1000 2000 3000 10 20 30 40
    print(&b); // ничего не напечатает

    destroy(&a);
    destroy(&b);
}
