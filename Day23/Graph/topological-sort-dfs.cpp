// https://practice.geeksforgeeks.org/problems/topological-sort/1

void solve(int node, vector<int> adj[],vector<int> &vis,stack<int> &st){
      vis[node]=1;
      for(auto i:adj[node]){
          if(!vis[i]) solve(i,adj,vis,st);
      }
      st.push(node);
  }
  vector<int> topoSort(int V, vector<int> adj[]) 
  {
      // code here
      vector<int>vis(V,0);
      stack<int>st;
      for(int i=0;i<V;i++){
          if(!vis[i]){
              solve(i,adj,vis,st);
          }
      }
      vector<int>res;
      while(st.size()){
          res.push_back(st.top());
          st.pop();
      }
      return res;
  }

