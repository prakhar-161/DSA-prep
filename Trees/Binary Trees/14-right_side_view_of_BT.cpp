// Solution 1
// More space
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if(root==NULL) return v;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int count=q.size();
            for(int i=0;i<count;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(i==count-1)
                    v.push_back(curr->val);
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
            }
        }
        return v;
    }
};

// Solution 2
// Less space
class Solution {
public:
    void rsv(TreeNode* node, int level, vector<int> &ds) {
        if(node == NULL) return;
        if(level == ds.size()) ds.push_back(node->val);
        
        rsv(node->right, level+1, ds);
        rsv(node->left, level+1, ds);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ds;
        rsv(root, 0, ds);
        return ds;
    }
};

// LEFT SIDE VIEW OF BINARY TREE
class Solution {
public:
    void lsv(TreeNode* node, int level, vector<int> &ds) {
        if(node == NULL) return;
        if(level == ds.size()) ds.push_back(node->val);
        
        lsv(node->left, level+1, ds);
        lsv(node->right, level+1, ds);
    }
    
    vector<int> leftSideView(TreeNode* root) {
        vector<int> ds;
        lsv(root, 0, ds);
        return ds;
    }
};