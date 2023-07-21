// Given a list arr of N integers, print sums of all subsets in it.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void findSubsetSums(int ind, int sum, vector<int> &arr, vector<int> &ans) {
        if(ind == arr.size()) {
            ans.push_back(sum);
            return;
        }

        // pick
        findSubsetSums(ind+1, sum + arr[ind], arr, ans);
        // notpick
        findSubsetSums(ind+1, sum, arr, ans);
    }

    vector<int> subsetSums(vector<int> arr, int N) {
        vector<int> ans;
        findSubsetSums(0, 0, arr, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};