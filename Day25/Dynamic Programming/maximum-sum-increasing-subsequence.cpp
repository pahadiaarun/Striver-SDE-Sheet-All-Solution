// https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    

  public:
  int maxSumIS(int rack[], int n)  
  {  
      // Your code goes here
      vector<vector<int>>dp(n+1,vector<int>(n+1,0));
      for(int i=n-1;i>=0;i--){
        for(int j=i-1;j>=-1;j--){
          int len=dp[i+1][j+1];
          if(j==-1 || rack[i]>rack[j]){
            len=max(len,rack[i]+dp[i+1][i+1]);
          }
          dp[i][j+1] = len;
        }
      }
      return dp[0][0];
  }  
};

//{ Driver Code Starts.
int main() 
{
     
   
     int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
          cin >> a[i];

      

      Solution ob;
      cout << ob.maxSumIS(a, n) << "\n";
       
    }
    return 0;
}


// } Driver Code Ends

