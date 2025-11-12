#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cctype>

std::vector<std::vector<std::size_t>> calculate_word_lengths(const std::string& filename)
{
    std::vector<std::vector<std::size_t>> result;
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        std::cerr << "Error: cannot open file " << filename << std::endl;
        return result;
    }
    
    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::size_t> line_lengths;
        std::stringstream ss(line);
        std::string word;
        
        while (ss >> word) {
            line_lengths.push_back(word.length());
        }
        
        if (!line_lengths.empty()) {
            result.push_back(line_lengths);
        } else {
           
            result.push_back(std::vector<std::size_t>());
        }
    }
    
    file.close();
    return result;
}


void print_result(const std::vector<std::vector<std::size_t>>& result)
{
    std::cout << "{";
    for (std::size_t i = 0; i < result.size(); ++i) {
        std::cout << "{";
        for (std::size_t j = 0; j < result[i].size(); ++j) {
            std::cout << result[i][j];
            if (j < result[i].size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "}";
        if (i < result.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "}" << std::endl;
}

int main()
{
   
    auto result = calculate_word_lengths("test.txt");
    print_result(result);
    
    return 0;
}
