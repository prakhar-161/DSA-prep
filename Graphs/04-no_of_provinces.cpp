#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int vis[201] = {0};
    void dfs(int node,  vector<int> adjLs[], int vis[]) {
        vis[node] = 1;
        for(auto it : adjLs[node]) {
            if(!vis[it]) {
                dfs(it, adjLs, vis);
            }
        }    
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> adjLs[V];
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(isConnected[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        
        int count = 0;
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                count++;
                dfs(i, adjLs, vis);
            }
        }
        
        return count;
    }
};

// TC -> O(N) + O(V+2E) ~ O(N)
// SC -> O(N) + O(N) ~ O(N)