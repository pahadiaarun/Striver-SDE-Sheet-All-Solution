// https://leetcode.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            long long x=target-nums[i];
            for(int j=i+1;j<n;j++){
                long long y=x-nums[j];
                int k=j+1,l=n-1;
                while(k<l){
                    long long z=nums[k]+nums[l];
                    if(z==y){
                        vector<int>v={nums[i],nums[j],nums[k],nums[l]};
                        res.push_back(v);
                        while(k<l && nums[k]==v[2]) k++;
                        while(k<l && nums[l]==v[3]) l--;
                    }
                    else if(z>y) l--;
                    else k++;
                }
                while(j+1<n && nums[j]==nums[j+1]) j++;
            }
            while(i+1<n && nums[i]==nums[i+1]) i++;
        }
        return res;
    }
};

