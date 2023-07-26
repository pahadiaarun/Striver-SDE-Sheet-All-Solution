// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

int solve(int n,int i,vector<int> &p,vector<vector<int>> &dp){
  if(n==0 || i==0) return 0;
  if(dp[i][n] != -1) return dp[i][n];
  if(i<=n){
    return dp[i][n] = max(p[i-1] + solve(n-i,i,p,dp),solve(n,i-1,p,dp));
  }
  return dp[i][n] = solve(n,i-1,p,dp);
}
int cutRod(vector<int> &price, int n)
{
  // Write your code here.
  vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
  return solve(n,n,price,dp);
}

