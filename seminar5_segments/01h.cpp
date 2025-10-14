#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book_ptr {
    char* title;
    int pages;
    float price;
};
typedef struct book_ptr BookPtr;

void print_book_ptr(const BookPtr *b) {
    printf("Title: %s, Pages: %d, Price: %.2f\n", b->title, b->pages, b->price);
}

int main() {
    BookPtr *book_with_ptr = malloc(sizeof(BookPtr));
    book_with_ptr->title = malloc(50 * sizeof(char));
    strcpy(book_with_ptr->title, "Don Quixote");
    book_with_ptr->pages = 1000;
    book_with_ptr->price = 750.0;
    
    printf("h. Book with title pointer: ");
    print_book_ptr(book_with_ptr);
    
    free(book_with_ptr->title);
    free(book_with_ptr);
    
    return 0;
}
