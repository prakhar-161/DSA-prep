#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    void dfs(int node, vector<int> adj[], int vis[], vector<int> &ans) {
        vis[node] = 1;
        ans.push_back(node);
        // traverse all its neighbours
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it, adj, vis, ans);
            }
        }
    }

    public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0};               // 0-based indexing graph
        int start = 0;
        vector<int> ans;
        dfs(start, adj, vis, ans);
        return ans;
    }
};

/*
    SC -> O(N)
    TC -> O(N + 2*E)
*/