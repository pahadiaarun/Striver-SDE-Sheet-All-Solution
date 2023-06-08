// https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1;
        int lmx=0,rmx=0;
        int res=0;
        while(l<=r){
            if(height[l]<=height[r]){
                if(height[l]>=lmx) lmx=height[l];
                else res+=(lmx-height[l]); 
                l++;
            }
            else{
                if(height[r]>=rmx) rmx=height[r];
                else res+=(rmx-height[r]); 
                r--;
            }
        }
        return res;
    }
};

