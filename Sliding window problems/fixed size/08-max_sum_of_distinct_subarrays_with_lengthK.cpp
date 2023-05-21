// You are given an integer array nums and an integer k. 
// Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:
// The length of the subarray is k, and
// All the elements of the subarray are distinct.
// Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.

// Input: nums = [1,5,4,2,9,9,9], k = 3
// Output: 15
// Explanation: The subarrays of nums with length 3 are:
// - [1,5,4] which meets the requirements and has a sum of 10.
// - [5,4,2] which meets the requirements and has a sum of 11.
// - [4,2,9] which meets the requirements and has a sum of 15.
// - [2,9,9] which does not meet the requirements because the element 9 is repeated.
// - [9,9,9] which does not meet the requirements because the element 9 is repeated.
// We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int i = 0, j = 0;
        long long maxi = 0;
        long long sum = 0;
        
        while(j < nums.size()) {
            mp[nums[j]]++;
            sum += nums[j];
            
            if(j - i + 1 < k) j++;
            else if(j - i + 1 == k) {
                // the following condition works in the case when an element is repeating
                if(mp.size() == k) {
                    maxi = max(maxi, sum);
                }
                
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                
                sum = sum - nums[i];
                i++;
                j++;
            }
        }
        return maxi;
    }
};