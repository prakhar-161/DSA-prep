#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int findMaxSum(vector<int> &nums, int k) {
        int sum = 0, maxi = INT_MIN;
        int i=0, j=0;
        while(j < nums.size()) {
            sum += nums[j];
            if(j-i+1 < k) j++;
            else if(j-i+1 == k) {
                maxi = max(maxi, sum);
                sum = sum - nums[i];
                i++;
                j++;
            }
        }
        return maxi;
    }
};