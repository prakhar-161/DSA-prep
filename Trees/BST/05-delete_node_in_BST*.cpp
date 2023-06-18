// HARD
class Solution {
public:
    TreeNode* helper(TreeNode* root) {
        if(root->left == NULL) {
            return root->right;
        }
        else if(root->right == NULL) {
            return root->left;
        }
        TreeNode* rightSide = root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightSide;
        return root->left;
    }

    TreeNode* findLastRight(TreeNode* root) {
        if(root->right == NULL) {
            return root;
        }
        return findLastRight(root->right);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root->val == key) return helper(root);
        TreeNode* temp = root;
        while(root != NULL) {
            if(key < root->val) {
                // left side
                if(root->left != NULL && root->left->val == key) {
                    // root->left is the node to be deleted
                    root->left = helper(root->left);
                    break;
                }
                else {
                    root = root->left;
                }
            }
            else {
                // right side
                if(root->right != NULL && root->right->val == key) {
                    // root->right is the node to be deleted
                    root->right = helper(root->right);
                    break;
                } 
                else {
                    root = root->right;
                }
            }
        }
        return temp;
    }
};