// Number of Provinces
// Connected components
// GFG

/*
    Given an undirected graph with V vertices. 
    We say two vertices u and v belong to a single province if there is a path from u to v or v to u. 
    Your task is to find the number of provinces.
*/

class Solution {
    private:
    void dfs(int node, vector<int> adjLs[], vector<int> &vis) {
        vis[node] = 1;
        for(auto it : adjLs[node]) {
            if(!vis[it]) {
                dfs(it, adjLs, vis);
            }
        }
    }

    public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // making adjacency list
        // because input given is adjacency matrix

        // to change adjacency matrix to adjacency list
        vector<int> adjLs[V];
        for(int i=0; i<V; i++) {
            for(int j=0; j<V; j++) {
                if(adj[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            } 
        }

        vector<int> vis(V, 0);
        int count = 0;
        for(int i=0; i<V; i++) {
            if(vis[i] == 0) {
                count++;
                dfs(i, adjLs, vis);
            }
        }
        return count;
    }
};

// SC -> O(N) + O(N) 
// TC -> 