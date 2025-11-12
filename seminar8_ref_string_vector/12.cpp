#include <iostream>
#include <string>
#include <vector>

std::string concatenate(const std::vector<std::string>& v)
{
    std::string result;
    
    for (const std::string& s : v)
    {
        result += s;
    }
    
    return result;
}

int main()
{
    std::vector<std::string> v {"Cat", "Dog", "Mouse", "Tiger", "Elk"};
    std::cout << concatenate(v) << std::endl; 
    return 0;
}
