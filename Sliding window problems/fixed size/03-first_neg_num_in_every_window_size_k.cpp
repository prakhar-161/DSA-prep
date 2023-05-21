// find first negative number in every window of size k in an array
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<int> firstNegativeNum(vector<int> &nums, int k) {
        int i = 0, j = 0;
        queue<int> q;
        vector<vector<int>> ans;
        while(j < nums.size()) {
            if(nums[j] < 0) {
                q.push(nums[j]);
            }

            if(j - i + 1 < k) j++;
            else if(j - i + 1 == k) {
                if(q.empty()) ans.push_back(0);
                else {
                    ans.push_back(q.front());
                    if(nums[i] == q.front()) {
                        q.pop();
                    }
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};