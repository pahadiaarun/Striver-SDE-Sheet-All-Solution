// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    vector<pair<int, int>> adj[n+1];
    for(int i = 0 ; i < m ; i++){
        adj[g[i].first.first].push_back({g[i].second, g[i].first.second});
        adj[g[i].first.second].push_back({g[i].second, g[i].first.first});

    }

    priority_queue<pair<int,pair<int, int>>,vector<pair<int,pair<int, int>>>,greater<pair<int,pair<int, int>>>>pq;
    pq.push({0,{1,-1}});
        
    vector<int>vis(n+1,0);
    vector<pair<pair<int, int>, int>>res;
    while(!pq.empty()){
        auto p=pq.top();
        pq.pop();
        int w=p.first;
        int u=p.second.first;
        int pr=p.second.second;
        if(vis[u]) continue;
        if(pr!=-1) res.push_back({{pr,u},w});
        vis[u]=1;
        for(auto i:adj[u]){
            int v=i.second,wt=i.first;
            if(!vis[v]){
                pq.push({wt,{v,u}});
            }
        }
    }
    return res;
}

