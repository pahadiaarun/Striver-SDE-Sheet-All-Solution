// https://leetcode.com/problems/boundary-of-binary-tree/

#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

bool isLeaf(TreeNode<int>* root){
    return (!root->left && !root->right);
}

void solve1(TreeNode<int>* root,vector<int>&res){
    TreeNode<int>* p=root->left;
    while(p){
        if(!isLeaf(p)) res.push_back(p->data);
        if(p->left) p=p->left;
        else p=p->right;
    }
}

void solve2(TreeNode<int>* root,vector<int>&res){
    if(root->left) solve2(root->left,res);
    if(isLeaf(root)) res.push_back(root->data);
    if(root->right) solve2(root->right,res);
}

void solve3(TreeNode<int>* root,vector<int>&res){
    TreeNode<int>* p=root->right;
    stack<int>st;
    while(p){
        if(!isLeaf(p)) st.push(p->data);
        if(p->right) p=p->right;
        else p=p->left;
    }
    while(st.size()){
        res.push_back(st.top());
        st.pop();
    }
}

vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int>res;
    if(!root) return res;
    if(!isLeaf(root)) res.push_back(root->data);
    solve1(root,res);
    solve2(root,res);
    solve3(root,res);
    return res;
}

