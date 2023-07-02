// https://www.codingninjas.com/studio/problems/ceil-from-bst_8230754?challengeSlug=striver-sde-challenge

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:
    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

void solve(BinaryTreeNode<int> *node, int x,int &res){
    if(!node) return ;
    solve(node->left,x,res);
    if(node->data>=x && node->data<=res) res=node->data;
    solve(node->right,x,res);
}

int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    int res=INT_MAX;
    solve(node,x,res);
    return (res==INT_MAX) ? -1 : res;
}

