// https://www.codingninjas.com/studio/problems/sort-a-stack_8230787?challengeSlug=striver-sde-challenge

#include <bits/stdc++.h> 

void solve(stack<int> &st,int top){
  if(st.empty() || st.top()<top){
    st.push(top);
    return;
  }
  int temp=st.top();
  st.pop();
  solve(st,top);
  st.push(temp);
}

void sortStack(stack<int> &stack)
{
  // Write your code here
  if(stack.empty()) return;
  int num=stack.top();
  stack.pop();
  sortStack(stack);
  solve(stack,num);
}

