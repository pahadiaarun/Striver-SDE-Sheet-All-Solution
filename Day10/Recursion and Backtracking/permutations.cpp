// https://leetcode.com/problems/permutations/

class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>>&res,int i){
        if(i==nums.size()){
            res.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            solve(nums,res,i+1);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        solve(nums,res,0);
        return res;
    }
};
