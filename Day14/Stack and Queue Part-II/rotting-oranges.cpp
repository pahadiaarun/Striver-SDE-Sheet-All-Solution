// https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int res=0;
        queue<pair<int,int>>q;
        int n=grid.size(),m=grid[0].size();
        set<pair<int,int>>st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) st.insert({i,j});
                if(grid[i][j]==2) q.push({i,j});
            }
        }
        if(st.size()==0) return 0;
        if(q.size()==0) return -1;
        q.push({-1,-1});
        vector<vector<int>> v1={{-1,0},{1,0},{0,-1},{0,1}};
        while(q.size() && st.size()){
            auto p=q.front();
            q.pop();
            int x=p.first;
            int y=p.second;
            if(x==-1 && y==-1){
                res++;
                if(q.front().first<0) break;
                q.push({-1,-1});
                continue;
            }
            for(int i=0;i<4;i++){
                int nx=x+v1[i][0];
                int ny=y+v1[i][1];
                if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==1){
                    q.push({nx,ny});
                    grid[nx][ny]=2;
                    st.erase({nx,ny});
                }
            }
        }
        if(st.size()) return -1;
        return res+1;
    }
};

