// GFG
// connected components

/*
    Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid), 
    consisting of '0's (Water) and '1's(Land). 
    Find the number of islands.

    Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally 
    i.e., in all 8 directions.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid) {
        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // traverse in the neighbours and mark them if it's a land
            for(int delrow=-1; delrow<=1; delrow++) {
                for(int delcol=-1; delcol<=1; delcol++) {
                    int nrow = row + delrow;
                    int ncol = col + delcol;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }        
    }

    public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = gird[0].size();
        vector<vector<int>> vis(n, vector<int> (m,0));
        int count = 0;
        for(int row=0; row<n; row++) {
            for(int col=0; col<m; col++) {
                if(vis[row][col] == 0 && grid[row][col] == '1') {
                    count++;
                    bfs(row, col, vis, grid);
                }
            }
        }
        return count;
    }
};

/*
    SC -> O(N*2)
    TC -> O(N*M)
*/