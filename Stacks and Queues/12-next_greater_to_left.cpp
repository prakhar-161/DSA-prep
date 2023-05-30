#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> nextGreaterToLeft(vector<int> &arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> v;
        for(int i=0; i<n; i++) {
            if(st.empty()) {
                v.push_back(-1);
            }
            else if(!st.empty() && st.top() > arr[i]) {
                v.push_back(st.top());
            }
            else if(!st.empty() && st.top() <= arr[i]) {
                while(!st.empty() && st.top() <= arr[i]) {
                    st.pop();
                }
                if(st.empty()) {
                    v.push_back(-1);
                }
                else {
                    v.push_back(st.top());
                }
            }
            st.push(arr[i]);
        }
        return v;
    }
};