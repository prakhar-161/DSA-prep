class Solution {
public:
    vector<int> NSR(vector<int>& heights, int n) {
        stack<pair<int, int>> s;
        vector<int> right;
        int pseudoIndex = n;
        for(int i=n-1; i>=0; i--) {
            if(s.size() == 0) {
                right.push_back(pseudoIndex);
            }
            else if(!s.empty() && s.top().first < heights[i]) {
                right.push_back(s.top().second);
            }
            else if(!s.empty() && s.top().first >= heights[i]) {
                while(!s.empty() && s.top().first >= heights[i]) {
                    s.pop();
                }
                if(s.size() == 0) {
                    right.push_back(pseudoIndex);
                }
                else {
                    right.push_back(s.top().second);
                }
            }
            s.push({heights[i], i});
        }
        reverse(right.begin(), right.end());
        return right;
    }
    
    vector<int> NSL(vector<int>& heights, int n) {
        stack<pair<int, int>> s;
        vector<int> left;
        for(int i=0; i<n; i++) {
            if(s.size() == 0) {
                left.push_back(-1);
            }
            else if(!s.empty() && s.top().first < heights[i]) {
                left.push_back(s.top().second);
            }
            else if(!s.empty() && s.top().first >= heights[i]) {
                while(!s.empty() && s.top().first >= heights[i]) {
                    s.pop();
                }
                if(s.size() == 0) {
                    left.push_back(-1);
                }
                else {
                    left.push_back(s.top().second);
                }
            }
            s.push({heights[i], i});
        }  
        return left;
    }
    
    int maxAreaHistogram(vector<int>& heights) {
        int n = heights.size();
        
        vector<int> nsr(n);
        nsr = NSR(heights, n);
        vector<int> nsl(n);
        nsl = NSL(heights, n);
        
        int maxi = INT_MIN;
        for(long long i=0; i<n; i++) {
            maxi = max(maxi, (nsr[i] - nsl[i] - 1) * heights[i]);
        }
    
        return maxi;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size(), res = 0;
        vector<int> histogram(m, 0);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == '0')
                    histogram[j] = 0;
                else
                    histogram[j] += 1;
            }
            res = max(res, maxAreaHistogram(histogram));
        }
        
        return res;
    }
};