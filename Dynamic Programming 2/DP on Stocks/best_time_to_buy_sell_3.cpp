#include<bits/stdc++.h>
using namespace std;

// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// Find the maximum profit you can achieve. You may complete at most two transactions.
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

// Memoization
int f(int ind, int buy, int cap, vector<int> &prices, int n, vector<vector<<vector<int>>> &dp) {
    if(cap == 0 || ind == n) return 0;

    if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
    int profit = 0;
    if(buy==1) {
        profit = max((-prices[ind] + f(ind+1, 0, cap, prices, n, dp)), (0 + f(ind+1, 1, cap, prices, n, dp)));
    }
    if(buy==0) {
        profit = max((prices[ind] + f(ind+1, 1, cap-1, prices, n, dp)), (0 + f(ind+1, 0, cap, prices, n, dp)));
    }

    return dp[ind][buy][cap] = profit;
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<<vector<int>> (2, vector<int> (3, -1)));
    return f(0, 1, 2, prices, n, dp);
}

// TC -> O(N*2*2)
// SC -> O(N*2*2) + O(N)

// Tabulation
int maxProfit(vector<int>& prices) {
    vector<vector<vector<int>>> dp(n, vector<<vector<int>> (2, vector<int> (3, 0)));
    // Base case
    // cap == 0
    // for(int ind = 0; ind < n; ind++) {
    //     for(int buy = 0; buy <= 1; buy++) {
    //         dp[ind][buy][0] = 0;
    //     }
    // }   
    // // ind == n
    // for(int buy = 0; buy <= 1; buy++) {
    //     for(int cap = 0; cap < 3; cap++) {
    //         dp[n][buy][cap] = 0;
    //     }
    // }

    for(int ind = n-1; ind >= 0; ind--) {
        for(int buy = 0; buy <= 1; buy++) {
            for(int cap = 1; cap <= 2; cap++) {
                if(buy) {
                    dp[ind][buy][cap] = max((-prices[ind] + dp[ind+1][0][cap]), (0 + dp[ind+1][1][cap]));
                }
                else {
                    dp[ind][buy][cap] = max((prices[ind] + dp[ind+1][1][cap-1]), (0 + dp[ind+1][0][cap]));
                }
            }
        }
    }

    return dp[0][1][2];
}

// TC -> O(N*2*2)
// SC -> O(N*2*2)

// Space Optimization
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> after(2, vector<int> (3, 0));
    vector<vector<int>> curr(2, vector<int> (3, 0));

    for(int ind = n-1; ind >= 0; ind--) {
        for(int buy = 0; buy <= 1; buy++) {
            for(int cap = 1; cap <= 2; cap++) {
                if(buy) {
                    curr[buy][cap] = max((-prices[ind] + after[0][cap]), (0 + after[1][cap]));
                }
                else {
                    curr[buy][cap] = max((prices[ind] + after[1][cap]), (0 + after[0][cap]));
                }
            }
        }
        after = curr;
    }

    return after[1][2];
}


// TYPE-2 SOLUTION
// dp[n][4]