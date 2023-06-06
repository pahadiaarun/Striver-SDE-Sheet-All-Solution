// https://www.codingninjas.com/codestudio/problems/count-inversions_615

#include <bits/stdc++.h> 

long long merge(vector<long long>&arr,long long l,long long m,long long h,vector<long long>temp){
    int cnt=0,i=l,j=m,k=l;
    while((i<=m-1) && (j<=h)){
        if(arr[i]<=arr[j]) temp[k++] = arr[i++];
        else{
            temp[k++] = arr[j++];
            cnt+=(m-i);
        }
    }
    while(i<=m-1) temp[k++] = arr[i++];
    while(j<=h) temp[k++] = arr[j++];
    for(i=l;i<=h;i++) arr[i] = temp[i];
    return cnt;
}

long long merge_Sort(vector<long long>&arr,long long l,long long h,vector<long long>temp){
    long long mid,cnt=0;
    if(h>l){
        mid=(l+h)/2;
        cnt+=merge_Sort(arr,l,mid,temp);
        cnt+=merge_Sort(arr,mid+1,h,temp);
        cnt+=merge(arr,l,mid+1,h,temp);
    }
    return cnt;
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    vector<long long>v;
    for(long long i=0;i<n;i++) v.push_back(arr[i]);
    return merge_Sort(v,0,n-1,vector<long long>(n));
}
