class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        for(auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        queue<pair<int, pair<int, int>>> q;         // {stops, {node, cost}}
        vector<int> minCost(n, 1e9);
        q.push({0, {src, 0}});
        minCost[src] = 0;  

        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int nodeCost = it.second.second;

            if(stops > k) continue;         // if stops more than k, no need to check for adjacent nodes
            for(auto it : adj[node]) {
                int adjNode = it.first;
                int adjCost = it.second;
                if(nodeCost + adjCost < minCost[adjNode] && stops <= k) {
                    minCost[adjNode] = nodeCost + adjCost;
                    q.push({stops + 1, {adjNode, minCost[adjNode]}});
                } 
            }
        }      

        if(minCost[dst] == 1e9) return -1;
        return minCost[dst];
    }
};

// Time Complexity: O( N ) 
// Space Complexity:  O( |E| + |V| ) 