// https://www.interviewbit.com/problems/repeat-and-missing-number-array/

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long n=A.size();;
    long long x=(n*(n+1))/2;
    long long y=(n*(n+1)*(2*n+1))/6;
    for(auto i:A){
        x-=(long long)i;
        y-=((long long)i*(long long)i);
    }
    int a=(x+(y/x))/2;
    int b=a-x;
    return {b,a};
}

