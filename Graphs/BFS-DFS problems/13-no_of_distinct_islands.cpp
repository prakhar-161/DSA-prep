// GFG

class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, vector<pair<int, int>>& vec, int row0, int col0) {
        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;
        vec.push({row - row0, col - col0});

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        for(int i=0; i<4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow >=0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0) {
                dfs(nrow, ncol, grid, vis, vec, row0, col0);
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        set<vector<pair<int, int>>> st;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && grid[i][j] == 1) {
                    vector<pair<int, int>> vec;
                    // n * m * 4
                    dfs(i, j, grid, vis, vec, i, j);
                    st.insert(vec);
                }
            }
        }

        // TC -> (N * M) + log(N*M) + (N * M * 4)
        // SC -> O(N * M)

        return st.size();
    }
};