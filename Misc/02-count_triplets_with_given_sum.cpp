#include<bits/stdc++.h>
using namespace std;

// better

class Solution {
public:
    for(int i=0; i<n-2; i++) {
        unordered_set<int> s;
        for(int j=i+1; j<n; j++) {
            int x = sum - (arr[i] + arr[j]);
            if(s.find(x) != s.end()) {
                cout << x << arr[i] << arr[j] << endl;
            }
            else {
                s.insert(arr[j]);
            }
        }
    }
};