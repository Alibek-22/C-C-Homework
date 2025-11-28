#include <iostream>
#include <string>
#include <vector>

int main() {
    int* int_ptr = new int(123);
    std::cout << *int_ptr << std::endl;
    delete int_ptr;

    std::string* str_ptr = new std::string("Cats and Dogs");
    std::cout << *str_ptr << std::endl;
    delete str_ptr;

    int* arr_int = new int[5]{10, 20, 30, 40, 50};
    for (int i = 0; i < 5; ++i) {
        std::cout << arr_int[i] << " ";
    }
    std::cout << std::endl;
    delete[] arr_int;

    std::vector<int>* vec_ptr = new std::vector<int>{10, 20, 30, 40, 50};
    for (int val : *vec_ptr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    delete vec_ptr;

    std::string* arr_str = new std::string[3]{"Cat", "Dog", "Mouse"};
    for (int i = 0; i < 3; ++i) {
        std::cout << arr_str[i] << " ";
    }
    std::cout << std::endl;
    delete[] arr_str;

    return 0;
}
