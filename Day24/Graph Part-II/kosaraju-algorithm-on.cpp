// https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/discuss/766485/kosaraju-algorithm-on

#include<bits/stdc++.h>

using namespace std;

void dfs(int node,vector<int> &vis,stack<int> &s,vector<int>adj[]){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]) dfs(it,vis,s,adj);
    }
    s.push(node);
}
void dfs2(int node,vector<int> &vis,vector<int>adjT[],vector<int> &temp){
    vis[node]=1;
    temp.push_back(node);
    for(auto it:adjT[node]){
        if(!vis[it]) dfs2(it,vis,adjT,temp);
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges){
    vector<int>adj[n],adjT[n];
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
    }
    //using toposort
    vector<int>vis(n,0);
    stack<int>s;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,vis,s,adj);
        }
    }
    //reverse all the edges
    for(auto it:edges){
        adjT[it[1]].push_back(it[0]);
    }
    for(int i=0;i<n;i++)vis[i]=0;
    //make a dfs call
    vector<vector<int>>scc;
    while(!s.empty()){
        int node=s.top();
        s.pop();
        vector<int>temp;
        if(!vis[node]) dfs2(node,vis,adjT,temp);
        scc.push_back(temp);
    }
    return scc;
}

