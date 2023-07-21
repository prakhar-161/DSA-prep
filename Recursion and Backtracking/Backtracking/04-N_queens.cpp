#include<bits/stdc++.h>
using namespace std;

// APPROACH - 2
// TC -> O(N!*N)
// SC -> O(N)
class Solution {
public:
    void solve(int col, vector<string> &board,  vector<vector<string>> &ans, vector<int> &leftRow, vector<int> &lowerDiagonal, vector<int> &upperDiagonal, int n) {
        if(col == n) {
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++) {
            if(leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;
                solve(col + 1, board, ans, leftRow, lowerDiagonal, upperDiagonal, n);
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i=0; i<n; i++) {
            board[i] = s;
        }
        vector<int> leftRow(n, 0), lowerDiagonal(2*n-1, 0), upperDiagonal(2*n-1, 0);
        solve(0, board, ans, leftRow, lowerDiagonal, upperDiagonal);
        return ans;
    }
};


// APPROACH - 1
// TC -> O(N!*N)
// SC -> O(N^2)
class Solution {
public:
    bool isSafe(int row, int col, vector<string> board, int n) {
        // check upper diagonal
        int duprow = row;
        int dupcol = col;

        while(row >= 0 && col >= 0) {
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }

        row = duprow;
        col = dupcol;
        while(col >= 0) {
            if(board[row][col] == 'Q') return false;
            col--;
        }

        row = duprow;
        col = dupcol;
        while(row >= 0 && col >= 0) {
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }

        return true;
    }

    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n) {
        if(col == n) {
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++) {
            if(isSafe(row, col, board, n) == true) {
                board[row][col] = 'Q';
                solve(col+1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i=0; i<n; i++) {
            board[i] = s;
        }
        solve(0, board, ans, n);
        return ans;
    }
};