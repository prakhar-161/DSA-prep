#include<bits/stdc++.h>
using namespace std;

// GFG
// Given a set of N items, each with a weight and a value, represented by the array w[] and val[] respectively. 
// Also, a knapsack with weight limit W.
// The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
// INFINITE SUPPLY

// Memoization
int f(int ind, int W, int val[], int wt[], vector<vector<int>> &dp) {
        if(ind == 0) {
            return ((int)(W / wt[0])) * val[0];
        }
    
        if(dp[ind][W] != -1) return dp[ind][W];
    
        int notpick = f(ind-1, W, wt, val, dp);
        int pick = INT_MIN;
        if(wt[ind] <= W) {
            pick = val[ind] + f(ind, W-wt[ind], wt, val, dp);
        }
    
        return dp[ind][W] = max(pick, notpick);
    }
    
    int knapSack(int N, int W, int val[], int wt[]) {
        vector<vector<int>> dp(N, vector<int> (W+1, -1));
        return f(N-1, W, val, wt, dp);
    }