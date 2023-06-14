// https://www.codingninjas.com/codestudio/problems/merge-k-sorted-arrays_975379

#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    priority_queue<int>pq;
    for(auto i:kArrays){
        for(auto j:i){
            pq.push(j);
        }
    }
    vector<int>res;
    while(pq.size()){
        res.push_back(pq.top());
        pq.pop();
    }
    reverse(res.begin(),res.end());
    return res;
}

