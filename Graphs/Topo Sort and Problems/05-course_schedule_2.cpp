class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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

        vector<int> ans;
        while(!q.empty()) {
            int course = q.front();
            q.pop();
            ans.push_back(course);

            for(auto it : adj[course]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        if(ans.size() == numCourses) return ans;
        return {};
    }
};