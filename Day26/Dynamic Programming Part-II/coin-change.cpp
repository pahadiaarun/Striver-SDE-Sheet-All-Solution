// https://leetcode.com/problems/coin-change/

#include<bits/stdc++.h>
long solve(int *arr, int i, int v, vector<vector<long>> &dp){
    if(v==0) return 1;
    if(i==0) return 0;
    if(dp[i][v]!=-1) return dp[i][v]; 

    if(v>=arr[i-1]){
        return dp[i][v] = solve(arr,i,v-arr[i-1],dp) + solve(arr,i-1,v,dp);
    }

    return dp[i][v] = solve(arr,i-1,v,dp);
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    vector<vector<long>>dp(n+1,vector<long>(value+1,-1));
    return solve(denominations,n,value,dp);
}

