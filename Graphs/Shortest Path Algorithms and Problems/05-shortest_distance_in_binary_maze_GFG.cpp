// GFG

// Given a n * m matrix grid where each element can either be 0 or 1. 
// You need to find the shortest distance between a given source cell to a destination cell. 
// The path can only be created out of a cell if its value is 1. 
// If the path is not possible between source cell and destination cell, then return -1.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, <pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int> (m, 1e9));

        if(source.first == destination.first && source.second == destination.second) return 0;

        dist[source.first][source.second] = 0;
        q.push({0, {source.first, source.second}});

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while(!q.empty()) {
            int row = q.front().second.first;
            int col = q.front().second.second;
            int dis = q.front().first;
            q.pop();

            for(int i=0; i<4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && dis + 1 < dist[nrow][ncol]) {
                    dist[nrow][ncol] = 1 + dis;
                    if(nrow == destination.first && ncol == destination.second) {
                        return 1 + dis;
                    }
                    q.push({1 + dis, {nrow, ncol}});
                }
            }
        }
        return -1;
    }
};