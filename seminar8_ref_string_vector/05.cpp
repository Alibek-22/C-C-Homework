#include <iostream>
#include <string>

struct Book
{
    std::string title;
    int pages;
    float price;
};
bool isExpensive(const Book &book)
{
    return book.price > 1000;
}

int main()
{
    Book book1 = {"Война и мир", 1225, 850.5f};
    Book book2 = {"Программирование на C++", 450, 2500.0f};
    Book book3 = {"Алгоритмы", 680, 999.99f};
    
    std::cout << "Книга: " << book1.title << ", цена: " << book1.price 
              << ", дорогая: " << (isExpensive(book1) ? "да" : "нет") << std::endl;
    
    std::cout << "Книга: " << book2.title << ", цена: " << book2.price 
              << ", дорогая: " << (isExpensive(book2) ? "да" : "нет") << std::endl;
    
    std::cout << "Книга: " << book3.title << ", цена: " << book3.price 
              << ", дорогая: " << (isExpensive(book3) ? "да" : "нет") << std::endl;
    
    return 0;
}
