#include <bits/stdc++.h>
using namespace std;

// Given an integer array nums, 
// return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

// Memoization
bool f(int ind, int target, vector<int>& nums, vector<vector<int>> &dp) {
    if(target == 0) return 1;
    if(ind == 0) return (nums[ind] == target);

    if(dp[ind][target] != -1) return dp[ind][target];

    bool notpick = f(ind-1, target, nums, dp);
    bool pick = false;
    if(nums[ind] <= target) pick = f(ind-1, target-nums[ind], nums, dp);

    return dp[ind][target] = pick | notpick;
}

bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    for(int i=0; i<n; i++) sum += nums[i];
    if(sum % 2 != 0) return false;
    int target = sum / 2;
    vector<vector<int>> dp(n, vector<int> (target+1, -1));
    return f(n-1, target, nums, dp);
}