// https://www.codingninjas.com/studio/problems/path-in-a-tree_8230860?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/
vector<int>res;

void solve(TreeNode<int> *root, int x,vector<int>v){
	if(root){
		if(root->data==x){
			v.push_back(root->data);
			res=v;
			return;
		}
		v.push_back(root->data);
		solve(root->left,x,v);
		solve(root->right,x,v);
	}
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	vector<int>v;
	solve(root,x,v);
	return res;
}
