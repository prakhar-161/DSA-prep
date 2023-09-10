// GFG
// Given a weighted, undirected and connected graph of V vertices and E edges. 
// The task is to find the sum of weights of the edges of the Minimum Spanning Tree.

// Since, this question only asks for the sum of weights of edges of MST,
// therefore we will only require MIN-HEAP (PQ) of the form pair<int, int> 
// If the MST was asked to be returned in form array, then we would have
// created the MIN-HEAP as pair<int, pair<int, int>> 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // pq -> {wt, node}
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(V, 0);
        
        pq.push({0, 0});
        int sum = 0;
        while(!pq.empty()) {
            auto it = pq.top();
            int wt = it.first;
            int node = it.second;
            pq.pop();
            
            if(vis[node]) continue;
            
            // since the node is not visited already
            // add its wt to the sum
            // and add it the to the mst if asked
            vis[node] = 1;
            sum += wt;
            
            for(auto it : adj[node]) {
                int adjNode = it[0];
                int edgeWt = it[1];
                if(!vis[adjNode]) {
                    pq.push({edgeWt, adjNode});
                }
            }
        }
        
        return sum;
    }
};