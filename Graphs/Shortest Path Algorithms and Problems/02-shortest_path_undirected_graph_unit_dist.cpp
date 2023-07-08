// APPROACH - 1
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> adj[N];
        for(int i=0; i<M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> dist(N, -1);
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto it : adj[node]) {
                if(dist[it] == -1) {
                    dist[it] = 1 + dist[node];
                    q.push(it);
                }
            }
        
        return dist;
    }
};
// TC : O(V+2E)
// SC : O(2V)

// APPROACH - 2
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> adj[N];
        for(int i=0; i<M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int> q;
        int dist[N] = {-1};
        dist[src] = 0;
        q.push(src);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto adjNode : adj[node]) {
                // relaxing of edges
                if(distance[node] + 1 < distance[adjNode]) {
                    distance[adjNode] = distance[node] + 1;
                    q.push(adjNode);
                }
            }
        }

        // vector<int> ans(N, -1);
        // for(int i=0; i<N; i++) {
        //     if(dist[i] != 1e9) {
        //         ans[i] = dist[i];
        //     }
        // }
        // return ans;

        return distance;
    }
};