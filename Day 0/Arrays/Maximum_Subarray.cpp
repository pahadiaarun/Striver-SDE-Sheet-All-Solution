// https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx=INT_MIN,mx1=0;
        for(auto i:nums) mx=max(mx,i);
        for(auto i:nums){
            mx1+=i;
            if(mx1>mx) mx=mx1;
            if(mx1<0) mx1=0;
        }
        return mx;
    }
};
