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
    bool getPath(Node* root, vector<int> &ans, int x) {
        if(root == NULL) return false;

        ans.push_back(root -> data);

        if(root -> data == x) {
            return true;
        }

        if(getPath(root -> left, ans, x) || getPath(root -> right, ans, x)) return true;

        ans.pop_back();

        return false;
    }

    public:
    vector<int> printPath(Node* A, int B) {
        vector<int> ans;
        if(A == NULL) return ans;
        getPath(A, ans, B);
        return ans;
    } 
};