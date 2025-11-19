#include <iostream>
#include "number.hpp"

int main() {
    // Тестирование чисел Фибоначчи
    std::cout << "Fibonacci numbers:" << std::endl;
    for (int i = 0; i <= 10; ++i) {
        std::cout << "F(" << i << ") = " << fibonacci(i) << std::endl;
    }
    
    // F(1000)
    std::cout << "F(1000) = " << fibonacci(1000) << std::endl;

    // Тестирование факториалов
    std::cout << "\nFactorials:" << std::endl;
    for (int i = 0; i <= 10; ++i) {
        std::cout << i << "! = " << factorial(i) << std::endl;
    }
    
    // 1000!
    std::cout << "1000! = " << factorial(1000) << std::endl;

    // Тестирование других методов
    std::cout << "\nOther tests:" << std::endl;
    Number a("123");
    Number b("456");
    std::cout << "123 + 456 = " << (a + b) << std::endl;
    std::cout << "123 * 456 = " << (a * b) << std::endl;
    std::cout << "123 is even: " << a.isEven() << std::endl;
    std::cout << "456 is even: " << b.isEven() << std::endl;

    return 0;
}
