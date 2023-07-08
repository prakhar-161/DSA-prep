
// BELLMAN FORD ALGORITHM
// It can be applied for the graphs which contain negative weights and cycles
// The relaxation of edges is done 'N-1' times where N is the no. of nodes

// Why relaxation is done 'N-1' times?
// because since in a graph of N nodes, in worst case,
// we will take N-1 edges to reach from the first to last,
// thereby we iterate for N-1 iterations

// How to detect negative cycles?
// On Nth iteration, the relaxation will be done and 
// if the dist array gets updated(reduced) 
// Therefore, negative cycle exist

class Solution {
public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        // O(V*E)
        for(int i=0; i<V; i++) {
            for(auto it : edges) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if(dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        // checking for negative cycle - Nth relaxation
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                return {-1};
            }
        }
        return dist;
    }
};

// This algorithm takes a bit more time than Dijkstra but it can detect negative cycles too and handle negative weights.