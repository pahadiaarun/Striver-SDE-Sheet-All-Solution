// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

vector<int>dist(V,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,S});
        dist[S]=0;
        
        while(pq.size()){
            auto p=pq.top();
            pq.pop();
            int w=p.first,u=p.second;
            for(auto i:adj[u]){
                int v=i[0],wt=i[1];
                if(dist[v]>w+wt){
                    dist[v]=w+wt;
                    pq.push({dist[v],v});
                }
            }
        }
        return dist;
}

