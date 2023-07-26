// https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int solve(int n, int k,vector<vector<int>> &dp){
        if(n==1 || k<=1) return k;
        if(dp[n][k]!=-1) return dp[n][k];
        int mn=INT_MAX;
        for(int i=1;i<=k;i++){
            int temp=1+max(solve(n-1,i-1,dp),solve(n,k-i,dp));
            mn=min(mn,temp);
        }
        return dp[n][k] = mn;
    }
    int eggDrop(int n, int k) 
    {
        // your code here
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return solve(n,k,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends

