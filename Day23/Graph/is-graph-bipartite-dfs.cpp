// https://leetcode.com/problems/is-graph-bipartite/

class Solution {
public:
    bool solve(vector<vector<int>>& adj,int p,vector<int> &col){
        if(col[p]==-1) col[p]=1;
        for(auto node:adj[p]){
            if(col[node]==-1){
                col[node]=1-col[p];
                if(solve(adj,node,col)) return 1;
            }
            else if(col[node]==col[p]) return 1;
        }
        return 0;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int>col(n,-1);
        
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                if(solve(adj,i,col)) return 0;
            }
        }
        
        return 1;
    }
};

