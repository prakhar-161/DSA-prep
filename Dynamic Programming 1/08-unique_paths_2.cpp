#include <bits/stdc++.h>
using namespace std;

// LEETCODE
// An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

// Memoization
int mod = (int)(1e9 + 7);
int f(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
    if(i>=0 && j>=0 && obstacleGrid[i][j] == 1) return 0;
    if(i==0 && j==0) return 1;
    if(i<0 || j<0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int up = f(i-1,j,dp);
    int left = f(i,j-1,dp);

    return dp[i][j] = (up+left) % mod;
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int> (n, -1));
    return f(m-1, n-1, obstacleGrid, dp);
}