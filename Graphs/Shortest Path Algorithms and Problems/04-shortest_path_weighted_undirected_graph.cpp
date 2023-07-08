
class Solution {
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<int>> adj[n+1];           // n+1 -> 1-based indexing
        for(auto it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n+1, 1e9), parent(n+1);
        for(int i=1; i<=n; i++) parent[i] = i;
        dist[1] = 0;
        pq.push({0, 1});
        
        while(!pq.empty()) {
            int node = pq.top().first;
            int dis = pq.top().second;
            pq.pop();
            
            // it[0] == adjNode
            // it[1] == wt
            for(auto it : adj[node]) {
                int adjNode = it.first;
                int wt = it.second;
                if(dis + wt < dist[adjNode]) {
                    dist[adjNode] = dis + wt;
                    pq.push({dis + wt, adjNode});
                    parent[adjNode] = node;
                } 
            }
        }
        
        // in case we were not able to reach the destination
        if(dist[n] == 1e9) return {-1};
        
        // for printing
        vector<int> shortestPath;
        int node = n;
        // O(V)
        while(parent[node] != node) {
            shortestPath.push_back(node);
            node = parent[node];
        }
        shortestPath.push_back(1);
        reverse(shortestPath.begin(), shortestPath.end());
        return shortestPath;
    }
};

// TC -> O(E*logV) + O(V)