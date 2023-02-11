// GFG
// Google
// Given a matrix mat of size N x M where every element is either O or X.
// Replace all O with X that are surrounded by X.
// A O (or a set of O) is considered to be surrounded by X if there are X at locations just below, just above, just left and just right of it.


#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    void dfs(int row, int col, vector<vector<char>> &mat, vector<vector<int>> &vis, int delrow[], int delcol[]) {
        vis[row][col] = 1;
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0; i<4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && mat[nrow][ncol] == 'O' && vis[nrow][ncol] == 0) {
                dfs(nrow, ncol, mat, vis, delrow, delcol);
            }
        }
    } 

    public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat) {
        vector<vector<int>> vis(n, vector<int> (m, 0));
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        // traverse first row and last row
        for(int j=0; j<m; i++) {
            // first row
            if(mat[0][j] == 'O' && vis[0][j] == 0) {
                dfs(0, j, mat, vis, delrow, delcol);
            }
            // last row
            if(mat[n-1][j] == 'O' && vis[n-1][j] == 0) {
                dfs(n-1, j, mat, vis, delrow, delcol);
            }
        }

        // traverse first column and last column 
        for(int i=0; i<n; i++) {
            // first column
            if(mat[i][0] == 'O' && vis[i][0] == 0) {
                dfs(i, 0, mat, vis, delrow, delcol);
            }
            // last column
            if(mat[i][n-1] == 'O' && vis[i][n-1] == 0) {
                dfs(i, n-1, mat, vis, delrow, delcol);
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(vis[i][j] != 1 && mat[i][j] == 'O') {
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};

/*
    TC -> O(N*M)
    SC -> O(N*M)
*/