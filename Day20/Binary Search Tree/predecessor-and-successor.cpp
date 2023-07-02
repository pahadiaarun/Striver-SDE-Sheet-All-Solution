// https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1

class Solution
{
    public:
    void solve(Node* root, Node*& pre, Node*& suc, int key){
        if(!root) return;
        solve(root->left,pre,suc,key);
        if(root->key<key) pre=root;
        if(root->key>key && !suc) suc=root;
        solve(root->right,pre,suc,key);
    }
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        pre=NULL;
        suc=NULL;
        solve(root,pre,suc,key);
    }
};

