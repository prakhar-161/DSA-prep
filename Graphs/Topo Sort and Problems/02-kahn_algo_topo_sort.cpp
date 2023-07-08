// BFS
// KAHN'S ALGORITHM - TOPOLOGICAL SORTING

class Solution {
    public:
    vector<int> topoSort(int V, vector<int> adj[]) {
        int indegree[V] = {0};
        // filling the indegree array
        for(int i=0; i<V; i++) {
            for(auto it : adj[i]) {
                indegree[it]++;
            }
        }

        // adding the nodes into the queue whose indegree is 0
        queue<int> q;
        for(int i=0; i<V; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        // traverse to  node's adjacent nodes and reduce the indegree of every adjacent node
        // and if indegree becomes 0 anytime for an adjacent node
        // we push that adj node into the queue
        vector<int> ans;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        return ans;
    }
};