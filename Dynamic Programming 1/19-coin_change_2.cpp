#include<bits/stdc++.h>
using namespace std;

// Leetcode
// You are given an integer array coins representing coins of different denominations 
// and an integer amount representing a total amount of money.
// Return the number of combinations that make up that amount. 
// If that amount of money cannot be made up by any combination of the coins, return 0.

// INFINITE SUPPLY

// Memoization
int f(int ind, int amount, vector<int>& coins, vector<vector<int>> &dp) {
    if(ind == 0) {
        if(amount % coins[0] == 0) return 1;
        else return 0;
    }

    if(dp[ind][amount] != -1) return dp[ind][amount];

    int nottake = f(ind-1, amount, coins, dp);
    int take = 0;
    if(coins[ind] <= amount) {
        take = f(ind, amount-coins[ind], coins, dp);
    }

    return dp[ind][amount] = take + nottake;
}

int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int> (amount+1, -1));
    return f(n-1, amount, coins, dp);    
}

// Tabulation
int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int> (amount+1, 0));
    for(int t=0; t<=amount; t++) {
        if(t % coins[0] == 0) dp[0][t] = 1;
    }

    for(int ind=1; ind<n; ind++) {
        for(int t=0; t<=amount; t++) {
            int nottake = dp[ind-1][t];
            int take = 0;
            if(coins[ind] <= t) {
                take = dp[ind][t - coins[ind]];
            }

            dp[ind][t] = take + nottake;
        }
    } 

    return dp[n-1][amount];
}
