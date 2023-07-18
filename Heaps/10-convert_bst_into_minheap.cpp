#include<bits/stdc++.h>
using namespace std;

void convertToInorder(BinaryTreeNode* root,vector<int> &inorder){
    if(root == NULL) return;
    
    convertToInorder(root->left,inorder);     //Left Call
    inorder.push_back(root->data);   //Root Data
    convertToInorder(root->right,inorder);    //Right Call
}

void preorder(BinaryTreeNode* root,vector<int> &inorder, int &index) {
    if(root == NULL) return;

    root->val = inorder[index++];
    preorder(root->left, inorder, index);
    preorder(root->right, inorder, index);
}


BinaryTreeNode* convertBST(BinaryTreeNode* root) {
    vector<int> inorder;

    convertToInorder(root, inorder);

    int i = 0;
    preorder(root, inorder, i);

    return root;
}