// Given a collection of candidate numbers (candidates) and a target number (target), 
// find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void findCombinations(int ind, int target, vector<int>& arr, vector<vector<int>> &ans, vector<int> &ds) {
        if(ind == arr.size()) {
            if(target == 0) ans.push_back(ds);
            return;
        }

        if(arr[ind] <= target) {
            ds.push_back(arr[ind]);
            findCombinations(ind+1, target-arr[ind], arr, ans, ds);
            ds.pop_back();
        }
        findCombinations(ind+1, target, arr, ans, ds);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombinations(0, target, candidates, ans, ds);
        return ans;
    }
};

