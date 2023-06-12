// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

class Solution{
    public:
    void solve(vector<vector<int>> &m,vector<string> &res,int n,string s,int x,int y){
        if(x==n-1 && y==n-1){
            res.push_back(s);
            return;
        }
        m[x][y]=0;
        vector<vector<int>> v1={{-1,0},{1,0},{0,-1},{0,1}};
        vector<char> v2={'U','D','L','R'};
        for(int i=0;i<4;i++){
            int nx=x+v1[i][0];
            int ny=y+v1[i][1];
            if(nx>=0 && ny>=0 && nx<n && ny<n && m[nx][ny]==1){
                s.push_back(v2[i]);
                solve(m,res,n,s,nx,ny);
                s.pop_back();
            }
        }
        m[x][y]=1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(m[n-1][n-1]==0 || m[0][0]==0) return {"-1"};
        vector<string>res;
        solve(m,res,n,"",0,0);
        return res;
    }
};

