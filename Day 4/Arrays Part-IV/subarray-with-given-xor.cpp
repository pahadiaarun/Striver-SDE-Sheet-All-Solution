// https://www.interviewbit.com/problems/subarray-with-given-xor/

int Solution::solve(vector<int> &A, int B) {
    long long res=0;
    int xr=0;
    unordered_map<int,int>mp;
    for(int i=0;i<A.size();i++){
        xr=xr^A[i];
        if(xr==B) res++;
        int h=xr^B;
        if(mp.find(h)!=mp.end()){
            res+=mp[h];
        }
        mp[xr]++;
    }
    return res;
}
