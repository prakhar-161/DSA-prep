#include<bits/stdc++.h>
using namespace std;

// find the smallest index in sorted array such that arr[index] >= X.

class Solution {
public:
    int lowerBound(vector<int>& arr, int x) {
        int n = arr.size();
        int low = 0, high = n-1;
        int ans = n;
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(arr[mid] >= x) {
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

// Lower bound using C++ stl
// lower_bound()
int lb = lower_bound(arr.begin(), arr.end(), x);