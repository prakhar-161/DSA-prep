// Kadane's Algorithm

// maxlen of subarray
long long maxSubarraySum(vector<int> nums) {
    int n = nums.size();
    long long sum = 0, maxi = LONG_MIN;
    for(int i=0; i<n; i++) {
        sum += nums[i];
        maxi = max(maxi, sum);
        if(sum < 0) {
            sum = 0;
        }
    }
    return maxi;
}

// printing subarray
long long maxSubarraySum(vector<int> nums) {
    int n = nums.size();
    long long sum = 0, maxi = LONG_MIN;
    int ansStart = -1, ansEnd = -1;
    for(int i=0; i<n; i++) {
        if(sum == 0) start = i;
        sum += nums[i];
        if(sum > maxi) {
            maxi = sum;
            ansStart = start; 
            ansEnd = i;
        }
        if(sum < 0) {
            sum = 0;
        }
    }
    return maxi;
}