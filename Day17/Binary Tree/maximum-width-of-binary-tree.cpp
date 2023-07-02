// https://leetcode.com/problems/maximum-width-of-binary-tree/

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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long>>q;
        q.push({root,1});
        int n,start,end,diff;
        int res=1;
        while(!q.empty()){
            n=q.size();
            for(int i=0;i<n;i++){
                auto [node,pos] = q.front();
                q.pop();
                if(i==0){
                    start=pos;
                    diff=pos-1;
                }
                if(i==n-1) end=pos;
                pos-=diff;
                if(node->left) q.push({node->left,2*pos-1});
                if(node->right) q.push({node->right,2*pos});
            }
            res=max(res,end-start+1);
        }
        return res;
    }
};

