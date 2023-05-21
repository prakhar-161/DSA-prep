class Solution {
public:
// equal no. of positives and negatives
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans (nums.size(),0);
        int posi = 0, negi = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] > 0) {
                ans[2*posi] = nums[i];
                posi += 1;
            }
            else {
                ans[2*negi+1] = nums[i];
                negi += 1;
            }
        }
        
        return ans;
    }
};

// unequal no of positives and negatives
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos, neg;
        for(int i=0; i<n; i++) {
            if(nums[i] < 0) {
                neg.push_back(nums[i]);
            }
            else {
                pos.push_back(nums[i]);
            }
        }

        if(pos.size() > neg.size()) {
            for(int i=0; i<neg.size(); i++) {
                nums[2*i] = pos[i];
                nums[2*i+1] = neg[i];
            }
            int index = neg.size()*2;
            for(int i=neg.size(); i<pos.size(); i++) {
                nums[index] = pos[i];
                index++;
            }
        }
        else {
            for(int i=0; i<pos.size(); i++) {
                nums[2*i] = pos[i];
                nums[2*i+1] = neg[i];
            }
            int index = pos.size()*2;
            for(int i=pos.size(); i<neg.size(); i++) {
                nums[index] = neg[i];
                index++;
            }
        }
        return nums;
    }
};

