#include <bits/stdc++.h>
using namespace std;

class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    public:
    vector<int> rightView(Node* head) {
        vector<int> ans;
        if(root == NULL) return ans;
        map<int, int> mpp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            
            Node* node = it.first;
            int level = it.second;
            
            if(mpp.find(level) == mmp.end()) {
                mpp[level] = node -> data;
            }
            
            if(node -> left) {
                q.push({node -> left, level + 1});
            }
            if(node -> right) {
                q.push({node -> right, level + 1});
            }
        }
        
        for(auto it : mpp) {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};