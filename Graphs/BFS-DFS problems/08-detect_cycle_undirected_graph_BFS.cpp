class Solution {
private:
    bool detectCycleBFS(int src, vector<int> adj[], int vis[]) {
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});              // node, parent
        while(!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for(auto adjacentNode : adj[node]) {
                if(!vis[adjacentNode]) {
                    vis[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                }
                // if visited already
                else if(vis[adjacentNode] &&  adjacentNode != parent) {
                    return true;
                }
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        // 0-based indexing
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                if(detectCycleBFS(i, adj, vis) == true) return true;
            }
        }
        return false;
    }
};