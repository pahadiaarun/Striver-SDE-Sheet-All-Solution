// https://leetcode.com/problems/binary-tree-preorder-traversal/

void solve(TreeNode *root,vector<int> &v){
    if(root){
        v.push_back(root->data);
        solve(root->left,v);
        solve(root->right,v);
    }
}
vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int>v;
    solve(root,v);
    return v;
}

