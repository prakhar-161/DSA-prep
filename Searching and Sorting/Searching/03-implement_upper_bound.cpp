#include<bits/stdc++.h>
using namespace std;

// find the smallest index in sorted array such that arr[index] > X.

class Solution {
public:
    int upperBound(vector<int>& arr, int x) {
        int n = arr.size();
        int low = 0, high = n-1;
        int ans = n;
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(arr[mid] > x) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;

    }
};

// c++ stl
int ub = upper_bound(arr.begin(), arr.end(), x);
// upper_bound(arr.begin(), arr.end(), x) - arr.begin();   -> to get the index
