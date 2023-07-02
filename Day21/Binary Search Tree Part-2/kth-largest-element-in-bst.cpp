// https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1

class Solution
{
    public:
    void solve(Node* root, int k,int &res,int &cnt){
        if(!root) return;
        solve(root->left,k,res,cnt);
        cnt++;
        if(cnt==k) res=root->data;
        solve(root->right,k,res,cnt);
    }
    int kthLargest(Node *root, int k)
    {
        //Your code here
        int res,cnt=0;
        solve(root,INT_MAX,res,cnt);
        int n=cnt;
        cnt=0;
        solve(root,n-k+1,res,cnt);
        return res;
    }
};

