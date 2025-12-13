#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n;
    
    cin >> n;
    
    set<int> unique_numbers;
    
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        unique_numbers.insert(num);
    }
    
    for (int num : unique_numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
