// https://leetcode.com/problems/search-in-rotated-sorted-array/

int search(int* arr, int n, int key) {
    // Write your code here.
    int l=0,h=n-1,m;
    while(l<=h){
        m=l+(h-l)/2;
        int prev=(m+1)%n;
        int nxt=(m+n-1)%n;
        if(arr[m]<arr[prev] && arr[m]<arr[nxt]) break;
        else if(arr[l]<=arr[m]) l=m+1;
        else if(arr[m]<=arr[h]) h=m-1;
    }
    l=0,h=m-1;
    while(l<=h){
        int mid=(l+h)/2;
        if(arr[mid]==key) return mid;
        else if(arr[mid]>key) h=mid-1;
        else l=mid+1;
    }
    l=m,h=n-1;
    while(l<=h){
        int mid=(l+h)/2;
        if(arr[mid]==key) return mid;
        else if(arr[mid]>key) h=mid-1;
        else l=mid+1;
    }
    return -1;
}

