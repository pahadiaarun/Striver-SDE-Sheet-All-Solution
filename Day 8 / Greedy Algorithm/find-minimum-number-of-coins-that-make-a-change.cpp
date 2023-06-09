// https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/

class Solution{
  public:
  vector<vector<int>>dp;
  int solve(int c[],int m,int v){
      if(m==0) return INT_MAX-1;
      if(v==0) return 0;
      if(dp[m][v]!=-1) return dp[m][v];
      if(v>=c[m-1]){
          return dp[m][v]=min(1+solve(c,m,v-c[m-1]),solve(c,m-1,v));
      }
      return dp[m][v]=solve(c,m-1,v);
  }
  int minCoins(int coins[], int M, int V) 
  { 
      // Your code goes here
      dp.resize(M+1,vector<int>(V+1,-1));
      int res=solve(coins,M,V);
      if(res==INT_MAX-1 || res==INT_MAX) return -1;
        return res;
  } 
};

