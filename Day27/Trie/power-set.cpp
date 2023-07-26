// https://practice.geeksforgeeks.org/problems/power-set4302/1#

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
      void solve(string s,vector<string> &res,int i,string temp){
          if(i==s.size()){
              if(temp!="") res.push_back(temp);
              return;
          }
          temp.push_back(s[i]);
          solve(s,res,i+1,temp);
          temp.pop_back();
          solve(s,res,i+1,temp);
      }
    vector<string> AllPossibleStrings(string s){
        // Code here
        vector<string>res;
        solve(s,res,0,"");
        sort(res.begin(),res.end());
        return res;
    }
};

//{ Driver Code Starts.
int main(){
  int tc;
  cin >> tc;
  while(tc--){
    string s;
    cin >> s;
    Solution ob;
    vector<string> res = ob.AllPossibleStrings(s);
    for(auto i : res)
      cout << i <<" ";
    cout << "\n";

  }
  return 0;
}
// } Driver Code Ends

