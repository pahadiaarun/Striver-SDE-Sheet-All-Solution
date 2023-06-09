// https://www.codingninjas.com/codestudio/problems/1062712?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include <bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &end) {
    // Write your code here.                            
        int res=1,n=start.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({end[i],start[i]});
        }
        sort(v.begin(),v.end());
        int e=v[0].first;
        for(int i=0;i<n;i++){
            if(e<=v[i].second){
                e=v[i].first;
                res++;
            }
        }
        return res;
}

