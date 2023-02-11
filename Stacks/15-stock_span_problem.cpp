// uses concept of nearest greater to left element code
// vi[] vector stores the nearest greater to left's indexes
// stack is a pair of two ints which are ngl's value, ngl's index
#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> stockSpan(vector<int> &arr) {
        stack<pair<int, int>> s;
        int n = arr.size();
        vector<int> vi(n);
        for(int i=0; i<n; i++) {
            if(s.empty()) {
                vi.push_back(-1);
            }
            else if(!s.empty() && s.top().first > arr[i]) {
                vi.push_back(s.top().second);
            }
            else if(!s.empty() && s.top().first <= arr[i]) {
                while(!s.empty() && s.top().first <= arr[i]) {
                    s.pop();
                }
                if(s.size() == 0) {
                    vi.push_back(-1);
                }
                else {
                    vi.push_back(s.top().second);
                }
            }

            s.push({arr[i], i});
        }

        vector<int> ans(n);
        for(int i=0; i<n; i++) {
            ans[i] = arr[i] - vi[i];
        }

        return ans;
    }
};