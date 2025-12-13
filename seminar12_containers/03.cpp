#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n;
    
    cin >> n;
    
    multiset<int> sorted_numbers;
    
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        sorted_numbers.insert(num);
    }
    
    for (int num : sorted_numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
