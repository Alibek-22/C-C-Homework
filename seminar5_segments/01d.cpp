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
    Book *book_heap = malloc(sizeof(Book));
    strcpy(book_heap->title, "Don Quixote");
    book_heap->pages = 1000;
    book_heap->price = 750.0;
    
    printf("d. Book in heap: ");
    print_book(book_heap);
    
    free(book_heap);
    
    return 0;
}
