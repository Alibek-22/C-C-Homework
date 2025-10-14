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
    Book *books_array = malloc(3 * sizeof(Book));
    
    strcpy(books_array[0].title, "Don Quixote");
    books_array[0].pages = 1000;
    books_array[0].price = 750.0;

    strcpy(books_array[1].title, "Oblomov");
    books_array[1].pages = 400;
    books_array[1].price = 250.0;

    strcpy(books_array[2].title, "The Odyssey");
    books_array[2].pages = 500;
    books_array[2].price = 500.0;

    printf("g. Array of books:\n");
    for (int i = 0; i < 3; i++) {
        print_book(&books_array[i]);
    }
    
    free(books_array);
    
    return 0;
}
