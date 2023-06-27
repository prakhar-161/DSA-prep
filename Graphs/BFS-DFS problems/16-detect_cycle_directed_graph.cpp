// DFS

class Solution {
private: 
    bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[]) {
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto it : adj[node]) {
            // when the node is not visited
            if(!vis[it]) {
                if(dfsCheck(it, adj, vis, pathVis) == true) return true;
            }
            // when the node is visited
            else if(pathVis[it] == 1) {         // vis[it] == 1 && pathVis[it] == 1
                return true;
            }
        }

        pathVis[node] = 0;
        return false;
    }

public:
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V] = {0};
        int pathVis[0] = {0};

        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                if(dfsCheck(i, adj, vis, pathVis) == true) return true;
            }
        }
        return false;
    }
};