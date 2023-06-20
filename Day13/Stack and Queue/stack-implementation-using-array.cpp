// https://www.codingninjas.com/studio/problems/stack-implementation-using-array_8230854?challengeSlug=striver-sde-challenge

#include <bits/stdc++.h> 
// Stack class.
class Stack {
    
public:
    vector<int>arr;
    int k=0,n;
    Stack(int capacity) {
        // Write your code here.
        n=capacity;
        arr.resize(n);
    }

    void push(int num) {
        // Write your code here.
        if(k==n) return;
        arr[k++]=num;
    }

    int pop() {
        // Write your code here.
        if(k==0) return -1;
        int x=arr[k-1];
        k--;
        return x;
    }
    
    int top() {
        // Write your code here.
        if(k==0) return -1;
        return arr[k-1];
    }
    
    int isEmpty() {
        // Write your code here.
        return k==0;
    }
    
    int isFull() {
        // Write your code here.
        return (k==n);
    }
    
};
