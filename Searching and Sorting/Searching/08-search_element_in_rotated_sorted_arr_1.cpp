#include<bits/stdc++.h>
using namespace std;

// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) 
// such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
// For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, 
// return the index of target if it is in nums, or -1 if it is not in nums.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(nums[mid] == target) return mid;

            // check if left-sorted
            if(nums[low] <= nums[mid]) {
                if(nums[low] <= target && target <= nums[mid]) {
                    high = mid - 1;
                }
                else low = mid + 1;
            }
            else {
                if(nums[mid] <= target && target <= nums[high]) {
                    low = mid + 1;
                }
                else high = mid - 1;
            }
        }
        return -1;
    }
};

// APPROACH

// if the left half is sorted, we will check if we have the target element is present in the left half. 
// If it is there, then we trim down the right half, else we trim down the left half.

// if the right half is sorted, we will check if the target element is present in the right half.
// If it is there, then we trim the left half otherwise we trim down the right half.