#include <iostream>

// Функция cube принимает число типа int по ссылке и возводит его в куб
void cube(int &num)
{
    num = num * num * num;
}

int main()
{
    int a = 5;
    cube(a);
    std::cout << a << std::endl; // Выведет 125
    
    return 0;
}
