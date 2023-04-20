#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mpp;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            int num = nums[i];
            int more = target - num;
            if(mpp.find(num) != mpp.end()) {
                return {mpp[more], i};
            }
            mpp[num] = i;
        }
        return {-1, -1};
    }
};

// Most Optimal for bool
// int left = 0, right = n-1;
// sort(nums.begin(), nums.end());
// while(left >= right) {
//     int sum = nums[left] + nums[right];
//     if(sum < target) left++;
//     else if(sum > target) right--;
//     else return true;
// } 
// return false;

// bool
// map<int, int> mpp;
// int n = nums.size();
// for(int i=0; i<n; i++) {
//     int ele = nums[i];
//     int more = target - ele;
//     if(mpp.find(more) != mpp.end()) {
//         return true;
//     }
//     mpp[ele] = i;
// }
// return false;