// https://leetcode.com/problems/binary-tree-level-order-traversal/

vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    if(!root) return {};
    queue<BinaryTreeNode<int> *>q;
    vector<int>res;
    q.push(root);
    res.push_back(root->val);
    while(!q.empty()){
        int n=q.size();
        while(n--){
            auto p=q.front();
            q.pop();
            if(p->left){
                q.push(p->left);
                res.push_back(p->left->val);
            }
            if(p->right){
                q.push(p->right);
                res.push_back(p->right->val);
            }
        }
    }
    return res;
}

