#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // Method - 2
        
    }
};


// Method - 1
// void setZeroes(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int m = matrix[0].size();
//         int row[n] = {0};
//         int col[m] = {0};
//         for(int i=0; i<n; i++) {
//             for(int j=0; j<m; j++) {
//                 if(matrix[i][j] == 0) {
//                     row[i] = 1;
//                     col[j] = 1;
//                 }
//             }
//         }

//         for(int i=0; i<n; i++) {
//             for(int j=0; j<m; j++) {
//                 if(row[i] || col[j]) {
//                     matrix[i][j] = 0;
//                 }
//             }
//         }
//     }