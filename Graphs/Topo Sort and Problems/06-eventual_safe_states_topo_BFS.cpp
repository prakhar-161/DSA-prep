// A node is a terminal node if there are no outgoing edges. 
// A node is a safe node if every possible path starting from that node leads to a terminal node.
// You have to return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.


// the intuition is to figure out the nodes which are neither a part of a cycle nor connected to the cycle
class Solution {
    public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> adjRev[V];
        int indegree[V] = {0};
        for(int i=0; i<V; i++) {
            //  i -> it
            for(auto it : adj[i]) {
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        for(int i=0; i<V; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> safeNodes;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for(auto it : adjRev[node]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};

// Question explanation of example
// if we dont reverse the edges then 11 gets added to safe sequence which is wrong, 
// now if we reverse the edges, the edges which are  not a part of a cycle or dont lead to cycle still do the same, 
// but in reverse direction (hence they will still be a part of safe sequence) , 
// but nodes like 11 which lead to a cycle earlier ,
// now wont get added since we are doing a topological ordering on this reversed graph and its degree will never be zero