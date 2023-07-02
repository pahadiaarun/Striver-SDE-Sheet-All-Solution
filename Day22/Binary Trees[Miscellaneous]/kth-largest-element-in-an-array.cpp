// https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int mx=*max_element(nums.begin(),nums.end());
        int mn=*min_element(nums.begin(),nums.end());
        vector<int>v(mx-mn+1,0);
        int z=0-mn;
        for(auto i:nums){
            if(i>0) v[i+z]++;
            else v[z-abs(i)]++;
        }
        int res=0,c=0;
        for(int i=mx-mn;i>=0;i--){
            if(v[i]==0) continue;
            res = i-z;
            if(i==z) res=-1*res;
            c+=v[i];
            if(c>=k) break;
        }
        return res;
    }
};

