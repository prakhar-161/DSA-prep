#include <bits/stdc++.h>
using namespace std;

// Given an array arr[] of non-negative integers and an integer sum, 
// the task is to count all subsets of the given array with a sum equal to a given sum.
// Note: Answer can be very large, so, output answer modulo 109+7

// Memoization
int f(int ind, int sum, int arr[], vector<vector<int>> &dp) {
	if(sum == 0) return 1;
    if(ind == 0) return (arr[0] == sum);
	        
	if(dp[ind][sum] != -1) return dp[ind][sum];
	     
    int notpick = f(ind-1, sum, arr, dp);
	int pick = 0;
	if(arr[ind] <= sum) {
        pick = f(ind-1, sum-arr[ind], arr, dp);
	}
	     
	return dp[ind][sum] = pick + notpick;
}

int perfectSum(int arr[], int n, int sum) {
    vector<vector<int>> dp(n, vector<int> (sum+1, -1));
    int ans = f(n-1, sum, arr, dp);
    return ans;
}

// Tabulation
int perfectSum(int arr[], int n, int sum) {
    vector<vector<int>> dp(n, vector<int> (sum+1, 0));
    for(int i=0; i<n; i++) dp[i][0] = 1;
    if(arr[0] <= sum) dp[0][arr[0]] = 1;
    for(int i=1; i<n; i++) {
        for(int k=1; k<=sum; k++) {
            int notPick = dp[i-1][k];
            int pick = 0;
            if(k >= arr[i]) {
                pick = dp[i-1][k-arr[i]];
            }

            dp[i][k] = pick + notPick;
        }
    }

    return dp[n-1][sum];
}

// TC->O(N*K)
// SC->O(N*K)