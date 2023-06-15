#include<bits/stdc++.h>
using namespace std;

// no duplicates
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int mini = INT_MAX;
        while(low <= high) {
            int mid = (low + high) / 2;
            // if left sorted
            if(nums[low] <= nums[mid]) {
                mini = min(mini, nums[low]);
                low = mid + 1;
            }
            // if right sorted
            else {
                mini = min(mini, nums[mid]);
                high = mid - 1;
            }
        }
        return mini;
    }
};