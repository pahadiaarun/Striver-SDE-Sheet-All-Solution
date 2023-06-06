// https://leetcode.com/problems/powx-n/

class Solution {
public:
    double myPow(double x, int n) {
        double res=1.0;
        long nn=n;
        if(n<0) nn=-1*nn;
        while(nn){
            if(nn%2) {res*=x; nn--;}
            else {x*=x; nn=nn/2;}
        }
        if(n<0) res=(double)1/res;
        return res;
    }
};
