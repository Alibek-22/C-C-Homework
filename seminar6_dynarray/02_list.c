#include <stdio.h>
#include <stdlib.h>
#include "list.h"


static Node* create_node(int value)
{
    Node* p = (Node*)malloc(sizeof(Node));
    if (!p)
    {
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }
    p->value = value;
    p->next = NULL;
    p->prev = NULL;
    return p;
}


List init(size_t n)
{
    List lst;
    lst.head = lst.tail = NULL;
    lst.size = 0;

    for (size_t i = 0; i < n; ++i)
        push_back(&lst, 0);

    return lst;
}


void print(const List* pl)
{
    for (Node* p = pl->head; p != NULL; p = p->next)
        printf("%d ", p->value);
    printf("\n");
}


void push_back(List* pl, int value)
{
    Node* p = create_node(value);
    if (pl->tail == NULL)
    {
        pl->head = pl->tail = p;
    }
    else
    {
        pl->tail->next = p;
        p->prev = pl->tail;
        pl->tail = p;
    }
    pl->size++;
}


void push_front(List* pl, int value)
{
    Node* p = create_node(value);
    if (pl->head == NULL)
    {
        pl->head = pl->tail = p;
    }
    else
    {
        p->next = pl->head;
        pl->head->prev = p;
        pl->head = p;
    }
    pl->size++;
}


int pop_back(List* pl)
{
    if (pl->tail == NULL)
    {
        fprintf(stderr, "Ошибка: список пуст.\n");
        exit(1);
    }

    int val = pl->tail->value;
    Node* tmp = pl->tail;
    pl->tail = pl->tail->prev;
    if (pl->tail)
        pl->tail->next = NULL;
    else
        pl->head = NULL;

    free(tmp);
    pl->size--;
    return val;
}


int pop_front(List* pl)
{
    if (pl->head == NULL)
    {
        fprintf(stderr, "Ошибка: список пуст.\n");
        exit(1);
    }

    int val = pl->head->value;
    Node* tmp = pl->head;
    pl->head = pl->head->next;
    if (pl->head)
        pl->head->prev = NULL;
    else
        pl->tail = NULL;

    free(tmp);
    pl->size--;
    return val;
}


Node* erase(List* pl, Node* p)
{
    if (p == NULL || pl->head == NULL)
        return NULL;

    Node* next = p->next;

    if (p->prev)
        p->prev->next = p->next;
    else
        pl->head = p->next;

    if (p->next)
        p->next->prev = p->prev;
    else
        pl->tail = p->prev;

    free(p);
    pl->size--;
    return next;
}


void splice(List* plist, Node* p, List* other)
{
    if (other->head == NULL)
        return;

    if (p == NULL)
    {
        // если p == NULL, вставляем в конец
        if (plist->tail == NULL)
        {
            *plist = *other;
        }
        else
        {
            plist->tail->next = other->head;
            other->head->prev = plist->tail;
            plist->tail = other->tail;
        }
    }
    else if (p == plist->head)
    {
        
        other->tail->next = plist->head;
        plist->head->prev = other->tail;
        plist->head = other->head;
    }
    else
    {
        
        Node* before = p->prev;
        before->next = other->head;
        other->head->prev = before;
        other->tail->next = p;
        p->prev = other->tail;
    }

    plist->size += other->size;

    
    other->head = other->tail = NULL;
    other->size = 0;
}


void destroy(List* pl)
{
    Node* p = pl->head;
    while (p != NULL)
    {
        Node* tmp = p;
        p = p->next;
        free(tmp);
    }
    pl->head = pl->tail = NULL;
    pl->size = 0;
}


void advance(Node** pp, size_t n)
{
    if (pp == NULL || *pp == NULL) return;
    for (size_t i = 0; i < n && *pp != NULL; ++i)
        *pp = (*pp)->next;
}
