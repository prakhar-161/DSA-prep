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
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return isSymmetricCheck(root->left, root->right);
    }
    
    bool isSymmetricCheck(TreeNode* left, TreeNode* right) {
        if(!left && !right) return true;
        else if(left == NULL || right == NULL) return false;
        else if(left->val != right->val) return false;
        
        return (isSymmetricCheck(left->left, right->right) && isSymmetricCheck(left->right, right->left));
    }
};