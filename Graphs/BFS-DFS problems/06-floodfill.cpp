class Solution {
public:
    void bfs(int row, int col, int color, int iniColor, vector<vector<int>> &ans, vector<vector<int>>& image) {
        ans[row][col] = color;
        int m = image.size();
        int n = image[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});
        
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, 1, 0, -1};
            for(int i=0; i<4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && image[nrow][ncol] == iniColor && ans[nrow][ncol] != color) {
                    ans[nrow][ncol] = color;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        
        bfs(sr, sc, color, iniColor, ans, image);
        return ans;
    }
};