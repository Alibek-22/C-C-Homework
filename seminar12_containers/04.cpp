#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n;
    
    cin >> n;
    
    map<long long, int> frequency;
    
    for (int i = 0; i < n; i++) {
        long long num;
        cin >> num;
        frequency[num]++;
    }
    
    for (auto it = frequency.begin(); it != frequency.end(); it++) {
        cout << it->first;
        if (next(it) != frequency.end()) {
            cout << " ";
        }
    }
    cout << endl;
    
    for (auto it = frequency.begin(); it != frequency.end(); it++) {
        cout << it->second;
        if (next(it) != frequency.end()) {
            cout << " ";
        }
    }
    cout << endl;
    
    return 0;
}
