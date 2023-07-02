#include<bits/stdc++.h>
using namespace std;

// optimal
class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        int ele = INT_MIN;
        vector<int> ans;
        for(int i=n-1; i>=0; i--) {
            if(a[i] >= ele) {
                ans.push_back(a[i]);
            }
            ele = max(ele, a[i]);
        } 
        reverse(ans.begin(), ans.end());
        return ans;
    }
};