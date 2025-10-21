#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Error checked malloc
static void* ecmalloc(size_t n)
{
    void* p = malloc(n);
    if (p == NULL)
    {
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }
    return p;
}

#define DECLARE_DOUBLY_LINKED_LIST(type) \
\
typedef struct Node_##type { \
    type data; \
    struct Node_##type* prev; \
    struct Node_##type* next; \
} Node_##type; \
\
typedef struct DoublyLinkedList_##type { \
    Node_##type* head; \
    Node_##type* tail; \
    size_t size; \
} DoublyLinkedList_##type; \
\
void dll_##type##_init(DoublyLinkedList_##type* list) { \
    list->head = NULL; \
    list->tail = NULL; \
    list->size = 0; \
} \
\
void dll_##type##_push_back(DoublyLinkedList_##type* list, type value) { \
    Node_##type* new_node = (Node_##type*)ecmalloc(sizeof(Node_##type)); \
    new_node->data = value; \
    new_node->next = NULL; \
    new_node->prev = list->tail; \
    \
    if (list->tail != NULL) { \
        list->tail->next = new_node; \
    } else { \
        list->head = new_node; \
    } \
    list->tail = new_node; \
    list->size++; \
} \
\
void dll_##type##_push_front(DoublyLinkedList_##type* list, type value) { \
    Node_##type* new_node = (Node_##type*)ecmalloc(sizeof(Node_##type)); \
    new_node->data = value; \
    new_node->prev = NULL; \
    new_node->next = list->head; \
    \
    if (list->head != NULL) { \
        list->head->prev = new_node; \
    } else { \
        list->tail = new_node; \
    } \
    list->head = new_node; \
    list->size++; \
} \
\
type dll_##type##_pop_back(DoublyLinkedList_##type* list) { \
    assert(list->tail != NULL && "List is empty"); \
    \
    Node_##type* old_tail = list->tail; \
    type value = old_tail->data; \
    \
    list->tail = old_tail->prev; \
    if (list->tail != NULL) { \
        list->tail->next = NULL; \
    } else { \
        list->head = NULL; \
    } \
    \
    free(old_tail); \
    list->size--; \
    return value; \
} \
\
type dll_##type##_pop_front(DoublyLinkedList_##type* list) { \
    assert(list->head != NULL && "List is empty"); \
    \
    Node_##type* old_head = list->head; \
    type value = old_head->data; \
    \
    list->head = old_head->next; \
    if (list->head != NULL) { \
        list->head->prev = NULL; \
    } else { \
        list->tail = NULL; \
    } \
    \
    free(old_head); \
    list->size--; \
    return value; \
} \
\
type dll_##type##_front(DoublyLinkedList_##type* list) { \
    assert(list->head != NULL && "List is empty"); \
    return list->head->data; \
} \
\
type dll_##type##_back(DoublyLinkedList_##type* list) { \
    assert(list->tail != NULL && "List is empty"); \
    return list->tail->data; \
} \
\
int dll_##type##_empty(DoublyLinkedList_##type* list) { \
    return list->head == NULL; \
} \
\
size_t dll_##type##_size(DoublyLinkedList_##type* list) { \
    return list->size; \
} \
\
void dll_##type##_destroy(DoublyLinkedList_##type* list) { \
    Node_##type* current = list->head; \
    while (current != NULL) { \
        Node_##type* next = current->next; \
        free(current); \
        current = next; \
    } \
    list->head = NULL; \
    list->tail = NULL; \
    list->size = 0; \
}
