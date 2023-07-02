// https://leetcode.com/problems/validate-binary-search-tree/

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
    bool solve(TreeNode* root, long long mn, long long mx ){
        if(!root) return 1;
        if(root->val>=mx || root->val<=mn) return 0;
        return solve(root->left,mn,root->val) && solve(root->right,root->val,mx);
    }
    bool isValidBST(TreeNode* root) {
        return solve(root,-1e18,1e18);
    }
};

