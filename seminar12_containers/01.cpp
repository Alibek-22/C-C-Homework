#include <iostream>
#include <list>
#include <vector>

using namespace std;

vector<int> josephus_permutation(int n, int m) {
    list<int> warriors;
    vector<int> elimination_order;
    
    for (int i = 1; i <= n; i++) {
        warriors.push_back(i);
    }
    
    auto it = warriors.begin();
    
    while (!warriors.empty()) {
        for (int i = 1; i < m; i++) {
            it++;
            if (it == warriors.end()) {
                it = warriors.begin();
            }
        }
        
        elimination_order.push_back(*it);
        
        it = warriors.erase(it);
        if (it == warriors.end() && !warriors.empty()) {
            it = warriors.begin();
        }
    }
    
    return elimination_order;
}

int main() {
    int n, m;
    
    cin >> n >> m;
    
    vector<int> result = josephus_permutation(n, m);
    
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
    
    return 0;
}
