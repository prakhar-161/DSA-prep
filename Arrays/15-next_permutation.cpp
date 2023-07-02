class Solution {
public:
    vector<int> nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        // first step
        // figure out the breakpoint
        // breakpoint can go upto index = n-2
        int ind = -1;
        for(int i=n-2; i>=0; i--) {
            if(nums[i] < nums[i+1]) {
                ind = i;
                break;
            }
        }

        if(ind == -1) {
            reverse(nums.begin(), nums.end());
            return nums;
        }
            
        // second step
        // figure out the element just greater than the breakpoint element from right
        for(int i=n-1; i>ind; i--) {
            if(nums[i] > nums[ind]) {
                swap(nums[i], nums[ind]);
                break;
            }
        }

        // third step
        // reverse the array from after the breakpoint till the end as there was no dip
        reverse(nums.begin() + ind + 1, nums.end());
    }
};

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;
        for(int i=n-2;i>=0;i--) {
            if(nums[i]<nums[i+1]) {
                ind=i;
                break;
            }
        }

        if(ind==-1) {
             reverse(nums.begin(),nums.end());
        }
        else {
            for(int i=n-1;i>ind;i--)
            {
                if(nums[i]>nums[ind])
                {
                    swap(nums[i],nums[ind]);
                    break;
                }
            }
            reverse(nums.begin()+ind+1,nums.end());
        }
    }
};