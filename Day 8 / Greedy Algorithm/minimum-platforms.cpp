// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
      // Your code here
      sort(arr,arr+n);
      sort(dep,dep+n);
      int i=1,j=0;
      int k=1;
      int res=0;
      while(i<n && j<n){
          if(arr[i]<=dep[j]) k++;
          else j++;
          i++;
          res=max(res,k);
      }
      return res;
    }
};

