// Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). 
// Find all possible paths that the rat can take to reach from source to destination. 
// The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right).
// Value 0 at a cell in the matrix represents that it is blocked and 
// rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
// Note: In a path, no cell can be visited more than one time. 
// If the source cell is 0, the rat cannot move to any other cell.

// https://www.youtube.com/watch?v=bLGZhJlt4y0&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=20

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void findPathHelper(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string move, vector<vector<int>> &vis) {
        if (i == n - 1 && j == n - 1) {
            ans.push_back(move);
            return;
        }

        // downward
        if (i + 1 < n && !vis[i + 1][j] && a[i + 1][j] == 1) {
            vis[i][j] = 1;
            findPathHelper(i + 1, j, a, n, ans, move + 'D', vis);
            vis[i][j] = 0;
        }

        // left
        if (j - 1 >= 0 && !vis[i][j - 1] && a[i][j - 1] == 1) {
            vis[i][j] = 1;
            findPathHelper(i, j - 1, a, n, ans, move + 'L', vis);
            vis[i][j] = 0;
        }

        // right 
        if (j + 1 < n && !vis[i][j + 1] && a[i][j + 1] == 1) {
            vis[i][j] = 1;
            findPathHelper(i, j + 1, a, n, ans, move + 'R', vis);
            vis[i][j] = 0;
        }

        // upward
        if (i - 1 >= 0 && !vis[i - 1][j] && a[i - 1][j] == 1) {
            vis[i][j] = 1;
            findPathHelper(i - 1, j, a, n, ans, move + 'U', vis);
            vis[i][j] = 0;
        }
    }

    vector<string> findPath(vector < vector < int >> & m, int n) {
        vector<string> ans;
        vector<vector<int>> vis(n, vector < int > (n, 0));

        if (m[0][0] == 1) findPathHelper(0, 0, m, n, ans, "", vis);
        return ans;
    }
};