// https://www.codingninjas.com/studio/problems/981269?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/

void solve(BinaryTreeNode<int> *root,vector<int>&inorder,vector<int>&preorder,vector<int>&postorder){
    if(root){
        preorder.push_back(root->data);
        solve(root->left,inorder,preorder,postorder);
        inorder.push_back(root->data);
        solve(root->right,inorder,preorder,postorder);
        postorder.push_back(root->data);
    }
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<vector<int>>res;
    vector<int>inorder;
    vector<int>preorder;
    vector<int>postorder;
    solve(root,inorder,preorder,postorder);
    res.push_back({inorder});
    res.push_back({preorder});
    res.push_back({postorder});
    return res;
}

