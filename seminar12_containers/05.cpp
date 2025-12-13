#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n, k;
    
    cin >> n >> k;
    
    set<int> cuts;
    cuts.insert(0);     
    cuts.insert(n);     
    
    multiset<int> segments;
    segments.insert(n); 
    
    vector<int> results;
    
    for (int i = 0; i < k; i++) {
        int cut_point;
        cin >> cut_point;
        
        auto it = cuts.upper_bound(cut_point);
        int right = *it;
        it--;
        int left = *it;
  
        int old_length = right - left;
        segments.erase(segments.find(old_length));
        
        int length1 = cut_point - left;
        int length2 = right - cut_point;
        segments.insert(length1);
        segments.insert(length2);
        
        cuts.insert(cut_point);
        
        results.push_back(*segments.rbegin());
    }
    
    for (size_t i = 0; i < results.size(); i++) {
        cout << results[i];
        if (i != results.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
    
    return 0;
}
