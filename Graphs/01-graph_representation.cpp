#include<bits/stdc++.h>
using namespace std;

// For Undirected graph
// SC -> O(2E)
int main() {
    int n, m;
    // n - nodes, m - edges
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

// For Directed graph
// SC -> O(E)
int main() {
    int n, m;
    // n - nodes, m - edges
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }
}