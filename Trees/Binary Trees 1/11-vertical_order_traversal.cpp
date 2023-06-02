#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

class Solution {
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // map : vertical -> level -> multinodes
        // queue : {node, {vertical, level}}
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0, 0}});
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int v = p.second.first, l = p.second.second;
            nodes[v][l].insert(node->val);
            if(node->left) {
                q.push({node->left, {v-1, l+1}});
            }
            if(node->right) {
                q.push({node->right, {v+1, l+1}});
            }
        }
        
        vector<vector<int>> ans;
        for(auto p : nodes) {
            vector<int> col;
            for(auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};