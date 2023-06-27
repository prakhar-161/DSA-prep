#include<bits/stdc++.h>
using namespace std;

// Memoization
class Solution {
public:
    int solve(int ind, int prev, vector<int>& nums, vector<vector<int>> &dp) {
        // base case
        if(ind == nums.size()) return 0;

        if(dp[ind][prev+1] != -1) return dp[ind][prev+1];

        int take = 0;  
        if(prev == -1 || nums[ind] > nums[prev]) {
            take = 1 + solve(ind+1, ind, nums, dp);    
        }
        int nottake = 0 + solve(ind+1, prev, nums, dp);

        return dp[ind][prev+1] = max(take, nottake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // dp[index][prevIndex] 
        // index : 0 -> n-1
        // prevIndex : (-1 -> n-1) : 0 -> n, therefore dp[ind][prev+1]
        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        return solve(0, -1, nums, dp);
    }
};
// TC -> O(N*N)
// SC -> O(N*N) + O(N)
// can give TLE (error)

// Tabulation
// keep in mind the prevIndex+1 concept i.e the shifting of the prevIndex
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        
        for(int ind = n-1; ind >= 0; ind--) {
            for(int prevInd = ind-1; prevInd >= -1; prevInd--) {
                // nottake
                int len = 0 + dp[ind+1][prevInd+1];
                if(prevInd == -1 || nums[ind] > nums[prevInd]) {
                    len = max(len, dp[ind+1][ind+1]);         // take
                }
                dp[ind][prevInd+1] = len;
            }
        }
        return dp[0][-1+1];
    }
};

// Best solution -> print LIS file

