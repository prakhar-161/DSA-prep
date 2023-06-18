// Given two strings s and t, return the number of distinct subsequences of s which equals t.
// Input: s = "babgbag", t = "bag"
// Output: 5

// Memoization - 0 based indexing
class Solution {
public:
    int solve(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
        // base case
        if(j < 0) return 1;
        if(i < 0 && j >= 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]) {
            return dp[i][j] = solve(i-1, j-1, s, t, dp) + solve(i-1, j, s, t, dp);
        }
        return dp[i][j] = solve(i-1, j, s, t, dp);
    }
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(n-1, m-1, s, t, dp);
    }
};

// Memoization - 1 based indexing
class Solution {
public:
    int solve(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
        // base case
        if(j == 0) return 1;
        if(i == 0 && j > 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i-1] == t[j-1]) {
            return dp[i][j] = solve(i-1, j-1, s, t, dp) + solve(i-1, j, s, t, dp);
        }
        return dp[i][j] = solve(i-1, j, s, t, dp);
    }
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return solve(n, m, s, t, dp);
    }
};
// TC -> O(N*M)
// SC -> O(N*M) + O(N+M)

// --------------------------------------------------------------------------------------------

// Tabulation
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<double>> dp(n+1, vector<double> (m+1, 0));

        for(int i=0; i<=n; i++) dp[i][0] = 1;
        // for(int j=1; j<=m; j++) dp[0][j] = 0;

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(s[i-1] == t[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return (int)dp[n][m];
    }
};
// TC -> O(N*M)
// SC -> O(N*M)

// --------------------------------------------------------------------------------------------

// Space Optimization
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<double> prev(m+1, 0), curr(m+1, 0);           // prev row and cur row

        prev[0] = curr[0] = 1;   

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(s[i-1] == t[j-1]) {
                    curr[j] = prev[j-1] + prev[j];
                }
                else {
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }
        return (int)prev[m];
    }
};
// used two arrays : prev and curr



// 1-D array optimization