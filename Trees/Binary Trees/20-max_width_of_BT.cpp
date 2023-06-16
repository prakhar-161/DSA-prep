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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*, int>> q;
        int ans = 0;
        q.push({root, 0});
        while(!q.empty()) {
            int size = q.size();
            int mmin = q.front().second;            // leftmost will be choosen everytime..so it is the min
            int first, last;
            for(int i=0; i<size; i++) {
                int currIndex = q.front().second - mmin;
                TreeNode* node = q.front().first;
                q.pop();
                if(i == 0) first = currIndex;
                if(i == size - 1) last = currIndex;
                if(node->left) {
                    q.push({node->left, (long long)2*currIndex + 1});
                }
                if(node->right) {
                    q.push({node->right, (long long)2*currIndex + 2});
                }
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};