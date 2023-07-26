// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

#include <bits/stdc++.h> 
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<set<int>> adj(vertex);
    for(auto e : edges){
        adj[e.first].insert(e.second);
        adj[e.second].insert(e.first);
    }
    vector<int> bfs;
    vector<bool> visited(vertex, false);
    for(int i = 0; i < vertex; i++){
        if(!visited[i]){
            queue<int> queue;
            queue.push(i);
            while(!queue.empty()){
                int curr = queue.front();
                queue.pop();
                if(visited[curr]) continue;
                visited[curr] = true;
                bfs.push_back(curr);
                for(auto j : adj[curr]){
                    if(!visited[j])
                        queue.push(j);
                }
            }
        }
    }
    return bfs;
}

