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

vector <int> preorder(Node* root) { 
    vector<int> ans;
    if(!root) return ans;
    
    stack<Node*> st;
    st.push(root);
    while(!st.empty()) {
        Node* node = st.top();
        st.pop();
        
        ans.push_back(node -> data);
        if(node -> right) {
            st.push(node -> right);
        }
        if(node -> left) {
            st.push(node -> left);
        }
    }
    return ans;
}