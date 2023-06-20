// https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    int dp[1001][1001];
    bool solve(int i,int j,string &s){
        if(i>=j) return 1;
        if(s[i]!=s[j]) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = solve(i+1,j-1,s);
    }
    
    string longestPalindrome(string s) {
        int n=s.size();
        int mx=1;
        string res="";
        memset(dp,-1,sizeof dp);
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(i,j,s)){
                    if(mx<=(j-i+1)){
                        res=s.substr(i,j-i+1);
                        mx=j-i+1;
                    }
                }
            }
        }
        
        return res;
    }
};

