#include <bits/stdc++.h>
using namespace std;

// Leetcode

// You are given an integer array coins representing coins of different denominations 
// and an integer amount representing a total amount of money.
// Return the fewest number of coins that you need to make up that amount. 
// If that amount of money cannot be made up by any combination of the coins, return -1.

// Memoization
int f(int ind, int amount, vector<int>& coins, vector<vector<int>> &dp) {
    // base case
    if(ind == 0) {
        if(amount % coins[0] == 0) return amount / coins[0];
        else return 1e9;
    }

    if(dp[ind][amount] != -1) return dp[ind][amount];

    int nottake = 0 + f(ind-1, amount, dp);
    int take = INT_MAX;
    if(coins[ind] <= amount) {
        take = 1 + f(ind, amount-coins[ind], dp);
    }

    return dp[ind][amount] = min(take, nottake);
}

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int> (amount+1, -1));
    int res = f(n-1, amount, coins, dp);
    if(res >= 1e9) return -1;
    return res;
}

// TC -> O(N*amount)
// SC -> O(N*amount) + O(amount)

// Tabulation
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int> (amount+1, 0));
    for(int i=0; i<=amount; i++) {
        if(i % coins[0] == 0) dp[0][i] = i / coins[0];
        else dp[0][i] = 1e9;
    }

    for(int ind=1; ind<n; ind++) {
        for(int j=0; j<=amount; j++) {
            int nottake = 0 + dp[ind-1][j];
            int take = 1e9;
            if(coins[ind] <= j) {
                take = 1 + dp[ind][j - coins[ind]];
            }

            dp[ind][j] = min(take, nottake);
        }
    }

    int ans = dp[n-1][amount];
    if(ans >= 1e9) return -1;
    return ans;
}

// tc -> o(N*T)
// SC -> O(N*T)

// Space Optimiation
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<int> prev(amount+1), curr(amount+1);
    for(int i=0; i<=amount; i++) {
        if(i % coins[0] == 0) prev[i] = i / coins[0];
        else prev[i] = 1e9;
    }

    for(int ind=1; ind<n; ind++) {
        for(int j=0; j<=amount; j++) {
            int nottake = 0 + prev[j];
            int take = 1e9;
            if(coins[ind] <= j) {
                take = 1 + curr[j - coins[ind]];
            }

            curr[j] = min(take, nottake);
        }
        prev = curr;
    }

    int ans = prev[amount];
    if(ans >= 1e9) return -1;
    return ans;
}

// TC -> O(N*amount)
// SC -> O(amount)