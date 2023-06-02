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
    vector<int> bottomView(Node* root) {
        vetcor<int> ans;
        if(!root) return ans;
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            Node* node = p.first;
            int vertical = p.second;
            mp[vertical] = node->val;
            if(node->left) {
                q.push({node->left, vertical - 1});
            }
            if(node->right) {
                q.push({node->right, vertical + 1});
            }
        }

        for(auto it : mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};