// https://leetcode.com/problems/balanced-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root){
        if(!root) return 0;
        return 1+max(solve(root->left),solve(root->right));
    }
    bool isBalanced(TreeNode* root) {
        int l,r;
        if(!root) return 0;
        l=solve(root->left);
        r=solve(root->right);
        if(abs(l-r)>1) return 0;
        bool x=isBalanced(root->left);
        bool y=isBalanced(root->right);
        if(!x || !y) return  0;
        return 1;
    }
};

