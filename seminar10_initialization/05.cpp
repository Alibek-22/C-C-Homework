#include <iostream>
#include <string>
#include <new>

int main() {
    std::string stack_str = "Cat";
    std::cout << stack_str << std::endl;

    std::string* heap_str = new std::string("Dog");
    std::cout << *heap_str << std::endl;
    delete heap_str;

    char x[sizeof(std::string)];
    std::string* placement_str = new (x) std::string("Elephant");
    std::cout << *placement_str << std::endl;
    
    placement_str->~basic_string();
    
    return 0;
}
