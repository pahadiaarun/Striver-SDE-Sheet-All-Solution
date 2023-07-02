// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure.

    template <typename T>
    class TreeNode {
        public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    stack<TreeNode<int> *>st;
    st.push(root);
    while(!st.empty()){
        TreeNode<int> * p=st.top();
        st.pop();
        if(p->right) st.push(p->right);
        if(p->left) st.push(p->left);
        if(!st.empty()) p->right=st.top();
        p->left=NULL;
    }
    return root;
}

