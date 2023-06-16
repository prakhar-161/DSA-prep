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
    private:
    bool isLeaf(Node* root) {
        return (!root->left && !root->right);
    }

    void addLeftBoundary(Node* root, vector<int> &ans) {
        Node* cur = root->left;
        while(cur) {
            if(!isLeaf(cur)) ans.push_back(cur->val);
            if(cur->left) cur = cur->left;
            else cur = cur->right;
        }
    }

    void addRightBoundary(Node* root, vector<int> &ans) {
        Node* cur = root->right;
        stack<int> st;
        while(cur) {
            if(!isLeaf(cur)) st.push(cur->val);
            if(cur->right) cur = cur->right;
            else cur = cur->left;
        }

        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
    }

    void addLeaves(Node* root, vector<int> &ans) {
        // inorder traversal
        if(isLeaf(root)) {
            ans.push_back(root->val);
            return;
        }

        if(root->left) addLeaves(root->left, ans);
        if(root->right) addLeaves(root->right, ans);
    }

    public:
    vector<int> boundaryTraversal(Node* root) {
        vector<int> ans;
        if(!root) return ans;
        if(!isLeaf(root)) ans.push_back(root->val);
        addLeftBoundary(root, ans);
        addLeaves(root, ans);
        addRightBoundary(root, ans);
        return ans;
    }
};