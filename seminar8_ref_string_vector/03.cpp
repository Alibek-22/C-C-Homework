#include <iostream>

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 10;
    int b = 20;
    std::cout << a << " " << b << std::endl; // Выведет 10 20

    swap(a, b);
    std::cout << a << " " << b << std::endl; // Выведет 20 10
    
    return 0;
}
