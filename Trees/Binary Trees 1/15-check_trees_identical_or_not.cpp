class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return 1;
        
        if(p && q) {
            return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
        }
        
        return 0;           // if one tree is empty and other is not
    }
};