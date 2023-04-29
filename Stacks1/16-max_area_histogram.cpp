#include<bits/stdc++.h>
using namespace std;

// needed to be debugged
// HARD
class Solution {
    vector<int> NSL(vector<int> &heights, int n) {
        stack<pair<int, int>> s;
        vector<int> left(n);
        int pseudoIndex = -1;
        for(int i=0; i<n; i++) {
            if(s.empty()) {
                left.push_back(pseudoIndex);
            }
            else if(!s.empty() && s.top().first < heights[i]) {
                left.push_back(s.top().second);
            }
            else if(!s.empty() && s.top().first >= heights[i]) {
                while(!s.empty() && s.top().first >= heights[i]) {
                    s.pop();
                }
                if(s.size() == 0) {
                    left.push_back(pseudoIndex);
                }
                else {
                    left.push_back(s.top().second);
                }
            }
            s.push({heights[i], i});
        }
        return left;
    }

    vector<int> NSR(vector<int> &heights, int n) {
        stack<pair<int, int>> s;
        vector<int> right(n);
        int pseudoIndex = n;
        for(int i=n-1; i>=0; i--) {
            if(s.empty()) {
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

    int maxAreaHistogram(vector<int> &heights) {
        int n = heights.size();
        
        vector<int> nsr(n);
        nsr = NSR(heights, n);
        vector<int> nsl(n);
        nsl = NSL(heights, n);

        vector<int> width(n);
        for(int i=0;i<n;i++) {
            width[i] = nsr[i] - nsl[i] - 1;
        }

        vector<int> ans(n);
        for(int i=0;i<n;i++) {
            ans[i] = heights[i] * width[i];
        }

        int maxi=0;
        for(int i=0;i<n;i++) {
            maxi = max(maxi, ans[i]);
        }
        return maxi;
    }
};