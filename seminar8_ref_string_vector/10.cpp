#include <iostream>
#include <string>

bool isDomainName(const std::string& str)
{
    return str.starts_with("www.") && str.ends_with(".com");
}

int main()
{
    std::cout << isDomainName("www.google.com") << std::endl;    
    std::cout << isDomainName("abc") << std::endl;               
    std::cout << isDomainName("hello.com") << std::endl;         
    
    // Дополнительные тесты
    std::cout << isDomainName("www.yandex.com") << std::endl;    
    std::cout << isDomainName("www.mail.com") << std::endl;      
    std::cout << isDomainName("google.com") << std::endl;        
    std::cout << isDomainName("www.google.org") << std::endl;    
  
    return 0;
}
