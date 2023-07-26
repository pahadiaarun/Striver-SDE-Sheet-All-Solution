// https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1

//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isValid(string s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]) return 0;
            i++;j--;
        }
        return 1;
    }
    int solve(string s,int i,int n,vector<int>&dp){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int mn=INT_MAX;
        for(int j=i;j<n;j++){
            if(isValid(s,i,j)){
                int cnt=1+solve(s,j+1,n,dp);
                mn=min(mn,cnt);
            }
        }
        return dp[i] = mn;
    }
    int palindromicPartition(string str)
    {
        // code here
        int n=str.size();
        vector<int>dp(n,-1);
        return solve(str,0,n,dp)-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends

