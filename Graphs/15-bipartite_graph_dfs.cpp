// GFG
// Given an adjacency list of a graph adj  of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.

#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    bool checkDFS(int node, int col, vector<int>adj[], int color[]) {
        color[node] = col;
        for(auto it : adj[node]) {
            // yet not coloured
            if(color[it] == -1) {
                if(dfs(it, !col, adj, color)) return true;
            }
            else if(color[it] == col) {
                return false;
            }
        }
        return true;
    }

    public:
    bool isBipartite(int V, vector<int>adj[]) {
        int color[V];
        for(int i=0; i<V; i++) color[i] = -1;

        for(int i=0; i<V; i++) {
            if(color[i] == -1) {
                if(!checkDFS(i, 0, adj, color)) return false;
            }
        }
        return true;
    }
};