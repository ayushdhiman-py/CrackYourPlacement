class Solution {
    int height(TreeNode* node){
        if(!node) return 0;
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return 1 + max(leftHeight, rightHeight);
    }
//      if(root==NULL) return 0;
//      int leftHeight = height(root->left);
//      int rightHeight = height(root->right);
//      maxi = max(maxi, leftHeight + rightHeight);
//      solve(maxi, root->left);
//      solve(maxi, root->right);
//      return 1 + max(leftHeight, rightHeight);
    int solve(int &maxi, TreeNode* root){
        if(root==NULL) return 0;
        int leftHeight = solve(maxi, root->left);
        int rightHeight = solve(maxi, root->right);
        maxi = max(maxi, leftHeight + rightHeight);
        return 1 + max(leftHeight, rightHeight);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;
        solve(maxi,root);
        return maxi;
    }
};
