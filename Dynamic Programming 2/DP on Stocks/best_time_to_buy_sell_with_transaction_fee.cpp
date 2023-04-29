#include<bits/stdc++.h>
using namespace std;

// LEETCODE

// You are given an array prices where prices[i] is the price of a given stock on the ith day, 
// and an integer fee representing a transaction fee.
// Find the maximum profit you can achieve. You may complete as many transactions as you like, 
// but you need to pay the transaction fee for each transaction.

int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int> (2, 0));

    dp[n][0] = dp[n][1] = 0;
    for(int ind = n-1; ind >= 0; ind--) {
        for(int buy = 0; buy <= 1; buy++) {
            if(buy) {
                dp[ind][buy] = max((-prices[ind] + dp[ind+1][0]), (0 + dp[ind+1][1]));
            }
            else {
                dp[ind][buy] = max((prices[ind] + dp[ind+2][1] - fee), (0 + dp[ind+1][0]));
            }
        }
    }

    return dp[0][1];
}