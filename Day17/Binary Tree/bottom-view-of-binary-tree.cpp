// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        if(!root) return {};
        vector<int>res;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        map<int,int>mp;
        mp[0]=root->data;
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            if(p.first->left){
                mp[p.second-1]=p.first->left->data;
                q.push({p.first->left,p.second-1});
            }
            if(p.first->right){
                mp[p.second+1]=p.first->right->data;
                q.push({p.first->right,p.second+1});
            }
        }
        for(auto i:mp){
            res.push_back(i.second);
        }
        return res;
    }
};

