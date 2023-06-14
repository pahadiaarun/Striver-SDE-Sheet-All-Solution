// https://www.interviewbit.com/problems/allocate-books/

bool check(vector<int> &A, int B,int m){
    int cnt=0;
    int sum=0;
    for(auto i:A){
        if(sum+i>m){
            sum=i;
            cnt++;
            if(i>m) return 0;
        }
        else sum+=i;
    }
    return (cnt<B) ;
}

int Solution::books(vector<int> &A, int B) {
    if (B > A.size()) return -1;
    int l=A[0],h=0;
    for(auto i:A){
        h+=i;
        l=min(l,i);
    }
    while(l<=h){
        int mid=(l+h)>>1;
        if(check(A,B,mid)) h=mid-1;
        else l=mid+1;
    }
    return l;
}

