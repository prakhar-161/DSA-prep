#include<bits/stdc++.h>
using namespace std;

// HOUSE ROBBER - 1

// Memoization
int f(int ind, vector<int> &arr, int n, vector<int> &dp) {
    if(ind == 0) return arr[ind];
    if(ind < 0) return 0;

    if(dp[ind] != -1) return dp[ind];

    int pick = arr[ind] + f(ind-2, arr, n, dp);
    int notpick = 0 + f(ind-1, arr, n, dp);

    return dp[ind] = max(pick, notpick);
}

int findMaxSum(vector<int> &arr, int n) {
    vector<int> dp(n+1, -1);
    return f(n-1, arr, n, dp); 
}

// Tabulation
int findMaxSum(vector<int> &arr, int n) {
    int dp[n];
    dp[0] = arr[0];
    int neg = 0;

    for(int i=1; i<n; i++) {
        int pick = arr[i];
        if(i>1) {
            pick += dp[i-2];
        }
        int notpick = 0 + dp[i-1];

        dp[i] = max(pick, notpick);
    }
    return dp[n-1];
}

// Space Optimization
int findMaxSum(vector<int> &arr, int n) {
    int prev = arr[0];
    int prev2 = 0;

    for(int i=1; i<n; i++) {
        int take = arr[i];
        if(i > 1) take += prev2;
        int nottake = 0 + prev;

        int curr = max(take, nottake);

        prev2 = prev;
        prev = curr;
    }
    return prev;
}