// https://www.codingninjas.com/studio/problems/1062670?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include<bits/stdc++.h>
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<int>adj[n+1];
    for(auto i : edges){
        int u=i[0],v=i[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<pair<int,int>>q;
    vector<int> vis(n+1, 0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            q.push({i,-1});
            while(!q.empty()){
                auto p=q.front();
                q.pop();
                int child=p.first,parent=p.second;
                for(auto node:adj[child]){
                    if(!vis[node]){
                        q.push({node,child});
                        vis[node]=1;
                    }
                    else if(node!=parent) return "Yes";
                }
            }
        }
    }
    return "No";
}
