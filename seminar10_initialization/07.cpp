#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>

int sumFromString(const std::string& str) {
    if (str.empty() || str.front() != '[' || str.back() != ']') {
        throw std::invalid_argument("Invalid string format: missing brackets");
    }
    
    if (str == "[]") {
        return 0;
    }
    
    std::string content = str.substr(1, str.length() - 2);
    
    std::stringstream ss(content);
    int sum = 0;
    int num;
    char comma;
    
    if (!(ss >> num)) {
        throw std::invalid_argument("Invalid number format");
    }
    sum += num;
    
    while (ss >> comma) {
        if (comma != ',') {
            throw std::invalid_argument("Invalid separator: expected comma");
        }
        if (!(ss >> num)) {
            throw std::invalid_argument("Invalid number format after comma");
        }
        sum += num;
    }
    
    if (!ss.eof()) {
        throw std::invalid_argument("Extra characters in string");
    }
    
    return sum;
}

int main() {
    std::string test_cases[] = {
        "[10, 20, 30, 40, 50]",
        "[4, 8, 15, 16, 23, 42]", 
        "[20]",
        "[]",
        "[1, 2, 3]"  
    };
    
    for (const auto& test : test_cases) {
        try {
            int result = sumFromString(test);
            std::cout << "Сумма строки \"" << test << "\" = " << result << std::endl;
        } catch (const std::invalid_argument& e) {
            std::cout << "Ошибка для строки \"" << test << "\": " << e.what() << std::endl;
        }
    }
    
    std::cout << "\nТест с некорректной строкой:" << std::endl;
    try {
        sumFromString("[10, 20, abc]");
    } catch (const std::invalid_argument& e) {
        std::cout << "Поймано исключение: " << e.what() << std::endl;
    }
    
    return 0;
}
