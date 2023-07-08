class Solution {
public:
    // similar concept to cycle detection in directed graph using kahn's algorithm
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // indegree = 0 for prerequisites[i][1]
        // indegree increase for prerequisites[i][0]
        // example: [2,1] == 1 -> {2}
        // to take 2, we have to complete 1, so in graph, 1 should come before 2
        
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses, 0);
        for(vector<int> v : prerequisites) {
            // [1,0] == 0 -> {1}
            adj[v[1]].push_back(v[0]);
            indegree[v[0]]++;
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        int cnt = 0;
        while(!q.empty()) {
            int course = q.front();
            q.pop();
            cnt++;

            for(auto it : adj[course]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        if(cnt == numCourses) {
            // means no cycle so course will be completed
            return true;
        } 
        // means there is a cycle in graph so it is impossible to complete the course
        return false;
    }
};