#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <utility>

using namespace std;

template<typename Container>
vector<pair<typename Container::value_type, typename Container::value_type>> 
make_pairs(const Container& container) {
    vector<pair<typename Container::value_type, typename Container::value_type>> result;
    
    auto it = container.begin();
    auto end = container.end();
    
    while (it != end) {
        typename Container::value_type first = *it;
        ++it;
        
        typename Container::value_type second = typename Container::value_type();
        if (it != end) {
            second = *it;
            ++it;
        }
        
        result.push_back({first, second});
    }
    
    return result;
}

template<typename T>
void print_pairs(const vector<pair<T, T>>& pairs) {
    cout << "{";
    for (size_t i = 0; i < pairs.size(); ++i) {
        cout << "{" << pairs[i].first << ", " << pairs[i].second << "}";
        if (i != pairs.size() - 1) {
            cout << ", ";
        }
    }
    cout << "}" << endl;
}

void print_pairs_char(const vector<pair<char, char>>& pairs) {
    cout << "{";
    for (size_t i = 0; i < pairs.size(); ++i) {
        cout << "{'" << pairs[i].first << "', '";
        if (pairs[i].second == '\0') {
            cout << "\\0";
        } else {
            cout << pairs[i].second;
        }
        cout << "'}";
        if (i != pairs.size() - 1) {
            cout << ", ";
        }
    }
    cout << "}" << endl;
}

int main() {
    {
        vector<int> vec = {10, 20, 30, 40, 50};
        auto pairs = make_pairs(vec);
        cout << "Test 1 (vector<int>): ";
        print_pairs(pairs);
    }
    
    {
        list<string> lst = {"cat", "dog", "mouse", "lion"};
        auto pairs = make_pairs(lst);
        cout << "Test 2 (list<string>): ";
        print_pairs(pairs);
    }
    
    {
        string str = "Hello";
        auto pairs = make_pairs(str);
        cout << "Test 3 (string): ";
        print_pairs_char(pairs);
    }
    
    
    
    {
        vector<int> empty_vec;
        auto pairs = make_pairs(empty_vec);
        cout << "Test 4 (empty vector): ";
        print_pairs(pairs);
    }
    
    {
        vector<int> even_vec = {1, 2, 3, 4};
        auto pairs = make_pairs(even_vec);
        cout << "Test 5 (even count): ";
        print_pairs(pairs);
    }
    
    {
        vector<int> single_vec = {42};
        auto pairs = make_pairs(single_vec);
        cout << "Test 6 (single element): ";
        print_pairs(pairs);
    }
    
    return 0;
}
