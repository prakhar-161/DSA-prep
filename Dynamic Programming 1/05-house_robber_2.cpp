#include <bits/stdc++.h>
using namespace std;

// HOUSE ROBBER - 2
// Leetcode
// All houses at this place are arranged in a circle

class Solution
{
public:
    // Memoization
    int findMaxSum(vector<int> &arr)
    {   
        int n = arr.size();
        int dp[n];
        dp[0] = arr[0];
        int neg = 0;

        for (int i = 1; i < n; i++)
        {
            int pick = arr[i];
            if (i > 1)
            {
                pick += dp[i - 2];
            }
            int notpick = 0 + dp[i - 1];

            dp[i] = max(pick, notpick);
        }
        return dp[n - 1];
    }

    int rob(vector<int> &arr)
    {   
        int n = arr.size();
        vector<int> temp1, temp2;
        if(n == 1) return arr[0];
        for(int i=0; i<n; i++) {
            if(i!=0) temp1.push_back(arr[i]);
            if(i!=n-1) temp2.push_back(arr[i]);
        }

        return max(findMaxSum(temp1), findMaxSum(temp2));
    }
};
