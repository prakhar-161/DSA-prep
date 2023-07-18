#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> mergeKArrays(vector<vector<int>> arr, int K){
        vector<int> ans;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        // inserting the first elements of all 'k' arrays
        for(int i=0; i<k; i++) {
            pq.push({arr[i][0], {i, 0}});
        }

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int ele = it.first;
            int apos = it.second.first;
            int epos = it.second.second;

            ans.push(ele);
            // edge case
            if(epos + 1 < arr[apos].size()) {
                q.push({arr[apos][epos+1], {apos, epos + 1}});
            }
        }
        return ans;
    }
};