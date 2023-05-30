// nearest smaller to right
#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> nearestSmallerToRight(vector<int> &arr) {
        stack<int> s;
        int n = arr.size();
        vector<int> v(n);
        for(int i=n-1; i>=0; i--) {
            if(s.empty()) {
                v.push_back(-1);
            }
            else if(!s.empty() && s.top() < arr[i]) {
                v.push_back(s.top());
            }
            else if(!s.empty() && s.top() >= arr[i]) {
                while(!s.empty() && s.top() >= arr[i]) {
                    s.pop();
                }

                if(s.size() == 0) {
                    v.push_back(-1);
                }
                else {
                    v.push_back(s.top());
                }
            }
            s.push(arr[i]);
        }
        reverse(v.begin(), v.end());
        return v;
    }
};