// https://leetcode.com/problems/search-in-a-binary-search-tree/

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
    TreeNode* res=NULL;
    void solve(TreeNode* root, int val){
        if(!root) return;
        if(root->val==val){
            res=root;
            return;
        }
        if(root->val > val) solve(root->left,val);
        else solve(root->right,val);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        solve(root,val);
        return res;
    }
};

