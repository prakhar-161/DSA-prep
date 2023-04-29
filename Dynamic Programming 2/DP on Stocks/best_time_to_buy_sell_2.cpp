#include<bits/stdc++.h>
using namespace std;

// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
// On each day, you may decide to buy and/or sell the stock. 
// You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.
// Find and return the maximum profit you can achieve.

// Memoization
int f(int ind, int buy, vector<int> &prices, int n, vector<vector<int>> &dp) {
    if(ind == n) return 0;

    if(dp[ind][buy] != -1) return dp[ind][buy];
    int profit = 0;
    if(buy==1) {
        profit = max((-prices[ind] + f(ind+1, 0, prices, n, dp)), (0 + f(ind+1, 1, prices, n, dp)));
    }
    if(buy==0) {
        profit = max((prices[ind] + f(ind+1, 1, prices, n, dp)), (0 + f(ind+1, 0, prices, n, dp)));
    }

    return dp[ind][buy] = profit;
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int> (2, -1));
    return f(0, 1, prices, n, dp);
}

// TC -> O(N*2) 
// SC -> O(N*2) + O(N)

// Tabulation
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int> (2, 0));

    dp[n][0] = dp[n][1] = 0;
    for(int ind = n-1; ind >= 0; ind--) {
        for(int buy = 0; buy <= 1; buy++) {
            int profit = 0;
            if(buy) {
                profit = max((-prices[ind] + dp[ind+1][0]), (0 + dp[ind+1][1]));
            }
            else {
                profit = max((prices[ind] + dp[ind+1][1]), (0 + dp[ind+1][0]));
            }

            dp[ind][buy] = profit;
        }
    }

    return dp[0][1];
}

// TC -> O(N*2) 
// SC -> O(N*2)

// Space Optimization
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<int> ahead(2, 0), curr(2, 0);
    ahead[0] = ahead[1] = 0;
    for(int ind = n-1; ind >= 0; ind--) {
        for(int buy = 0; buy <= 1; buy++) {
            int profit = 0;
            if(buy) {
                int profit = max((-prices[ind] + ahead[0]), (0 + ahead[1]));
            }
            else {
                int profit = max((prices[ind] + ahead[1]), (0 + ahead[0]));
            }

            curr[buy] = profit;
        }
        ahead = curr;
    }

    return ahead[1];
}

// TC -> O(N*2) 
// SC ->  O(1)