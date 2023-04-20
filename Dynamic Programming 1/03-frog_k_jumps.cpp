#include<bits/stdc++.h>
using namespace std;

// Memoization
int f(int ind, vector<int>& height, int k, vector<int> &dp) {
    if(ind == 0) return 0;

    int minSteps = INT_MAX;
    for(int j=1; j<=k; j++) {
        if(ind > j) {
            int jump = f(ind-j, height, k, dp) + abs(height[ind] - height[ind-j]);
            minSteps = min(minSteps, jump);
        }
    }
    return minSteps;
}

int minimizeCost(vector<int>& height, int n, int k) { 
    vector<int> dp(n+1, -1);
    return f(n-1, height, k, dp); 
}

// Tabulation
int minimizeCost(vector<int>& height, int n, int k) {
    int dp[n];
    dp[0] = 0;
    for(int i=1; i<n; i++) {
        int minSteps = INT_MAX;
        for(int j=1; j<=k; j++) {
            if(i-j > 0) {
                int jump = dp[i-j] + abs(height[i] - height[i-j]);
                minSteps = min(minsSteps, jump);
            }
        }
        dp[i] = minSteps;
    }
    return dp[n-1];
}

