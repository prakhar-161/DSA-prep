#include<bits/stdc++.h>
using namespace std;

// answer is simply the index of the min. element in array
// because it is the rotating point 

class Solution {
public:
    int findRotations(vector<int> &nums) {
        int low = 0, high = nums.size() - 1;
        int index = 0;
        while(low <= high) {
            int mid = (low + high) / 2;
            // if left sorted
            if(nums[low] <= nums[mid]) {
                mini = min(mini, nums[low]);
                index = low;
                low = mid + 1;
            }
            // if right sorted
            else {
                mini = min(mini, nums[mid]);
                index = mid;
                high = mid - 1;
            }
        }
        return index;
    }
};