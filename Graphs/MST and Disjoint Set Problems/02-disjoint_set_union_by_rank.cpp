#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n+1, 0);
        rank.resize(n+1);
        for(int i=0; i<=n; i++) {
            parent[i] = i;
        }
    }

    // path compression
    // find ultimate parent
    int findUPar(int node) {
        if(node = parent[node]) {
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ultp_u = findUPar(u);
        int ultp_v = findUPar(v);
        if(ultp_u == ultp_v) return;        // belonging to the same component

        if(rank[ultp_u] < rank[ultp_v]) {
            parent[ultp_u] = ultp_v;
        }
        else if(rank[ultp_u] > rank[ultp_v]) {
            parent[ultp_v] = ultp_u;
        }
        else {
            parent[ultp_v] = ultp_u;
            rank[ultp_u]++;
        }
    }
};

int main() {
    DisjointSet ds;
    
}