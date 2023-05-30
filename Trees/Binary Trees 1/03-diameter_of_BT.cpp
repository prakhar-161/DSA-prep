#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Brute
class Solution {
    private:
    int height(TreeNode* root) {
        if(!root) return root;
        int lh = height(root->left);
        int rh = height(root->right);
        return max(lh,rh) + 1;
    }

    public: 
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        int l = diameter(root->left);
        int r = diameter(root->right);
        int lr = height(root->left) + 1 + height(root->right);

        return max(l, max(r, lr));
    }
}
// TC -> O(N*2)

// ------------------------------------------

// OPTIMAL
class Solution {
    public:
    // variation of height of bt
    int height(TreeNode* node, int &dia) {
        if(!node) return 0;
        int lh = height(node->left, dia);
        int rh = height(node->righ, dia);
        dia = max(dia, lh+rh);
        return max(lh,rh) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        height(root, dia);
        return dia;
    }
};