#include<bits/stdc++.h>
using namespace std;

// 3 methods -> preference : M-3, M-2, M-1

// Method - 1
class Solution {
public:
    bool binarySearch(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(nums[mid] == target) return true;
            else if(nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        if(binarySearch(nums, target) == true) {
            int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
            int last = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
            return {first, last-1};
        } 
        return {-1, -1};    
    }
};

// Method - 2
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0) return {-1, -1};
        int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(first == n || nums[first] != target) return {-1, -1};
        int last = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

        return {first, last-1};
    }
};

// Method - 3
class Solution {
public:
    int firstOccurrence(vector<int>& nums, int n, int target) {
        int low = 0, high = n-1;
        int first = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] == target) {
                first = mid;
                high = mid - 1;
            }
            else if(nums[mid] < target) {
                low = mid + 1;
            } 
            else high = mid - 1;
        }
        return first;
    }

    int lastOccurrence(vector<int>& nums, int n, int target) {
        int low = 0, high = n-1;
        int last = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] == target) {
                last = mid;
                low = mid + 1;
            }
            else if(nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = firstOccurrence(nums, n, target);
        if(first == -1) return {-1, -1};
        int last = lastOccurrence(nums, n, target);
        return {first, last};
    }
};