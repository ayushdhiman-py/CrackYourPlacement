class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false; // If root is null, no subtree can match
        if (isSame(root, subRoot)) return true; // Check if trees are identical
        // Recursively check left and right subtrees
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
    
    bool isSame(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true; // Both are null, so trees are identical
        if (!s || !t) return false; // One is null, so trees are not identical
        if (s->val != t->val) return false; // Values don't match
        // Recursively check left and right children
        return isSame(s->left, t->left) && isSame(s->right, t->right);
    }
};
