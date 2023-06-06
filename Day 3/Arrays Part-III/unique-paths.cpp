// https://leetcode.com/problems/unique-paths/

class Solution {
public:
    int uniquePaths(int m, int n) {
        double res=1;
        int a=m+n-2,b=m-1;
        for(int i=1;i<=b;i++) res=res*(a-b+i)/i;
        return (int)res;
    }
};

