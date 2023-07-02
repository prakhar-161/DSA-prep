#include<bits/stdc++.h>
using namespace std;

// BRUTE
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans[n][n];
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                ans[j][n-1] = matrix[i][j];
            }
        }
        return ans;
    }
};

// OPTIMAL 
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // transpose of matrix
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reverse every row
        for(int i=0; i<n; i++) {
            // mat[i] is row
            reverse(matrix[i].begin(), matrix[i].end());
        }

    }
};