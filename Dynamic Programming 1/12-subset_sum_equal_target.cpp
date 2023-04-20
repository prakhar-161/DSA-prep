// GFG
#include <bits/stdc++.h>
using namespace std;

// Given an array of non-negative integers, and a value sum, 
// determine if there is a subset of the given set with sum equal to given sum. 

// Memoization
bool f(int ind, int target, vector<int>arr, vector<vector<int>> &dp) {
    if(target == 0) return 1;
    if(ind == 0) return (arr[0] == target);

    if(dp[ind][target] != -1) return dp[ind][target];

    bool notPick = f(ind-1, target);
    bool pick = false;
    if(target >= arr[ind]) {
        pick = f(ind - 1, target - arr[ind]);
    }

    return dp[ind][target] = (pick | notPick);
}

bool isSubsetSum(vector<int>arr, int target){
    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int> (target+1, -1));
    return f(n-1, target, arr, dp);
}

// Tabulation
bool isSubsetSum(vector<int>arr, int target) {
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool> (target+1, false));
    for(int i=0; i<n; i++) dp[i][0] = true;
    // important
    if(arr[0] <= target) dp[0][arr[0]] = true;
    for(int i=1; i<n; i++) {
        for(int k=1; k<=target; k++) {
            bool notPick = dp[i-1][k];
            bool pick = false;
            if(k >= arr[i]) {
                pick = dp[i-1][k-arr[i]];
            }

            dp[i][k] = pick || notPick;
        }
    }

    return dp[n-1][target];
}
