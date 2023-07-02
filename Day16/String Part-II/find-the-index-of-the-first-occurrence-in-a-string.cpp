// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

class Solution {
public:
    void lps(string s,vector<int>&v){
        int i=1;
        int j=0;
        int n=s.size();
        while(i<n){
            if(s[i]==s[j]){
                v[i]=j+1;
                j++;
                i++;
            }
            else{
                if(j==0) i++;
                else j=v[j-1];
            }
        }
    }
    void solve(string s,string a,vector<int>v,int &res){
        int i=0,j=0;
        int n=s.size(),m=a.size();
        while(i<n && j<m){
            if(s[i]==a[j]){i++;j++;}
            else{
                if(j==0) i++;
                else j=v[j-1];
            }
            if(j==m){
                res=min(res,i-j);
                j=v[j-1];
            }
        }
    }
    int strStr(string s, string a) {
        int n=s.size(),m=a.size();
        vector<int>v(m+1);
        lps(a,v);
        int res=n;
        solve(s,a,v,res);
        if(res==n) return -1;
        return res;
    }
};

