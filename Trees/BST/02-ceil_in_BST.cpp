class Solution {
public:
    TreeNode* findCeil(TreeNode* root, int key) {
        int ceil = -1;
        while(root != NULL) {
            if(root->val == key) {
                ceil = root->val;
                return ceil;
            }
            else if(key < root->val) {
                ceil = root->val;
                root = root->left;
            }
            else {
                root = root->right;
            }
        }
        return ceil;
    }
};