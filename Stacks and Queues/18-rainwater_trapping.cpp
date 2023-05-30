// BETTER (prefix maxLeft array and suffix maxRight array)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxLeft(n), maxRight(n);
        
        // for maxLeft array
        maxLeft[0] = height[0];
        for(int i=1; i<n; i++) {
            maxLeft[i] = max(maxLeft[i-1], height[i]);
        } 
        
        // for maxRight array
        maxRight[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--) {
            maxRight[i] = max(maxRight[i+1], height[i]);
        }
        
        int water = 0;
        for(int i=0; i<n; i++) {
            water += min(maxLeft[i], maxRight[i]) - height[i];
        }
        
        return water;
    }
};
// SC -> O(2*N) ~ O(N)
// TC -> O(N)
// logic in notebook

// SC -> O(1)
// TC -> O(N)
// OPTIMAL
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int water = 0;
        int leftmax = 0, rightmax = 0;
        while(left <= right) {
            if(height[left] <= height[right]) {
                if(height[left] >= leftmax) leftmax = height[left];
                else water += leftmax - height[left];
                left++;
            }
            else {
                if(height[right] >= rightmax) rightmax = height[right];
                else water += rightmax - height[right];
                right--;
            }
        }
        return water;
    }
};