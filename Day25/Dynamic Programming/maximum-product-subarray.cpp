// https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int x=1,y=1;
        int n=nums.size();
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            if(x==0) x=1;
            if(y==0) y=1;
            x=x*nums[i];
            y=y*nums[n-i-1];
            mx=max(mx,max(x,y));
        }
        return mx;
    }
};

