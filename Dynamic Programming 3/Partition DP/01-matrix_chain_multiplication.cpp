#include<bits/stdc++.h>
using namespace std;

//  no. of operations = A[i-1] * A[k] * A[j]

// Memoization
int solve(int i, int j, vector<int> &arr, vector<vector<int>> &dp) {
    if(i == j) return 0;

    if(dp[i][j] == -1) return dp[i][j];

    int mini = 1e9;
    for(int k = i; k < j; k++) {            // k goes from i to j-1
        int steps = (arr[i-1] * arr[k] * arr[j]) + f(i, k, arr, dp) + f(k+1, j, arr, dp);
        if(steps < mini) mini = steps;
    }
    return dp[i][j] = mini;
}

int matrixMultiplication(vector<int> &arr, int N) {
    vector<vector<int>> dp(N, vector<int> (N, -1));
    return solve(1, N-1, arr, dp);
}
// TC -> O(N**3)
// SC -> O(N**2) + O(N)

int matrixMultiplication(vector<int> &arr, int N) {
    int dp[N][N];
    for(int i=1; i<N; i++) dp[i][i] = 0;
    for(int i=N-1; i>=1; i--) {
        for(int j=i+1; j<N; j++) {
            int mini = 1e9;
            for(int k=i; k<j; k++) {
                int steps = (arr[i-1] * arr[k] * arr[j]) + dp[i][k] + dp[k+1][j];
                mini = min(steps, mini);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][N-1];

}
