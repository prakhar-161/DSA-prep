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

// concept of flag variable for each level/row
 
class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root) {
    	vector<int> ans;
    	if(root == NULL) return ans;
        queue<Node*> q;
        q.push(root);
        bool leftToRight = true;
        while(!q.empty()) {
            int size = q.size();
            vector<int> row(size);
            for(int i=0; i<size; i++) {
                Node* node = q.front();
                q.pop();
                
                int index = (leftToRight) ? i : size - i - 1;
                row[index] = node -> data;
                
                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
            }
            leftToRight = !leftToRight;
            
            for(int i=0; i<row.size(); i++) {
                ans.push_back(row[i]);
            }
        }
        
        return ans;
    }
};