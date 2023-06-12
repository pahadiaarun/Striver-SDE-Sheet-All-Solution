// https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#

class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool check(bool graph[101][101],vector<int>vis,int m,int in,int n){
        for(int j=0;j<n;j++){
            if(graph[in][j]==1) if(vis[j]==m) return 0;
        }
        return 1;        
    }
    bool solve(bool graph[101][101],int m,int n,vector<int>&vis,int in){
        if(in==n) return 1;
        for(int i=1;i<=m;i++){
            if(check(graph,vis,i,in,n)){
                vis[in]=i;
                if(solve(graph,m,n,vis,in+1)) return 1;
                else vis[in]=0;
            }
        }
        return 0;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int>vis(n,0);
        return solve(graph,m,n,vis,0);
    }
};
