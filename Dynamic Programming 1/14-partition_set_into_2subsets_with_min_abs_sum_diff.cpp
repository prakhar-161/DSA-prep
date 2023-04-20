#include <bits/stdc++.h>
using namespace std;

// Leetcode
// You are given an integer array nums of 2 * n integers. 
// You need to partition nums into two arrays of length n to minimize the absolute difference of the sums of the arrays. 
// To partition nums, put each element of nums into one of the two arrays.
// Return the minimum possible absolute difference.

// Q12
// subset sum code used in this question
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

int minimumDifference(vector<int>& arr, int n) {
    int totalSum = 0;
    for(int i=0; i<n; i++) totalSum += arr[i];
    int target = totalSum;

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

    // dp[n-1][col->0...totalSum]
    int mini = 1e9;
    for(int s1 = 0; s1<=totalSum/2; s1++) {
        if(dp[n-1][s1] == true) {
            mini = min(mini, abs((totalSum - s1) - s1));
        }
    }

    return mini;
}