class Solution {
public:
    TreeNode* findFloor(TreeNode* root, int key) {
        int floor = -1;
        while(root) {
            if(root->val == key) {
                floor = root->val;
                return floor;
            }
            else if(key < root->val) {
                // left subtree
                root = root->left;
            }
            else {
                floor = root->val;
                root = root->right;
            }
        }
        return floor;
    }
};