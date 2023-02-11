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

// LEFT ROOT RIGHT
vector<int> inOrder(Node* root) {
    vector<int> ans;
    Node* node = root;
    stack<Node*> st;
    while(true) {
        if(node != NULL) {
            st.push(node);
            node = node -> left;
            }
        else {
            if(st.empty()) break;
            node = st.top();
            st.pop();
            ans.push_back(node -> data);
            node = node -> right;
        }
    }
    return ans;
}