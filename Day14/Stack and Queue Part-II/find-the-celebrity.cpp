// https://leetcode.com/accounts/login/?next=/problems/find-the-celebrity/
// https://www.codingninjas.com/studio/problems/the-celebrity-problem_8230781?challengeSlug=striver-sde-challenge

#include <bits/stdc++.h> 
/*
  This is signature of helper function 'knows'.
  You should not implement it, or speculate about its implementation.

  bool knows(int A, int B); 
  Function 'knows(A, B)' will returns "true" if the person having
  id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
   // Write your code here.
   int c=-1;
   stack<int>st;
   for(int i=0;i<n;i++) st.push(i);
   while(st.size()>1){
     int x=st.top();
     st.pop();
     int y=st.top();
     st.pop();
     if (knows(x, y)) st.push(y);
     else st.push(x);
   }
   c=st.top();
   st.pop();
   for(int i=0;i<n;i++){
     if(i!=c && (!knows(i,c) || knows(c,i))) return -1;
   }
   return c;
}

