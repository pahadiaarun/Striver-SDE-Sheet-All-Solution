// https://www.codingninjas.com/studio/problems/implement-a-queue_8230848?challengeSlug=striver-sde-challenge

#include <bits/stdc++.h> 
class Queue {
public:
    vector<int>v;
    int k=0,n=0;
    Queue() {
        // Implement the Constructor
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return ((n==0) || (k==n));
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        n++;
        v.push_back(data);
    }

    int dequeue() {
        // Implement the dequeue() function
        if(k==n) return -1;
        int x=v[k++];
        return x;
    }

    int front() {
        // Implement the front() function
        if(k==n) return -1;
        return v[k];
    }
};
