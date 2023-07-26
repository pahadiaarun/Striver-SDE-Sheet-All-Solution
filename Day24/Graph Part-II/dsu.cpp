// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

#include <bits/stdc++.h> 

class DisJointSet{
  vector<int> rank, parent, size; 
public:
  DisJointSet(int n){
    rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

  int findparent(int u){
    if(u==parent[u]) return u;
    else parent[u] = findparent(parent[u]);
  }

  void unionByRank(int u, int v){
    int pu=findparent(u);
    int pv=findparent(v);
    if(pu==pv) return;
    if(rank[pu]<rank[pv]){
      parent[pu]=pv;
    }
    else if(rank[pv]<rank[pu]){
      parent[pv]=pu;
    }
    else{
      parent[pv]=pu;
      rank[pu]++;
    }
  }

  void unionbysize(int u,int v){
    int pu=findparent(u);
    int pv=findparent(v);
    if(pu==pv) return;
    if(size[pu]<size[pv]){
      parent[pu]=pv;
      size[pv]+=size[pu];
    } 
    else{
      parent[pv] = pu;
      size[pu] += size[pv];
    }
  }
};

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
  // Write your code here.
  vector<pair<int,pair<int,int>>>edges;
  for(auto it:graph){
    int u=it[0];
    int v=it[1];
    int wt=it[2];
    edges.push_back({wt,{u,v}});
  }

  DisJointSet dst(n);
  sort(edges.begin(),edges.end());
  
  int sum=0;
  for(auto it:edges){
    int u=it.second.first;
    int v=it.second.second;
    int wt=it.first;
    if(dst.findparent(u)!=dst.findparent(v)){
      sum+=wt;
      dst.unionbysize(u, v);
    }
  }
  return sum;
}

