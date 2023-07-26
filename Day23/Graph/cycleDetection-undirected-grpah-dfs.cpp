// https://www.codingninjas.com/studio/problems/1062670?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include<bits/stdc++.h>

bool solve(vector<int>adj[],int child,vector<int> &vis,int parent){
    vis[child]=1;
    for(auto node:adj[child]){
        if(node==parent) continue;
        if (!vis[node]) {
            if(solve(adj,node,vis,child)) return 1;
        } 
        else return 1;
    }
    return 0;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<int>adj[n+1];
    for(auto i : edges){
        int u=i[0],v=i[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n+1, 0);
    for(int i=1;i<=n;i++){
        if(!vis[i]) if(solve(adj,i,vis,-1)) return "Yes";
    }
    return "No";
}

