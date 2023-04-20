#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Memoization
    int climbStairs(int n, vector<int> &dp) {
        if(n <= 1) return n;

        if(dp[n] != -1) return dp[n];

        return dp[n] = f(n-1, dp) + f(n-2, dp);
    }

    // Tabulation
    int climbStairs(int n) {
        int dp[n+1];
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> dp(n+1, -1);
    cout << climbStairs(n, dp);
    return 0;
}