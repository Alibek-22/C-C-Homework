#include <iostream>
#include <string>
#include <cctype>

void countLetters(const std::string& str, int& numLetters, int& numDigits)
{
    numLetters = 0;
    numDigits = 0;
    
    for (char c : str) {
        if (std::isalpha(c)) {
            numLetters++;
        } else if (std::isdigit(c)) {
            numDigits++;
        }
    }
}

int main()
{
    std::string test1 = "Hello123World45!";
    int letters, digits;
    
    countLetters(test1, letters, digits);
    std::cout << "Строка: \"" << test1 << "\"" << std::endl;
    std::cout << "Букв: " << letters << ", Цифр: " << digits << std::endl;
    
    std::string test2 = "ABCdef 123 !@# 456";
    countLetters(test2, letters, digits);
    std::cout << "Строка: \"" << test2 << "\"" << std::endl;
    std::cout << "Букв: " << letters << ", Цифр: " << digits << std::endl;
    
    std::string test3 = "OnlyLetters";
    countLetters(test3, letters, digits);
    std::cout << "Строка: \"" << test3 << "\"" << std::endl;
    std::cout << "Букв: " << letters << ", Цифр: " << digits << std::endl;
    
    std::string test4 = "1234567890";
    countLetters(test4, letters, digits);
    std::cout << "Строка: \"" << test4 << "\"" << std::endl;
    std::cout << "Букв: " << letters << ", Цифр: " << digits << std::endl;
    
    return 0;
}
