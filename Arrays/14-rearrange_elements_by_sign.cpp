#include<bits/stdc++.h>
using namespace std;

// ----------------------------------------------- TYPE - 1 ------------------------------------------------------
// BRUTE
// TC -> O(2*N)
// SC -> O(N)
// size : pos => n/2, neg => n/2
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] > 0) {
                pos.push_back(nums[i]);
            else 
                neg.push_back(nums[i]);
        }

        // pos, neg
        for(int i=0; i<nums.size()/2; i++) {
            nums[2*i] = pos[i];
            nums[2*i+1] = neg[i];
        }

        return nums;
    }
};

// OPTIMAL
// TC -> O(N)
// SC -> O(N)
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int posIndex = 0, negIndex = 1;
        for(int i=0; i<n; i++) {
            if(nums[i] > 0) {
                ans[posIndex] = nums[i];
                posIndex += 2;
            }
            else {
                ans[negIndex] = nums[i];
                negIndex += 2;
            }
        }
        return ans;
    }
};

// ----------------------------------------------- TYPE - 2 ------------------------------------------------------ 
// WHEN THE NUMBER OF POSITIVES AND NEGATIVES ARE NOT EQUAL
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] > 0) pos.push_back(nums[i]);
            else neg[i].push_back(nums[i]);
        }

        if(pos.size() < neg.size()) {
            for(int i=0; i<pos.size(); i++) {
                nums[2*i] = pos[i];
                nums[2*i+1] = neg[i];
            }
            int numIndex = pos.size();
            for(int i=pos.size(); i<neg.size(); i++) {
                nums[numIndex] = neg[i];
                numIndex++;
            }
        }
        else {
            for(int i=0; i<neg.size(); i++) {
                nums[2*i] = pos[i];
                nums[2*i+1] = neg[i];
            }
            int numIndex = neg.size();
            for(int i=neg.size(); i<pos.size(); i++) {
                nums[numIndex] = pos[i];
                numIndex++;
            }
        }
        return nums;
    }
};