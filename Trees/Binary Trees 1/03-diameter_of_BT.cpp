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

// Base Condition -> Stop when the node is null by returning 0.

// Main Logic -> You are supposed to find the max diameter at each node and update the variable which stores the max diameter found till that point, 'diameter' in the logic below.

// 1. At any node you can find the diameter by doing (1 + left + right), and then comparing if it is the max diameter till that point of time. If yes, store it in the 'diameter' variable.
// 2. Returning (1 + max(left,right)) to it's parent call to let parent node also calculate the diameter on similar lines as mentioned in step 1.
// Why max(left,right) ? As parent won't require both but just the path/height/depth that gives max value.

// OPTIMAL
class Solution {
    public:
    // variation of height of bt
    int height(TreeNode* node, int &dia) {
        if(!node) return 0;
        int lh = height(node->left, dia);
        int rh = height(node->right, dia);
        int diaAtCurrentNode = lh + rh;
        dia = max(dia, diaAtCurrentNode);
        return max(lh,rh) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        height(root, dia);
        return dia;
    }
};