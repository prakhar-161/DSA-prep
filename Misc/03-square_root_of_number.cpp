#include<bits/stdc++.h>
using namespace std;

// Optimal - Binary Search
class Solution {
public:
    int squareRoot(int n) {
        int low = 1, high = n;
        int ans = 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if((mid * mid) <= n) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
};

// Brute - Linear Search
class Solution {
public:
    int squareRoot(int n) {
        int ans = 1;
        for(int i=1; i<=n; i++) {
            if(i * i <= n) {
                ans = i;
            } 
            else break;
        }
        return ans;
    }
};

