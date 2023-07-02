// https://leetcode.com/problems/symmetric-tree/

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
    bool solve(TreeNode* p,TreeNode* q){
        if(!p && !q) return 1;
        if(!p || !q || p->val!=q->val) return 0;
        bool a=solve(p->left,q->right);
        bool b=solve(p->right,q->left);
        return a && b;
    }
    bool isSymmetric(TreeNode* root) {
        return solve(root->left,root->right);
    }
};

