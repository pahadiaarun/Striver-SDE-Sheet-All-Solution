// https://leetcode.com/problems/combination-sum/

class Solution {
public:
    void solve(vector<int>&c, vector<vector<int>>&res, int t, int n, vector<int>temp){
        if(n<=0){
            if(t==0) res.push_back(temp);
            return;
        }
        if(t==0){
            res.push_back(temp);
            return;
        }
        if(c[n-1]<=t){
            temp.push_back(c[n-1]);
            solve(c,res,t-c[n-1],n,temp);
            temp.pop_back();
        }
        solve(c,res,t,n-1,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<vector<int>>res;
        solve(candidates,res,target,n,vector<int>());
        return res;
    }
};

