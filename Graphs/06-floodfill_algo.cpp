//GFG
/*
    An image is represented by a 2-D array of integers, each integer representing the pixel value of the image.

    Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, 
    and a pixel value newColor, "flood fill" the image.

    To perform a "flood fill", consider the starting pixel, 
    plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, 
    plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. 
    Replace the color of all of the aforementioned pixels with the newColor.¸`
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    // DFS solution
    private: 
    void dfs(int row, int col,  vector<vector<int>> &ans, vector<vector<int>> &image, int iniColor, int newcolor, int delrow[], int delcol[]) {
        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();
        for(int i=0; i<4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol] != newColor && image[nrow][ncol] == iniColor) {
                // ans[nrow][ncol] != newColor -> this means that this particular index should not be coloured (or visited) already.
                dfs(nrow, ncol, ans, image, iniColor, newColor, delrow, delcol);
            }
        }
    }

    public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1}; 
        dfs(sr, sc, ans, iniColor, newColor, delrow, delcol, image);
        return ans;
    }
};

/*
    SC -> O(N*M)
    TC -> O(N*M)
*/

// BFS solution
// class Solution {
//     private:
//     void bfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>>& image, int newColor, 
//         int delRow[], int delCol[], int iniColor) {
//             ans[row][col] = newColor;
//             queue<pair<int, int>> q;
//             q.push({row, col});
//             int n = image.size();
//             int m = image[0].size();

//             while(!q.empty()) {
//                 int row = q.front().first;
//                 int col = q.front().second;
//                 q.pop();

//                 for(int i=0; i<4; i++) {
//                     int nrow = row + delRow[i];
//                     int ncol = col + delCol[i];

//                     if(image[nrow][ncol] == iniColor && nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol] != newColor) {
//                         ans[nrow][ncol] = newColor;
//                         q.push({nrow, ncol});
//                     }
//                 }
//             }
//         }

//     public:
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
//         int iniColor = image[sr][sc];
//         vector<vector<int>> ans = image;
//         int delRow[] = {-1, 0, 1, 0};
//         int delCol[] = {0, 1, 0, -1};
//         bfs(sr, sc, ans, image, newColor, delRow, delCol, iniColor);
//         return ans;
//     }
// }; 