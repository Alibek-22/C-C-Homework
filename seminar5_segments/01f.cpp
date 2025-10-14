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
    Book **yz = malloc(sizeof(Book*));
    *yz = malloc(sizeof(Book));
    strcpy((*yz)->title, "Don Quixote");
    (*yz)->pages = 1000;
    (*yz)->price = 750.0;
    
    printf("f. Pointer to heap book: ");
    print_book(*yz);
    
    free(*yz);
    free(yz);
    
    return 0;
}
