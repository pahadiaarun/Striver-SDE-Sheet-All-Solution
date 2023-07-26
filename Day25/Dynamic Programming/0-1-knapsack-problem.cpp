// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

int solve(vector<int> &v, vector<int> &wt,int i, int n, int w,vector<vector<int>> &dp){
  if(i>=n) return 0;
  if(dp[i][w]!=-1) return dp[i][w];
  int notTake=0+solve(v,wt,i+1,n,w,dp);
  int take = 0;
  if(w>=wt[i]){
    take = v[i]+solve(v,wt,i+1,n,w-wt[i],dp);
  }
  return dp[i][w] = max(take,notTake);
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
  // Write your code here
  vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
  return solve(values,weights,0,n,w,dp);
}

