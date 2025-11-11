#include <iostream>
#include <string>

std::string repeat(int n)
{
    if (n <= 0) {
        return "";
    }
    
    std::string numStr = std::to_string(n);
    std::string result;
    result.reserve(numStr.length() * n); 
    
    for (int i = 0; i < n; i++) {
        result += numStr;
    }
    
    return result;
}

int main()
{
    std::cout << repeat(5) << std::endl;  
    std::cout << repeat(10) << std::endl; 
    std::cout << repeat(-1) << std::endl; 
    std::cout << repeat(0) << std::endl;  
    std::cout << repeat(3) << std::endl; 
    
    return 0;
}
