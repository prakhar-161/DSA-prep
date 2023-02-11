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
    bool isSymmetric(struct Node* root) {
	    return root == NULL || isSymmetricHelper(root -> left, root -> right);
    }
    
    bool isSymmetricHelper(Node* left, Node* right) {
        if(left == NULL || right == NULL) return left == right;
        
        if(left -> data != right -> data) return false;
        
        return isSymmetricHelper(left -> left, right -> right) && 
                isSymmetricHelper(left -> right, right -> left);
    }
};