#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> stockSpan(vector<int> &arr) {
        stack<pair<int, int>> st;
        vector<int> v;
        int n = arr.size();
        for(int i=0; i<n; i++) {
            if(st.empty()) {
                v.push_back(-1);
            }
            else if(!st.empty() && s.top().first > arr[i]) {
                v.push_back(s.top().second);
            }
            else if(!st.empty() && s.top().first <= arr[i]) {
                while(!st.empty() && s.top().first <= arr[i]) {
                    st.pop();
                }
                if(st.empty()) {
                    v.push_back(-1);
                }
                else {
                    v.push_back(s.top().second);
                }
            }
            st.push({arr[i], i});
        }
        
        for(int i=0; i<v.size(); i++) {
            v[i] = abs(i - v[i]);
        }

        return output;
    }
};