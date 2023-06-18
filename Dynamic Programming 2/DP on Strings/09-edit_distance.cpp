// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
// You have the following three operations permitted on a word:
// Insert a character
// Delete a character
// Replace a character

// f(i, j-1) + 1    -- insert operation (hypothetically inserting after i and matching that with j and 
//                    reducing j and i stays where it was
// f(i-1, j) + 1    -- delete operation (delete letter in i and decrease the word length to i-1)
// f(i-1, j-1) + 1  -- replace operation

// Memoization - 1 base indexing solution
class Solution {
public:
    int solve(int i, int j, string &word1, string &word2, vector<vector<int>> &dp) {
        // base case
        if(i == 0) return j;
        if(j == 0) return i;
        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i-1] == word2[j-1]) {
            return dp[i][j] = solve(i-1, j-1, word1, word2, dp);
        }
        return min(1 + solve(i, j-1, word1, word2, dp), min(1 + solve(i-1, j, word1, word2, dp), 1 + solve(i-1, j-1, word1, word2, dp)));
    }

    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return solve(n, m, word1, word2, dp);
    }
};
// TC -> O(N*M)
// SC -> O(N*M) + O(N+M)

// -----------------------------------------------------------------------------------------------

// Tabulation
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        // base case
        for(int j=0; j<=m; j++) dp[0][j] = j;
        for(int i=0; i<=n; i++) dp[i][0] = i;

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = min(1 + dp[i][j-1], min(1 + dp[i-1][j], 1 + dp[i-1][j-1]));
                }
            }
        }
        return dp[n][m];
    }
};
// TC -> O(N*M)
// SC -> O(N*M)

// -----------------------------------------------------------------------------------------------

// Space Optimization
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<int> prev(m+1, 0), cur(m+1, 0);
        // base case
        for(int j=0; j<=m; j++) prev[j] = j;

        for(int i=1; i<=n; i++) {
            cur[0] = i;                 // important edge case
            for(int j=1; j<=m; j++) {
                if(word1[i-1] == word2[j-1]) {
                    cur[j] = prev[j-1];
                }
                else {
                    cur[j] = min(1 + cur[j-1], min(1 + prev[j], 1 + prev[j-1]));
                }
            }
            prev = cur;
        }
        return prev[m];
    }
};

// Can we 1-d space optimise this?  NO, because the we are dependent on the prev state of the cur.