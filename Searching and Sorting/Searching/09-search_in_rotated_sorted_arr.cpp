#include<bits/stdc++.h>
using namespace std;

// previous ques but with duplicates

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // tiny edge case to be handled
        // where a[low] == a[mid] == a[high]
        // if this condition is true,
        // it will not tell whether the sub part of array is leftsorted or rightsorted.
        int n = nums.size();
        int low = 0, high = n-1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(nums[mid] == target) return true;

            // handling the edge case
            // by shrinking the search space
            if(nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low = low + 1;
                high = high - 1;
                continue;
            }

            // check if left-sorted
            if(nums[low] <= nums[mid]) {
                // check if target lies in the left-sorted part
                // if it does, shrink the right part, as it is of no use
                if(nums[low] <= target && target <= nums[mid]) {
                    high = mid - 1;
                }
                else low = mid + 1;
            }
            // check if right-sorted
            else {
                // check if the target lies the right-sorted part
                // if it does, shrink the left part, as it is of no use
                if(nums[mid] <= target && target <= nums[high]) {
                    low = mid + 1;
                }
                else high = mid - 1;
            }
        }
        return false;
    }
};