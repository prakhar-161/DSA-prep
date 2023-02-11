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
    private:
    bool isLeaf(Node* root) {
        return (!root -> left && !root -> right);
    }

    void addLeftBoundary(Node* root, vector<int> &ans) {
        Node* curr = root -> left;
        while(curr) {
            if(!isLeaf(curr)) ans.push_back(curr -> data);
            if(curr -> left) curr = curr -> left;
            else curr = curr -> right;
        }
    }

    void addLeaves(Node* root, vector<int> &ans) {
        // inorder traversal
        if(isLeaf(root)) {
            ans.push_back(root -> data);
            return;
        }

        if(root -> left) addLeaves(root -> left, ans);
        if(root -> right) addLeaves(root -> right, ans);
    }

    void addRightBoundary(Node* root, vector<int> &ans) {
        Node* curr = root -> right;
        stack<int> st;
        while(curr) {
            if(!isLeaf(curr)) st.push(curr -> data);
            if(curr -> right) curr = curr -> right;
            else curr = curr -> left;
        }

        while(!st.empty()) {
            int val = st.top();
            st.pop();
            ans.push_back(val);
        }
    }

    public:
    vector <int> boundary(Node *root) {
        vector<int> ans;
        if(root == NULL) return ans;
        if(!isLeaf(root)) ans.push_back(root -> data);
        addLeftBoundary(root, ans);
        addLeaves(root, ans);
        addRightBoundary(root, ans);
        return ans;
    }
};