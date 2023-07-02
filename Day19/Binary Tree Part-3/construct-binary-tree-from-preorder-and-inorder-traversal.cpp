// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int l,int h,int &j){
        if(l>h) return NULL;
        TreeNode* root=new TreeNode(preorder[j++]);
        int i;
        for(i=l;i<=h;i++) if(inorder[i]==root->val) break;
        root->left=solve(preorder,inorder,l,i-1,j);
        root->right=solve(preorder,inorder,i+1,h,j);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int j=0;
        return solve(preorder,inorder,0,inorder.size()-1,j);
    }
};

