// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {{}};
        map<pair<int,int>,priority_queue<int, vector<int>, greater<int> >>mp;
        vector<vector<int>>res;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            mp[{p.second.first,p.second.second}].push(p.first->val);
            if(p.first->left) q.push({p.first->left,{p.second.first+1,p.second.second-1}});
            if(p.first->right) q.push({p.first->right,{p.second.first+1,p.second.second+1}});
        }
        map<int,vector<int>>mp1;
        for(auto i:mp){
            auto x=i.first;
            auto y=i.second;
            while(!y.empty()){
                mp1[x.second].push_back(y.top());
                y.pop();
            }
        }
        for(auto i:mp1){
            res.push_back(i.second);
        }
        return res;
    }

