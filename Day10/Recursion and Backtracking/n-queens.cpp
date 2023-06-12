// https://leetcode.com/problems/n-queens/

class Solution {
public:
    bool check(int n,vector<string>&temp,int x,int y){
        int i=0;
        while(i!=x){
            if(temp[i++][y]=='Q') return 0;
        }
        i=0;
        while(x-i>=0 && y-i>=0){
            if(temp[x-i][y-i]=='Q') return 0;
            i++;
        }
        i=0;
        while(x-i>=0 && y+i<n){
            if(temp[x-i][y+i]=='Q') return 0;
            i++;
        }
        return 1;
    }
    
    void solve(int n,vector<vector<string>>&res,vector<string>&temp,int x){
        if(x==n){
            res.push_back(temp);
            return;
        }
        for(int i=0;i<n;i++){
            if(check(n,temp,x,i)){
                temp[x][i]='Q';
                solve(n,res,temp,x+1);
                temp[x][i]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        vector<string>temp(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) temp[i]+='.';
        }
        solve(n,res,temp,0);
        return res;
    }
};
