
class Solution {
private: 
    // color a component and checks if bipartite or not
    bool checkBFS(int start, int V, vector<int>adj[], int color[]) {
        queue<int> q;
        q.push(start);
        color[start] = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto it : adj[node]) {
                // if the adjacent node is yet not colored
                // give the opposite color
                if(color[it] == -1) {   
                    color[it] != color[node];
                    q.push(it);
                } 
                // is the adjacent node has the same color as the node
                else if(color[it] == color[node]) {
                    return false;
                }
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
                if(checkBFS(i, V, adj, color) == false) return false;
            }
        }
        return true;
	}
};