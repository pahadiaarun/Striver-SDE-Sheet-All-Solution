// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

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
    TreeNode* solve(vector<int>& preorder,int l,int h){
        if(l>h) return NULL;
        TreeNode* root=new TreeNode(preorder[l]);
        int i;
        for(i=l+1;i<=h;i++) if(preorder[i]>root->val) break;
        root->left=solve(preorder,l+1,i-1);
        root->right=solve(preorder,i,h);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int l=0,h=preorder.size()-1;
        return solve(preorder,l,h);
    }
};

