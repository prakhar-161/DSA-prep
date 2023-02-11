// GFG
// Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.
// dfs

#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    bool detectDFS(int node, int parent, vector<int> adj[], int vis[]) {
        vis[node] = 1;
        for(auto adjNode : adj[node]) {
            if(vis[adjNode] == 0) {
                if(detectDFS(adjNode, node, adj, vis) == true) return true;
            }
            else if(adjNode != parent) {
                return true;
            }
        }
        return false;
    }

    public:
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                if(detectDFS(i, -1, adj, vis)) return true;
            }
        }
        return false;
    }
};