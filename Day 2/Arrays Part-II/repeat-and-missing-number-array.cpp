// https://www.interviewbit.com/problems/repeat-and-missing-number-array/

// XOR solution

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int xr=0;
    int n=A.size();
    for(int i=0;i<n;i++){
        xr^=(A[i]^(i+1));
    }
    int b=0;
    while(1){
        if(xr & (1<<b)) break;
        b++;
    }
    int z=0,o=0;
    for(int i=0;i<n;i++){
        //one club
        if(A[i] & (1<<b)) o^=A[i];
        //zero club
        else z^=A[i];
    }
    for(int i=1;i<=n;i++){
        //one club
        if(i & (1<<b)) o^=i;
        //zero club
        else z^=i;
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(A[i]==z) cnt++;
    }
    if(cnt==2) return {z,o};
    return {o,z};
}
