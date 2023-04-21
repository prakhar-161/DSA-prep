#include <bits/stdc++.h>
using namespace std;

// GFG

// Memoization
int f(int ind, int W, int wt[], int val[]) {
    if(ind == 0) {
        if(wt[0] <= W) return val[0];
        else return 0;
    }

    if(dp[ind][W] != -1) return dp[ind][W];

    int notpick = f(ind-1, W, wt, val);
    int pick = INT_MIN;
    if(wt[ind] <= W) {
        pick = val[ind] + f(ind-1, W-wt[ind], wt, val);
    }

    return dp[ind][W] = max(pick, notpick);
}

int knapSack(int W, int wt[], int val[], int n) {
    vector<vector<int>> dp(n, vector<int> (W+1, -1));
    return f(n-1, W, wt, val);
}

// Tabulation
int knapSack(int W, int wt[], int val[], int n) {
    vector<vector<int>> dp(n, vector<int> (W+1, 0));
    for(int i=wt[0]; i<=W; i++) {
        dp[0][i] = val[0];
    }

    for(int ind = 1; ind < n; ind++) {
        for(int w=0; w<=W; w++) {
            int notpick = dp[ind-1][w];
            int pick = INT_MIN;
            if(wt[ind] <= w) {
                pick = val[ind] + dp[ind-1][w-wt[ind]];
            }

            dp[ind][w] = max(pick, notpick);
        }
    }

    return dp[n-1][W];
}

// Space Optimisation
int knapSack(int W, int wt[], int val[], int n) {
    vector<int> prev(W+1, 0), cur(W+1, 0);
    for(int i=wt[0]; i<=W; i++) {
        prev[i] = val[0];
    }

    for(int ind = 1; ind < n; ind++) {
        for(int w=0; w<=W; w++) {
            int notpick = prev[w];
            int pick = INT_MIN;
            if(wt[ind] <= w) {
                pick = val[ind] + prev[w-wt[ind]];
            }

            cur[w] = max(pick, notpick);
        }
        prev = curr;
    }
    return prev[W];
}