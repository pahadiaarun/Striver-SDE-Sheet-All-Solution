// https://leetcode.com/problems/is-graph-bipartite/

class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int>col(n,-1);
        
        queue<int>q;
        
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                q.push(i);
                col[i]=0;
                while(!q.empty()){
                    int p=q.front();
                    q.pop();
                    for(auto node:adj[p]){
                        if(col[node]==-1){
                            q.push(node);
                            col[node]=!col[p];
                        }
                        else if(col[node]==col[p]) return 0;
                    }
                }
            }
        }
        
        return 1;
    }
};

