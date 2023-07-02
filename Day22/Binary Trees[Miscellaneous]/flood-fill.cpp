// https://leetcode.com/problems/flood-fill/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size(),m=image[0].size();
        queue<pair<int,int>>q;
        set<pair<int,int>>st;
        q.push({sr,sc});
        st.insert({sr,sc});
        vector<pair<int,int>>v={{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nx=x+v[i].first;
                int ny=y+v[i].second;
                if(nx>=0 && ny>=0 && nx<n && ny<m && image[nx][ny]==image[x][y] && !st.count({nx,ny})){
                    q.push({nx,ny});
                    st.insert({nx,ny});
                }
            }
            image[x][y]=color;
        }
        return image;
    }
};

