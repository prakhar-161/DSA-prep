// Atmost K transactions
#include<bits/stdc++.h>
using namespace std;

// Tabulation
int maxProfit(vector<int>& prices) {
    vector<vector<vector<int>>> dp(n, vector<<vector<int>> (2, vector<int> (k+1, 0)));
    for(int ind = n-1; ind >= 0; ind--) {
        for(int buy = 0; buy <= 1; buy++) {
            for(int cap = 1; cap <= k; cap++) {
                if(buy) {
                    dp[ind][buy][cap] = max((-prices[ind] + dp[ind+1][0][cap]), (0 + dp[ind+1][1][cap]));
                }
                else {
                    dp[ind][buy][cap] = max((prices[ind] + dp[ind+1][1][cap-1]), (0 + dp[ind+1][0][cap]));
                }
            }
        }
    }

    return dp[0][1][k];
}

// TC -> O(N*2*K)
// SC -> O(N*2*K)

// TYPE-2 SOLUTION
// Memoization
int f(int ind, int tranNum, vector<int> &prices, int n, int k, vector<vector<vector<int>>> &dp) {
    if(ind == n || tranNum == 2*k) return 0;

    if(dp[ind][tranNum] != -1) return dp[ind][tranNum];

    if(tranNum % 2 == 0) {  // buy
        return dp[ind][tranNum] = max((-prices[ind] + f(ind+1, tranNum+1, prices, n, k, dp)), (0 + f(ind+1, tranNum, prices, n, k, dp)));
    }

    return dp[ind][tranNum] = max((prices[ind] + f(ind+1, tranNum+1, prices, n, k, dp)), (0 + f(ind+1, tranNum, prices, n, k, dp)));
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    return f(0, 0, prices, n, k);
}