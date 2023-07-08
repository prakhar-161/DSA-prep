#include<bits/stdc++.h>
using namespace std;

// PRIORITY QUEUE METHOD
class Solution {
public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        priority_queue <<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V);
        for(int i=0; i<V; i++) dist[i] = 1e9;

        dist[S] = 0;
        q.push({0, S});
        while(!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : adj[node]) {
                int adjNode = it.first;
                int wt = it.second;
                if(dis + wt < dist[adjNode]) {
                    dist[adjNode] = dis + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};

// SET METHOD
class Solution {
public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        set<pair<int, int>> st;
        for(int i=0; i<V; i++) dist[i] = 1e9;

        dist[S] = 0;
        st.insert({0, S});
        while(!st.empty()) {
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);

            for(auto it : adj[node]) {
                int adjNode = it[0];
                int wt = it[1];
                if(dis + wt < dist[adjNode]) {
                    if(dist[adjNode] != 1e9) {
                        st.erase({dist[adjNode], adjNode});
                    }
                    dist[adjNode] = dis + wt;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};