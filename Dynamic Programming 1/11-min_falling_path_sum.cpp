#include <bits/stdc++.h>
using namespace std;

// Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
// A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. 
// Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

// Memoization
int f(int i, int j, vector<vector<int>>& mat, vector<vector<int>> &dp) {
    if(j<0 || j>=n) return 1e9;
    if(i == 0) return mat[0][j];

    if(dp[i][j] != -1) return dp[i][j];

    int ups = mat[i][j] + f(i-1, j, mat, dp);
    int upld = mat[i][j] + f(i-1, j-1, mat, dp);
    int uprd = mat[i][j] + f(i-1, j+1, mat, dp);

    return dp[i][j] = min(ups, min(upld, uprd));
}

int minFallingPathSum(vector<vector<int>>& mat) {
    int n = mat.size();  
    vector<vector<int>> dp(n, vector<int> (n, -1));

    int mini = 1e9;
    for(int col = 0; col < n; col++) {
        mini = min(mini, f(n-1, col, mat, dp));
    }

    return mini;
}

// Tabulation
int maxFallingPathSum(vector<vector<int>>& mat) {
    int n = mat.size();
    vector<vector<int>> dp(n, vector<int> (n, 0));

    for(int j=0; j<n; j++) dp[0][j] = mat[0][j];
    for(int i=1; i<n; i++) {
        for(int j=0; j<n; j++) {
            int ups = mat[i][j] + dp[i-1][j];
            int upld = mat[i][j]
            if(j-1 >= 0) upld += dp[i-1][j-1];
            else upld += -1e8;
            int uprd = mat[i][j];
            if(j+1 < n) uprd += dp[i-1][j+1];
            else uprd += -1e8;

            dp[i][j] = min(ups, min(upld, uprd));
        }
    }
    int maxi = -1e8;
    for(int j=0; j<n; j++) { 
        maxi = max(maxi, dp[n-1][j]);
    }

    return maxi;
}
