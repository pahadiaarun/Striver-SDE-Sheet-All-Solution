// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

void solve(vector<int>adj[],int in,vector<int>& vis,vector<int>& v){
    v.push_back(in);
    vis[in]=1;
    for(auto i:adj[in]){
        if(!vis[i]){
            solve(adj,i,vis,v);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<int>adj[V];
    for(auto i:edges){
        int u=i[0],v=i[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>>res;
    vector<int>vis(V,0);
    for(int i=0;i<V;i++){
        if(!vis[i]){
            vector<int>v;
            solve(adj,i,vis,v);
            res.push_back(v);
        }
    }
    return res;
}

