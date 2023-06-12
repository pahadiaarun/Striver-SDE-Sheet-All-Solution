// https://leetcode.com/problems/subsets-ii/

class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>>&res,int i,vector<int>temp){
        res.push_back(temp);
        for(int in=i;in<nums.size();in++){
            if(in != i && nums[in]==nums[in-1]) continue;
            temp.push_back(nums[in]);
            solve(nums,res,in+1,temp);
            temp.pop_back();
        }        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        solve(nums,res,0,vector<int>());
        return res;
    }
};
