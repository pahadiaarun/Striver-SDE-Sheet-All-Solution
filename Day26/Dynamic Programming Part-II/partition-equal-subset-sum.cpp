// https://leetcode.com/problems/partition-equal-subset-sum/

#include <bits/stdc++.h> 
bool solve(int i, int k, vector<int> &arr,vector<vector<int>> &dp){
    if(k==0) return 1;
    if(i==0) return 0;
    if(dp[i][k]!=-1) return dp[i][k];
    if(arr[i-1]<=k){
        return dp[i][k] = solve(i-1,k-arr[i-1],arr,dp) || solve(i-1,k,arr,dp);
    }
    return dp[i][k] = solve(i-1,k,arr,dp);
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
    return solve(n,k,arr,dp);
}

