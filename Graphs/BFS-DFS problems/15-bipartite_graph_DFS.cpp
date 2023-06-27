class Solution {
private: 
    // color a component and checks if bipartite or not
    bool checkDFS(int node, int col, vector<int>adj[], int color[]) {
        color[node] = 0;

        for(auto it : adj[node]) {
            // if the adjacent node is yet not colored
            // give the opposite color
            if(color[it] == -1) {   
                if(checkDFS(it, !col, adj, color) == false) return false;
            } 
            // is the adjacent node has the same color as the node
            else if(color[it] == col) {                 // color[it] == color[node]
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(int V, vector<int>adj[]){
        // 0-based indexing
	    int color = [V];
        for(int i=0; i<V; i++) color[i] = -1;

        for(int i=0; i<v; i++) {
            if(color[i] == -1) {
                if(checkDFS(i, V, adj, color) == false) return false;
            }
        }
        return true;
	}
};