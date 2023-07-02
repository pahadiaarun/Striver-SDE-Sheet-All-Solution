// https://www.codingninjas.com/studio/problems/floor-in-bst_8230753?challengeSlug=striver-sde-challenge

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void solve(TreeNode<int> *node, int x,int &res){
    if(!node) return ;
    solve(node->left,x,res);
    if(node->val<=x && node->val>=res) res=node->val;
    solve(node->right,x,res);
}

int floorInBST(TreeNode<int> * node, int x)
{
    // Write your code here.
    int res=INT_MIN;
    solve(node,x,res);
    return (res==INT_MIN) ? -1 : res;
}

