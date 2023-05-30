#include <bits/stdc++.h>
using namespace std;

// height of bt
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int maxDepth(TreeNode* root) {
        if(!root) return root;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        return max(lh,rh) + 1;
    }
};