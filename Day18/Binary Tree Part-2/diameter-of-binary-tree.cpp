// https://leetcode.com/problems/diameter-of-binary-tree/

class Solution {
public:
    int res=0;
    int solve(TreeNode* p){
        if(!p) return 0;
        int l=solve(p->left);
        int r=solve(p->right);
        res=max(res,l+r+1);
        return 1 + max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return res-1;
    }
};

