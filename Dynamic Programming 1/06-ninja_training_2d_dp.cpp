#include <bits/stdc++.h>
using namespace std;

// Memoization
int f(int day, int last, vector<vector<int>> &points,  vector<vector<int>>& dp) {
    if(day == 0) {
        int maxi = 0;
        for(int task = 0; task < 3; task++) {
            if(task != last) {
                maxi = max(maxi, task);
            }
        }
        return maxi;
    }

    if(dp[day][last] != -1) return dp[day][last];

    int maxi = 0;
    for(int task = 0; task < 3; task++) {
        if(task != last) {
            int point = points[day][task] + f(day-1, task, points, dp);
            maxi = max(maxi, point);
        }
    }

    return dp[day][last] = maxi; 
}

int ninjaTraining(int n, vector<vector<int>> &points) {
    vector<vector<int>> dp(n, vector<int> (4, -1));
    return f(n-1, 3, points, dp);
}

// Tabulation
int ninjaTraining(int n, vector<vector<int>> &points) {
    int dp[n][4];
    // base case
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for(int day = 1; day < n; day++) {
        for(int last = 0; last < 4; last++) {
            dp[day][last] = 0;
            int maxi = 0;
            for(int task = 0; task < 3; task++) {
                if(task != last) {
                    int point = points[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }
    return dp[n-1][3];
}