#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
    char title[50];
    int pages;
    float price;
};
typedef struct book Book;

void print_book(const Book *b) {
    printf("Title: %s, Pages: %d, Price: %.2f\n", b->title, b->pages, b->price);
}

int main() {
    Book x;
    strcpy(x.title, "Don Quixote");
    x.pages = 1000;
    x.price = 750.0;
    
    Book *ptr_to_stack_book = &x;
    
    printf("e. Pointer to stack book: ");
    print_book(ptr_to_stack_book);
    
    return 0;
}
