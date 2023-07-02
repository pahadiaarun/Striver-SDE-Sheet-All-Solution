// https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/

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
class node{
    public:
    int maxi;
    int mini;
    bool isbst;
    int sum;
};

class Solution {
public:
    node solve(TreeNode* root,int &sum){
        if(root==NULL){
            return {INT_MIN,INT_MAX,1,0};
        }
        node lf = solve(root->left,sum);
        node rt = solve(root->right,sum);
        if(lf.isbst && rt.isbst && (root->val > lf.maxi) && (root->val <rt.mini)){
            sum = max(sum,lf.sum+rt.sum+root->val);
            return {max(rt.maxi,root->val),min(lf.mini,root->val),1,lf.sum+rt.sum+root->val};
        }
        return {INT_MAX,INT_MIN,0,0};
    }

    int maxSumBST(TreeNode* root) {
        int ans = 0;
        node val = solve(root,ans);
        return ans;
    }
};

