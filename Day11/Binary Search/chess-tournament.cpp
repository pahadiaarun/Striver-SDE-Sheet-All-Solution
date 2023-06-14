// https://www.spoj.com/problems/AGGRCOW/

// https://www.codingninjas.com/codestudio/problems/chess-tournament_8230779?challengeSlug=striver-sde-challenge

#include <bits/stdc++.h> 

bool check(vector<int> p,int n,int c,int mid){
  int x=p[0],cnt=1;
  for(int i=1;i<n;i++){
    if(p[i]-x>=mid){
      x=p[i];
      cnt++;
    }
    if(cnt==c) return 1;
  }
  return 0;
}

int chessTournament(vector<int> positions , int n ,  int c){
  // Write your code here
  sort(positions.begin(),positions.end());
  int l=1,h=positions[n-1]-1;
  int ans=-1;
  while(l<=h){
    int mid=(l+h)>>1;
    if(check(positions,n,c,mid)){
      ans=mid;
      l=mid+1;
    }
    else h=mid-1;
  }
  return ans;
}

