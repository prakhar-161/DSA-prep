#include <bits/stdc++.h>
using namespace std;

// LEETCODE
// Given a m x n grid filled with non-negative numbers, 
// find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int> (n, -1));

    int mini = INT_MAX;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(i==0 && j==0) {
                dp[i][i] = grid[i][j];
            }
            else {
                int upSum = 0, leftSum = 0;
                if(i>0) upSum = grid[i][j] + dp[i-1][j];
                if(j>0) leftSum = grid[i][j] + dp[i][j-1];

                mini = min(mini, upSum + leftSum);
            }
        }
    }   
    return mini;     
}