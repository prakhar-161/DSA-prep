// GFG
// Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.
// bfs

#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    bool detectBFS(int src, vector<int> adj[], int vis[]) {
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});
        while(!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto it : adj[node]) {
                if(!vis[it]) {
                    vis[it] = 1;
                    q.push({it, node});
                }
                // IMPORTANT
                else if(parent != it) {
                    return true;
                }
            }
        }
        return false;
    }

    public:
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                if(detectBFS(i, adj, vis)) return true;
            }
        }
        return false;
    }
};

/*
    TC -> O(N+2*E) + O(N)
    SC -> O(N)
*/