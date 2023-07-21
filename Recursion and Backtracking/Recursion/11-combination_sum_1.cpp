// Given an array of distinct integers and a target, you have to return the list of all unique combinations where the chosen numbers sum to target. You may return the combinations in any order.
// The same number may be chosen from the given array an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
// It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void findCombinations(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds) {
        if(ind == arr.size()) {
            if(target == 0) {
                ans.push_back(ds);
            }
            return;
        }

        // pick
        if(arr[ind] <= target) {
            ds.push_back(arr[ind]);
            findCombinations(ind, target-arr[ind], arr, ans, ds);
            ds.pop_back();
        }
        // not pick
        findCombinations(ind+1, target, arr, ans, ds);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombinations(0, target, candidates, ans, ds);
        return ans;
    }
};