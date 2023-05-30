#include<bits/stdc++.h>
using namespace std;

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
        while(!s.empty()) s.pop();
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
        while(!s.empty()) s.pop();
        return left;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        vector<int> nsr(n);
        nsr = NSR(heights, n);
        vector<int> nsl(n);
        nsl = NSL(heights, n);
        
        vector<int> width(n+1);
        for(int i=0; i<n; i++) {
            width[i] = nsr[i] - nsl[i] - 1;
        }
        
        long long int area = 0, maxi = 0;
        for(int i=0; i<n; i++) {
            area = heights[i] * width[i];
            maxi = max(maxi, area);
        }
    
        return maxi;
    }
};