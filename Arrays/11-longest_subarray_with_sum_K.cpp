// Most optimal for positive, negative values
// TC -> O(N*logN) : ordered map
// TC -> O(N*N) worst case for unordered map and O(N*1) best case for unordered map
// SC -> O(N)

// We have to return the maximum length
class Solution {
    public:
    int longestSubarrayWithSumK(vector<int> &nums, long long k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        long long preSum = 0;
        int len = 0;
        for(int i=0; i<n; i++) {
            preSum += nums[i];
            if(preSum == k) {               // when the loop starts and first time condition is met
                len = max(len, i+1);
            }

            int remainingSum = preSum - k;
            if(mp.find(remainingSum) != mp.end()) {
                len = max(len, i - mp[remainingSum]);
            }

            // edge case - handling zeros
            if(mp.find(preSum) == mp.end()) {
                mp[preSum] = i;
            }
        }
    }
};

// Most Optimal - Only for positives and zeros in the array
class Solution {
    public:
    int longestSubarrayWithSumK(vector<int> &nums, long long k) {
        int n = nums.size();
        long long sum = 0;
        int maxlen = 0, left = 0, right = 0;
        while(right < n) {
            sum += nums[right];
            if(sum == k) {
                maxlen = max(maxlen, right - left + 1);
                right++;
            }
            else if(sum < k) {
                right++;
            }
            else if(sum > k) {
                while(sum > k) {
                    sum -= nums[left];
                    left++;
                }
                if(sum == k) {
                    maxlen = max(maxlen, right - left + 1);
                }
                right++;    
            }
        }
        return maxlen;
    }
};

