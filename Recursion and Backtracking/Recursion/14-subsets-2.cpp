// Given an integer array nums that may contain duplicates, return all possible 
// subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void findSubsets(int ind, vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds) {
        ans.push_back(ds);
        for(int i=ind; i<n; i++) {
            if(i != ind && nums[i] == nums[i-1]) continue;
            ds.push_back(nums[i]);
            findSubsets(ind+1, nums, ds, ans);
            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        findSubsets(0, nums, ds, ans);
        return ans;
    }
};