// https://leetcode.com/problems/course-schedule/

bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>in(V,0);
        for(int i=0;i<V;i++){
            for(auto node:adj[i]) in[node]++;
        }
        
        queue<int>q;
        int cnt=0;
        
        for(int i=0;i<V;i++){
            if(in[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int p=q.front();
            q.pop();
            
            for(auto i:adj[p]){
                in[i]--;
                if(in[i]==0) q.push(i);
            }
            
            cnt++;
        }
        
        if(cnt==V) return 0;
        return 1;
    }

