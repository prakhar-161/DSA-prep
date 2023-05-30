// KADANE'S Algorithm
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            if(sum > maxi) maxi = sum;  // calculating maxi = max(maxi, sum)
            if(sum < 0) sum = 0;
        }
        // empty subarray if condn given in ques
        // if(maxi < 0) maxi = 0;
        
        return maxi;
    }
};