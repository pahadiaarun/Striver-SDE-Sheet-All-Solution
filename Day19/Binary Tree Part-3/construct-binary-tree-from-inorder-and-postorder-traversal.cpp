// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
    TreeNode* buildTree(vector<int>& in, vector<int>& po) {
        unordered_map<int, int> m;
        for(int i=0; i<in.size(); i++) m[in[i]] = i;
        return helper(in, 0, in.size()-1, po, 0, po.size()-1, m);
    }
    
    TreeNode* helper(vector<int>& in, int inStart, int inEnd, vector<int>& po, int poStart, int poEnd, unordered_map<int, int> & m){
        
        if(poStart > poEnd || inStart > inEnd) return NULL;
        TreeNode* root = new TreeNode(po[poEnd]);
        int rootIdx = m[po[poEnd]];
        int numsOnLeft = rootIdx - inStart;
        
        root->left = helper(in, inStart, rootIdx-1, po, poStart, poStart+numsOnLeft-1, m);
        root->right = helper(in, rootIdx+1, inEnd, po, poStart+numsOnLeft, poEnd-1, m);
        
        return root;
    }
};

