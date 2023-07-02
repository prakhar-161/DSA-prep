// Two types of problems of two-sum
// TYPE-1 : if the pair exist, print yes or no
// TYPE-2 : if the pair exist, return the indexes of the elements of the pair

// Below is the better solution for both types and optimal for type-2 specifically
// Using map
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for(int i=0; i<n; i++) {
            int curr = nums[i];
            int rem = target - curr;
            if(mpp.find(rem) != mpp.end()) {
                return {mpp[rem], i};
                // return "YES"
            }
            mpp[curr] = i;
        }
        return {-1, -1};
        // return "NO"
    }
};

// Below is the optimal solution for type-1
// TWO POINTER APPROACH
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        int sum = 0;
        while(left < right) {
            sum += nums[left] + nums[right];
            if(sum == target) {
                return "YES";
            }
            else if(sum < target) {
                left++;
            }
            else {
                right--;
            }
        }
        return "NO";
    }
};