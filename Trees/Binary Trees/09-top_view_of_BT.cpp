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
    vector<int> topView(Node *root) {
        vector<int> ans;
        if(root == NULL) return ans;
        // map<line, node>
        map<int ,int> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int line = it.second;
            
            if(mp.find(line) == mp.end()) {
                mp[line] = node -> data;
            }
            
            if(node -> left) {
                q.push({node -> left, line - 1});
            }
            if(node -> right) {
                q.push({node -> right, line + 1});
            }
        }
        
        for(auto it : mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};