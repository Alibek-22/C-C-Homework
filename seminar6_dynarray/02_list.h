#ifndef LIST_H
#define LIST_H

#include <stddef.h>

typedef struct node {
    int value;
    struct node* next;
    struct node* prev;
} Node;

typedef struct list {
    Node* head;
    Node* tail;
    size_t size;
} List;

List init(size_t n);
void print(const List* pl);
void push_back(List* pl, int value);
void push_front(List* pl, int value);
int pop_back(List* pl);
int pop_front(List* pl);
Node* erase(List* pl, Node* p);
void splice(List* plist, Node* p, List* other);
void destroy(List* pl);
void advance(Node** pp, size_t n);

#endif
