// https://www.interviewbit.com/problems/matrix-median/

int count(vector<int> &row, int mid){
    int l = 0, h = row.size() - 1;
    while (l <= h){
        int md = (l + h) >> 1;
        if (row[md] <= mid) l = md + 1;
        else h = md - 1;
    }
    return l;
}

int Solution::findMedian(vector<vector<int> > &A) {
    int l=1,h=INT_MAX;
    int n=A.size(),m=A[0].size();
    while(l<=h){
        int mid=l+(h-l)/2;
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt += count(A[i], mid);
        }
        if(cnt<=(n*m)/2) l=mid+1;
        else h=mid-1;
    }
    return l;
}

