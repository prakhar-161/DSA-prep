// Given an array nums of distinct integers, return all the possible permutations.
// answer can be in any order
#include<bits/stdc++.h>
using namespace std;

// APPROACH - 2 (easy approach)
class Solution {
public:
    void recurPermute(int ind, vector<int>& nums, vector<vector<int>>& ans) {
        if(ind == nums.size()) {
            ans.push_back(nums[i]);
            return;
        }

        for(int i=ind; i<nums.size(); i++) {
            swap(nums[ind], nums[i]);
            recurPermute(ind+1, nums, ans);
            swap(nums[ind], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        recurPermute(0, nums, ans);
        return ans;
    }
};

// APPROACH - 1
class Solution {
public:
    void recurPermute(vector<int> &ds, vector<int>& nums, vector<vector<int>>& ans, int freq[]) {
        if(ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }

        for(int i=0; i<nums.size(); i++) {
            if(!freq[i]) {
                freq[i] = 1;
                ds.push_back(nums[i]);
                recurPermute(ds, nums, ans, freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[nums.size()];
        for(int i=0; i<nums.size(); i++) freq[i] = 0;
        recurPermute(ds, nums, ans, freq);
        return ans;
    }
};

// TC -> O(N! * N)
// SC -> O(N) + O(N)
// ASC -> O(N)